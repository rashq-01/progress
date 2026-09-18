// App.jsx
import { useState } from 'react';
import './App.css';
import ProfileHeader from './components/ProfileHeader';
import StatsCard from './components/StatsCard';
import PostCard from './components/PostCard';
import FriendList from './components/FriendList';
import SearchBar from './components/SearchBar';
import CreatePost from './components/CreatePost';

function App() {
  // Move all data to state so it can change
  const [posts, setPosts] = useState([
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
  ]);

  const [searchTerm, setSearchTerm] = useState('');
  const [friends, setFriends] = useState([
    { id: 1, name: "Sarah Miller", mutual: 24, avatar: "https://i.pravatar.cc/150?img=5", isFollowing: false },
    { id: 2, name: "Mike Chen", mutual: 18, avatar: "https://i.pravatar.cc/150?img=6", isFollowing: false },
    { id: 3, name: "Emma Wilson", mutual: 32, avatar: "https://i.pravatar.cc/150?img=7", isFollowing: false },
    { id: 4, name: "David Park", mutual: 15, avatar: "https://i.pravatar.cc/150?img=8", isFollowing: false }
  ]);

  // ============ EVENT HANDLERS ============

  // 1. Handle Follow Button Click
  const handleFollow = (friendName) => {
    setFriends(prevFriends =>
      prevFriends.map(friend =>
        friend.name === friendName
          ? { ...friend, isFollowing: !friend.isFollowing }
          : friend
      )
    );
    
    const friend = friends.find(f => f.name === friendName);
    if (!friend?.isFollowing) {
      alert(`✅ You are now following ${friendName}!`);
    } else {
      alert(`❌ You unfollowed ${friendName}`);
    }
  };

  // 2. Handle Like Button Click
  const handleLike = (postId) => {
    setPosts(prevPosts =>
      prevPosts.map(post =>
        post.id === postId
          ? { ...post, likes: post.likes + 1 }
          : post
      )
    );
    
    // Show like animation (using event)
    const post = posts.find(p => p.id === postId);
    console.log(`❤️ Liked post: "${post?.title}"`);
  };

  // 3. Handle Comment Button Click
  const handleComment = (postId) => {
    const post = posts.find(p => p.id === postId);
    const comment = prompt(`💬 Add a comment to "${post?.title}":`);
    
    if (comment && comment.trim()) {
      setPosts(prevPosts =>
        prevPosts.map(post =>
          post.id === postId
            ? { ...post, comments: post.comments + 1 }
            : post
        )
      );
      alert('✅ Comment added successfully!');
    }
  };

  // 4. Handle Share Button Click
  const handleShare = (postId) => {
    setPosts(prevPosts =>
      prevPosts.map(post =>
        post.id === postId
          ? { ...post, shares: post.shares + 1 }
          : post
      )
    );
    
    const post = posts.find(p => p.id === postId);
    alert(`🔁 Shared post: "${post?.title}"`);
  };

  // 5. Handle Search
  const handleSearch = (term) => {
    setSearchTerm(term);
    console.log(`🔍 Searching for: ${term}`);
  };

  // 6. Handle Create Post
  const handleCreatePost = (newPost) => {
    setPosts([newPost, ...posts]);
  };

  // 7. Handle Delete Post
  const handleDeletePost = (postId) => {
    const confirm = window.confirm('Are you sure you want to delete this post?');
    if (confirm) {
      setPosts(prevPosts => prevPosts.filter(post => post.id !== postId));
      alert('🗑️ Post deleted successfully!');
    }
  };

  // 8. Handle Form Submit Example
  const handleNewsletterSubmit = (e) => {
    e.preventDefault();
    const email = e.target.email.value;
    alert(`📧 Subscribed with email: ${email}`);
    e.target.reset(); // Clear form
  };

  // Filter posts based on search
  const filteredPosts = posts.filter(post =>
    post.title.toLowerCase().includes(searchTerm.toLowerCase()) ||
    post.content.toLowerCase().includes(searchTerm.toLowerCase()) ||
    post.tags.some(tag => tag.toLowerCase().includes(searchTerm.toLowerCase()))
  );

  // User data (static for now)
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
    posts: posts.length,
    followers: 2458,
    following: 342,
    likes: posts.reduce((total, post) => total + post.likes, 0)
  };

  return (
    <div className="app">
      <ProfileHeader {...userData} />
      
      <div className="dashboard">
        <main className="main-content">
          {/* Newsletter Signup Form - onSubmit Example */}
          <form onSubmit={handleNewsletterSubmit} className="newsletter-form">
            <h4>📫 Subscribe to Newsletter</h4>
            <div className="newsletter-input-group">
              <input
                type="email"
                name="email"
                placeholder="Enter your email"
                required
                onChange={(e) => console.log('Email input:', e.target.value)}
              />
              <button type="submit">Subscribe</button>
            </div>
          </form>

          {/* Search Bar - onChange Example */}
          <SearchBar onSearch={handleSearch} />
          
          {/* Create Post Form - onSubmit with multiple inputs */}
          <CreatePost onCreatePost={handleCreatePost} />
          
          <section className="stats-section">
            <h2>Your Statistics</h2>
            <div className="stats-grid">
              <StatsCard icon="📝" label="Posts" value={stats.posts} color="#ff6b6b" />
              <StatsCard icon="👥" label="Followers" value={stats.followers} color="#4ecdc4" />
              <StatsCard icon="👤" label="Following" value={stats.following} color="#45b7d1" />
              <StatsCard icon="❤️" label="Likes" value={stats.likes} color="#96ceb4" />
            </div>
          </section>

          <section className="posts-section">
            <h2>Recent Posts ({filteredPosts.length})</h2>
            <div className="posts-container">
              {filteredPosts.map((post) => (
                <div key={post.id} className="post-wrapper">
                  <PostCard 
                    {...post}
                    onLike={handleLike}
                    onComment={handleComment}
                    onShare={handleShare}
                  />
                  <button 
                    className="delete-post-btn"
                    onClick={() => handleDeletePost(post.id)}
                    onMouseEnter={(e) => e.target.style.opacity = '1'}
                    onMouseLeave={(e) => e.target.style.opacity = '0.7'}
                  >
                    🗑️ Delete
                  </button>
                </div>
              ))}
              
              {filteredPosts.length === 0 && (
                <div className="no-results">
                  <p>🔍 No posts found matching "{searchTerm}"</p>
                </div>
              )}
            </div>
          </section>
        </main>

        <aside className="sidebar">
          <FriendList 
            title="Your Friends" 
            friends={friends}
            onFollow={handleFollow}
          />
          
          <FriendList 
            title="Suggested Friends" 
            friends={friends.slice(0, 2).map(f => ({ ...f, isFollowing: false }))}
            onFollow={handleFollow}
          />
        </aside>
      </div>
    </div>
  );
}

export default App;