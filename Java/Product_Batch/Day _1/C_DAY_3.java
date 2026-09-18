
import java.util.Scanner;

public class C_DAY_3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number : ");
        int n = sc.nextInt();
        //Start printing
        System.out.println("-------------------SQUARE----------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 || j == 1 || i == n || j == n) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
        System.out.println("-------------------------CROSS---------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || (i + j) == n + 1) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }

        System.out.println("-----------------------PLUS------------------");
        if (n % 2 == 0) {
            System.out.println("Enter odd number only");
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == (n / 2 + 1) || j == (n / 2 + 1)) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }

        System.out.println("-------------------------CROSS with condition---------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || (i + j) == n + 1) {
                    if (i <= n / 2 + 1) {
                        System.out.print(i);
                    } else {
                        System.out.print(n + 1 - i);
                    }
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
        System.out.println("-------------------------SWASTIK---------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((i == n / 2 + 1) || (j == n / 2 + 1) || (i == 1 && j >= (n / 2 + 1)) || (j == 1 && i <= n / 2 + 1) || (i == n && j <= n / 2 + 1) || (j == n && i >= n / 2 + 1)) {
                    System.out.print("*" + " ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }

        System.out.println("------------------------ODD EVEN PATTERN-----------------------");

        int num = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (num % 2 == 0) {
                    System.out.print("0 ");
                } else {
                    System.out.print("1 ");
                }
                num++;
            }
            System.out.println();
        }
        System.out.println("---------------------Right Angled Triangle-----------------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println("---------------------Inverted Right Angled Triangle-----------------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i + 1; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println("---------------------Right Angled Triangle from right side-----------------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                System.out.print("  ");
            }
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println("---------------------Triangle-----------------------------");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                System.out.print("  ");
            }
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            for (int j = i - 1; j >= 1; j--) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println("---------------------Triangle Downward-----------------------------");
        System.out.println();
        for (int i = n; i >= 0; i--) {
            for (int j = 1; j <= n - i; j++) {
                System.out.print("  ");
            }
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            for (int j = i - 1; j >= 1; j--) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println("---------------------Floyd's Triangle-----------------------------");
        int count = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (count < 10) {
                    System.out.print(count++ + "  ");

                } else {
                    System.out.print(count++ + " ");

                }
            }
            System.out.println();
        }

        System.out.println("-----------------------Pascal's Triangle-----------------------------");

        // Formula is value = (value * (row-col))/col;
        for (int r = 0; r < n; r++) {
            int val = 1;
            for (int s = 0; s < n - r; s++) {
                System.out.print(" ");
            }
            for (int c = 0; c <= r; c++) {
                System.out.print(val + " ");
                val = val * (r - c) / (c + 1);
            }
            System.out.println();
        }

        sc.close();
    }
}

/*

P1. Print largest digit in a number;
P2. Happy Number
p3. Strong Number sum of factorials is equl to the original number
p4. Automorphic number
p5. Armstrong number sum of cube of every digit should be equal to number

p6. Ugly Number

    Q1. WAP to print the below pattern
    Q2. WAP to print swastik symbol
    Q3. WAP to print Right angled triangle
    Check the bit
    flip the bit
    clear the bit
    set the bit








 */
