package lambdas;

import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.*;

class Sample1_SortingStringsTest {
    private String[] strings;
    private static final String[] sorted  = new String[]{"a", "b", "c", "c3", "b22", "a111"};

    private static Sample1_SortingStrings sorter;

    @BeforeAll
    static void prepare() {
        sorter = new Sample1_SortingStrings();
    }
    @AfterAll
    static void cleanUp() {
        sorter = null;
    }

    @BeforeEach
    void setUp() {
        strings = new String[]{"a", "b", "c", "a111", "b22", "c3"};
    }

    @AfterEach
    void tearDown() {
        strings = null;
    }

    @Test
    void testSortWithAnonymousClassOld() {
        sorter.sortWithAnonymousClassOld(strings);
        assertArrayEquals(sorted, strings);
    }

    @Test
    void testSortWithAnonymousClass() {
        sorter.sortWithAnonymousClass(strings);
        assertArrayEquals(sorted, strings);
    }

    @Test
    void testSortWithLambda() {
        sorter.sortWithLambda(strings);
        assertArrayEquals(sorted, strings);
    }

    @Test
    void testSortWithMethodReference() {
        sorter.sortWithLMethod(strings);
        assertArrayEquals(sorted, strings);
    }

}