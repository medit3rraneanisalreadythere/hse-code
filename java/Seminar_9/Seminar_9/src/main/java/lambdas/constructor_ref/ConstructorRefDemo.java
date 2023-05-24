package lambdas.constructor_ref;

import java.util.function.Supplier;

interface MyFunc {
    MyClass func(int n);
}

class MyClass {
    private final int value;

    MyClass(int v) {
System.out.println("MyClass(" + v + ") invoked...");
        value = v;
    }
    MyClass() {
System.out.println("MyClass() invoked...");
        value = 0;
    }

    int getValue() {
        return value;
    }
    public String toString(){
        return getClass().getSimpleName() + "(" + value + ")";
    }
}

public class ConstructorRefDemo {
    public static void main(String[] args) {
        MyFunc myConstructor = MyClass::new;
        MyClass myClassInstance = myConstructor.func(100);
        System.out.println(myClassInstance);
        Supplier<MyClass> myDefaultConstructor = MyClass::new;
        myClassInstance = myDefaultConstructor.get();
        System.out.println(myClassInstance);
    }
}