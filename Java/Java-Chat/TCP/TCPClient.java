import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPClient {

    private static final String SERVER = "localhost";
    private static final int PORT = 5000;

    public static void main(String[] args) {

        try {

            Socket socket = new Socket(SERVER, PORT);

            System.out.println("Connected to TCP Chat Server.");

            BufferedReader in = new BufferedReader(
                    new InputStreamReader(
                            socket.getInputStream()
                    )
            );

            PrintWriter out = new PrintWriter(
                    socket.getOutputStream(),
                    true
            );

            Thread receiver = new Thread(() -> {

                try {

                    String message;

                    while ((message = in.readLine()) != null) {
                        System.out.println("\n" + message);
                        System.out.print("You: ");
                    }

                } catch (IOException e) {
                    System.out.println("Disconnected from server.");
                }
            });

            receiver.start();

            Scanner scanner = new Scanner(System.in);

            while (true) {

                System.out.print("You: ");

                String message = scanner.nextLine();

                if (message.equalsIgnoreCase("exit")) {
                    break;
                }

                out.println(message);
            }

            socket.close();
            scanner.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}