
import java.util.Scanner;

public class B_Day_2_Homework {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // P1. Number until its sum of digit zero
        System.out.print("Enter the range (eg 5 10)");
        int start = sc.nextInt();
        int last = sc.nextInt();

        for (int i = start; i <= last; i++) {
            int spy = i;
            int sum = 0;
            int prod = 1;
            while (spy > 0) {
                int dig = spy % 10;
                sum += dig;
                prod *= dig;
                spy /= 10;
            }
            if (sum == prod) {
                System.out.print(i + " ");
            }

        }

        // P3 . Add digits of a number until a single digit
        System.out.print("Enter the number : ");
        int num = sc.nextInt();

        while (num / 10 != 0) {
            int temp = num;

            int sum = 0;
            while (temp > 0) {
                sum += (temp % 10);
                temp /= 10;
            }
            num = sum;
        }
        System.out.println("The final number is : " + num);

        //    P4 . Program for Neon Number  for a number num if the sum of digits of square of the number is equal
        System.out.println("---------------For NEON NUMBER--------------------");
        System.out.print("Enter the number : ");
        int neon = sc.nextInt();
        int sqr = neon * neon;
        int temp = neon;
        int sum = 0;
        while (sqr > 0) {
            sum += (sqr % 10);
            sqr /= 10;
        }
        System.out.println(sum == temp ? "It's a NEON number." : "It's not a NEON number");


        System.out.println("-------------------------Factorial-----------------------------");
        System.out.print("Enter the number : ");
        int fact = sc.nextInt();
        

        sc.close();
    }
}
