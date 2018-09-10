# Vectorization & VSM

## What is vector?
One dimensional array

## Vectorization example
* D1: Roses are red violet is blue your face is red, my face is blue
* D2: Roses are red violet is blue so that my love is only for you

__Unique terms__:
```
[roses, are, red, violet, is, blue, your, my, face, so, that, love, only, for, you]
```
__Vector (using term frequency)__:
```
        D1  D2
roses   1   1
are     1   1
red     2   1
violet  1   1
is      3   2
blue    2   1
your    1   0
my      1   1
face    2   0
so      0   1
that    0   1
love    0   1
only    0   1
for     0   1
you     0   1
```

## Vector length
$|a| = \sqrt{a_1^2 + a_2^2 + a_3^2 + ... + a_n^2}$

$|a| = \sqrt{\Sigma_{i=1}^n a_i^2}$

## Dot product

$a.b = |a| \times |b| \cos(\theta)$

## Also dot product

$a.b = (a_1 \times b_1) + (a_2 \times b_2) + (a_3 \times b_3) + ... + (a_n \times b_n)$

$a.b = \Sigma_{i=1}^n a_i \times b_i$

## Cosine Similarity
$\cos(\theta) = \frac{(a_1 \times b_1) + (a_2 \times b_2)  + (a_3 \times b_3) + ... + (a_n \times b_n)}{|a| \times |b|}$

$\cos(\theta) = \frac{\Sigma_{i=1}^n a_i \times b_i}{|a| \times |b|}$

__Note__: Since github cannot render LAtEx, here i make a [screenshot of the formula](rumus-vsm.png), as well as [program example in java](Similarity.java)