document.addEventListener('DOMContentLoaded', function() {
    // Mobile menu toggle
    const hamburger = document.querySelector('.hamburger');
    const navMenu = document.querySelector('nav ul');

    hamburger?.addEventListener('click', () => {
        navMenu.classList.toggle('active');
    });

    // Load latest news
    loadLatestNews();
});

function loadLatestNews() {
    const news = [
        {
            title: "Champions League Final Update",
            content: "Latest news about the upcoming Champions League final..."
        },
        {
            title: "Transfer Window News",
            content: "Recent transfers and rumors in the football world..."
        },
        {
            title: "International Fixtures",
            content: "Upcoming international matches and tournament updates..."
        }
    ];

    const newsContainer = document.getElementById('news-container');
    if (!newsContainer) return;

    news.forEach(item => {
        const newsItem = document.createElement('div');
        newsItem.className = 'news-item';
        newsItem.innerHTML = `
            <h3>${item.title}</h3>
            <p>${item.content}</p>
        `;
        newsContainer.appendChild(newsItem);
    });
