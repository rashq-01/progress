
import java.util.Scanner;

class B_Day_2 {
    public int fact(int n){
      if(n==0 || n==1)return 1;

      return n * fact(n-1);
    }
    public static void main(String[] args) {
        //Bit manipulations

        //User in input
        Scanner sc = new Scanner(System.in);
        // int intVal;
        // float floatVal;

        // System.out.println("Enter integer value : ");
        // intVal = sc.nextInt();
        // System.out.println("Enter float Value : ");
        // floatVal = sc.nextFloat();
        // System.out.print("Enter you name : ");
        // String name = sc.next();
        // System.out.println("You name is : " + name);
        // System.out.println("Enter a character : ");
        // char ch = sc.next().charAt(0);
        // System.out.println(("You entered the character : " + ch));
        // System.out.printf("The values are :- intVal->%d  , floatVal->%f", intVal, floatVal);
        // int a = sc.nextInt();
        // int b = sc.nextInt();
        // // swapping using XOR
        // System.out.print("Before swapping : " + a + " " + b);
        // a = a ^ b;
        // b = a ^ b;
        // a = a ^ b;
        // System.out.print("\nAfter swapping : " + a + " " + b);
        // String name = sc.next();
        // sc.nextLine();
        // float per = sc.nextFloat();
        // int LPA = sc.nextInt();
        // System.out.printf("I'm %s, with %.00f percentage aiming for %d LPA.",name,per,LPA);
        // System.out.print("Enter your age : ");
        // int age = sc.nextInt();
        // if(age>=18 && age<=60){
        //     System.out.println("Have you the pass ?: ");
        //     boolean pass = sc.nextBoolean();
        //     if(pass==true)System.out.println("You are allowed");
        //     else{
        //         System.out.println("You are not allowed.");
        //     }
        // }
        // else{
        //     System.out.println("You are not allowed as your age is not meeting the required age.");
        // }
        // System.out.println("Enter the day number : ");
        // int day = sc.nextInt();
        // switch(day){
        //     case 1 : System.out.println("Monday");break;
        //     case 2 : System.out.println("Tuesday");break;
        //     case 3 : System.out.println("Wednesday");break;
        //     case 4 : System.out.println("Thursday");break;
        //     case 5 : System.out.println("Friday");break;  -> 
        //     case 6 : System.out.println("Saturday");break;  -> 
        //     case 7 : System.out.println("sunday");break;  -> 
        //     default : System.out.println("Invalid day");
        // }
        // System.out.println("Enter the day number : ");
        // int day = sc.nextInt();
        // day %= 7;
        // switch(day){
        //     case 0 : System.out.println("Weekend");break;
        //     case 5 : System.out.println("Weekend");break;
        //     case 6 : System.out.println("Weekend");break;
        //     default : System.out.println("Weekday");break;
        // }
        //-------------------------------LOOPING STATEMENTS------------------------------
        // for (int i = 1; i <= 10; i++) {
        //     System.out.print(i + " ");
        // }
        // System.out.println("Enter the number : ");
        // int num = sc.nextInt();
        // System.out.println("The table of the number " + num);
        // System.out.println();
        // for (int i = 1; i <= 10; i++) {
        //     System.out.println(num + " * " + i + " = " + i * num);
        // }
        //Print divisible of a number in a range 
        // int numberOfFactors = 0;
        // System.out.println("Enter the number : ");
        // int num = sc.nextInt();
        // for (int i = 1; i <= num / 2; i++) {
        //     if (num % i == 0) {
        //         numberOfFactors++;
        //     }
        // }




        //---------------------------------------------------- Home work--------------------------------------------------------
        // 1. Count digit
        // 2. Add digits
        // 3. product digits
        // 4. highest digit
        // 5. least digit

        System.out.println("Enter number : ");
        int num = sc.nextInt();


        int countDig = 0;
        int sum = 0;
        int prod = 1;
        int highest = -1;
        int least = 10000000;

        int temp = num;
        while(temp>0){
            countDig++;
            int rem = temp % 10;
            sum += rem;
            prod *= rem;
            highest = highest > rem ? highest : rem;
            least = least < rem  ? least : rem;

            temp/=10;
        }
        System.out.println("Total digits : " + countDig);
        System.out.println("Sum of digits : " + sum);
        System.out.println("Product of digits : " + prod);
        System.out.println("The highest digit  : " + highest);
        System.out.print("Least digit : " + least);
        

    


        // System.out.println("Total number of factors  : " + numberOfFactors);

        sc.close();
    }
}


