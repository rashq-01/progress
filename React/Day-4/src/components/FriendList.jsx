// FriendList.jsx
function FriendList({ friends, title = "Friends" }) {
  return (
    <div className="friend-list">
      <h3>{title} ({friends.length})</h3>
      {friends.map((friend) => (
        <div key={friend.id} className="friend-item">
          <img src={friend.avatar} alt={friend.name} />
          <div>
            <p>{friend.name}</p>
            <small>{friend.mutual} mutual friends</small>
          </div>
          <button className="btn-follow">Follow</button>
        </div>
      ))}
    </div>
  );
}

export default FriendList;