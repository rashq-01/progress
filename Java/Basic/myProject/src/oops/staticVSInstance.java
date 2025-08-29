
class Parent {

    static void hello() {
        System.out.println("Hello by parent");
    }

    void greet() {
        System.out.println("Greet by Parent");
    }
}

class Child extends Parent {

    // void hello() {
    //     System.out.println("Hello by Child");
    // }
    void greet() {
        System.out.println("Greet by Child");
    }
}

public class staticVSInstance {

    public static void main(String[] args) {
        Parent ref = new Child();

        ref.hello();
        ref.greet();
    }
}
