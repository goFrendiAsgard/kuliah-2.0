def luasPersegi(s):
    return luasPersegiPanjang(s, s)

def luasPersegiPanjang(s1, s2):
    return s1 * s2

def luasSegitiga(a, t):
    return 0.5 * luasPersegiPanjang(a, t)

def luasLingkaran(r):
    return 22/7 * luasPersegi(r)

if __name__ == "__main__":
    print("1. Persegi")
    print("2. Persegi Panjang")
    print("3. Segitiga")

    pilihan = input("Masukkan pilihan")
    if pilihan == "1":
        s = int(input("Masukkan sisi "))
        luas = luasPersegi(s)
    elif pilihan == "2":
        p = int(input("Masukkan panjang "))
        l = int(input("Masukkan lebar "))
        luas = luasPersegiPanjang(p, l)
    else:
        a = int(input("Masukkan alas"))
        t = int(input("Masukkan tinggi"))
        luas = luasSegitiga(a, t)

    print(luas)
