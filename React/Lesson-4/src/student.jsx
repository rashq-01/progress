function Student({ name, branch, year }) {
  return (
    <h2>
      Hello {name}, You are from {year} and belongs to {branch} Year.
      Your are {year>=2? "Senior":"Junior"}
    </h2>
  );
}

export default Student;
