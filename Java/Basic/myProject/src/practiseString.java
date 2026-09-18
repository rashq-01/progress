
import java.lang.*;
import java.util.Scanner;

public class practiseString {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Strings : ");
        String s1 = sc.nextLine();
        char[] chars = s1.toCharArray();
        int size = chars.length;
        int t = size / 2;
        boolean pal = true;
        for (int i = 0; i < t; i++) {
            if (chars[i] != chars[size - i - 1]) {
                pal = false;
            }
        }
        if (pal) {
            System.out.print("Palindrom!");
        } else {
            System.out.print("Not Palindrom!!!");
        }
        int vowel = 0, con = 0;
        for (int i = 0; i < size; i++) {
            if ((chars[i] <= (97 + 26)) && (chars[i] >= 97)) {
                vowel++;
            }
            if ((chars[i] <= (65 + 26)) && (chars[i] >= 65)) {
                con++;
            }
        }
        System.out.printf("\nNo. of Vowel : %d\nNo.of Consonant : %d", vowel, con);
        System.out.printf("\na = %d\nA = %d\n", (int) ' ', (int) 'A');

        System.out.println("Enter sentence : ");
        String sen = sc.nextLine();
        System.out.print("Original String : ");
        char[] senChar = sen.toCharArray();
        System.out.print("\nWithout Space : ");
        int sz = senChar.length;
        for (int i = 0; i < sz; i++) {
            if (senChar[i] != ' ') {
                System.out.print(senChar[i]);

            }
        }

        sc.close();

    }
}
