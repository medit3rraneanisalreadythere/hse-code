package sample_4;

/*
TODO: read about removing limitations on static members in inner classes starting from JDK16(+):
https://stackoverflow.com/questions/68521280/why-are-static-methods-allowed-inside-a-non-static-inner-class-in-java-16
//*/

public class OuterClass {

//    public static final Object INNER_OBJECT = new Object();
    private static final int STATIC_FINAL_INT = 2;

    //TODO: show warning (... may be static) and explain it...
    //TODO: note that IDEA compiler shows warnings while Oracle compiler does not...
    private class InnerClass {
        //TODO: NOTE: starting from JDK16 it is allowed to have static declarations in inner classes !!!
//        public static final Object INNER_OBJECT = new Object();   //todo:  old JDK (before 16) compile error! why?
//        public static int STATIC_INT = 2;                         //todo:  old JDK (before 16) compile error! why?
        public static final int STATIC_FINAL_INT = 3; //todo: explain - why it's ok (instead of attempts above)?

//        int number = 7;

        public int getInnerStaticFinalIntValue(){
            return STATIC_FINAL_INT;
        }

        private int getOuterStaticFinalIntValue(){
            //TODO: explain warning below: access to static field by instance reference:
//            return OuterClass.this.STATIC_FINAL_INT;
            // TODO: comment out rows written above and below, and explain warning that will be shown at the InnerClass...
//            System.out.println(OuterClass.this);
            //TODO: uncomment below when commenting out all above written lines of the method:
            return OuterClass.STATIC_FINAL_INT; // access to static field by class reference
        }

//        public Object getInnerObject(){return INNER_OBJECT;}
//        public int getStaticInt(){return STATIC_INT;}

    }

    InnerClass getInnerInstance(OuterClass o){
        InnerClass res = o.new InnerClass();
        System.out.println(res);
//        System.out.println(InnerClass.STATIC_INT);
        return res;
    }


    public static void main(String[] args) {
        InnerClass innerInstance = new OuterClass().new InnerClass();
        System.out.println("value = " + innerInstance.getInnerStaticFinalIntValue());
        System.out.println("value = " + innerInstance.getOuterStaticFinalIntValue());
//        System.out.println(innerInstance.getInnerObject());
    }
}

class A{
    public static void main(String[] args) {
        OuterClass outerClass = new OuterClass();
        Object obj = outerClass.getInnerInstance(outerClass);
        System.out.println(obj);
    }
}