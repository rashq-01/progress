import './Counter.css'
import { useState } from 'react';
function Counter(){
    const [count,setCount] = useState(0);
    function clickHander(status){
        if(status===1){
            setCount((prev=>prev+1));
        }
        else if(status===-1){
            setCount((prev=>prev-1));
        }
        else if(status===0){
            setCount(10);
        }
    }
    return(
        <div className="counter-container">
            <p id="para">You have clicked {count} times</p>
            <div className='btn-group'>
            <button id="btn" onClick={()=>clickHander(1)}>Increment by 1</button>
            <button id="btn" onClick={()=>clickHander(-1)}>Decrement by 1</button>
            <button id="btn"onClick={()=>clickHander(0)} >Reset</button>

            </div>
        </div>
    )
}
export default Counter;