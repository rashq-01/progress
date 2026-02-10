import Header from "./components/Header/Header";
import Container from "./components/Container/Container";
import ProductCard from "./components/ProductCard/ProductCard";
import Button from "./components/Button/Button";
import "./App.css";

function App() {
  const product = [
    {
      id: 1,
      name: "Wireless Headphones",
      price: 99.99,
      description: "Noise cancelling wireless headphones",
      imageUrl: "https://picsum.photos/300/200?random=1",
    },
    {
      id: 2,
      name: "Smart Watch",
      price: 199.99,
      description: "Fitness tracker with heart rate monitor",
      imageUrl: "https://picsum.photos/300/200?random=2",
    },
    {
      id: 3,
      name: "Laptop Stand",
      price: 49.99,
      description: "Adjustable aluminum laptop stand",
      imageUrl: "https://picsum.photos/300/200?random=3",
    },
  ];

  const handleAddToCart = (productName)=>{
    alert(`Added ${productName} to cart!`);
  };

  return (
    <div className="App">
      <Header title="TechStore" subtitle="Your one-stop tech shop" />

      <Container className="products-container">
      <div className="products-grid">
        {product.map(pd=>(
          <ProductCard key={pd.id} name={pd.name} price={pd.price} description={pd.description} imageUrl={pd.imageUrl} onAddToCart={()=>handleAddToCart(product.name)} />
        ))}
      </div>

      <div className="cart-summary">
        <h3>Cart Summary</h3>
        <Button variant="primary" onClick={()=>alert(`Checkout clicked!`)} >
        Checkout Now
        </Button>
      </div>
      </Container>
    </div>
  );
}

export default App;
