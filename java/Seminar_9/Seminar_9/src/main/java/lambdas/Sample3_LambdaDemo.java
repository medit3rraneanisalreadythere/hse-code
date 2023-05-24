package lambdas;

@FunctionalInterface  //TODO: use annotation just to ensure that we have the only abstract method in interface...
interface NumericTest {
    boolean test(int i);
//    void qq(); // uncomment it and see how the annotation reacts...
}

public class Sample3_LambdaDemo {
    public static void main(String[] args) {

        NumericTest isEven = (n) -> (n % 2) == 0;
        System.out.println("isEven = " + isEven);
        Class<?> isEvenClass = isEven.getClass();
        System.out.println("isEvenClass = " + isEvenClass);

        if (isEven.test(10))
            System.out.println("10 is even");
        if (!isEven.test(9))
            System.out.println("9 is not even");
        if (isEven.test(-10))
            System.out.println("-10 is even");
        if (!isEven.test(-9))
            System.out.println("-9 is not even");

//todo: we see that isEvenClass exists, it is instantiated, it works, but we cannot get it by name...
        Class<?> c = getClassByName(isEvenClass.getName());
        System.out.println(c);

        //todo: just one more sample:
        NumericTest isNonNegative = (n) -> n >= 0;
        System.out.println("isNonNegative.getClass() = " + isNonNegative.getClass());
        if (isNonNegative.test(1))
            System.out.println("1 is non-negative");
        if (!isNonNegative.test(-1))
            System.out.println("-1 is negative");

        NumericTest isNotOdd = (n) -> (n % 2) == 0; //TODO: note that the lambda class is not reused...
        System.out.println("isNotOdd = " + isNotOdd);
        System.out.println("isNotOdd.getClass() = " + isNotOdd.getClass());
// classNames for lambdas are specifically generated...
    }

    public static Class<?> getClassByName(String className) {
        System.out.println("looking for class by name: " + className);
        Class<?> result = null;
        try {
            result = Class.forName(className);
        } catch (ClassNotFoundException cnfe) {
            System.out.println("got exception: " + cnfe);
        }
        return result;
    }

}
