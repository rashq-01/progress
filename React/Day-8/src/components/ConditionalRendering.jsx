import { useState } from 'react';

function ConditionalRenderingDemo() {
  const [isLoggedIn, setIsLoggedIn] = useState(false);
  const [role, setRole] = useState('user');
  const [notifications, setNotifications] = useState(5);
  const [loading] = useState(false);

  // ===========================================
  // METHOD 1: if/else (outside JSX)
  // ===========================================
  let authButton;
  if (isLoggedIn) {
    authButton = <button onClick={() => setIsLoggedIn(false)}>Logout</button>;
  } else {
    authButton = <button onClick={() => setIsLoggedIn(true)}>Login</button>;
  }

  // ===========================================
  // METHOD 2: Ternary Operator (condition ? true : false)
  // ===========================================
  // Best for if/else scenarios inside JSX
  
  // ===========================================
  // METHOD 3: Logical && (AND operator)
  // ===========================================
  // Best for "show if true" scenarios (no else)
  
  // ===========================================
  // METHOD 4: Switch statement / Object literal
  // ===========================================
  // Best for multiple conditions

  return (
    <div className="demo">
      <h2>🎯 Conditional Rendering Demo</h2>
      
      {/* METHOD 1: if/else (variable) */}
      <div className="section">
        <h3>1. if/else (outside JSX)</h3>
        {authButton}
      </div>

      {/* METHOD 2: Ternary Operator */}
      <div className="section">
        <h3>2. Ternary Operator</h3>
        <p>Status: {isLoggedIn ? '✅ Logged In' : '❌ Logged Out'}</p>
        <button onClick={() => setIsLoggedIn(!isLoggedIn)}>
          {isLoggedIn ? 'Logout' : 'Login'}
        </button>
        
        {/* Ternary with multiple lines */}
        {isLoggedIn ? (
          <div className="welcome-card">
            <h4>Welcome back!</h4>
            <p>You have {notifications} notifications</p>
          </div>
        ) : (
          <div className="login-prompt">
            <p>Please login to continue</p>
          </div>
        )}
      </div>

      {/* METHOD 3: Logical && (AND) */}
      <div className="section">
        <h3>3. Logical && (AND)</h3>
        
        {/* Show only if condition is true */}
        {isLoggedIn && (
          <div className="badge">
            <span>🟢 Online</span>
          </div>
        )}
        
        {/* Show notifications only if > 0 */}
        {notifications > 0 && (
          <div className="notification-badge">
            You have {notifications} unread messages! 
            <button onClick={() => setNotifications(0)}>Mark all read</button>
          </div>
        )}
        
        {/* Loading indicator */}
        {loading && <div className="spinner">Loading...</div>}
        
        {/* Chained conditions */}
        {isLoggedIn && notifications > 3 && (
          <div className="warning">⚠️ Too many notifications!</div>
        )}
      </div>

      {/* METHOD 4: Switch with Object Literal */}
      <div className="section">
        <h3>4. Object Literal (Switch alternative)</h3>
        
        {/* Object mapping */}
        {{
          'admin': <div className="role-admin">👑 Admin Dashboard</div>,
          'user': <div className="role-user">👤 User Profile</div>,
          'guest': <div className="role-guest">🔓 Guest View</div>
        }[role] || <div>🔍 Select a role</div>}

        <div className="role-buttons">
          <button onClick={() => setRole('admin')}>Admin</button>
          <button onClick={() => setRole('user')}>User</button>
          <button onClick={() => setRole('guest')}>Guest</button>
        </div>
      </div>

      {/* Nested Conditions */}
      <div className="section">
        <h3>Nested Conditions</h3>
        {isLoggedIn ? (
          role === 'admin' ? (
            <div>Welcome Admin! You have full access.</div>
          ) : role === 'user' ? (
            <div>Welcome User! View your profile.</div>
          ) : (
            <div>Welcome Guest! Limited access.</div>
          )
        ) : (
          <div>Please login to continue</div>
        )}
      </div>
    </div>
  );
}

export default ConditionalRenderingDemo;