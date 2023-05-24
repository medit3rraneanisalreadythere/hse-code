package sample_3;

/**
 * TODO: answer - what should be printed and why ? Explain - what's happening...
 * TODO: look at the B.class through decompiler
 */

class A {
   A() {
      System.out.println("this.getClass() : "  + this.getClass());
      init();
   }
   public void init() {
   }
}

class B extends A {

   private final Integer i1 = 1;                 //Integer.valueOf(1); // at init() is not initialized  yet...
   private final int i2 = 320000;               // (as statically known by compiler it is inlined in methods...!!!)
   private int i3 = 3;                         // at init() is not initialized yet...

   B() {
      super();
   }

   // TODO: look at the console output:
   public void init() {
      System.out.println(" i = " + i1);
      System.out.println(" ii = " + i2); // TODO: why it is initialized when i1 and i3 are not initialized ?
      System.out.println(" iii = " + i3);
   }

   Integer getI1() {
      return i1;
   }
   int getI2() {
      return i2;
   }
   int getI3(){
      return i3;
   }
}

public class InitTest {
   // TODO: stop at the very first line and execute step by step... (or just run and ask to explain the output...)
   public static void main(String[] args){
      B b = new B();
      System.out.println(" i = " + b.getI1());
      System.out.println(" ii = " + b.getI2());
      System.out.println(" iii = " + b.getI3());
   }
}
