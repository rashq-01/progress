// UserDashboard.jsx
import { useState } from 'react';
import './UserDashboard.css';

function UserDashboard() {
  // State for different conditions
  const [user, setUser] = useState(null); // null, object
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  const [theme, setTheme] = useState('light');
  const [notifications] = useState(3);
  const [view, setView] = useState('grid'); // 'grid' or 'list'
  const [permissions, setPermissions] = useState({
    canEdit: false,
    canDelete: false,
    canShare: true
  });
  const [selectedTab, setSelectedTab] = useState('profile'); // 'profile', 'settings', 'activity'

  // Mock users for demo
  const mockUsers = {
    admin: {
      id: 1,
      name: 'Alice Johnson',
      role: 'admin',
      email: 'alice@example.com',
      avatar: '👩‍💼',
      joinDate: '2023-01-15',
      isActive: true,
      isVerified: true,
      posts: 156,
      followers: 2458
    },
    user: {
      id: 2,
      name: 'Bob Smith',
      role: 'user',
      email: 'bob@example.com',
      avatar: '👨‍💻',
      joinDate: '2024-02-20',
      isActive: true,
      isVerified: false,
      posts: 23,
      followers: 342
    },
    guest: {
      id: 3,
      name: 'Guest User',
      role: 'guest',
      email: 'guest@example.com',
      avatar: '👤',
      joinDate: '2024-03-10',
      isActive: false,
      isVerified: false,
      posts: 0,
      followers: 0
    }
  };

  // Simulate login
  const handleLogin = (role) => {
    setLoading(true);
    setError(null);
    
    // Simulate API call
    setTimeout(() => {
      setUser(mockUsers[role]);
      setLoading(false);
    }, 1500);
  };

  // Simulate logout
  const handleLogout = () => {
    setUser(null);
    setSelectedTab('profile');
  };

  // Simulate error
  const handleError = () => {
    setLoading(true);
    setTimeout(() => {
      setError({ message: 'Failed to load user data. Please try again.' });
      setLoading(false);
    }, 1500);
  };

  // Toggle theme
  const toggleTheme = () => {
    setTheme(prev => prev === 'light' ? 'dark' : 'light');
  };

  // ===========================================
  // CONDITIONAL RENDERING EXAMPLES
  // ===========================================

  // 1. Loading State
  if (loading) {
    return (
      <div className={`dashboard loading-state theme-${theme}`}>
        <div className="loading-spinner">
          <div className="spinner"></div>
          <p>Loading your dashboard...</p>
        </div>
      </div>
    );
  }

  // 2. Error State
  if (error) {
    return (
      <div className={`dashboard error-state theme-${theme}`}>
        <div className="error-container">
          <span className="error-icon">❌</span>
          <h2>Oops! Something went wrong</h2>
          <p>{error.message}</p>
          <button onClick={() => setError(null)} className="retry-btn">
            Try Again
          </button>
        </div>
      </div>
    );
  }

  // 3. No User State (Not Logged In)
  if (!user) {
    return (
      <div className={`dashboard login-state theme-${theme}`}>
        <button onClick={toggleTheme} className="theme-toggle">
          {theme === 'light' ? '🌙' : '☀️'}
        </button>
        
        <div className="login-container">
          <h1>Welcome to User Dashboard</h1>
          <p>Please login to continue</p>
          
          <div className="login-buttons">
            <button onClick={() => handleLogin('admin')} className="login-btn admin">
              Login as Admin
            </button>
            <button onClick={() => handleLogin('user')} className="login-btn user">
              Login as User
            </button>
            <button onClick={() => handleLogin('guest')} className="login-btn guest">
              Login as Guest
            </button>
            <button onClick={handleError} className="login-btn error">
              Simulate Error
            </button>
          </div>

          {/* Tip: Show based on condition */}
          {theme === 'dark' && (
            <p className="dark-mode-tip">🌙 Dark mode is active</p>
          )}
        </div>
      </div>
    );
  }

  // 4. Logged In State - Main Dashboard
  return (
    <div className={`dashboard user-dashboard theme-${theme}`}>
      {/* Header with conditional elements */}
      <header className="dashboard-header">
        <div className="header-left">
          <h1>Dashboard</h1>
          
          {/* Conditional badge based on role */}
          <span className={`role-badge role-${user.role}`}>
            {user.role === 'admin' && '👑 Admin'}
            {user.role === 'user' && '👤 User'}
            {user.role === 'guest' && '🔓 Guest'}
          </span>

          {/* Conditional verification badge */}
          {user.isVerified && (
            <span className="verified-badge" title="Verified Account">
              ✅ Verified
            </span>
          )}
        </div>

        <div className="header-right">
          {/* Theme toggle always visible */}
          <button onClick={toggleTheme} className="theme-toggle">
            {theme === 'light' ? '🌙' : '☀️'}
          </button>

          {/* Conditional notifications - show only if > 0 */}
          {notifications > 0 && (
            <div className="notification-icon">
              🔔
              <span className="notification-count">{notifications}</span>
            </div>
          )}

          <button onClick={handleLogout} className="logout-btn">
            Logout
          </button>
        </div>
      </header>

      {/* User Profile Section */}
      <section className="profile-section">
        <div className="profile-card">
          <div className="profile-avatar">{user.avatar}</div>
          <div className="profile-info">
            <h2>{user.name}</h2>
            <p>{user.email}</p>
            <p className="join-date">Joined: {user.joinDate}</p>
            
            {/* Conditional status indicator */}
            <div className="status-container">
              <span className={`status-dot ${user.isActive ? 'active' : 'inactive'}`}></span>
              <span>{user.isActive ? 'Active' : 'Inactive'}</span>
            </div>
          </div>
        </div>
      </section>

      {/* Stats Section with conditional rendering */}
      <section className="stats-section">
        <h3>Statistics</h3>
        <div className="stats-grid">
          <div className="stat-card">
            <span className="stat-value">{user.posts}</span>
            <span className="stat-label">Posts</span>
          </div>
          <div className="stat-card">
            <span className="stat-value">{user.followers}</span>
            <span className="stat-label">Followers</span>
          </div>
          <div className="stat-card">
            <span className="stat-value">
              {user.role === 'admin' ? '∞' : '5/10'}
            </span>
            <span className="stat-label">Projects</span>
          </div>
        </div>
      </section>

      {/* Tabs Navigation */}
      <div className="tabs-container">
        <button 
          className={`tab ${selectedTab === 'profile' ? 'active' : ''}`}
          onClick={() => setSelectedTab('profile')}
        >
          Profile
        </button>
        <button 
          className={`tab ${selectedTab === 'settings' ? 'active' : ''}`}
          onClick={() => setSelectedTab('settings')}
        >
          Settings
        </button>
        <button 
          className={`tab ${selectedTab === 'activity' ? 'active' : ''}`}
          onClick={() => setSelectedTab('activity')}
        >
          Activity
        </button>

        {/* Conditional view toggle - only show for certain tabs */}
        {selectedTab === 'activity' && (
          <div className="view-toggle">
            <button 
              className={`view-btn ${view === 'grid' ? 'active' : ''}`}
              onClick={() => setView('grid')}
            >
              📱 Grid
            </button>
            <button 
              className={`view-btn ${view === 'list' ? 'active' : ''}`}
              onClick={() => setView('list')}
            >
              📋 List
            </button>
          </div>
        )}
      </div>

      {/* Tab Content with Conditional Rendering */}
      <div className="tab-content">
        {/* Profile Tab */}
        {selectedTab === 'profile' && (
          <div className="profile-tab">
            <h3>Profile Information</h3>
            <div className="info-grid">
              <div className="info-item">
                <label>Full Name</label>
                <p>{user.name}</p>
              </div>
              <div className="info-item">
                <label>Email</label>
                <p>{user.email}</p>
              </div>
              <div className="info-item">
                <label>Role</label>
                <p className={`role-text role-${user.role}`}>
                  {user.role.toUpperCase()}
                </p>
              </div>
              <div className="info-item">
                <label>Account Status</label>
                <p className={user.isActive ? 'active-text' : 'inactive-text'}>
                  {user.isActive ? 'Active' : 'Inactive'}
                </p>
              </div>
            </div>

            {/* Admin-only section */}
            {user.role === 'admin' && (
              <div className="admin-section">
                <h4>👑 Admin Controls</h4>
                <div className="admin-controls">
                  <button className="admin-btn">Manage Users</button>
                  <button className="admin-btn">System Settings</button>
                  <button className="admin-btn">View Logs</button>
                </div>
              </div>
            )}

            {/* Verified user badge - nested condition */}
            {user.isVerified ? (
              <div className="verified-message">
                ✅ Your account is verified. You have access to all features.
              </div>
            ) : (
              <div className="verify-prompt">
                ⚠️ Your account is not verified. 
                <button className="verify-btn">Verify Now</button>
              </div>
            )}
          </div>
        )}

        {/* Settings Tab */}
        {selectedTab === 'settings' && (
          <div className="settings-tab">
            <h3>Account Settings</h3>
            
            {/* Permissions section with conditional toggles */}
            <div className="permissions">
              <h4>Permissions</h4>
              
              <label className="toggle">
                <input 
                  type="checkbox" 
                  checked={permissions.canEdit}
                  onChange={(e) => setPermissions({
                    ...permissions,
                    canEdit: e.target.checked
                  })}
                />
                <span>Can Edit</span>
              </label>

              <label className="toggle">
                <input 
                  type="checkbox" 
                  checked={permissions.canDelete}
                  onChange={(e) => setPermissions({
                    ...permissions,
                    canDelete: e.target.checked
                  })}
                />
                <span>Can Delete</span>
              </label>

              <label className="toggle">
                <input 
                  type="checkbox" 
                  checked={permissions.canShare}
                  onChange={(e) => setPermissions({
                    ...permissions,
                    canShare: e.target.checked
                  })}
                />
                <span>Can Share</span>
              </label>
            </div>

            {/* Conditional warning based on permissions */}
            {!permissions.canDelete && user.role === 'admin' && (
              <div className="warning-message">
                ⚠️ As admin, you should have delete permissions!
              </div>
            )}

            {/* Save button - only show if changes made */}
            {(permissions.canEdit || permissions.canDelete || !permissions.canShare) && (
              <button className="save-settings-btn">
                Save Changes
              </button>
            )}
          </div>
        )}

        {/* Activity Tab */}
        {selectedTab === 'activity' && (
          <div className="activity-tab">
            <h3>Recent Activity</h3>
            
            {/* Conditional empty state */}
            {user.posts === 0 ? (
              <div className="empty-state">
                <p>📭 No activity yet</p>
                {user.role !== 'guest' && (
                  <button className="create-post-btn">
                    Create First Post
                  </button>
                )}
              </div>
            ) : (
              // Show activities based on view mode
              <div className={`activities-view view-${view}`}>
                {[1, 2, 3].map((item) => (
                  <div key={item} className="activity-item">
                    <span className="activity-icon">
                      {view === 'grid' ? '📦' : '📄'}
                    </span>
                    <div className="activity-details">
                      <p>Activity {item}</p>
                      <small>2 hours ago</small>
                    </div>
                  </div>
                ))}
              </div>
            )}
          </div>
        )}
      </div>

      {/* Footer - only show for certain conditions */}
      {user.role !== 'guest' && (
        <footer className="dashboard-footer">
          <p>🔒 Private dashboard. Only visible to registered users.</p>
          {/* Nested condition for beta feature */}
          {user.role === 'admin' && (
            <p className="beta-badge">⚡ Beta features enabled</p>
          )}
        </footer>
      )}
    </div>
  );
}

export default UserDashboard;