
import java.util.Scanner;

public class methods {

    static int power(int val, int p) {
        int res = 1;
        for (int i = 0; i < p; i++) {
            res *= val;
        }
        return res;
    }

    static boolean isPrime(int val) {
        if (val == 1 || val == 2 || val == 3) {
            return true;
        }
        for (int i = 2; i < val / 2; i++) {
            if (val % 2 == 0) {
                return false;
            }
        }
        return false;
    }

    static int reverseNumber(int num) {
        int res = 0;
        while (num > 0) {
            int dig = num % 10;
            res += dig;
            dig /= 10;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers : ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.printf("Power of %d^%d : ", a, b);
        System.out.println(power(a, b));
        System.out.printf("Prime or not %d: ", a);
        if (isPrime(a)) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }

        System.out.printf("Reversed number of %d : ", a);
        System.out.print(reverseNumber(a));

    }
}
