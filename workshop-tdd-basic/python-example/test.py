from program import luasPersegi, luasPersegiPanjang, luasSegitiga, luasLingkaran

def test(keterangan, statement):
    if statement:
        print("[PASS] " + keterangan)
    else:
        raise Exception("[FAILED] " + keterangan)

test("persegi", luasPersegi(5) == 25)
test("persegi panjang", luasPersegiPanjang(4, 5) == 20)
test("segitiga", luasSegitiga(2, 4) == 4)
test("segitiga lagi", luasSegitiga(3, 5) == 7.5)
test("lingkaran", luasLingkaran(7) == 154)
