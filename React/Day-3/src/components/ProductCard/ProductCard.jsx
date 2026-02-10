import Button from "../Button/Button";
import "./ProductCard.css"

function ProductCard({name,price,description,imageUrl,onAddToCart}){
    return(
        <div className="product-card">
            <img src={imageUrl} alt={name} className="product-image" />
            <div className="product-info">
                <h3 className="product-name">{name}</h3>
                <p className="product-description">{description}</p>
                <div className="product-footer">
                    <span className="product-price">${price}</span>
                    <Button variant="secondary" onClick={onAddToCart}>
                        Add to Cart
                    </Button>
                </div>
            </div>
        </div>
    );
}

export default ProductCard;