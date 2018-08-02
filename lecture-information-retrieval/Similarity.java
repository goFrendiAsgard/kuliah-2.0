public class Similarity {

  static String[] k = {
    "pineapple apple pen", // k[0]
    "pineapple apple apple", // k[1]
    "pen apple", // k[2]
    "pineapple apple" // k[3]
  };

  static String[] kataKataUnik = {"pineapple", "apple", "pen"};

  public static void main(String[] args) {
    String kalimatDicari = k[3];
    System.out.println("Kalimat Dicari: " + kalimatDicari);
    double[] vektorDicari = vektorKalimat(k, kalimatDicari, kataKataUnik);
    for (String kalimat: k) {
      double[] vektor = vektorKalimat(k, kalimat, kataKataUnik);
      double nilaiSimilarity = similarity(vektor, vektorDicari);
      System.out.println("Kalimat: " + kalimat);
      System.out.println("Similarity: " + nilaiSimilarity);
    }
  }

  static double similarity (double[] a, double[] b) {
    double nilaiDotProduct = dotProduct(a, b);
    double panjangA = panjangVektor(a);
    double panjangB = panjangVektor(b);
    return nilaiDotProduct / (panjangA * panjangB);
  }

  static double dotProduct(double[] a, double[] b) {
    double hasil = 0;
    for (int i = 0; i < a.length; i++ ) {
      double an = a[i];
      double bn = b[i];
      hasil = hasil + (an * bn);
    }
    return hasil;
  }

  static double panjangVektor(double[] vektor) {
    double hasil = 0;
    for(double angka: vektor) {
      hasil = hasil + (angka * angka);
    }
    hasil = Math.sqrt(hasil);
    return hasil;
  }

  static void tampilVektor(double[] vektor) {
    for (double angka: vektor) {
      System.out.print(angka + ", ");
    }
    System.out.println();
  }

  static double[] vektorKalimat(String[] k, String kalimat, String[] kataKataUnik) {
    double[] hasil = new double[kataKataUnik.length];
    for (int i = 0; i < hasil.length; i++) {
      String kataDicari = kataKataUnik[i];
      int nilaiTf = tf(kalimat, kataDicari);
      double nilaiIdf = idf(k, kataDicari);
      double bobot = nilaiTf * nilaiIdf;
      hasil[i] = bobot;
    }
    return hasil;
  }

  static int tf(String kalimat, String kataDicari) {
    String[] kataKata = splitKalimat(kalimat);
    int jumlah = 0;
    for (String kata : kataKata) {
      if (kata.equals(kataDicari)) {
        jumlah = jumlah + 1;
      }
    }
    return jumlah;
  }

  static double idf(String[] k, String kataDicari) {
    double n = k.length;
    double nilaiDf = df(k, kataDicari);
    return Math.log10(n / nilaiDf);
  }

  static int df(String[] k, String kataDicari) {
    int jumlah = 0;
    for (String kalimat : k) {
      String[] kataKata = splitKalimat(kalimat);
      for (String kata : kataKata) {
        if (kata.equals(kataDicari)) {
          jumlah = jumlah + 1;
          break;
        }
      }
    }
    return jumlah;
  }

  static String[] splitKalimat(String kalimat) {
    return kalimat.split(" ");
  }

}
