import java.io.*;
import java.net.*;
import java.util.*;

public class TCPServer {

    private static final int PORT = 5000;

    private static final Set<PrintWriter> clients =
            Collections.synchronizedSet(new HashSet<>());

    public static void main(String[] args) {

        System.out.println("TCP Chat Server starting...");

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {

            System.out.println("TCP Server running on port " + PORT);

            while (true) {

                Socket socket = serverSocket.accept();

                System.out.println(
                        "Client connected: " +
                        socket.getInetAddress()
                );

                new ClientHandler(socket).start();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static void broadcast(String message, PrintWriter sender) {

        synchronized (clients) {

            for (PrintWriter client : clients) {

                if (client != sender) {
                    client.println(message);
                }
            }
        }
    }

    static class ClientHandler extends Thread {

        private Socket socket;
        private PrintWriter out;
        private BufferedReader in;

        ClientHandler(Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {

            try {

                in = new BufferedReader(
                        new InputStreamReader(
                                socket.getInputStream()
                        )
                );

                out = new PrintWriter(
                        socket.getOutputStream(),
                        true
                );

                clients.add(out);

                String message;

                while ((message = in.readLine()) != null) {

                    System.out.println("Message: " + message);

                    broadcast(message, out);
                }

            } catch (IOException e) {

                System.out.println("Client disconnected.");

            } finally {

                if (out != null) {
                    clients.remove(out);
                }

                try {
                    socket.close();
                } catch (IOException ignored) {
                }
            }
        }
    }
}