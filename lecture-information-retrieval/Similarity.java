public class Similarity {

    static double[] hitungKuadratVektor(double[] array) {
        return hitungDotProduct(array, array);
    }

    static double hitungPanjangVektor(double[] vektor) {
        double[] vektorKuadrat = hitungKuadratVektor(vektor);
        double total = hitungSigma(vektorKuadrat);
        return Math.pow(total, 0.5);
    }

    static double[] hitungDotProduct(double[] v1, double[] v2) {
        double[] vektorHasil = new double[v1.length];
        for(int index = 0; index < vektorHasil.length; index ++) {
            vektorHasil[index] = v1[index] * v2[index];
        }
        return vektorHasil;
    }

    static double hitungSigma(double[] vektor) {
        double hasil = 0.0;
        for (double angka: vektor) {
            hasil += angka;
        }
        return hasil;
    }

    static double hitungSimilarity(double[] v1, double[] v2) {
        double panjangV1 = hitungPanjangVektor(v1);
        double panjangV2 = hitungPanjangVektor(v2);
        double v1KaliV2 = hitungSigma(hitungDotProduct(v1, v2));
        return v1KaliV2 / (panjangV1 * panjangV2);
    }

    public static void main(String[] args) {
        double[] d1 = {1,1,2,1,3,2,1,1,2,0,0,0,0,0,0};
        double[] d2 = {1,1,1,2,1,0,1,0,1,1,1,1,1,1,1};
        System.out.println(hitungSimilarity(d1, d2));
    }
}
