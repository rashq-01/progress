// ToggleSwitch.jsx
import { useState } from 'react';
import './ToggleSwitch.css';

function ToggleSwitch() {
  const [isOn, setIsOn] = useState(false);
  const [theme, setTheme] = useState('light');
  const [notifications, setNotifications] = useState(true);

  const togglePower = () => {
    setIsOn(prev => !prev);
  };

  const toggleTheme = () => {
    setTheme(prev => prev === 'light' ? 'dark' : 'light');
  };

  const toggleNotifications = () => {
    setNotifications(prev => !prev);
  };

  return (
    <div className={`toggle-container theme-${theme}`}>
      <h2>Toggle Controls</h2>
      
      {/* Power Toggle */}
      <div className="toggle-item">
        <span className="toggle-label">Power</span>
        <button 
          className={`toggle-switch ${isOn ? 'on' : 'off'}`}
          onClick={togglePower}
        >
          <span className="toggle-slider"></span>
          <span className="toggle-state">{isOn ? 'ON' : 'OFF'}</span>
        </button>
      </div>

      {/* Theme Toggle */}
      <div className="toggle-item">
        <span className="toggle-label">Dark Mode</span>
        <button 
          className={`toggle-switch ${theme === 'dark' ? 'on' : 'off'}`}
          onClick={toggleTheme}
        >
          <span className="toggle-slider"></span>
          <span className="toggle-state">{theme === 'dark' ? 'DARK' : 'LIGHT'}</span>
        </button>
      </div>

      {/* Notifications Toggle */}
      <div className="toggle-item">
        <span className="toggle-label">Notifications</span>
        <button 
          className={`toggle-switch ${notifications ? 'on' : 'off'}`}
          onClick={toggleNotifications}
        >
          <span className="toggle-slider"></span>
          <span className="toggle-state">{notifications ? 'ON' : 'OFF'}</span>
        </button>
      </div>

      {/* Status Display */}
      <div className="status-panel">
        <h3>Current Status:</h3>
        <p>🔌 Power: {isOn ? 'ON' : 'OFF'}</p>
        <p>🎨 Theme: {theme}</p>
        <p>🔔 Notifications: {notifications ? 'Enabled' : 'Disabled'}</p>
      </div>
    </div>
  );
}

export default ToggleSwitch;