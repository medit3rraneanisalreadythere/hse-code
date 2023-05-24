package lambdas.method_ref;

public class MethodRefDemo1 {

    private static String stringOps(StringFunc sf, String s){
System.out.println("sf = " + sf + "; sf.getClass() = " + sf.getClass());
        return sf.func(s);
    }

    public static void main(String[] args) {
        String inputString = "Lambdas add power to Java";
        String outputString;

        // one variant of target context:
        outputString = stringOps( MyStringOps::strReverse_static, inputString);
        System.out.println(outputString);

        // another target context of the functional interface:
        StringFunc sf = MyStringOps::strReverse_static;
System.out.println("sf = " + sf + "; sf.getClass() = " + sf.getClass());
        outputString = sf.func(inputString);
        System.out.println(outputString);
    }
}
