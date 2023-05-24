package edu.hse.cs.se.seminar2;

public class Sample_3_VariableNames {

    public static void main(String[] args) {
        System.out.println((char) 65);
        System.out.println((char) 66);
        System.out.println((char) 67);
        System.out.println("Character.isJavaIdentifierStart('8') -> " + Character.isJavaIdentifierStart('8'));
        System.out.println("Character.isJavaIdentifierPart('8') -> " + Character.isJavaIdentifierPart('8'));
        char c = '\u0008'; // это символ "забой" (см. https://unicode-table.com/ru/#0008 )
        System.out.println(c);
        char cc = '\r';
        System.out.println(c + ", " + cc);
        System.out.println("c = " + (int) c + "; cc = " + (int) cc);
        System.out.println(Character.isJavaIdentifierStart('_'));
        System.out.println(Character.isJavaIdentifierStart('$'));
    }
}
