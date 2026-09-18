import { useState } from "react";


function Counter(){

    const [count,setCount] = useState(0);
    function Increment(){
        setCount(count+1);
    }
    function Decrement(){
        setCount(count-1);
    }
    function reset(){
        setCount(0);
    }

    return(
        <div>
            <h1>Counter: {(count<0)? "Can't Go below 0":count}</h1>
            <br />
            <button onClick={Increment}>Increment</button><br />
            <button onClick={Decrement}>Decrement</button><br />
            <button onClick={reset}>reset</button>

        </div>
    )

}

export default Counter;