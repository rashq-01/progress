import java.util.Scanner;

public class Conditional {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int age;
        System.out.print("Enter your age: ");
        age = scn.nextInt();

        if(age<=5){
            System.out.println("Infant.....");
        }
        else if(age<=10){
            System.out.println("Children.....");
        }
        else if(age<18){
            System.out.println("Teen Age....");
        }
        else{
            System.out.println("Adult....");
        }


        int day;
        System.out.print("Enter day : ");
        day = scn.nextInt();

        switch (day) {
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wednesday");
                break;
            default:
                System.out.println("Invalid day");
        }


        scn.close();
    }
}
