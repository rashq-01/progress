import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class UDPClient {

    private static final String SERVER = "localhost";
    private static final int PORT = 6000;

    public static void main(String[] args) {

        try {

            DatagramSocket socket =
                    new DatagramSocket();

            InetAddress serverAddress =
                    InetAddress.getByName(SERVER);

            System.out.println(
                    "Connected to UDP Chat Server."
            );

            Thread receiver = new Thread(() -> {

                try {

                    byte[] buffer = new byte[1024];

                    while (true) {

                        DatagramPacket packet =
                                new DatagramPacket(
                                        buffer,
                                        buffer.length
                                );

                        socket.receive(packet);

                        String message =
                                new String(
                                        packet.getData(),
                                        packet.getOffset(),
                                        packet.getLength(),
                                        StandardCharsets.UTF_8
                                );

                        System.out.println(
                                "\n" + message
                        );

                        System.out.print("You: ");

                        buffer = new byte[1024];
                    }

                } catch (Exception e) {
                    System.out.println(
                            "Disconnected from server."
                    );
                }
            });

            receiver.start();

            Scanner scanner = new Scanner(System.in);

            while (true) {

                System.out.print("You: ");

                String message =
                        scanner.nextLine();

                if (message.equalsIgnoreCase("exit")) {
                    break;
                }

                byte[] data =
                        message.getBytes(
                                StandardCharsets.UTF_8
                        );

                DatagramPacket packet =
                        new DatagramPacket(
                                data,
                                data.length,
                                serverAddress,
                                PORT
                        );

                socket.send(packet);
            }

            socket.close();
            scanner.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}