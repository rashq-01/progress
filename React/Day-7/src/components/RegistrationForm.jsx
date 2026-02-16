import { useState } from "react";
import "./Registration.css";

function RegistrationForm() {
  const [formData, setFormData] = useState({
    fullName: "",
    email: "",
    phone: "",
    datOfBirth: "",
    gender: "",

    address: "",
    city: "",
    country: "",
    zipCode: "",

    department: "",
    semester: "",
    subjects: [],

    username: "",
    password: "",
    confirmPassword: "",

    newsletter: false,
    terms: false,
  });

  const [errors, setErrors] = useState({});
  const [submittedData, setSubmittedData] = useState(null);
  const [isEditing, setIsEditing] = useState(false);

  const departments = {
    "Computer Science": [
      "Data Structures",
      "Algorithms",
      "Web Development",
      "Database",
    ],
    Engineering: [
      "Thermodynamics",
      "Fluid Mechanics",
      "Circuit Analysis",
      "Materials",
    ],
    Business: ["Marketing", "Finance", "Economics", "Management"],
    Arts: ["History", "Literature", "Philosophy", "Psychology"],
  };

  // Generic change handler
  const handleChange = (e) => {
    const { name, value, type, checked } = e.target;

    setFormData((prev) => ({
      ...prev,
      [name]: type === "checkbox" ? checked : value,
    }));

    // Clear error for this field
    if (errors[name]) {
      setErrors((prev) => ({
        ...prev,
        [name]: "",
      }));
    }
  };

  // Handle department change (resets subjects)
  const handleDepartmentChange = (e) => {
    const { value } = e.target;
    setFormData(prev => ({
      ...prev,
      department: value,
      subjects: [] // Reset subjects when department changes
    }));
  };

  // Handle subject selection (multiple checkboxes)
  const handleSubjectChange = (e) => {
    const { value, checked } = e.target;
    setFormData(prev => ({
      ...prev,
      subjects: checked
        ? [...prev.subjects, value]
        : prev.subjects.filter(subject => subject !== value)
    }));
  };

  // Validate form
  const validateForm = () => {
    const newErrors = {};

    // Personal Info
    if (!formData.fullName.trim()) {
      newErrors.fullName = 'Full name is required';
    }

    if (!formData.email) {
      newErrors.email = 'Email is required';
    } else if (!/\S+@\S+\.\S+/.test(formData.email)) {
      newErrors.email = 'Email is invalid';
    }

    if (!formData.phone) {
      newErrors.phone = 'Phone number is required';
    } else if (!/^\d{10}$/.test(formData.phone.replace(/\D/g, ''))) {
      newErrors.phone = 'Phone must be 10 digits';
    }

    if (!formData.dateOfBirth) {
      newErrors.dateOfBirth = 'Date of birth is required';
    }

    if (!formData.gender) {
      newErrors.gender = 'Please select a gender';
    }

    // Address
    if (!formData.address.trim()) {
      newErrors.address = 'Address is required';
    }

    if (!formData.city.trim()) {
      newErrors.city = 'City is required';
    }

    if (!formData.country) {
      newErrors.country = 'Please select a country';
    }

    if (!formData.zipCode) {
      newErrors.zipCode = 'ZIP code is required';
    }

    // Academic
    if (!formData.department) {
      newErrors.department = 'Please select a department';
    }

    if (!formData.semester) {
      newErrors.semester = 'Please select a semester';
    }

    if (formData.subjects.length === 0) {
      newErrors.subjects = 'Select at least one subject';
    }

    // Account
    if (!formData.username) {
      newErrors.username = 'Username is required';
    } else if (formData.username.length < 4) {
      newErrors.username = 'Username must be at least 4 characters';
    }

    if (!formData.password) {
      newErrors.password = 'Password is required';
    } else if (formData.password.length < 6) {
      newErrors.password = 'Password must be at least 6 characters';
    }

    if (formData.password !== formData.confirmPassword) {
      newErrors.confirmPassword = 'Passwords do not match';
    }

    // Terms
    if (!formData.terms) {
      newErrors.terms = 'You must accept the terms and conditions';
    }

    return newErrors;
  };

  // Handle form submission
  const handleSubmit = (e) => {
    e.preventDefault();
    
    const newErrors = validateForm();
    if (Object.keys(newErrors).length > 0) {
      setErrors(newErrors);
      // Scroll to first error
      const firstError = document.querySelector('.error-message');
      if (firstError) {
        firstError.scrollIntoView({ behavior: 'smooth', block: 'center' });
      }
      return;
    }

    // Store submitted data
    setSubmittedData(formData);
    console.log('Registration successful:', formData);
    alert('✅ Registration successful! Check the summary below.');
  };

  // Handle edit
  const handleEdit = () => {
    setIsEditing(true);
    window.scrollTo({ top: 0, behavior: 'smooth' });
  };

  // Handle reset
  const handleReset = () => {
    if (window.confirm('Are you sure you want to reset the form?')) {
      setFormData({
        fullName: '',
        email: '',
        phone: '',
        dateOfBirth: '',
        gender: '',
        address: '',
        city: '',
        country: '',
        zipCode: '',
        department: '',
        semester: '',
        subjects: [],
        username: '',
        password: '',
        confirmPassword: '',
        newsletter: false,
        terms: false
      });
      setErrors({});
      setSubmittedData(null);
      setIsEditing(true);
    }
  };


  return (
    <div className="registration-container">
      <h2>🎓 Student Registration System</h2>
      
      {submittedData && !isEditing ? (
        <div className="success-message">
          <h3>✅ Registration Successful!</h3>
          <p>Welcome, {submittedData.fullName}!</p>
          <button onClick={handleEdit} className="edit-btn">
            Edit Registration
          </button>
          <button onClick={handleReset} className="new-btn">
            New Registration
          </button>
        </div>
      ) : (
        <form onSubmit={handleSubmit} className="registration-form">
          {/* Personal Information Section */}
          <fieldset>
            <legend>📋 Personal Information</legend>
            
            <div className="form-group">
              <label>Full Name *</label>
              <input
                type="text"
                name="fullName"
                value={formData.fullName}
                onChange={handleChange}
                placeholder="Enter your full name"
                className={errors.fullName ? 'error' : ''}
              />
              {errors.fullName && <span className="error-message">{errors.fullName}</span>}
            </div>

            <div className="form-row">
              <div className="form-group">
                <label>Email *</label>
                <input
                  type="email"
                  name="email"
                  value={formData.email}
                  onChange={handleChange}
                  placeholder="your@email.com"
                  className={errors.email ? 'error' : ''}
                />
                {errors.email && <span className="error-message">{errors.email}</span>}
              </div>

              <div className="form-group">
                <label>Phone *</label>
                <input
                  type="tel"
                  name="phone"
                  value={formData.phone}
                  onChange={handleChange}
                  placeholder="1234567890"
                  className={errors.phone ? 'error' : ''}
                />
                {errors.phone && <span className="error-message">{errors.phone}</span>}
              </div>
            </div>

            <div className="form-row">
              <div className="form-group">
                <label>Date of Birth *</label>
                <input
                  type="date"
                  name="dateOfBirth"
                  value={formData.dateOfBirth}
                  onChange={handleChange}
                  className={errors.dateOfBirth ? 'error' : ''}
                />
                {errors.dateOfBirth && <span className="error-message">{errors.dateOfBirth}</span>}
              </div>

              <div className="form-group">
                <label>Gender *</label>
                <select
                  name="gender"
                  value={formData.gender}
                  onChange={handleChange}
                  className={errors.gender ? 'error' : ''}
                >
                  <option value="">Select Gender</option>
                  <option value="male">Male</option>
                  <option value="female">Female</option>
                  <option value="other">Other</option>
                  <option value="prefer-not">Prefer not to say</option>
                </select>
                {errors.gender && <span className="error-message">{errors.gender}</span>}
              </div>
            </div>
          </fieldset>

          {/* Address Section */}
          <fieldset>
            <legend>📍 Address</legend>
            
            <div className="form-group">
              <label>Street Address *</label>
              <input
                type="text"
                name="address"
                value={formData.address}
                onChange={handleChange}
                placeholder="Enter your street address"
                className={errors.address ? 'error' : ''}
              />
              {errors.address && <span className="error-message">{errors.address}</span>}
            </div>

            <div className="form-row">
              <div className="form-group">
                <label>City *</label>
                <input
                  type="text"
                  name="city"
                  value={formData.city}
                  onChange={handleChange}
                  placeholder="City"
                  className={errors.city ? 'error' : ''}
                />
                {errors.city && <span className="error-message">{errors.city}</span>}
              </div>

              <div className="form-group">
                <label>Country *</label>
                <select
                  name="country"
                  value={formData.country}
                  onChange={handleChange}
                  className={errors.country ? 'error' : ''}
                >
                  <option value="">Select Country</option>
                  <option value="USA">United States</option>
                  <option value="UK">United Kingdom</option>
                  <option value="Canada">Canada</option>
                  <option value="Australia">Australia</option>
                  <option value="India">India</option>
                  <option value="Other">Other</option>
                </select>
                {errors.country && <span className="error-message">{errors.country}</span>}
              </div>

              <div className="form-group">
                <label>ZIP Code *</label>
                <input
                  type="text"
                  name="zipCode"
                  value={formData.zipCode}
                  onChange={handleChange}
                  placeholder="ZIP Code"
                  className={errors.zipCode ? 'error' : ''}
                />
                {errors.zipCode && <span className="error-message">{errors.zipCode}</span>}
              </div>
            </div>
          </fieldset>

          {/* Academic Information */}
          <fieldset>
            <legend>📚 Academic Information</legend>
            
            <div className="form-row">
              <div className="form-group">
                <label>Department *</label>
                <select
                  name="department"
                  value={formData.department}
                  onChange={handleDepartmentChange}
                  className={errors.department ? 'error' : ''}
                >
                  <option value="">Select Department</option>
                  {Object.keys(departments).map(dept => (
                    <option key={dept} value={dept}>{dept}</option>
                  ))}
                </select>
                {errors.department && <span className="error-message">{errors.department}</span>}
              </div>

              <div className="form-group">
                <label>Semester *</label>
                <select
                  name="semester"
                  value={formData.semester}
                  onChange={handleChange}
                  className={errors.semester ? 'error' : ''}
                >
                  <option value="">Select Semester</option>
                  <option value="1">Semester 1</option>
                  <option value="2">Semester 2</option>
                  <option value="3">Semester 3</option>
                  <option value="4">Semester 4</option>
                  <option value="5">Semester 5</option>
                  <option value="6">Semester 6</option>
                  <option value="7">Semester 7</option>
                  <option value="8">Semester 8</option>
                </select>
                {errors.semester && <span className="error-message">{errors.semester}</span>}
              </div>
            </div>

            <div className="form-group">
              <label>Subjects * (Select at least one)</label>
              <div className="checkbox-group">
                {formData.department ? (
                  departments[formData.department].map(subject => (
                    <label key={subject} className="checkbox-label">
                      <input
                        type="checkbox"
                        value={subject}
                        checked={formData.subjects.includes(subject)}
                        onChange={handleSubjectChange}
                      />
                      {subject}
                    </label>
                  ))
                ) : (
                  <p className="hint">Please select a department first</p>
                )}
              </div>
              {errors.subjects && <span className="error-message">{errors.subjects}</span>}
            </div>
          </fieldset>

          {/* Account Information */}
          <fieldset>
            <legend>🔐 Account Information</legend>
            
            <div className="form-group">
              <label>Username *</label>
              <input
                type="text"
                name="username"
                value={formData.username}
                onChange={handleChange}
                placeholder="Choose a username"
                className={errors.username ? 'error' : ''}
              />
              {errors.username && <span className="error-message">{errors.username}</span>}
            </div>

            <div className="form-row">
              <div className="form-group">
                <label>Password *</label>
                <input
                  type="password"
                  name="password"
                  value={formData.password}
                  onChange={handleChange}
                  placeholder="••••••••"
                  className={errors.password ? 'error' : ''}
                />
                {errors.password && <span className="error-message">{errors.password}</span>}
              </div>

              <div className="form-group">
                <label>Confirm Password *</label>
                <input
                  type="password"
                  name="confirmPassword"
                  value={formData.confirmPassword}
                  onChange={handleChange}
                  placeholder="••••••••"
                  className={errors.confirmPassword ? 'error' : ''}
                />
                {errors.confirmPassword && <span className="error-message">{errors.confirmPassword}</span>}
              </div>
            </div>
          </fieldset>

          {/* Preferences */}
          <fieldset>
            <legend>⚙️ Preferences</legend>
            
            <div className="checkbox-group">
              <label className="checkbox-label">
                <input
                  type="checkbox"
                  name="newsletter"
                  checked={formData.newsletter}
                  onChange={handleChange}
                />
                Subscribe to newsletter
              </label>

              <label className="checkbox-label">
                <input
                  type="checkbox"
                  name="terms"
                  checked={formData.terms}
                  onChange={handleChange}
                />
                I accept the terms and conditions *
              </label>
              {errors.terms && <span className="error-message">{errors.terms}</span>}
            </div>
          </fieldset>

          {/* Form Actions */}
          <div className="form-actions">
            <button type="submit" className="submit-btn">
              Register
            </button>
            <button type="button" onClick={handleReset} className="reset-btn">
              Reset Form
            </button>
          </div>

          {/* Live Preview */}
          <div className="live-preview">
            <h4>👀 Live Preview</h4>
            <p><strong>Name:</strong> {formData.fullName || 'Not provided'}</p>
            <p><strong>Email:</strong> {formData.email || 'Not provided'}</p>
            <p><strong>Department:</strong> {formData.department || 'Not selected'}</p>
            <p><strong>Subjects:</strong> {formData.subjects.length > 0 
              ? formData.subjects.join(', ') 
              : 'None selected'}</p>
          </div>
        </form>
      )}
    </div>
  );
}

export default RegistrationForm;