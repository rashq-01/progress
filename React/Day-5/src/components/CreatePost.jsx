// CreatePost.jsx
import { useState } from 'react';
import './CreatePost.css';

function CreatePost({ onCreatePost }) {
  const [formData, setFormData] = useState({
    title: '',
    content: '',
    tags: ''
  });

  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData(prev => ({
      ...prev,
      [name]: value
    }));
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    
    // Validation
    if (!formData.title.trim() || !formData.content.trim()) {
      alert('Please fill in all fields!');
      return;
    }

    // Convert tags string to array
    const tagsArray = formData.tags
      .split(',')
      .map(tag => tag.trim())
      .filter(tag => tag !== '');

    // Create new post
    const newPost = {
      id: Date.now(),
      title: formData.title,
      content: formData.content,
      tags: tagsArray,
      likes: 0,
      comments: 0,
      shares: 0,
      timestamp: 'Just now'
    };

    onCreatePost(newPost);
    
    // Reset form
    setFormData({ title: '', content: '', tags: '' });
    
    // Show success message
    alert('Post created successfully! 🎉');
  };

  const handleCancel = () => {
    if (formData.title || formData.content || formData.tags) {
      const confirm = window.confirm('Are you sure? Your post will not be saved.');
      if (confirm) {
        setFormData({ title: '', content: '', tags: '' });
      }
    }
  };

  return (
    <div className="create-post">
      <h3>Create New Post</h3>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          name="title"
          value={formData.title}
          onChange={handleChange}
          placeholder="Post title"
          className="post-title-input"
        />
        
        <textarea
          name="content"
          value={formData.content}
          onChange={handleChange}
          placeholder="What's on your mind?"
          rows="4"
          className="post-content-input"
        />
        
        <input
          type="text"
          name="tags"
          value={formData.tags}
          onChange={handleChange}
          placeholder="Tags (comma separated)"
          className="post-tags-input"
        />
        
        <div className="form-actions">
          <button 
            type="button" 
            className="cancel-btn"
            onClick={handleCancel}
            onMouseEnter={(e) => e.target.style.background = '#f8f9fa'}
            onMouseLeave={(e) => e.target.style.background = 'white'}
          >
            Cancel
          </button>
          <button 
            type="submit" 
            className="submit-btn"
            onMouseEnter={(e) => e.target.style.background = '#0056b3'}
            onMouseLeave={(e) => e.target.style.background = '#007bff'}
          >
            Publish Post
          </button>
        </div>
      </form>
    </div>
  );
}

export default CreatePost;