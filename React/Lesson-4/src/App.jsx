import Welcome from "./Welcome";
import Greating from "./Greating";
import Box from "./childrenComp"
import Student from "./student";

function App(){
  return(
    <div>
    <h2>App Component</h2>
    <Welcome/>
    <h2>Props!!!!!!!!</h2>
    <Greating name={"Rajesh"} age={20}/>
    <Greating name = {"Suraj"} age={32}/>
    <Greating name = {"Sanjog"} age={33}/>

    <h1>Children Comp!!!!</h1>
    <Box><p>I give anything into this and this will be treated as the child of the Box class</p></Box>

    <h1>For Rajesh: </h1>
    <Student name={"Rajesh Pandit"} branch="B.Tech CSE" year={2}/>
    <h1>For Sanjog: </h1>
    <Student name={"Sanjog Gaudel"} branch="B.Tech ME" year={2}/>
    <h1>For Suraj: </h1>
    <Student name={"Suraj Chaudhary"} branch="B.Tech ME" year={2}/>
    </div>
  );
}

export default App;