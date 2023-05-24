package seminar_3.sample_1;

//TODO: explain the array creation & initialization details...

//import java.util.Arrays;

public class Arrays {
    public static void main(String[] args) {
        int[] ints = {1, 2, 3, 4, 5};
//         ints = {6,7,8,9,10}; // not allowed here...
//TODO: why we need java.util prefixed below? -> because of our Arrays class name collision with java.util.Arrays...
        System.out.println(java.util.Arrays.toString(ints));
        ints = new int[]{1, 2, 3, 4, 5}; // it's ok, but never used - see warning (and the name ints colored in gray)...
        ints = new int[5];
        System.out.println(java.util.Arrays.toString(ints));
//        System.out.println(Arrays.toString (ints));
//        ints = new int[5]{1, 2, 3, 4, 5}; // not allowed...
    }
}
