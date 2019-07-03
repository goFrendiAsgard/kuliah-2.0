from scipy.sparse import find
from sklearn.feature_extraction.text import TfidfVectorizer

list_artikel = [
    "saya suka bermain sepak bola",
    "bola adalah teman",
    "bola dunia itu bulat"
]

vectorizer = TfidfVectorizer()
vektor = vectorizer.fit_transform(list_artikel)

print(list_artikel)
print(vectorizer.get_feature_names())

print(vektor.toarray())

for indexArtikel, v in enumerate(list_artikel):
    print ("Artikel ke: ", indexArtikel, list_artikel[indexArtikel])
    for indexKata, kata in enumerate(vectorizer.get_feature_names()):
        print(indexKata, kata, vektor.toarray()[indexArtikel][indexKata])
    print()

