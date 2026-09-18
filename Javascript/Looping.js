// let gameNum = 25;
// let userNum = parseInt(prompt("Guess a number"));
// console.log(typeof userNum);


// while(userNum != gameNum){
//     console.log("Guess again");
//     userNum = prompt("Guess again");
// }
// console.log("You guessed it right");





// let name ="Rajesh Pandit";
// for(let x in name){
//     console.log(x);
// }







// let name1 = "Rajesh Pandit";
// for(let x of name1){
//     console.log(x);
// }


// let num = parseInt(prompt("Guess a number"));
// var sum = 0;
// document.getElementById('temp').innerHTML =pandit;

// function guess() {
//     for(let i = num; i >= 1; i--) {
//         sum = sum + i;
//         console.log(sum);
//     }
//     console.log("The total sum is: ",sum);
//     document.getElementById("temp").innerHTML = sum;

// }







// function add(number1,number2){
//     let number3;
//     number3 = number1 + number2;
//     // byd default its a number value
//     console.log(typeof number3);
//     console.log(number3);


//     // conversion of number into a string
//     let number4 = String(number3);
//     console.log(typeof number4);
//     console.log(number4);

//     // Conversion of string and number into a boolean value
//     let number5 = Boolean(number4);
//     console.log(typeof number5);
//     console.log(number5);


//     let number6 = Boolean(number3);
//     console.log(typeof number6);
// }
// add(parseInt(prompt("Enter a number")), parseInt(prompt("Enter a number")));




// let book = ["Rajesh", "Naresh", "Pradip","Bikash","Rupesh","Nitesh", 6, true] ;
// book.push("Temp");
// for(let i = 0; i < book.length; i++){
//     console.log(book[i]);
// }


// Function with a button click
// let sum = 0;
// function add(){
//     console.log("Rajesh Pandit");
//     console.log("Clicked on");
//     document.getElementById("temp").innerHTML = document.getElementById("temp").innerHTML + "<h1>"+ sum + "</h1>" ;
//     // let conf = confirm("Are you sure");
//     // console.log(conf);
//     sum = sum + 2;
// }



//Objects

// let person = {
    //     name: "Rajesh",
//     age: 16,
//     class: 12,
//     address: "Bishrampur-03, Bara, Nepal"
// };
// function btn(){
//     let input = parseInt(prompt("Enter 1 for name, 2 for age, 3 for class, 4 for Address"));
//     if(input == 1){
//         console.log(person.name);
//         document.getElementById('h1').innerHTML = person.name;
//     }
//     else if(input == 2){
//         console.log(person.age);
//         document.getElementById('h1').innerHTML = person.age;
//     }
//     else if(input == 3){
//         console.log(person.class);
//         document.getElementById('h1').innerHTML = person.class;
//     }
//     else if(input == 4){
//         console.log(person.address);
//         document.getElementById('h1').innerHTML = person.address;
//     }
//     else if(input == 5){
//         console.log(person);
//         document.getElementById('h1').innerHTML = person;
//     }
//     else{
    //         console.log("Invalid Input")
    //         document.getElementById('h1').innerHTML = "Invalid Input";
    //     }
    // }
    
    

    
    // var user = {
        //     name: "rajesh",
        //     age: 16,
        //     class: 12,
        //     address: "Bishrampur-03, Bara, Nepal",
        //     personalinfo: {
            //         password: "nothing",
            //         email: 123456789,
            //         phone: 987654321,
            //     }
            // };

            
            
            
            // hello();
            // function hello(){
//     console.log("Hello function is called");
// }

// Hoisting

// var x = 0;
// var y = Boolean(x);
// console.log(typeof(y));
// console.log(typeof(x));
// console.log("The value of y is ",y);

// function click(){
    //     console.log("Clicked on");
    // }
    
    // let btn = document.querySelector('.btn');
    // btn.addEventListener('click', click());

    // var x = 4.9;
    
    // var m = Math.round(x);
    // var m = Math.ceil(x);
    // var m = Math.floor(x);
    // var m = Math.trunc(x);  
// var m = Math.pow(10,2);  

// console.log(m);

// function random(min, max){
    
//     let x = Math.floor(Math.random() * (max -min + 1) + min);
//     return x;
    

// document.getElementById('btn').addEventListener("click", function(){
//     console.log("Clicked on");
//     document.getElementById("temp").innerHTML = document.getElementById("temp").innerHTML + "<div>"+ sum + "</div>" ;
//     // let conf = confirm("Are you sure");
//     // console.log(conf);
//     sum = sum + 2;
// }) 
// // document.getElementById('btn').addEventListener('click',btn());





// }
// function generate(){
//     var min = parseInt(document.getElementById('min').value);
//     var max = parseInt(document.getElementById('max').value);
//     var result = Math.floor(Math.random()*(max-min+1)+min)
//     console.log(result);
    
// }
var date = Date();
console.log(date);