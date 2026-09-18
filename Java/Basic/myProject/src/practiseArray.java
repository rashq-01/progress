
import java.util.Scanner;

public class practiseArray {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.printf("Enter size: ");
        int size = sc.nextInt();
        int arr[] = new int[size];
        System.out.printf("Enter %d elements: ", size);
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();

        }
        int sum = 0;
        int max = arr[0];
        int min = arr[0];
        int odd = 0;
        int even = 0;
        System.out.println("\nArray elements: ");
        for (int i = 0; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
            sum += arr[i];
            System.out.print(arr[i] + " ");
            if (arr[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }

        }
        System.out.println();
        System.out.printf("The total Sum : %d", sum);
        System.out.printf("\nMaximum: %d\nMinimum: %d", max, min);
        System.out.printf("\nEven Number : %d\nOdd Number : %d", even, odd);

        //Reversing array;
        int t = size / 2;
        for (int i = 0; i < t; i++) {
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
        System.out.print("\nReverse array : ");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}
