import { useState } from "react"

function App(){
  const [name,setName] = useState("");
  const [age,setAge] = useState(0);

  return(
    <div>
      <input type="text" placeholder="Enter your Name" value={name} onChange={(e)=>{setName(e.target.value)}} />
      <br />
      <input type="number" placeholder="Enter your Age" value={age} onChange={(e)=>{setAge(e.target.value)}} />
      <button onClick={()=>{setAge(0);setName("")}}>Reset</button>
      <button type="submit" onClick={()=>{alert(`Hi ${name}, You are ${age} years old.`)}}>submit</button>
      <br />
      <h3>Hello {name}, You are {age} Years old.</h3>

    </div>
  );
}

export default App
