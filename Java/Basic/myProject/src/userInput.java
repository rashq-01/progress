
import java.util.Scanner;

public class userInput {

    public static void main(String[] args) {
        //Creating object of Scanner
        Scanner scn = new Scanner(System.in);

        // Taking a single word input
        String s1;
        System.out.print("Enter a single word: ");
        s1 = scn.next();
        scn.nextLine();
        System.out.println("Your word is: " + s1);

        // Clear the newline left in the buffer
        // Taking a full sentence or paragraph
        String s2;
        System.out.print("\nEnter a paragraph: ");
        s2 = scn.nextLine();
        System.out.println("Your sentence: " + s2);

        //Taking a integer
        int integer1;
        System.out.print("Enter a integer: ");
        integer1 = scn.nextInt();
        System.out.println("Your integer : " + integer1);

        //Taking a float
        float var1;
        System.out.print("Enter a float value: ");
        var1 = scn.nextFloat();
        System.out.println("Your float : " + var1);

        //Taking double
        double d1;
        System.out.print("Enter a double : ");
        d1 = scn.nextDouble();
        System.out.println("Your double : " + d1);

        //Taking boolean 
        boolean b1;
        System.out.print("Enter a boolean : ");
        b1 = scn.nextBoolean();
        System.out.println("Your boolean : " + b1);

        scn.close();
    }
}
