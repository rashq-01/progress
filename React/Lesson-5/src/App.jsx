import InlineCSS from "./InlineCSS";
import Button from "./button";
import './index.css'
import ProfileCard from "./ProfileCard";

function App() {
  const headingStyle = {color:"red", fontSize:"24px"};

  return (
    <>
    <InlineCSS/>
     <h1 style={headingStyle}>HI</h1>
     <br />
      <h1 className="title">Using Global CSS property</h1>
      <br />
      <Button text="Button"/>
      <button className="bg-green-500 text-white px-4 py-2 rounded-lg hover:bg-green-700">Rajesh</button>
      <ProfileCard Name="Rajesh" Branch="CSE" Age={21}/>
    </>
  )
}

export default App
