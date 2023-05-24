package edu.hse.cs.se.seminar2;

import java.util.Date;

/**
 * This class is to show some text usages... Show step by step in debug mode...
 */
public class Sample_0_Texts {
    public static void main(String[] args) {
        System.out.println("Hello, World! - from JDK 17..."); // let's speak in English...
        System.out.println("Здравствуйте, ребята... " + new Date()); // And let's speak in Russian...
        char a = '\u005B';
        char b = '\u005D';
        System.out.println("a = " + a + ", b = " + b);
        System.out.println("a = " + (int) a + ", b = " + (int) b);
        System.out.println("a * b = " + a * b);
        System.out.println(91 * 93);
    }
}

