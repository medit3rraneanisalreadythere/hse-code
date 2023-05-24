package lambdas;

//TODO: note - that is Checked exception:
class EmptyArrayException extends Exception {
    EmptyArrayException() { super("Array is Empty"); }
}

@FunctionalInterface
interface DoubleNumericArrayFunc {
    // TODO: throws clause must be present (try to remove it)...
    //  if throwing checked exception is declared in interface, lambda implementation must throw it...
    //  if throwing checked exception is not declared in interface, lambda cannot throw it...
    double func(double[] array)
          throws EmptyArrayException;
}

public class Sample4_LambdaException {
    private static final double[] EMPTY_DOUBLE_ARRAY = new double[0];

    // TODO: set command line parameters as appropriate: should be array of doubles...
    public static void main(String[] args) throws EmptyArrayException {
        double[] values = getDoubleArrayFromStrings(args);
        new Sample4_LambdaException().demo(values);
    }

    void demo(double[] values) throws EmptyArrayException {

        DoubleNumericArrayFunc average = (a) -> {
            double sum = 0;
            if (a.length == 0) // this check is needed by our goal definition...
                throw new EmptyArrayException();
            for (double anA : a) sum += anA;
            return sum / a.length;
        };

        System.out.println("The average = " + average.func(values));
    }

    private static double[] getDoubleArrayFromStrings(String[] strings) {
        double[] result = new double[strings.length];
        for (int i = 0; i < strings.length; i++) {
            try {
                result[i] = Double.parseDouble(strings[i]);
            } catch (NumberFormatException nfe) {
                return EMPTY_DOUBLE_ARRAY;
            }
        }
        return result;
    }
}