/*
To read input at runtime we have to use Scanner class from java.util package
eg Scanner sc = new Scanner(System.in)



2.Derived Data types are collection of primitive Data Types :
 
     1.Array
     2. String
      3. class
     4.INterface
     5 .Enum

3 .Variable:->  Variable is acts like  a container to hold the value in the memory .

  Different Types of variable :
 
Instance Variable ( in class ,out of a method)
Static Variable (in class ,with static keyword)
Local variable ( in class & method)

kEYWORDS:->

       KEYWORDS HAVE RESERVED WORDS WHICH HAS SPECIFIC MEANING WHICH CAN NOT CHANGE AT RUN TIME.OUT OF THEM TWO ARE
           NOT IN USED.
GOTO CONST


Naming Convention :->
 
Pascal Case: used for classname EX: MyProgram
camelCase: used for variable and methods Ex:myFirstName,countIntegers
lowercase:used for single word variables. Ex: num,digits()


Typecasting: converting one to another datatype
1.implicit Type Casting converting lower to higher datatypes  without loosing any data by compiler is called implicit type casting.

2.Explicit type casting : conversion between higher datatype to lower datatype with possible alots of data manually by users.

newvalue=(typecast)value;
double f=3.5;
int i;
i = int(f);
// it cast double value 3.5 to int 3.

// Comments
comments are used for information and documentation of the program.
these comments will be ignored by during execution.


# operators :-> An operators is a special symbol to manipulate the data works on operands .

ARITHMETIC OPERATIONS
  1.+,-,*,/,%

Relational operators -> >,<,==,!=,>= ,<= [boolean]

logical operators-> &&,


BITWISE O:IN BITWISE OPERATIONS ARE PERFORMED BINARY OF THE VALUES ->

      a=

 

  9 = 8421
      00001001
      11110110
 
        -00001001
                 1
                  1010
 
<< left shift multiply by 2 .

right shift divide by 2.

ternary ? : these are the symbols which are used in ternary operators like that.

  System.out.printl( 18%2==0 ? "even" :"odd")

  type of ternary operators :
int n =-10
 
nested ternary : if ? state1 : (if ? stat :else))


(n>0) ? "+ve" :((n<0)? "-ve": "zero")
 


How to read input from the users:

  to read input at run time we have to use
 
Scanner class from java.util package
 


Q.Swapping of two numbers

a=5   b=10

a=15
b=15-10
a=15-5

a=a+b
b=a-b;  5 10
a=a-b;

a=a^b          same shift value 0 different 1.
b=a^b
c=a^b



i'm kiran ,with 8.9 percentage aiming for lpa




 -------------------------------------------- Switch Case------------------------------------------------------------
 1. Syntax for Switch Cases
    
    switch(arg) {
        case exp1 : statement for exp1;break;
        case exp2 : statement for exp2; break;
        case exp3 : statement for exp3; break;
        case exp4 : statement for exp4; break;
        default : statement if no exp matches; break;
    }

    ------------------------------ Home work--------------------
    1. Count digit
    2. Add digits
    3. product digits
    4. highest digit
    5. least digit



    P1 . Perfect number (On LeetCode)
    P2 . Print spy number in a range
    P3 . Add digits of a number until a single digit
    P4 . Program for Neon Number  for a number num if the sum of digits of square of the number is equal
    P5 . Program for factorial of a number 


 */
