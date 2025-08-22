function App(){
  const college = "Sri Venkateswara College";
  const course = "B.Tech";
  const year = 3;

  return(
    <>
    <p><b>College </b>: {college}</p>
    <p><b>course </b>: {course}</p>
    <p><b>Year </b>: {year>=3? "Senior":"Junior"}</p>
    
    </>
  );
}

export default App;
