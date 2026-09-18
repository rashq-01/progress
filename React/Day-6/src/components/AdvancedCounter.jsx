// AdvancedCounter.jsx
import { useState } from 'react';
import './AdvancedCounter.css';

function AdvancedCounter() {
  const [count, setCount] = useState(0);
  const [step, setStep] = useState(1);
  const [history, setHistory] = useState([]);

  const increment = () => {
    setCount(prev => prev + step);
    setHistory(prev => [`Added ${step} → Total: ${count + step}`, ...prev].slice(0, 5));
  };

  const decrement = () => {
    if (count - step >= 0) {
      setCount(prev => prev - step);
      setHistory(prev => [`Subtracted ${step} → Total: ${count - step}`, ...prev].slice(0, 5));
    } else {
      alert("Count cannot go below 0!");
    }
  };

  const reset = () => {
    setCount(0);
    setHistory([]);
  };

  const double = () => {
    setCount(prev => prev * 2);
    setHistory(prev => [`Doubled → Total: ${count * 2}`, ...prev].slice(0, 5));
  };

  const handleStepChange = (e) => {
    const value = parseInt(e.target.value) || 1;
    setStep(Math.max(1, value));
  };

  return (
    <div className="advanced-counter">
      <h2>Advanced Counter</h2>
      
      <div className="count-display">
        <span className="current-count">{count}</span>
      </div>

      <div className="step-control">
        <label>Step Size:</label>
        <input
          type="number"
          min="1"
          max="10"
          value={step}
          onChange={handleStepChange}
        />
      </div>

      <div className="button-grid">
        <button onClick={decrement} className="btn control-btn">-{step}</button>
        <button onClick={increment} className="btn control-btn">+{step}</button>
        <button onClick={double} className="btn control-btn">×2</button>
        <button onClick={reset} className="btn control-btn reset">Reset</button>
      </div>

      <div className="history-section">
        <h3>Recent Operations</h3>
        {history.length > 0 ? (
          <ul className="history-list">
            {history.map((item, index) => (
              <li key={index} className="history-item">{item}</li>
            ))}
          </ul>
        ) : (
          <p className="no-history">No operations yet</p>
        )}
      </div>

      <div className="stats">
        <p>Count is {count % 2 === 0 ? 'even' : 'odd'}</p>
        <p>Count is {count === 0 ? 'zero' : count > 0 ? 'positive' : 'negative'}</p>
      </div>
    </div>
  );
}

export default AdvancedCounter;