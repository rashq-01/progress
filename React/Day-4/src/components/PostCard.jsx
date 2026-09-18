// PostCard.jsx
function PostCard({ 
  title, 
  content, 
  likes, 
  comments, 
  shares, 
  timestamp,
  tags = []  // Default empty array
}) {
  return (
    <div className="post-card">
      <h3>{title}</h3>
      <p>{content}</p>
      
      {/* Tags using map */}
      <div className="tags">
        {tags.map((tag, index) => (
          <span key={index} className="tag">#{tag}</span>
        ))}
      </div>
      
      <div className="post-stats">
        <span>❤️ {likes}</span>
        <span>💬 {comments}</span>
        <span>🔁 {shares}</span>
        <span className="timestamp">{timestamp}</span>
      </div>
    </div>
  );
}


export default PostCard;