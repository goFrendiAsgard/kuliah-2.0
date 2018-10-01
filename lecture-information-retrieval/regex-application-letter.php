<?php
$documents = [
    "
Kepada Yth.
Bapak Pimpinan
Harian Radar Makassar
Di
Jalan Urip Sumohardjo Km 1 Makassar

Dengan hormat,
Melalui Surat Kabar Radar Makassar pada hari ini, tanggal 8 September 2017, saya mendapat informasi bahwa Harian Radar Makassar membuka kesempatan untuk menjadi wartawan. Berdasarkan informasi tersebut, maka bersama ini saya mengajukan lamaran untuk mengisi kesempatan tersebut. Adapun data singkat tentang diri saya adalah sebagai berikut:

Nama : Rahardjo Purnawei
Tempat, Tanggal Lahir : Makassar, 6 Maret 1992
Pendidikan Terakhir : S1 Ilmu Komunikasi Universitas Indonesia Timur, lulus Februari 2016
Alamat : Jln. Perintis Kemerdekaan Km. 1 Makassar
Nomor Telepon/HP/email : 098765432190 wtf@jaman.sekarang.ga.punya.email

Saya menyukai profesi kepenulisan, terutama wartawan. Bersama ini saya lampirkan beberapa tulisan saya di antaranya artikel, untuk Akademi Kebudayaan Makassar. Saya sangat berharap Radar Makassar menjadi bermain yang bisa mengembangkan pribadi saya sekaligus bersama-sama membangun pers yang berkompetisi di Makassar.

Data lebih lanjut mengenai diri saya, saya lampirkan bersama surat ini. Saya berharap mendapat panggilan untuk interview, saya siap kapan saja.Atas perhatian dan segala pertimbangan Bapak terhadap saya, saya mengucapkan terima kasih.

Hormat saya,

*tanda tangan

Rahardjo Purnawei
    ",
    "
Kepada
Yth. Menteri Pendidikan Nasional RI
melalui
Rektor Universitas Gadjah MadaDengan hormat,
Yang bertanda tangan di bawah ini, saya:

Nama : Rahayu Budi Utami
Tempat, Tanggal Lahir : Yaogyakarta, 09 September 1994
Alamat : Gurwodiningraton,  N6 I /909 Yogyakarta
Pendidikan : Sarjana Muda Akuntansi

mengajukan lamaran sebagai calon Pegawai Negeri Sipil di lingkungan Departemen Pendidikan Nasional.Bersama ini saya lampirkan berkas sebagai syarat kelengkapan:

    Surat Keterangan Catatan Kepolisian
    Surat keterangan sehat jasmani dan rohani dari dokter
    Fotokopi ijazah / STTB yang telah dilegalisir oleh pejabat yang berwenang
    Daftar riwayat hidup
    Surat pernyataan .

Besar harapan saya untuk dapat diterima sebagai calon pegawai negeri sipil.
Atas perhatiannya, saya mengucapkan terima kasih.

Yogyakarta, 12 Desember 2016
Hormat saya,

Rahayu Budi Utami
    "
];

function extractEntity($document, $pattern) {
    $matches = array();
    preg_match($pattern, $document, $matches);
    return $matches[1];
}

function extractPendidikan($document) {
    $pattern = '/^pendidikan.*: *(.*)$/mi';
    return extractEntity($document, $pattern);
}

function extractName($document) {
    $pattern = '/^nam[a,e] *: *(.*)$/mi';
    return extractEntity($document, $pattern);
}

function extractEmail($document) {
    $pattern = '/([a-zA-Z0-9]+@[a-zA-Z0-9]+\.[a-zA-Z0-9\.]+)/mi';
    return extractEntity($document, $pattern);
}

$entities = [];
foreach($documents as $document) {
    $name = extractName($document);
    $pendidikan = extractPendidikan($document);
    $email = extractEmail($document);
    $entities[] = array(
        "nama" => $name,
        "pendidkan" => $pendidikan,
        "email" => $email,
    );
}

var_dump($entities);