package lambdas.underhood;

import tool.Reflector;

/**
 *
 * Decompiled with CFR 0.150.
 */
/*
package lambdas.underhood;

import java.lang.invoke.LambdaMetafactory;

public class CapturingLambda {
    public static void main(String[] args) {
        String effectivelyFinal = "effectivelyFinal";
        Runnable capturingLambda = (Runnable)LambdaMetafactory.metafactory(
             null,
             null,
             null,
             ()V, lambda$main$0(java.lang.String ), ()V)((String)effectivelyFinal
        );
        capturingLambda.run();
    }

    //synthetic method:
    private static void lambda$main$0(String effectivelyFinal) {
        System.out.println("CapturingLambda " + effectivelyFinal);
    }
}
//*/

public class CapturingLambda {
    public static void main(String[] args) {
        String effectivelyFinal = "effectivelyFinal";
        Runnable capturingLambda = () -> System.out.println(effectivelyFinal);
        capturingLambda.run();

        //TODO: uncomment the following lines to use reflection:
//        Reflector.printClassInfo(capturingLambda.getClass());
//        Reflector.printFieldValues(capturingLambda);
//        System.out.println("declaring class = " + capturingLambda.getClass().getEnclosingClass());
    }
}
