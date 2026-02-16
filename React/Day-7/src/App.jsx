// App.jsx
import { useState } from 'react';
import RegistrationForm from './components/RegistrationForm';
import './App.css';

function App() {
  const [showForm, setShowForm] = useState(true);

  return (
    <div className="app">
      <header className="app-header">
        <h1>🎓 Student Management System</h1>
        <button 
          className="toggle-btn"
          onClick={() => setShowForm(!showForm)}
        >
          {showForm ? 'Hide Form' : 'Show Form'}
        </button>
      </header>

      {showForm && <RegistrationForm />}

      <footer className="app-footer">
        <p>Day 7 - useState with Objects, Arrays & Form Inputs</p>
      </footer>
    </div>
  );
}

export default App;