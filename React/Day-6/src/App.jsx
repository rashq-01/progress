// App.jsx
import { useState } from 'react';
import './App.css';
import SimpleCounter from './components/SimpleCounter';
import ToggleSwitch from './components/ToggleSwitch';
import AdvancedCounter from './components/AdvancedCounter';

function App() {
  const [activeTab, setActiveTab] = useState('simple');

  return (
    <div className="app">
      <h1 className="main-title">🎣 useState Practice</h1>
      
      <div className="tab-navigation">
        <button 
          className={`tab-btn ${activeTab === 'simple' ? 'active' : ''}`}
          onClick={() => setActiveTab('simple')}
        >
          Simple Counter
        </button>
        <button 
          className={`tab-btn ${activeTab === 'toggle' ? 'active' : ''}`}
          onClick={() => setActiveTab('toggle')}
        >
          Toggle Switch
        </button>
        <button 
          className={`tab-btn ${activeTab === 'advanced' ? 'active' : ''}`}
          onClick={() => setActiveTab('advanced')}
        >
          Advanced Counter
        </button>
      </div>

      <div className="demo-container">
        {activeTab === 'simple' && <SimpleCounter />}
        {activeTab === 'toggle' && <ToggleSwitch />}
        {activeTab === 'advanced' && <AdvancedCounter />}
      </div>

      <div className="concepts-summary">
        <h3>📚 What You Learned:</h3>
        <ul>
          <li>✅ useState initialization: <code>const [state, setState] = useState(0)</code></li>
          <li>✅ State updates trigger re-renders</li>
          <li>✅ Functional updates: <code>setCount(prev =&gt; prev + 1)</code></li>
          <li>✅ Multiple state variables in one component</li>
          <li>✅ Boolean state for toggles</li>
          <li>✅ Array state for history</li>
          <li>✅ Input binding with state</li>
        </ul>
      </div>
    </div>
  );
}

export default App;