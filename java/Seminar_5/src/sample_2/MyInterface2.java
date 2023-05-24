package sample_2;

public interface MyInterface2
//    extends MyInterface1  //TODO: see - what happens when this line is uncommented (and where). Why?
{
    int method1();

    default int method2() { return 2; }
}
