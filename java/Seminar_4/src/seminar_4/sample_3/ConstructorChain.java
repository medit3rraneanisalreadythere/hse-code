package seminar_4.sample_3;

//TODO: what will be printed when running that program? Explain - why?

public class ConstructorChain {
    public static void main(String[] args) {
        Child c = new Child();
    }
}

class Child extends Parent {
    Child() {
        System.out.println("Child() constructor");
    }
}

class Parent extends Grandparent {
    Parent() {
//        super();
        this(25);
        System.out.println("Parent() constructor");
    }

    Parent(int x) {
//        this();
//        super(); //TODO: what will be happened when we'll uncomment it? Try it ...
        System.out.println("Parent(" + x + ") constructor");
    }
}

class Grandparent {
    Grandparent() {
        System.out.println("Grandparent() constructor");
    }
}