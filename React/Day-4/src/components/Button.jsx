// src/components/Button/Button.jsx
function Button({ 
  label, 
  variant = "primary", 
  size = "medium",
  onClick,
  disabled = false,
  fullWidth = false 
}) {
  const baseStyles = {
    padding: size === "small" ? "8px 16px" : 
             size === "large" ? "14px 28px" : "10px 20px",
    fontSize: size === "small" ? "0.875rem" : 
              size === "large" ? "1.125rem" : "1rem",
    borderRadius: "8px",
    border: "none",
    cursor: disabled ? "not-allowed" : "pointer",
    transition: "all 0.3s ease",
    fontWeight: "600",
    width: fullWidth ? "100%" : "auto",
    opacity: disabled ? 0.6 : 1
  };

  const variants = {
    primary: {
      backgroundColor: "#007bff",
      color: "white",
      "&:hover": {
        backgroundColor: "#0056b3",
        transform: "translateY(-2px)"
      }
    },
    secondary: {
      backgroundColor: "#6c757d",
      color: "white",
      "&:hover": {
        backgroundColor: "#545b62",
        transform: "translateY(-2px)"
      }
    },
    outline: {
      backgroundColor: "transparent",
      color: "#007bff",
      border: "2px solid #007bff",
      "&:hover": {
        backgroundColor: "#007bff",
        color: "white"
      }
    },
    danger: {
      backgroundColor: "#dc3545",
      color: "white",
      "&:hover": {
        backgroundColor: "#bb2d3b",
        transform: "translateY(-2px)"
      }
    }
  };

  return (
    <button
      className={`btn btn-${variant}`}
      style={{
        ...baseStyles,
        ...variants[variant],
        ...(disabled && { pointerEvents: "none" })
      }}
      onClick={onClick}
      disabled={disabled}
    >
      {label}
    </button>
  );
}

export default Button;