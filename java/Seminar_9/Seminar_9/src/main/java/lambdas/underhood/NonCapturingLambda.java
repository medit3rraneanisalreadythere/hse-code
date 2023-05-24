package lambdas.underhood;

import tool.Reflector;

/**
 * Встроенный в Idea FernFlower decompiler plugin не показывает внутренности реализации с использованием invokedynamic.
 * Эти детали реализации можно посмотреть с помощью Bytecode Viewer'а (View -> Show Bytecode) в Idea.
 * Альтернативно, можно воспользоваться декомпилятором, который написан на Java 6 (CFR 0.150) и который
 * показывает "изнутри" использование invokedynamic:
 *
 * Decompiled with CFR 0.150. - Код получен с помощью запуска командого файла decompileNonCapturing.bat
 *
 *
import java.lang.invoke.LambdaMetafactory;

public class NonCapturingLambda {
    public static void main(String[] args) {
        Runnable nonCapturingLambda = (Runnable)LambdaMetafactory.metafactory(
                null, null, null, ()V, lambda$main$0(), ()V) ();
        nonCapturingLambda.run();
    }

    // synthetic method:
     private static void lambda$main$0() {
        System.out.println("nonCapturingLambda");
    }
}
//*/
/* TODO:
 *  Ниже - код, показанный с помощью Bytecode Viewer'а...

public class lambdas/underhood/NonCapturingLambda {

// compiled from: NonCapturingLambda.java
// access flags 0x19
public final static INNERCLASS java/lang/invoke/MethodHandles$Lookup java/lang/invoke/MethodHandles Lookup

// access flags 0x1
public <init>()V
        L0
        LINENUMBER 29 L0
        ALOAD 0
        INVOKESPECIAL java/lang/Object.<init> ()V
        RETURN
        L1
        LOCALVARIABLE this Llambdas/underhood/NonCapturingLambda; L0 L1 0
        MAXSTACK = 1
        MAXLOCALS = 1

// access flags 0x9
public static main([Ljava/lang/String;)V
        L0
        LINENUMBER 31 L0
        INVOKEDYNAMIC run()Ljava/lang/Runnable; [
        // handle kind 0x6 : INVOKESTATIC java/lang/invoke/LambdaMetafactory.metafactory
        (
            Ljava/lang/invoke/MethodHandles$Lookup;
            Ljava/lang/String;
            Ljava/lang/invoke/MethodType;
            Ljava/lang/invoke/MethodType;
            Ljava/lang/invoke/MethodHandle;
            Ljava/lang/invoke/MethodType;
        )Ljava/lang/invoke/CallSite;
        // arguments:
        ()V,
        // handle kind 0x6 : INVOKESTATIC lambdas/underhood/NonCapturingLambda.lambda$main$0()V,
        ()V
        ]
        ASTORE 1
        L1
        LINENUMBER 32 L1
        ALOAD 1
        INVOKEINTERFACE java/lang/Runnable.run ()V (itf)
        L2
        LINENUMBER 33 L2
        RETURN
        L3
        LOCALVARIABLE args [Ljava/lang/String; L0 L3 0
        LOCALVARIABLE nonCapturingLambda Ljava/lang/Runnable; L1 L3 1
        MAXSTACK = 1
        MAXLOCALS = 2

// access flags 0x100A
private static synthetic lambda$main$0()V
        L0
        LINENUMBER 31 L0
        GETSTATIC java/lang/System.out : Ljava/io/PrintStream;
        LDC "nonCapturingLambda"
        INVOKEVIRTUAL java/io/PrintStream.println (Ljava/lang/String;)V
        RETURN
        MAXSTACK = 2
        MAXLOCALS = 0
        }
*/

public class NonCapturingLambda {
    public static void main(String[] args) {
        Runnable nonCapturingLambda = () -> System.out.println("nonCapturingLambda");
        nonCapturingLambda.run();

        //TODO: to see  with reflection uncomment the following:
//        Reflector.printClassInfo(nonCapturingLambda.getClass());
//        Reflector.printFieldValues(nonCapturingLambda);
//        System.out.println("declaring class = " + nonCapturingLambda.getClass().getEnclosingClass());
    }
}
//*/

