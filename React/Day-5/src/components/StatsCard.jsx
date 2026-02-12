// StatsCard.jsx
function StatsCard({ icon, label, value, color = "#007bff" }) {
  return (
    <div className="stats-card" style={{ borderTopColor: color }}>
      <div className="stats-icon">{icon}</div>
      <div className="stats-content">
        <h3>{value.toLocaleString()}</h3>
        <p>{label}</p>
      </div>
    </div>
  );
}

// // Usage in App.jsx
// <div className="stats-grid">
//   <StatsCard icon="📝" label="Posts" value={stats.posts} color="#ff6b6b" />
//   <StatsCard icon="👥" label="Followers" value={stats.followers} color="#4ecdc4" />
//   <StatsCard icon="👤" label="Following" value={stats.following} color="#45b7d1" />
//   <StatsCard icon="❤️" label="Likes" value={stats.likes} color="#96ceb4" />
// </div>

export default StatsCard;