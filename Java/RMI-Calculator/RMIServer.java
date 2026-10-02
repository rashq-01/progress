import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class RMIServer {

    public static void main(String[] args) {

        try {
            CalculatorImpl calculator = new CalculatorImpl();

            Registry registry = LocateRegistry.createRegistry(1099);

            registry.rebind("CalculatorService", calculator);

            System.out.println("RMI Calculator Server started...");
            System.out.println("Waiting for client...");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}