data = [1,2,3,4,5,6];

function kuadrat(angka) {
  return angka * angka;
}

function genap(angka) {
  return angka % 2 == 0;
}

function tambah(a, b) {
  return a + b;
}

function kali(a, b) {
  return a * b;
}

dataKuadrat = data.map(kuadrat);
console.log(dataKuadrat);

dataGenap = data.filter(genap);
console.log(dataGenap);

totalJumlah = data.reduce(tambah, 0);
console.log(totalJumlah);

totalKali = data.reduce(kali, 1);
console.log(totalKali);

dataBaru = data.map(kuadrat).filter(genap).reduce(tambah, 0);
console.log(dataBaru);
