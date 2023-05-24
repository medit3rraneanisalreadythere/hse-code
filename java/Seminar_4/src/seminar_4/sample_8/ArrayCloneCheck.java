package seminar_4.sample_8;

import java.lang.reflect.Modifier;
import java.util.Arrays;

/*
    TODO: postpone this sample discussion until the next seminar(s): after interfaces, clone() and reflection...
 */

public class ArrayCloneCheck
        extends MyObject
//        implements Cloneable
{
    public static void main(String[] args) throws Exception {
        MyObject o1 = new MyObject(); //new Object();
//        Object myObjectClone = o1.clone();
        MyObject[] myObjects = new MyObject[] {new MyObject(), new MyObject(), new MyObject()};
        //TODO: Note: arrays have public clone() 'invisible by reflection'...
        MyObject[] myObjects1 = myObjects.clone();

        Class<?> c = myObjects.getClass();
        System.out.println(c.getSuperclass());
        //TODO: array class access modifier is determined by element type access...
        System.out.println(c.getSimpleName() + ".isPublic(" + c + "): " + isPublic(c));
        System.out.println(Arrays.toString(myObjects.getClass().getMethods()));
        System.out.println(Arrays.toString(myObjects.getClass().getDeclaredMethods()));
    }

    private static boolean isPublic(Class<?> c) {
        return Modifier.isPublic(c.getModifiers());
    }
}

class MyObject implements Cloneable {
    //    public
    protected
    Object clone() throws CloneNotSupportedException {
        // that is the instance method of MyObject class, and  this has its' type ==> MyObject
        System.out.println(this + ": clone() invoked.");
        return super.clone();
    }
}
