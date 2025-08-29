
class Animal {

    void eat() {
        System.out.println("Animal eats.");
    }

    void sound() {
        System.out.println("Animal sounds.");
    }
}

class dog extends Animal {

    void waveTail() {
        System.out.println("Wagin Tail");
    }

    @Override
    void sound() {
        System.out.println("Dog barks.");
    }
}

public class override {

    public static void main(String[] args) {

        Animal b = new dog();

        dog a = new dog();

        a.eat();
        a.sound();
        a.waveTail();

        b.eat();
        b.sound();
        // b.waveTail();
    }

}
