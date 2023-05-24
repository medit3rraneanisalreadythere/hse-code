package lambdas.method_ref;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

public class MethodRefDemo0 {
    public static void main(String[] args) {
        ActionListener actionListener = System.out::println;
        System.out.println("actionListener = " + actionListener);
        tool.Reflector.printClassInfo(actionListener.getClass());

//        new Timer(1000, System.out::println).start();

        new Timer(1000,
                (e) -> {
                    Toolkit.getDefaultToolkit().beep();
                    System.out.println(e);
                }
        ).start();

        JOptionPane.showMessageDialog(null, "Quit program?");
        System.exit(0);
    }
}
