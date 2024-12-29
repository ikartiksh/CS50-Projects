const players = [
    {
        name: "Pelé",
        country: "Brazil",
        achievements: "3 World Cups, 1279 goals",
        bio: "Widely regarded as one of the greatest players of all time..."
    },
    {
        name: "Diego Maradona",
        country: "Argentina",
        achievements: "1986 World Cup, 2 Serie A titles",
        bio: "Famous for the 'Hand of God' goal and leading Argentina to World Cup glory..."
    },
    // Add more players
];

function loadPlayers() {
    const container = document.getElementById('player-container');
    if (!container) return;

    players.forEach(player => {
        const card = document.createElement('div');
        card.className = 'player-card';
        card.innerHTML = `
            <h3>${player.name}</h3>
            <p>${player.country}</p>
            <button onclick="showPlayerDetails('${player.name}')">View Details</button>
        `;
        container.appendChild(card);
    });
}

function showPlayerDetails(playerName) {
    const player = players.find(p => p.name === playerName);
    const detailsContainer = document.getElementById('detailed-info');
    if (!detailsContainer || !player) return;

    detailsContainer.innerHTML = `
        <h3>${player.name}</h3>
        <p><strong>Country:</strong> ${player.country}</p>
        <p><strong>Achievements:</strong> ${player.achievements}</p>
        <p>${player.bio}</p>
    `;
}

document.addEventListener('DOMContentLoaded', loadPlayers);
