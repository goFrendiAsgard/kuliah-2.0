class Orang {
    String nama;
    Orang bapak;
}

public class SecondMeetingLinkedListProto {
    public static void main(String[] args) {

        Orang magni = new Orang();
        magni.nama = "Magni Odingrandson";
        magni.bapak = new Orang();
        magni.bapak.nama = "Thor Odinson";
        magni.bapak.bapak = new Orang();
        magni.bapak.bapak.nama = "Odin ALlfather";

        System.out.println(magni.bapak.bapak.nama);
    }
}