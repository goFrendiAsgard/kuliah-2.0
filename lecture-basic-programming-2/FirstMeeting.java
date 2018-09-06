import java.util.ArrayList;
public class FirstMeeting {
    public static void main(String[] args) {
        int a = 5; // a = 5
        int b = a; // a = 5, b = 5
        a = 7; // a = 7, b = 5
        System.out.println(a); // 7
        System.out.println(b); // 5

        int[] c = {5, 6, 7}; // c = {5,6,7}
        int[] d = c; // d = c = {5,6,7}
        c[0] = 8; // d = c = {8,6,7}
        System.out.println(c[0]); // 8
        System.out.println(d[0]); // 8

        int[] e = new int[2]; // e = {0,0}
        e[0] = 1; // e = {1,0}
        e[1] = 5; // e = {1,5}
       
        ArrayList f = new ArrayList();
        f.add(1);
        f.add(2);
        System.out.println(f);
    }
}
