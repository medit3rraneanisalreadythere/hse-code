package lambdas.method_ref; //package lambdas.method_ref;
// TODO: for use in 2021-2022 course at Method reference talk...

import org.junit.jupiter.api.Test;

import java.lang.reflect.Method;
import java.util.Arrays;

class C {
    private static int m() {
        return 7;
    }
    private static void r() {
        System.out.println("r() called.");
    }
}


public class AccessControlAndMethodRefsTest {

    // todo: note- m is accessible in nested class
    //    static class C {
    //        private static int m() {
    //            return 7;
    //        }
    //    }

    @Test
    void testPrivateMethodCallByMethodRef(){
//        int value = C.m(); // m() is inaccessible when C is not nested class
//        System.out.println(value);

        Runnable r = AccessControlAndMethodRefsTest::r; // todo: explain - why it is valid? (we point to our own method...)
        r.run();
        System.out.println(r);
        Method[] methods = r.getClass().getDeclaredMethods();
        System.out.println(Arrays.toString(methods));
        // todo: we see that r has public run(), that "delegates" to the given private r()...
    }

    private static void r() {
        System.out.println("my r() called...");
    }

    @Test
    void testPrivateMethodCallByAnonymousClass() {
        Runnable r = new
                Runnable() {
                    @Override
                    public void run() {
                        r(); // todo: note- we are delegating to the accessible method (in this context)...
                    }
                };
        r.run();
    }
}
