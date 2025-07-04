#include "helpers.h"
#include <math.h>


// Convert image to grayscale, calculate the averages of rgb and set all 3 to averages- then get 3 to averages
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0;  j < width; j++)
        {
            int average = (int)((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0 + 0.5);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
}

// Convert image to sepia, get original values of RGB - set values to original sepia version of values
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;

            //set the values to original pixel values of sepia
            image[i][j].rgbtRed = fmin(255, (int)(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue + 0.5));
            image[i][j].rgbtGreen = fmin(255, (int)(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue + 0.5));
            image[i][j].rgbtBlue = fmin(255, (int)(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue + 0.5));

            }
    }
}

// Reflect image horizontally, SWAP the pixel values to the evrtical centre of the photo
void reflect(int height, int width, RGBTRIPLE image[height][width])

{
    RGBTRIPLE temp_row[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_row[j] = image[i][j];
        }
         for (int j = 0;  j < width; j++)
         {
            image[i][j].rgbtRed = temp_row[width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = temp_row[width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = temp_row[width - 1 - j].rgbtBlue;
         }
    }
}

// Blur image, iterate over each pixel, - vars to store rgb values and counter in neighbouring pixels iterating in 3*3 grid
//calculate coordinates of neighbouring pixels, skip oob neighb pixles, add rgb valuesof neighbouring pixels to total rgb values
// increment counter for neighouring pixels, set rgb values of current pixel in any temp array to average rgb of neighbouring pixles
// copy blurred pixles to original one
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j  = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0;  j < width; j++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            float counter = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // calculate the coordinates of neigjbouring pixels
                    int currentX = i + x;
                    int currentY = j + y;

                    // neighbouring pixles are not out of bounce skip if it is
                    if (currentX == 0 || currentX > (height - 1) || currentY == 0 || currentY > (width -1))
                    {
                        continue;
                    }

                    //add rgb valuesof neighbouring pixels to total rgb values
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }
            }
            temp[i][j].rgbtRed = round( totalRed / counter);
            temp[i][j].rgbtGreen = round( totalGreen / counter);
            temp[i][j].rgbtBlue = round( totalBlue / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
