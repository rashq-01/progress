
import java.util.Scanner;

public class Array {

    public static void main(String[] args) {
        //Array
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int size = scanner.nextInt();

        int[] data1 = new int[size];         //Declaration and memory allocation
        for (int i = 0; i < size; i++) {
            System.out.printf("Enter %d element: ", i + 1);
            data1[i] = scanner.nextInt();
        }
        System.out.print("Before adding 5: ");
        for (int i = 0; i < size; i++) {
            System.out.printf(" %d ", data1[i]);
        }
        System.out.print("\nAfter adding 5: ");
        for (int i = 0; i < size; i++) {
            System.out.printf(" %d ", data1[i] + 5);
        }

        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6}
        };
        System.out.println();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

    }
}
