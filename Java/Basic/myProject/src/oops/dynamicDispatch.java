
class A {

    void display() {
        System.out.println("Displayed by A");
    }
}

class B extends A {

    @Override
    void display() {
        System.out.println("Displayed by B");
    }
}

class C extends B {

    @Override
    void display() {
        System.out.println("Displayed by C");
    }
}

public class dynamicDispatch {

    public static void main(String[] args) {
        A obj = new C();
        obj.display();
    }
}
