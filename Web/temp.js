

class Employee{

    constructor(name,id,deptId,salary){
        this.name = name;
        this.id = id;
        this.salary = salary;
        this.deptId = deptId;

    }


    details(){
        console.log(`Hi welcome ${this.name} having employee id ${this.id} with salary ${this.salary} with department Id : ${this.deptId}`);
    }
}

let emp = new Employee("Rajesh",202,"CSE",500000);
emp.details()