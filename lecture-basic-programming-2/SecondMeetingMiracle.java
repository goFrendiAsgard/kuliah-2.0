import java.util.Scanner;
class SecondMeetingMiracle {
    public static void main(String[] args) {
        String[] barangBarang = new String[0];
        String barang = "";
        while(true) {
            Scanner in = new Scanner(System.in);
            barang = in.nextLine();
            if (barang.equals("sudah")) {
                break;
            }
            String barangBaru[] = new String[barangBarang.length + 1];
            for(int i=0; i<barangBarang.length; i++) {
                barangBaru[i] = barangBarang[i];
            }
            barangBaru[barangBaru.length - 1] = barang;
            barangBarang = barangBaru;
        }
        for(int i=0; i<barangBarang.length; i++) {
            System.out.println(barangBarang[i]);
        }
    }
}