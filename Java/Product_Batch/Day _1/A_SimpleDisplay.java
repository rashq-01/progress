
public class A_SimpleDisplay {

    public static void main(String[] args) {
        System.out.println("Hello SVCET....");

        System.out.println("Kohli goes down the ground, Kohli goes out of the ground");

        //Prompt + variable together
        String name = "Kiran";
        String player = "Virat";
        int hs = 183;

        System.out.println("I like " + player + " " + "his highest score is " + hs);

        System.out.println();

        int tempi = 9;
        double tempd = (double) tempi;

        double tempD = 9.9;
        int tempI = (int) tempD;

        System.out.println("Explicit--------->" + tempd);
        System.out.println("Implicit---------->" + tempI);
    }
}


/*

 -- To terminate the line we use the semicolon
 -- Class Name and File Name both should be same and should have the first letter capital
 -- In a java program, we can write multiple classes but only only one class should be public with main method


 ----------------------------------- PART of JAVA Program ----------------------------------------------

 1. Public
    Public is an access modifier and a keyword.

 2. Class
    Class is a keyword and used to create a class.

 3. Main
    Main is the class name and identifier.

 4. Static
    Static is a keyword belongs to the class not to the object
 
 5. Void 
    Void is a return data type of the main method.

 6. Main
    Main is the method and entry point of the execution

 7. Command Line Arguments
    It is used to read input at runtime and options.

 8. System
    

 JRE (Java Run time enviroments)
 JVM + JAva runtime libraries java packages classes eg util,latedt libraries and other supporting file jvm





 Comments are used for information and documentation of the program
 These comments will be ignored during the executions.
      1. for single line comment, we use double slash //
      2. for multi line comment, we use /* */ /*



 Operator
 An operartor is a symbol to manipulate the data to works on operands
 DAY-1: JAVA TARGET 5CR



Types of Programming Language:
 
   1.Monolithic Programming Language:-A single Large block of code there are no control statement
   written only between {}.
   2.Structure Oriented (SOP):IN SOP CONTROL STATEMENTS WERE INTRODUCED.
   3. PROCEDURAL ORIENTED (POP):PROGRAM IS DEVIDED INTO PROCEDURE (FUNCTION).
   4.Object Oriented (OOP): Pragram  is build around classes and objects. Ex - Python and Java


   JAVA INTRODUCTION :
                  JAVA IS A VERY POPULAR PROGRAMMING LANGUAGE DEVELOPED BY  JAMES GOSLING IN 1991 AT
                  SUN MICROSYSTEM  WITH MOTO OF WRITE ONCE RUN ANYWHERE (WORA IS ON WRITE ONCE RUN ANYWHERE).JAVA INITIAL NAME IS OAK.
  ORACLE AQUIRED JAVA IN EARLY 2000.

 THE FIRST VERSION OF JAVA RELEASED IN 1995 .
 
- Java Features:
 
  1.General Purpose :-
    can be used in every domain.
  2.High Level Language:- Java is very easy to understand
  3.Platform Independent :- A java program can run on different Operating system.
  4.Robust:- It can handle Errors. Java supports automatic garbage collection  and Exceptional Handling.
  5.There is no pointer concept.
  6.Java Installation Process:

Key Points:
1 .java is the extension  of every java program  .
2 anycode must be written inside the a class only .
3 to indicate a block we use  {} .
4 to terminate a line we use semicolon ;
5 class name and file name both should be same .
6 in java program we can multiple classes but only one class should be public with main method.

basic code:


public class main{

public static void main(String[] args){

   System.out.println("Hello Narendra !");

}

}

Parts of java Program:
  1.Public : is a  access modifier and keyword.
  2.class : is a keyword and used to create class
  3.main is class name and identifier
  4.static
  5.


JDK
JRE
JVM


JDK:JAVA DEVELOPMENT KIT-> JDK PROVIDES JRE + DEVELOPMENT TOOL (COMPILER ,DEBUGGER ETC).JDK CONTAINS AND JRE TO EXECUTE THE APPLICATION.

JRE:-> JVM + JAVA RUNTIMME LIBRARIES + JAVA PACKAGE CLASSES (E.G UTIL,LIBRARIES AND OTHER SUPPORTING FILES WITH JVM.)

JVM(JAVA VIRTUAL MACHINE):-> JVM(JAVA VIRTUAL MACHINE ) IS A SOFTWARE WHICH CONVERTS BYTES CODE INTO EXECUTABLE CODE.

JVM ARCHITECTURE :

 
   CLASS FILES -> CLASS LOADER SUBSYSTEM
                    |<
                    >
 
[[MEHTOD AREA ] [HEAP] [JAVA STACKS] [PC REGISTERS] [NATIVE METHOD STACKS]]
 
                               ^|
                                >
[EXECUTION ENGINE] <-> NATIVE METHOD INTERFACE <- NATIVE METHOD LIBRARIES
 

JVM IS DIVIDED INTO THEREE PARTS:1.CLASS LOADER SUBSYSTEM: LOAD.CLASS FILES 2.VERIFY THE BYTE CODE 3.ALLOCATE THE MEMORY FOR STATIC VARIABLE
4. INITIALIZES STATIC BLOCK

ii) RUNTIME DATA AREA(IN THE MEMORY AREAS):A METHODS AREA :STORE CLASS INFORMATION , METHODS BYTE CODE AND STATIC VARIABLE
HEAP AREA: STORES OBJECTS AND MANAGED BY GARBAGE COLLECTOR
iii) STACK AREA :- STORES METHODS CALLS AND LOCAL VARIABLE
iV) PC REGISTERS:- PROGRAM COUNTER REGISTER IN THIS AREA STORES THE ADDRESSS OF NEXT EXECUTABLE INSTRUCTION .
V) NATIVE METHODS STACKS:CODES WRITTEN IN C OR C++ RUNS HERE.
VI) EXECUTION ENGINE:- THIS IS HEART OF JVM

   1.INTERPRETER:-EXECUTE THE BYTES CODE LINE BY LINE
   2.JIT COMPILER( JUST INTIME COMPILER) :- CONVERTS MOST USED CODE INTO MACHINE CODE FOR FAST EXECUTION
   3.Garbage Collector: deletes unused objects


output methods:-

  To print the output in the console (screen) in java we can three methods:->
     1.Print Methods-> Control stays on same line.
     2. println methods-> control moves to the nextLine.
     3.printf -> c style formatted output


Data TYPES:
IT TELLS WHICH TYPES OF DATA WE ARE WORKING WITH

TYPES OF DATA TYPES:

Primitive Datatype:
 
  in java there are 8 primitive datatype :
 
  Datatype    Size    Default_value
 
   1.Byte      1        0
   2.Short     2        0
   3.Int       4        0
   4.Long      8        0L

2.Character category data types:

   char        2        \u0000
 
3. Float Category data types


    float      4       0.0f
 
    double     8       0.0d

4.Boolean Category data Types:

    Boolean    1bit    false


java follows Unicode Character set:

Data types are  bounded in java :

byte = 1 byte=8bits

signed=[2^n-1 - 2^n-1 -1] o nether + or - so don't count

unsigned=






 */
