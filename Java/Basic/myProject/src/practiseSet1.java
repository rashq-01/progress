
import java.util.Scanner;

public class practiseSet1 {

    public static void main(String[] args) {
        //Sum of three numbers
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter three numbers: ");
        int n1 = scanner.nextInt(), n2 = scanner.nextInt(), n3 = scanner.nextInt();
        System.out.print("The sum of three numbers is : " + (n1 + n2 + n3));

        scanner.close();
    }
}
