
public class Threads {

    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            for (int i = 1; i <= 5; i++) {
                System.out.println("Task 1 - Count: " + i);
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 1; i <= 5; i++) {
                System.out.println("Task 2 - Count: " + i);
            }
        });

        t1.start();
        t2.start();
    }
}
