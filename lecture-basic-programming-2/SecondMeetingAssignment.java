import java.util.Scanner;
public class SecondMeetingAssignment {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // baca `batas`
        int batas = in.nextInt();
        // buat array `a`, `b`, dan `c` yang ukurannya sepanjang `batas`
        int[] a = new int[batas];
        int[] b = new int[batas];
        int[] c = new int[batas];
        // baca integer sebanyak `batas` kali, masukkan nilainya ke array `a`
        for(int i=0; i<batas; i++) {
            a[i] = in.nextInt();
        }
        // baca integer sebanyak `batas` kali, masukkan nilainya ke array `b`
        for(int i=0; i<batas; i++) {
            b[i] = in.nextInt();
        }
        // c[i] = a[i] * b[i], tampilkan c[i] 
        for(int i=0; i<batas; i++) {
            c[i] = a[i] * b[i];
            System.out.print(c[i] + " ");
        }
        in.close();
    }
}