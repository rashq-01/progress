
import java.util.Scanner;

public class C_DAY_3_BIT {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Using bit manipulation to find even or odd
        // System.out.println("Enter the number");
        // int n = sc.nextInt();
        // System.out.println((n & 1) == 1 ? "Odd" : "Even");
        // 1. increment with 1 without using +
        // System.out.println("Enter the number  : ");
        // int n = sc.nextInt();
        // System.out.println(-1 * (~n));
        //2. check if the number is power of 2 or not
        // System.out.println("Enter the number : ");
        // int n = sc.nextInt();
        // if ((n & (n - 1)) == 0) {
        //     System.out.println("This number is the power of 2.");
        // } else {
        //     System.out.println("This number is not power of 2.");
        // }
        //3. Count set bit in a number
        // System.out.println("Enter the number : ");
        // int n = sc.nextInt();
        // int c = 0;
        // while (n > 0) {
        //     c += (n & 1);
        //     n >>= 1;
        // }
        // System.out.println("Total set bit : " + c);

        sc.close();
    }
}
