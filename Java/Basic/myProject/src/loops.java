
import java.util.Scanner;

public class loops {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //For loop
        System.out.print("Enter the size: ");
        int size = scanner.nextInt();
        for (int i = 0; i < size; i++) {
            if (i == 2) {
                continue;
            }
            if (i == 4) {
                break;
            }
            System.out.println((i + 1) + ". For Loop");
        }

        //While Loop
        int i = 0;
        while (i < size) {
            System.out.println((i + 1) + ". While loop");
            i++;
        }

        //Do-While Loop
        i = 0;
        do {
            System.out.println((i + 1) + ". Do-While Loop");
            i++;
        } while (i != size);
        scanner.close();
    }
}
