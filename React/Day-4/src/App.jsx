// App.jsx
import './App.css';
import ProfileHeader from './components/ProfileHeader';
import StatsCard from './components/StatsCard';
import PostCard from './components/PostCard';
import FriendList from './components/FriendList';

function App() {
  // Mock data
  const userData = {
    name: "Alex Johnson",
    username: "@alexj",
    bio: "Frontend Developer | React Enthusiast | Coffee Lover ☕",
    location: "San Francisco, CA",
    joinDate: "January 2023",
    profileImage: "https://i.pravatar.cc/150?img=1",
    coverImage: "https://picsum.photos/800/200?random=1",
    isVerified: true,
    isOnline: true
  };

  const stats = {
    posts: 156,
    followers: 2458,
    following: 342,
    likes: 12560
  };

  const posts = [
    {
      id: 1,
      title: "Just learned React Hooks!",
      content: "useState and useEffect are game changers!",
      likes: 42,
      comments: 8,
      shares: 3,
      timestamp: "2 hours ago",
      tags: ["react", "webdev", "javascript"]
    },
    {
      id: 2,
      title: "My new project",
      content: "Working on an amazing dashboard with React and Tailwind CSS",
      likes: 128,
      comments: 24,
      shares: 12,
      timestamp: "1 day ago",
      tags: ["react", "tailwind", "project"]
    },
    {
      id: 3,
      title: "React Conference 2024",
      content: "Amazing talks and met so many developers!",
      likes: 256,
      comments: 42,
      shares: 18,
      timestamp: "3 days ago",
      tags: ["conference", "react", "networking"]
    }
  ];

  const friends = [
    { id: 1, name: "Sarah Miller", mutual: 24, avatar: "https://i.pravatar.cc/150?img=5" },
    { id: 2, name: "Mike Chen", mutual: 18, avatar: "https://i.pravatar.cc/150?img=6" },
    { id: 3, name: "Emma Wilson", mutual: 32, avatar: "https://i.pravatar.cc/150?img=7" },
    { id: 4, name: "David Park", mutual: 15, avatar: "https://i.pravatar.cc/150?img=8" }
  ];

  // Event handler functions (will be used tomorrow)
  const handleFollowClick = (friendName) => {
    alert(`Followed ${friendName}!`);
  };

  const handleLikePost = (postTitle) => {
    alert(`Liked post: ${postTitle}`);
  };

  return (
    <div className="app">
      {/* Pass entire userData object using spread operator */}
      <ProfileHeader {...userData} />
      
      <div className="dashboard">
        <main className="main-content">
          <section className="stats-section">
            <h2>Your Statistics</h2>
            <div className="stats-grid">
              {/* Pass individual props */}
              <StatsCard 
                icon="📝" 
                label="Posts" 
                value={stats.posts} 
                color="#ff6b6b" 
              />
              <StatsCard 
                icon="👥" 
                label="Followers" 
                value={stats.followers} 
                color="#4ecdc4" 
              />
              <StatsCard 
                icon="👤" 
                label="Following" 
                value={stats.following} 
                color="#45b7d1" 
              />
              <StatsCard 
                icon="❤️" 
                label="Likes" 
                value={stats.likes} 
                color="#96ceb4" 
              />
            </div>
          </section>

          <section className="posts-section">
            <h2>Recent Posts</h2>
            <div className="posts-container">
              {/* Map through posts array and pass props */}
              {posts.map((post) => (
                <PostCard 
                  key={post.id}
                  title={post.title}
                  content={post.content}
                  likes={post.likes}
                  comments={post.comments}
                  shares={post.shares}
                  timestamp={post.timestamp}
                  tags={post.tags}
                  // Passing function as prop (preview for tomorrow)
                  onLike={() => handleLikePost(post.title)}
                />
              ))}
            </div>
          </section>
        </main>

        <aside className="sidebar">
          {/* Pass friends array and title prop */}
          <FriendList 
            title="Your Friends" 
            friends={friends} 
            onFollow={handleFollowClick} // Function as prop
          />
          
          {/* Same component with different props */}
          <FriendList 
            title="Suggested Friends" 
            friends={friends.slice(0, 2)} // Passing subset
          />
        </aside>
      </div>
    </div>
  );
}

export default App;