// const employee = {
//     calTax(){
//         console.log('tax rate is 10%')
//     }
// };

// const karnArjun = {
//     salary: 50000
// };

// karnArjun.__proto__ = employee;
// karnArjun.calTax();


// class Car{
//     constructor(){
//         console.log('Creating Constructor')
//     }
//     start(){
//         console.log('Start:');
//     }
    
//     stop(){
//         console.log('Stop');
//     }
//     setBrand(brand){
//         this.brand = brand;
//     }

// }

// let car1 = new Car();
// car1.setBrand('Fortuner')
// console.log(car1)


class Person{
    constructor(){
        console.log('Persong Constructor')
        this.species = 'Homo sapiens';
        console.log('exit person Constructor')
    }
    eat(){
        console.log('Eat');
    }

}

class Engineer extends Person{
    constructor(branch){
        super();
        console.log('Engineer Constructor')
        this.branch = branch;
        console.log('Exit Engineer Constructor')
    }
    work(){
        super.eat();
        console.log('Solve problems, Build Something');
    }

}

let eng1 = new Engineer('CSE');
eng1.work();