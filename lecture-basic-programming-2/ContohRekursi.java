public class ContohRekursi {

    public static void main(String[] args) {
        System.out.println(fibo(7));
    }

    public static int fibo(int n) {
        if (n <= 2) {
            return 1;
        }
        return fibo(n-1) + fibo(n-2);
    }

    public static void tampilkanAngka(int angka) {
        System.out.println(angka);
        if (angka < 5) {
            tampilkanAngka(angka + 1);
        }
    }

}
