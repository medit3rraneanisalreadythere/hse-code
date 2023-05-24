package lambdas;

@FunctionalInterface
interface SomeFunc<T> {
    T func(T t);
}

public class Sample6_GenericFunctionalInterface {
    public static void main(String[] args) {

        SomeFunc<String> reverse = (str) -> {
//TODO: explain - why following implementation is bad:
//            String result = "";
//            for (int i = str.length() - 1; i >= 0; i-- ){
//                result += str.charAt(i);
//            }
//            return result;

            StringBuilder stringBuilder = new StringBuilder();
            for (int i = str.length() - 1; i >= 0; i--) {
                stringBuilder.append(str.charAt(i));
            }
            return stringBuilder.toString();
        };
        System.out.println("Lambda reversed is " + reverse.func("Lambda"));

        SomeFunc<Integer> factorial = (n) -> {
            int res = 1;
            for (int i = 1; i <= n; i++) {
                res = i * res;
            }
            return res;
        };
        System.out.println("Factorial of 5 is " + factorial.func(5));
    }
}
