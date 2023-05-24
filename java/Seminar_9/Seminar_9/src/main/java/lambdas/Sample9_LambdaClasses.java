package lambdas;

import tool.Reflector;

@FunctionalInterface
interface Action {
    void perform();
}

public class Sample9_LambdaClasses {

    public static void main(String[] args) {
        new Sample9_LambdaClasses().testLambdaClasses();
    }

    void testLambdaClasses(){
        Class<?> thisClass = this.getClass();
System.out.println("this.getClass().getClassLoader() = " + this.getClass().getClassLoader());
         Action f1 = () -> System.out.println("1");
         f1.perform();
         Action f2 = () -> System.out.println("2");
         f2.perform();
        Class<?> lambdaClass = f1.getClass();
System.out.println("lambda.superClass = " + lambdaClass.getSuperclass());
System.out.println("lambda.enclosingClass = " + lambdaClass.getEnclosingClass());
System.out.println("lambda.enclosingMethod = " + lambdaClass.getEnclosingMethod());

        Reflector.printClassInfo(lambdaClass);
System.out.println("f1 = " + f1);
System.out.println("f2 = " + f2);
System.out.println("f1.getClass() = " + f1.getClass());
System.out.println("f2.getClass() = " + f2.getClass());
System.out.println("f1.getClass().getClassLoader() = " + f1.getClass().getClassLoader());
System.out.println("f2.getClass().getClassLoader() = " + f2.getClass().getClassLoader());

        try {
            Class<?> thisClassForName = Class.forName(this.getClass().getName());
System.out.println("thisClass == thisClassForName => " + (thisClass == thisClassForName));
            Class<?> lambdaClassForName = Class.forName(f1.getClass().getName());
System.out.println("lambdaClass == lambdaClassForName => " + (lambdaClass == lambdaClassForName));
        } catch (Exception ex) {
            System.out.println("got exception: " + ex);
            //todo: note that in contrast with ordinal classes lambda classes cannot be searched by their names...
        }
    }
}
