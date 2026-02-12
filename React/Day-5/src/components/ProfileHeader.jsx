// ProfileHeader.jsx
function ProfileHeader({
  name,
  username,
  bio,
  location,
  joinDate,
  profileImage,
  coverImage,
  isVerified,
  isOnline
}) {
  return (
    <div className="profile-header">
      <img src={coverImage} alt="Cover" className="cover-photo" />
      <div className="profile-info">
        <div className="avatar-container">
          <img src={profileImage} alt={name} className="avatar" />
          {isOnline && <span className="online-status"></span>}
        </div>
        <div>
          <h1>
            {name}
            {isVerified && <span className="verified-badge">✓</span>}
          </h1>
          <p className="username">{username}</p>
          <p className="bio">{bio}</p>
          <div className="details">
            <span>📍 {location}</span>
            <span>📅 Joined {joinDate}</span>
          </div>
        </div>
      </div>
    </div>
  );
}

export default ProfileHeader;