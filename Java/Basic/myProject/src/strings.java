
import java.lang.*;
import java.util.Scanner;

public class strings {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s1 = "Rajesh Pandit";
        String s2 = new String("Rajesh");
        System.out.println("Length: "+s1.length());
        System.out.println("charAt(3): "+s1.charAt(3));
        System.out.println("substring(3,9): "+s1.substring(3,9));
        System.out.println("Lowercase: "+s1.toLowerCase());
        System.out.println("UpperCase: "+s1.toUpperCase());
        System.out.println("s1=s2 ? : "+s1.equals(s2));
        System.out.println("s1===s2? : "+s1.equalsIgnoreCase(s2));
        System.out.println("s1.contains(aje): "+s1.contains("aje"));
        System.out.println("index of e :"+s1.indexOf("e"));
        System.out.println("Replace a with b : "+s1.replace("a","b"));






        scanner.close();
    }
}
