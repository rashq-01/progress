// ProductCatalog.jsx
import { useState } from 'react';
import './ProductCatalog.css';

function ProductCatalog() {
  // Initial product data
  const [products, setProducts] = useState([
    {
      id: 1,
      name: 'Wireless Headphones',
      category: 'Electronics',
      price: 99.99,
      rating: 4.5,
      inStock: 15,
      image: '🎧',
      description: 'Noise cancelling wireless headphones with 20hr battery',
      tags: ['audio', 'wireless', 'bluetooth']
    },
    {
      id: 2,
      name: 'Gaming Mouse',
      category: 'Electronics',
      price: 49.99,
      rating: 4.8,
      inStock: 8,
      image: '🖱️',
      description: 'RGB gaming mouse with 6 programmable buttons',
      tags: ['gaming', 'rgb', 'wired']
    },
    {
      id: 3,
      name: 'Mechanical Keyboard',
      category: 'Electronics',
      price: 129.99,
      rating: 4.7,
      inStock: 5,
      image: '⌨️',
      description: 'Mechanical keyboard with blue switches',
      tags: ['mechanical', 'rgb', 'wired']
    },
    {
      id: 4,
      name: 'USB-C Hub',
      category: 'Accessories',
      price: 39.99,
      rating: 4.3,
      inStock: 0,
      image: '🔌',
      description: '7-in-1 USB-C hub with HDMI and SD card reader',
      tags: ['usb', 'adapter', 'multiport']
    },
    {
      id: 5,
      name: 'Laptop Stand',
      category: 'Accessories',
      price: 29.99,
      rating: 4.6,
      inStock: 12,
      image: '💻',
      description: 'Adjustable aluminum laptop stand',
      tags: ['ergonomic', 'aluminum', 'portable']
    },
    {
      id: 6,
      name: 'Monitor 27"',
      category: 'Electronics',
      price: 299.99,
      rating: 4.9,
      inStock: 3,
      image: '🖥️',
      description: '4K UHD monitor with HDR support',
      tags: ['4k', 'monitor', 'display']
    }
  ]);

  // Cart state
  const [cart, setCart] = useState([]);
  
  // Filter and sort state
  const [filterCategory, setFilterCategory] = useState('All');
  const [sortBy, setSortBy] = useState('default');
  const [searchTerm, setSearchTerm] = useState('');
  const [showInStockOnly, setShowInStockOnly] = useState(false);
  
  // UI state
  const [viewMode, setViewMode] = useState('grid'); // 'grid' or 'list'
  const [expandedProduct, setExpandedProduct] = useState(null);

  // Get unique categories for filter
  const categories = ['All', ...new Set(products.map(p => p.category))];

  // ============ FILTERING & SORTING ============
  
  // Filter products based on criteria
  const filteredProducts = products
    .filter(product => {
      // Category filter
      if (filterCategory !== 'All' && product.category !== filterCategory) {
        return false;
      }
      
      // Search filter
      if (searchTerm && !product.name.toLowerCase().includes(searchTerm.toLowerCase()) &&
          !product.description.toLowerCase().includes(searchTerm.toLowerCase())) {
        return false;
      }
      
      // In stock filter
      if (showInStockOnly && product.inStock === 0) {
        return false;
      }
      
      return true;
    })
    .sort((a, b) => {
      // Sorting
      switch(sortBy) {
        case 'price-low':
          return a.price - b.price;
        case 'price-high':
          return b.price - a.price;
        case 'rating':
          return b.rating - a.rating;
        case 'name':
          return a.name.localeCompare(b.name);
        default:
          return 0;
      }
    });

  // ============ CART OPERATIONS ============
  
  const addToCart = (product) => {
    // Check if product already in cart
    const existingItem = cart.find(item => item.id === product.id);
    
    if (existingItem) {
      // Update quantity
      setCart(cart.map(item =>
        item.id === product.id
          ? { ...item, quantity: item.quantity + 1 }
          : item
      ));
    } else {
      // Add new item
      setCart([...cart, { ...product, quantity: 1 }]);
    }
    
    // Update stock
    setProducts(products.map(p =>
      p.id === product.id
        ? { ...p, inStock: p.inStock - 1 }
        : p
    ));
  };

  const removeFromCart = (productId) => {
    // Find item to restore stock
    const cartItem = cart.find(item => item.id === productId);
    
    if (cartItem) {
      // Restore stock
      setProducts(products.map(p =>
        p.id === productId
          ? { ...p, inStock: p.inStock + cartItem.quantity }
          : p
      ));
      
      // Remove from cart
      setCart(cart.filter(item => item.id !== productId));
    }
  };

  const updateQuantity = (productId, newQuantity) => {
    if (newQuantity <= 0) {
      removeFromCart(productId);
      return;
    }
    
    const cartItem = cart.find(item => item.id === productId);
    const product = products.find(p => p.id === productId);
    
    if (cartItem && product) {
      const quantityDiff = newQuantity - cartItem.quantity;
      
      // Check if enough stock
      if (quantityDiff > 0 && product.inStock < quantityDiff) {
        alert(`Only ${product.inStock} items available!`);
        return;
      }
      
      // Update cart quantity
      setCart(cart.map(item =>
        item.id === productId
          ? { ...item, quantity: newQuantity }
          : item
      ));
      
      // Update stock
      setProducts(products.map(p =>
        p.id === productId
          ? { ...p, inStock: p.inStock - quantityDiff }
          : p
      ));
    }
  };

  const clearCart = () => {
    // Restore all stock
    setProducts(products.map(product => {
      const cartItem = cart.find(item => item.id === product.id);
      return cartItem
        ? { ...product, inStock: product.inStock + cartItem.quantity }
        : product;
    }));
    
    // Clear cart
    setCart([]);
  };

  const getCartTotal = () => {
    return cart.reduce((total, item) => total + (item.price * item.quantity), 0);
  };

  // ============ PRODUCT OPERATIONS ============
  
  const addNewProduct = () => {
    const newProduct = {
      id: Date.now(),
      name: 'New Product',
      category: 'Electronics',
      price: 99.99,
      rating: 4.0,
      inStock: 10,
      image: '📦',
      description: 'New product description',
      tags: ['new', 'featured']
    };
    
    setProducts([...products, newProduct]);
  };

  const deleteProduct = (productId) => {
    // Check if in cart
    if (cart.some(item => item.id === productId)) {
      alert('Cannot delete product that is in cart!');
      return;
    }
    
    setProducts(products.filter(p => p.id !== productId));
  };

  const updateProduct = (productId, updates) => {
    setProducts(products.map(p =>
      p.id === productId
        ? { ...p, ...updates }
        : p
    ));
  };

  // ============ RENDER ============
  
  return (
    <div className="product-catalog">
      <header className="catalog-header">
        <h1>🛍️ Product Catalog</h1>
        
        {/* Search Bar */}
        <div className="search-bar">
          <input
            type="text"
            placeholder="Search products..."
            value={searchTerm}
            onChange={(e) => setSearchTerm(e.target.value)}
          />
          {searchTerm && (
            <button onClick={() => setSearchTerm('')} className="clear-search">
              ✕
            </button>
          )}
        </div>

        {/* Controls */}
        <div className="catalog-controls">
          {/* Category Filter */}
          <select 
            value={filterCategory} 
            onChange={(e) => setFilterCategory(e.target.value)}
          >
            {categories.map(category => (
              <option key={category} value={category}>
                {category}
              </option>
            ))}
          </select>

          {/* Sort By */}
          <select value={sortBy} onChange={(e) => setSortBy(e.target.value)}>
            <option value="default">Default</option>
            <option value="price-low">Price: Low to High</option>
            <option value="price-high">Price: High to Low</option>
            <option value="rating">Rating</option>
            <option value="name">Name</option>
          </select>

          {/* In Stock Toggle */}
          <label className="checkbox-label">
            <input
              type="checkbox"
              checked={showInStockOnly}
              onChange={(e) => setShowInStockOnly(e.target.checked)}
            />
            In Stock Only
          </label>

          {/* View Mode Toggle */}
          <div className="view-toggle">
            <button 
              className={`view-btn ${viewMode === 'grid' ? 'active' : ''}`}
              onClick={() => setViewMode('grid')}
            >
              📱 Grid
            </button>
            <button 
              className={`view-btn ${viewMode === 'list' ? 'active' : ''}`}
              onClick={() => setViewMode('list')}
            >
              📋 List
            </button>
          </div>

          {/* Add Product Button */}
          <button onClick={addNewProduct} className="add-product-btn">
            + Add Product
          </button>
        </div>
      </header>

      {/* Main Content */}
      <div className="catalog-content">
        {/* Products Section */}
        <div className={`products-section view-${viewMode}`}>
          <h2>Products ({filteredProducts.length})</h2>
          
          {/* Conditional Rendering for Empty State */}
          {filteredProducts.length === 0 ? (
            <div className="empty-products">
              <p>🔍 No products found</p>
              <button onClick={() => {
                setFilterCategory('All');
                setSearchTerm('');
                setShowInStockOnly(false);
              }}>
                Clear Filters
              </button>
            </div>
          ) : (
            <div className={`products-${viewMode}`}>
              {filteredProducts.map(product => (
                <div 
                  key={product.id} 
                  className={`product-card ${expandedProduct === product.id ? 'expanded' : ''}`}
                >
                  <div className="product-image">{product.image}</div>
                  
                  <div className="product-info">
                    <h3>{product.name}</h3>
                    <p className="product-category">{product.category}</p>
                    
                    {/* Rating Stars */}
                    <div className="rating">
                      {[1, 2, 3, 4, 5].map(star => (
                        <span key={star} className={star <= product.rating ? 'star filled' : 'star'}>
                          ★
                        </span>
                      ))}
                      <span className="rating-value">({product.rating})</span>
                    </div>
                    
                    <p className="product-price">${product.price.toFixed(2)}</p>
                    
                    {/* Stock Status with Conditional Styling */}
                    <p className={`stock-status ${product.inStock > 0 ? 'in-stock' : 'out-of-stock'}`}>
                      {product.inStock > 0 
                        ? `✓ ${product.inStock} in stock` 
                        : '❌ Out of stock'}
                    </p>
                    
                    {/* Expand/Collapse Description */}
                    <button 
                      className="expand-btn"
                      onClick={() => setExpandedProduct(
                        expandedProduct === product.id ? null : product.id
                      )}
                    >
                      {expandedProduct === product.id ? '▲ Less' : '▼ More'}
                    </button>
                    
                    {/* Expanded Content */}
                    {expandedProduct === product.id && (
                      <div className="product-details">
                        <p className="description">{product.description}</p>
                        
                        {/* Tags List */}
                        <div className="tags">
                          {product.tags.map((tag, index) => (
                            <span key={`${product.id}-${tag}-${index}`} className="tag">
                              #{tag}
                            </span>
                          ))}
                        </div>
                        
                        {/* Admin Controls */}
                        <div className="admin-controls">
                          <input
                            type="text"
                            value={product.name}
                            onChange={(e) => updateProduct(product.id, { name: e.target.value })}
                            placeholder="Name"
                          />
                          <input
                            type="number"
                            value={product.price}
                            onChange={(e) => updateProduct(product.id, { price: parseFloat(e.target.value) })}
                            step="0.01"
                          />
                          <button onClick={() => deleteProduct(product.id)} className="delete-btn">
                            Delete
                          </button>
                        </div>
                      </div>
                    )}
                    
                    {/* Add to Cart Button */}
                    <button 
                      className="add-to-cart-btn"
                      onClick={() => addToCart(product)}
                      disabled={product.inStock === 0}
                    >
                      {product.inStock > 0 ? 'Add to Cart' : 'Out of Stock'}
                    </button>
                  </div>
                </div>
              ))}
            </div>
          )}
        </div>

        {/* Shopping Cart Section */}
        <div className="cart-section">
          <h2>Shopping Cart ({cart.length})</h2>
          
          {/* Cart Items List */}
          {cart.length === 0 ? (
            <div className="empty-cart">
              <p>🛒 Your cart is empty</p>
            </div>
          ) : (
            <>
              <div className="cart-items">
                {cart.map(item => (
                  <div key={item.id} className="cart-item">
                    <span className="cart-item-image">{item.image}</span>
                    
                    <div className="cart-item-info">
                      <h4>{item.name}</h4>
                      <p className="cart-item-price">${item.price.toFixed(2)}</p>
                    </div>
                    
                    <div className="cart-item-quantity">
                      <button 
                        onClick={() => updateQuantity(item.id, item.quantity - 1)}
                        disabled={item.quantity <= 1}
                      >
                        -
                      </button>
                      <span>{item.quantity}</span>
                      <button 
                        onClick={() => updateQuantity(item.id, item.quantity + 1)}
                        disabled={item.quantity >= products.find(p => p.id === item.id)?.inStock + item.quantity}
                      >
                        +
                      </button>
                    </div>
                    
                    <button 
                      className="remove-item"
                      onClick={() => removeFromCart(item.id)}
                    >
                      ✕
                    </button>
                  </div>
                ))}
              </div>
              
              {/* Cart Summary */}
              <div className="cart-summary">
                <div className="summary-row">
                  <span>Subtotal:</span>
                  <span>${getCartTotal().toFixed(2)}</span>
                </div>
                <div className="summary-row">
                  <span>Shipping:</span>
                  <span>{getCartTotal() > 100 ? 'Free' : '$5.00'}</span>
                </div>
                <div className="summary-row total">
                  <span>Total:</span>
                  <span>
                    ${(getCartTotal() + (getCartTotal() > 100 ? 0 : 5)).toFixed(2)}
                  </span>
                </div>
                
                <button className="checkout-btn" disabled={cart.length === 0}>
                  Proceed to Checkout
                </button>
                <button className="clear-cart-btn" onClick={clearCart}>
                  Clear Cart
                </button>
              </div>
            </>
          )}
        </div>
      </div>

      {/* Product Statistics - List Summary */}
      <div className="catalog-footer">
        <h3>📊 Catalog Statistics</h3>
        <div className="stats-list">
          <div className="stat-item">
            <span>Total Products:</span>
            <strong>{products.length}</strong>
          </div>
          <div className="stat-item">
            <span>Total Categories:</span>
            <strong>{categories.length - 1}</strong>
          </div>
          <div className="stat-item">
            <span>In Stock Items:</span>
            <strong>{products.filter(p => p.inStock > 0).length}</strong>
          </div>
          <div className="stat-item">
            <span>Out of Stock:</span>
            <strong>{products.filter(p => p.inStock === 0).length}</strong>
          </div>
          <div className="stat-item">
            <span>Average Price:</span>
            <strong>
              ${(products.reduce((sum, p) => sum + p.price, 0) / products.length).toFixed(2)}
            </strong>
          </div>
          <div className="stat-item">
            <span>Cart Value:</span>
            <strong>${getCartTotal().toFixed(2)}</strong>
          </div>
        </div>
      </div>
    </div>
  );
}

export default ProductCatalog;