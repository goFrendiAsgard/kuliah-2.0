# Primitive vs Composite
```java
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
```

## Primitive Types
* Call by value: The value of variables are copied
* Example
    * int
    * float
    * boolean
    * char

## Composite Types
* Call by reference: The variables could refering to the same data
* Example
    * int[]
    * float[]
    * boolean[]
    * char[]
    * String
    * object

# Array

```java
int[] a = {1, 3, 5}; // a = {1, 3, 5}
int[] b = new int[4]; // b = {0, 0, 0, 0}

// naive approach
b[0] = 5; // b = {5, 0, 0, 0}
b[1] = 2; // b = {5, 2, 0, 0}

// not-so-naive approach
int i = 0; // b = {0, 0, 0, 0}, i = 0
b[i] = i;  // b[0] = 0  --> b = {0, 0, 0, 0}, i = 0
i = i + 1; // i = 0 + 1 --> b = {0, 0, 0, 0}, i = 1
b[i] = i;  // b[1] = 1  --> b = {0, 1, 0, 0}, i = 1
i = i + 1; // i = 1 + 1 --> b = {0, 1, 0, 0}, i = 2
b[i] = i;  // b[2] = 2  --> b = {0, 1, 2, 0}, i = 2
i = i + 1; // i = 2 + 1 --> b = {0, 1, 2, 0}, i = 3
b[i] = i;  // b[3] = 3  --> b = {0, 1, 2, 3}, i = 3
i = i + 1; // i = 3 + 1 --> b = {0, 1, 2, 3}, i = 4

// loop-approach (basically a shorter version of `not-so-naive approach`)
for(int i = 0; i < b.length; i++) {
    b[i] = i;
}
// b = {0, 1, 2, 3}
```

# Dynamic array (without ArrayList)

```java
Scanner in = new Scanner(System.in);
int[] a = new int[0];
while(true) {
    // baca inputan user
    int nilai = in.nextInt();
    if(nilai == -1) {
        break;
    }
    // buat b
    int[] b = new int[a.length + 1];
    // copykan semua nilai a ke b
    for(int i = 0; i < a.length; i++) {
        b[i] = a[i];
    }
    // isi elemen terakhir b dengan inputan user
    b[a.length] = nilai;
    a = b;
}
for (int i = 0; i < a.length; i++) {
    System.out.println(a[i]);
}
in.close();
```
# Link List Prototype

```java
class Kucing {
    String nama;
    Kucing ibu;
}

public class ArrayTest {
    public static void main(String[] args) {
        Kucing shadowCat = new Kucing();
        shadowCat.nama = "Amanda";
        shadowCat.ibu = new Kucing();
        shadowCat.ibu.nama = "Betty";
        shadowCat.ibu.ibu = new Kucing();
        shadowCat.ibu.ibu.nama = "Cindy";

        System.out.println(shadowCat.nama);
        System.out.println(shadowCat.ibu.ibu.nama);

        Kucing x = shadowCat;
        while(x != null) {
            System.out.println(x.nama);
            x = x.ibu;
        }
    }
}
```

## Assignment

```java
class Kucing {
    String nama;
    Kucing ibu;
}

public class ArrayTest {

    public static void traverse(Kucing kucing) {
        while(kucing != null) {
            System.out.println(kucing.nama);
            kucing = kucing.ibu;
        }
    }

    public static void addAncestor(Kucing kucing, String ancestorName) {
        // DO something here
    }

    public static void main(String[] args) {
        Kucing shadowCat = new Kucing();
        shadowCat.nama = "Amanda";
        addAncestor(shadowCat, "Betty");
        addAncestor(shadowCat, "Cindy");
        traverse(shadowCat);
    }
}
```

## Assignment

Complete the empty functions so that the output of the program will be `Ana Chika `

```java
class Orang {
    public String name;
    public Orang next;
}

public class TugasYangBerat {
    static Orang terdepan;
    public static void main(String[] args) {
        addFirst("Bima");
        addFirst("Bimo");
        removeFirst();
        addFirst("Ana");
        removeLast();
        addLast("Chika");
        show(); // Ana Chika
    }

    public static void show() {
        Orang orang = terdepan;
        while(orang != null) {
            System.out.print(orang.name + " ");
            orang = orang.next;
        }
        System.out.println();
    }

    public static void addFirst(String nama) {
        Orang orang = new Orang();
        orang.name = nama;
        orang.next = terdepan;
        terdepan = orang;
    }

    public static void removeFirst() {
        if (terdepan != null) {
            terdepan = terdepan.next;
        }
    }

    public static void addLast(String nama) {
        // TODO: Lengkapi method ini
    }

    public static void removeLast() {
        // TODO: Lengkapi method ini
    }

}
```

## Assignment
```java
class Orang {
    public String name;
    public Orang next;
}

public class TugasYangBerat {
    static Orang terdepan;
    public static void main(String[] args) {
        addFirst("Betty"); // Betty
        addFirst("Amanda");  // Amanda Betty
        addLast("Cindy"); // Amanda Betty Cindy
        addLast("Donna"); // Amanda Betty Cindy Donna
        removeLast(); // Amanda Betty Cindy
        removeFirst(); // Betty Cindy
        addLast("Edelyn");
        show(); // Betty Cindy Edelyn
        addAfter("Betty", "Chika");
        show(); // Betty Chika Cindy Edelyn
        removeAfter("Chika");
        show(); // Betty Chika Edelyn
    }

    public static void show() {
        Orang orang = terdepan;
        while(orang != null) {
            System.out.print(orang.name + " ");
            orang = orang.next;
        }
        System.out.println();
    }

    public static void addAfter(String nama, String namaBaru) {
        // TODO: complete this
    }

    public static void removeAfter(String nama) {
        // TODO: complete this
    }

    public static void addFirst(String nama) {
        Orang orangBaru = new Orang();
        orangBaru.name = nama;
        orangBaru.next = terdepan;
        terdepan = orangBaru;
    }

    public static void removeFirst() {
        if (terdepan != null) {
            terdepan = terdepan.next;
        }
    }

    public static void addLast(String nama) {
        Orang orangBaru = new Orang();
        orangBaru.name = nama;
        if (terdepan == null) {
            terdepan = orangBaru;
        } else {
            Orang orang = terdepan;
            while (orang.next != null) {
                orang = orang.next;
            }
            orang.next = orangBaru;
        }
    }

    public static void removeLast() {
        if (terdepan != null) {
            if (terdepan.next == null) {
                terdepan = null;
            } else {
                Orang orang = terdepan;
                while (orang.next.next != null) {
                    orang = orang.next;
                }
                orang.next = null;
            }
        }
    }

}
```
