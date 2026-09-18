// function Greating(props){
//     return <h1>Learning Props: Hello {props.name}!</h1>;
// }

function Greating({name,age}){
    return(
        <h2>Hello {name}! Your Age is {age}.</h2>
    );
};


export default Greating;