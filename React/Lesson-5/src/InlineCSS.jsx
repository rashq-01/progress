import "./App.css"
const css = {color:"red",fontSize:"50px"};
function InlineCSS(){
    return(
        <div>
            <h1 style={css}>Using Inline CSS property with variable</h1>
            <h1 style={{color:"blue",fontFamily:"sans-serif"}}>Using Inline CSS Atributes without variable</h1>

        </div>
    )
}

export default InlineCSS;