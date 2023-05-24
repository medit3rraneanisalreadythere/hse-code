package lambdas;

@FunctionalInterface
interface StringFunc {
    String func(String s);
}

public class Sample7_LambdaAsArgument {

    private static String stringOp (StringFunc sf, String str) {
        return sf.func(str);
    }

    public static void main(String[] args) {
        String stringIn = "Lambdas add power to Java";
        String stringOut;

        stringOut = stringOp(
                (str) -> {
                    StringBuilder sb = new StringBuilder();
                    for (int i = 0; i < str.length(); i++) {
                        if (str.charAt(i) != ' ') {
                            sb.append(str.charAt(i));
                        }
                    }
                    return sb.toString();
                },
              stringIn
        );
        System.out.println(stringOut);

        System.out.println (stringOp ((str) -> str.toUpperCase(), "my sample string"));

        stringOut = stringOp(String::toUpperCase, stringIn);
        System.out.println(stringOut);
    }
}
