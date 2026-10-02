import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class RMIClient {

    public static void main(String[] args) {

        try {

            Registry registry =
                    LocateRegistry.getRegistry("localhost", 1099);

            Calculator calculator =
                    (Calculator) registry.lookup("CalculatorService");

            Scanner scanner = new Scanner(System.in);

            System.out.print("Enter first number: ");
            int a = scanner.nextInt();

            System.out.print("Enter second number: ");
            int b = scanner.nextInt();

            System.out.println("\nChoose operation:");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");

            System.out.print("Enter choice: ");
            int choice = scanner.nextInt();

            switch (choice) {

                case 1:
                    System.out.println("Result = " +
                            calculator.add(a, b));
                    break;

                case 2:
                    System.out.println("Result = " +
                            calculator.subtract(a, b));
                    break;

                case 3:
                    System.out.println("Result = " +
                            calculator.multiply(a, b));
                    break;

                case 4:
                    System.out.println("Result = " +
                            calculator.divide(a, b));
                    break;

                default:
                    System.out.println("Invalid choice");
            }

            scanner.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}