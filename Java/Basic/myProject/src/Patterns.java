
import java.util.Scanner;

public class Patterns {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter size: ");
        int size = scanner.nextInt();

        //Triangle pattern
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            System.out.print("\n");
        }
        System.out.println("\n\nSquare pattern");
        //Square pattern
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print("*");
            }
            System.out.print("\n");
        }
        scanner.close();
    }
}
