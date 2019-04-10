https://www.dezyre.com/apache-spark-tutorial/apache-spark-installation-tutorial

Jalankan apache sparks

```
spark-shell
```

```
var Data = sc.textFile("./contoh-teks.txt")
var tokens = Data.flatMap(s => s.split(" "))
var tokens_1 = tokens.map(s => (s,1))
var sum_each = tokens_1.reduceByKey((a, b) => a + b)
sum_each.collect()
```
