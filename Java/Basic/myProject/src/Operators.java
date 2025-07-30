public class Operators {
    public static void main(String[] args) {
        int a = 10;
        int b = 5;

        //Arithematic Operators
        System.out.println("Addition : "+(a+b));
        System.out.println("Substraction : "+(a-b));
        System.out.println("Multiplication : "+(a*b));
        System.out.println("Division : "+(a/b));
        System.out.println("Modulus : "+(a%b));

        //Conditional Operators
        System.out.println("\na<b : "+(a<b));
        System.out.println("a>b : "+(a>b));
        System.out.println("a!=b : "+(a!=b));
        System.out.println("a==b : "+(a==b));
        System.out.println("a<=b : "+(a<=b));
        System.out.println("a>=b : "+(a>=b));
        
        //Logical Operators
        System.out.println("\n a<10 && b>10 : "+(a<10 && b>10));
    }
}
