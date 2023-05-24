package lambdas;

import tool.Reflector;

@FunctionalInterface
interface MyFunction{
    int perform(int n);
}

/**
 * TODO: this test illustrates effectively final requirements for locals and arguments values.
 */
public class Sample5_LambdaTest {
    private static int staticIntValue = 5;
    private int instanceIntValue = 7;

    public static void main(String[] args) {
        Sample5_LambdaTest myInstance = new Sample5_LambdaTest();

        MyFunction myFunction = myInstance.enclosingTestMethod((args.length == 0)? 33 : 55);
        System.out.println("myFunction = " + myFunction);
        Class<?> myFunctionClass1 = myFunction.getClass();
        Reflector.printClassInfo(myFunctionClass1);
        Reflector.printFieldValues(myFunction);

        myFunction = myInstance.enclosingTestMethod((args.length == 0)? 34 : 55);
        System.out.println("myFunction = " + myFunction);
        Class<?> myFunctionClass2 = myFunction.getClass();
        Reflector.printClassInfo(myFunctionClass2);
        Reflector.printFieldValues(myFunction);

        System.out.println("the same lambda class? " + (myFunctionClass1 == myFunctionClass2));
        int res = myFunction.perform(7);
        System.out.println(res);
    }

    private MyFunction enclosingTestMethod (long param) {
        System.out.println("param = " + param);
        double local = 10.0;
        //todo: local variable and param value cannot be modified...
        // (the values cannot be extracted later on - when lambda will be invoked)
        // the values are to be stored in final fields of the lambda implementation
        // ans that's why the values must be effectively final
//        param = 11; // parameter cannot be modified...
//        local++; // local variables cannot be modified...
//        staticIntValue++; // it is ok
//        instanceIntValue++; // it is ok
        MyFunction myLambda = (n) -> {
            staticIntValue = 0; // ok
            instanceIntValue = 0; // ok
            return (int)(local + param + instanceIntValue + staticIntValue + n);
        };
//        param = 11; // parameter cannot be modified...
//        local++; // local variables cannot be modified...
//        System.out.println("result = " + myLambda.perform((int)param));
        return myLambda;
    }
}
