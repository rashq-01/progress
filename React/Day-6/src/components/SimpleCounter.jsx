// SimpleCounter.jsx
import { useState } from 'react';
import './SimpleCounter.css';

function SimpleCounter() {
  const [count, setCount] = useState(0);

  const increment = () => {
    setCount(prevCount => prevCount + 1);
  };

  const decrement = () => {
    setCount(prevCount => Math.max(0, prevCount - 1));
  };

  const reset = () => {
    setCount(0);
  };

  const addFive = () => {
    // Using function form ensures we get latest state
    setCount(prev => prev + 5);
  };

  return (
    <div className="counter-container">
      <h2>Simple Counter</h2>
      <div className="counter-display">
        <span className="count">{count}</span>
      </div>
      <div className="counter-buttons">
        <button onClick={decrement} className="btn btn-decrement">-</button>
        <button onClick={increment} className="btn btn-increment">+</button>
        <button onClick={addFive} className="btn btn-add-five">+5</button>
        <button onClick={reset} className="btn btn-reset">Reset</button>
      </div>
      <div className="counter-info">
        <p>Count is {count % 2 === 0 ? 'even' : 'odd'}</p>
        {count >= 10 && <p className="warning">🎉 You reached 10+!</p>}
      </div>
    </div>
  );
}

export default SimpleCounter;