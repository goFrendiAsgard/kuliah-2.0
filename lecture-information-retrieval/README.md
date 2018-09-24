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

# Better vectorization

## TF.IDF
* TF = Term Frequencey
* DF = Document Frequency
* IDF = Inverse Document Frequency = $\log\frac{N}{DF}$

### Example
```
D1: Roses are red violet is blue your face is red, my face is blue (14 words)

D2: Roses are red violet is blue so that my love is only for you (14 words)

TF(red, D1) = 2/14 --> 2 `red` from 14 words in D1
TF(blue, D2) = 1/14 --> 1 `blue` from 14 words in D2
TF(green, D1) = 0/14

DF(red) = 2
DF(love) = 1

N = how many document available = 2
IDF(red) = log (2/2) = 0
IDF(love) = log(2/1) = log(2)

TF.IDF(red, D1) = TF(red, D1) * IDF(red)
                = 2/14 * 0
                = 0
```

## N-Gram

```
D1: pen pineapple apple pen
D2: I have a pen, I have an apple, apple pen

Unique words:
* pen
* pineapple
* apple
* I
* have
* a
* an

N-Gram (2 Gram): Unique words + phrase contains of two sequential words
* pen pineapple
* pineapple apple
* apple pen
* I have
* have a
* a pen
* pen I
* have an
* an apple
* apple apple

```

### Vectorization

```
D1: pen pineapple apple pen
D2: I have a pen, I have an apple, apple pen

TF (pen pineapple, D1) = 1 / 3
* pen pineapple / (pen pineapple, pineapple apple, apple pen)

Vector                  D1
pen                   TF(pen, D1)*IDF(pen)
pineapple             TF(pineapple, D1)*IDF(pineapple)
apple
I
have
a
an
pen pineapple
pineapple apple
apple pen
I have
have a
a pen
pen I
have an
an apple
apple apple
```

### Assignment

* Find a formula to calculate how many phrase (N-Gram) is available in a sentence/document

```javascript
function detectPhrases(article: string, N: integer): string[] {}

example:
phrases = detectPhrases("pen pineapple apple pen pineapple", 2);
/*
phrases == [
  "pen pineapple",
  "pineapple apple",
  "apple pen",
  "pen pineapple"
]
*/
phrases = detectPhrases("pen pineapple apple pen pineapple", 3);
/*
phrases == [
  "pen pineapple apple",
  "pineapple apple pen",
  "apple pen pineapple",
]
*/```

* Detect intent

```
PHRASE                  INTENT
forget it               cancel
cancel                  cancel
ga jadi                 cancel
g jd                    cancel
jd g?                   confirm
jd?                     confirm
jadi?                   confirm
gimana?                 confirm

Detect intent for:
Gmn, g jd?
```