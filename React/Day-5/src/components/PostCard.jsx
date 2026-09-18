// PostCard.jsx
function PostCard({ 
  id,
  title, 
  content, 
  likes, 
  comments, 
  shares, 
  timestamp,
  tags = [],  // Default empty array
  onLike,
  onComment,
  onShare,
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
        <button className="stat-btn like-btn" onClick={(e)=>{
          e.stopPropagation(); // Prevent even bubbling
          onLike(id);
        }}>
          ❤️ {likes}
        </button>

        <button className="stat-btn comment-btn" onClick={()=>onComment(id)}>
        💬 {comments}
        </button>

        <button className="stat-btn share-btn" onClick={()=>onShare(id)}>🔁 {shares}</button>
        <span className="timestamp">{timestamp}</span>
      </div>
    </div>
  );
}


export default PostCard;