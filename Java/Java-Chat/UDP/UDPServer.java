import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class UDPServer {

    private static final int PORT = 6000;

    private static final Set<SocketAddress> clients =
            new HashSet<>();

    public static void main(String[] args) {

        System.out.println("UDP Chat Server starting...");

        try (DatagramSocket socket =
                     new DatagramSocket(PORT)) {

            System.out.println(
                    "UDP Server running on port " + PORT
            );

            byte[] buffer = new byte[1024];

            while (true) {

                DatagramPacket packet =
                        new DatagramPacket(
                                buffer,
                                buffer.length
                        );

                socket.receive(packet);

                SocketAddress clientAddress =
                        packet.getSocketAddress();

                clients.add(clientAddress);

                String message =
                        new String(
                                packet.getData(),
                                packet.getOffset(),
                                packet.getLength(),
                                StandardCharsets.UTF_8
                        );

                System.out.println(
                        "Message: " + message
                );

                byte[] data =
                        message.getBytes(StandardCharsets.UTF_8);

                for (SocketAddress client : clients) {

                    if (!client.equals(clientAddress)) {

                        DatagramPacket response =
                                new DatagramPacket(
                                        data,
                                        data.length,
                                        client
                                );

                        socket.send(response);
                    }
                }

                buffer = new byte[1024];
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}