package tool;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Scanner;

/**
 *
 */
public class Reflector {
    public static void main(String[] args) {
        String name;
        Scanner in = new Scanner(System.in);
        while ((name = getClassName(in)) != null){
            if (name.equalsIgnoreCase("exit")) {
                break;
            }
            Class<?> cl;
            try {
                cl = Class.forName(name);
            } catch (ClassNotFoundException e) {
                //e.printStackTrace();
                System.err.println(e.toString());
                continue;
            }
            printClassInfo(cl);
        }
        System.exit(0);
    }

    private static String getClassName(Scanner in){
        System.out.println("Enter fully qualified class name (or exit - to quit): ");
        return in.next();
    }

    public static void printClassInfo(Class<?> cl){
        if (cl == null)
            return;
//        System.out.println(cl.toGenericString()); // JDK8(+)
        Class<?> superclass = cl.getSuperclass();
        String modifiers = Modifier.toString(cl.getModifiers());
        if (modifiers.length() > 0)
            System.out.print(modifiers + " ");
        System.out.print("class " + cl.getName());
        if (superclass != null && superclass != Object.class)
            System.out.print(" extends " + superclass.getName());
        System.out.print(" {\n");
        printConstructors(cl);
        printMethods(cl);
        printFields(cl);
        printClasses(cl);
        System.out.println("}");
    }

    /**
    * Prints all constructors of a class
    * @param cl a class
    */
    private static void printConstructors(Class<?> cl) {
        Constructor<?>[] constructors = cl.getDeclaredConstructors();
        System.out.println("constructors:");
        for (Constructor<?> c : constructors) {
            String name = c.getName();
            System.out.print(" ");
            String modifiers = Modifier.toString(c.getModifiers());
            if (modifiers.length() > 0)
                System.out.print(modifiers + " ");
            System.out.print(name + "(");
            // print parameter types
            Class<?>[] paramTypes = c.getParameterTypes();
            printParameterTypes(paramTypes);
            System.out.println(");");
        }
    }
    /**
    * Prints all methods of a class
    * @param cl a class
    */
    private static void printMethods(Class<?> cl) {
        Method[] methods = cl.getDeclaredMethods();
        System.out.println("methods:");
        for (Method m : methods) {
            Class<?> retType = m.getReturnType();
            String name = m.getName();
            System.out.print(" ");
            // print modifiers, return type and method name
            String modifiers = Modifier.toString(m.getModifiers());
            if (modifiers.length() > 0)
                System.out.print(modifiers + " ");
            System.out.print(retType.getName() + " " + name + "(");
            // print parameter types
            Class<?>[] paramTypes = m.getParameterTypes();
            printParameterTypes(paramTypes);
            System.out.println(");");
        }
    }

    private static void printParameterTypes(Class<?>[] parameterTypes) {
        for (int j = 0; j < parameterTypes.length; j++) {
            if (j > 0) System.out.print(", ");
            System.out.print(parameterTypes[j].getName());
        }
    }

    /**
    * Prints all fields of a class // TODO: print static fields with their values...
    * @param cl a class
    */
    private static void printFields(Class<?> cl) {
        Field[] fields = cl.getDeclaredFields();
        System.out.println("fields:");
        for (Field f : fields) {
            Class<?> type = f.getType();
            String name = f.getName();
            System.out.print(" ");
            String modifiers = Modifier.toString(f.getModifiers());
            if (modifiers.length() > 0)
                System.out.print(modifiers + " ");
            System.out.println(type.getName() + " " + name + ";");
        }
    }
    /**
     * Prints all classes of a class; TODO: show all info on nested/inner classes recursively...
     * @param cl a class
     */
    private static void printClasses(Class<?> cl){
        Class<?>[] classes = cl.getDeclaredClasses();
        System.out.println("classes:");
        for (Class<?> c : classes) {
            String name = c.getName();
            System.out.print(" ");
            String modifiers = Modifier.toString(c.getModifiers());
            if (modifiers.length() > 0)
                System.out.print(modifiers + " ");
            System.out.println("class " + name + "{...};");
        }
    }

    public static void printFieldValues(Object o){
        Field[] fields = o.getClass().getDeclaredFields();
        System.out.println("fields:");
        for (Field f : fields) {
            Class<?> type = f.getType();
            String name = f.getName();
            System.out.print(" ");
            String modifiers = Modifier.toString(f.getModifiers());
            if (modifiers.length() > 0)
                System.out.print(modifiers + " ");
            System.out.print(type.getName() + " " + name + ";");
            try {
                f.setAccessible(true);
                System.out.println(" value = " + f.get(o));
            } catch (Exception ex){
                System.out.println("Cannot get value of " + f);
            }
        }

    }
    /*
     * TODO: could we have a method to print value (object) with its' type info in some form? In what form it could be done?
     */
}
