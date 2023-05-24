package lambdas.method_ref;

public class MethodRefDemo2 {

    private static String stringOps(StringFunc sf, String s){
        return sf.func(s);
    }

    public static void main(String[] args) {
        String inputString = "Lambdas add power to Java";
        String outputString;

        // one variant of target context:
        MyStringOps ops = new MyStringOps();
        outputString = stringOps(ops::strReverse, inputString);
        System.out.println(outputString);

        // another target context of the functional interface:
        StringFunc sf = ops::strReverse;
        outputString = sf.func(inputString);
        System.out.println(outputString);
    }
}
