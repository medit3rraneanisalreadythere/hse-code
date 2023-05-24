package enums;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import tool.Reflector;

import java.lang.reflect.Field;

import static org.junit.jupiter.api.Assertions.*;

class SizeTest {

    @BeforeEach
    void setUp() {
        System.out.println("setUp()");
    }

    @AfterEach
    void tearDown() {
        System.out.println("tearDown90");
    }

    @Test
    public void testSize() {
        Reflector.printClassInfo(Size.class);

        System.out.println(Size.SMALL.getClass());
        System.out.println(Size.SMALL.getDeclaringClass());

        System.out.println(Size.MEDIUM.getClass());
        System.out.println(Size.MEDIUM.getDeclaringClass());

        System.out.println(Size.LARGE.getClass());
        System.out.println(Size.LARGE.getDeclaringClass());

        System.out.println(Size.EXTRA_LARGE.getClass());
        System.out.println(Size.EXTRA_LARGE.getDeclaringClass());
    }

    @Test
    public void testSMALL() {
        Reflector.printClassInfo(Size.SMALL.getClass());
        Reflector.printFieldValues(Size.SMALL);
    }
}