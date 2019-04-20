import pandas as pd
from sklearn.naive_bayes import GaussianNB

def getUniqueTokens(listOfTokens):
    result = []
    for tokens in listOfTokens:
        for token in tokens:
            # jika token sudah ada di result atau tidak valid, maka lanjutkan
            if token in result or token == "":
                continue
            result.append(token)
    return result

def vectorizeTokens(uniqueTokens, tokens):
    vector = []
    for token in uniqueTokens:
        jumlah = 0
        for actualToken in tokens:
            if actualToken == token:
                jumlah += 1
        vector.append(jumlah)
    return vector

def tokenize(kalimat):
    kalimat = kalimat.replace(".", " ")
    kalimat = kalimat.replace(",", " ")
    kalimat = kalimat.replace("-", " ")
    kalimat = kalimat.replace("/", " ")
    kalimat = kalimat.lower()
    tokens = kalimat.split(" ")
    return tokens


# load csv
df = pd.read_csv("spam_notspam.csv")
print("Data Frame:", df, "\n")

# chop of the sentences into tokens
listOfTokens = []
for kalimat in df["Kalimat"]:
    tokens = tokenize(kalimat)
    listOfTokens.append(tokens)
print("List of Tokens:", listOfTokens, "\n")

# get unique tokens
uniqueTokens = getUniqueTokens(listOfTokens)
print("Unique Tokens:", uniqueTokens, "\n")

# prepare dataset
X = []
Y = []
for index in range(len(listOfTokens)):
    tokens = listOfTokens[index]
    X.append(vectorizeTokens(uniqueTokens, tokens))
    Y.append(df["Tipe"][index])
print("X:", X, "\n")
print("Y:", Y, "\n")

# prepare classifier & train
gnb = GaussianNB()
gnb.fit(X, Y)

kalimatTest = "Menawarkan pinjaman dana basis online proses 100% aman"
tokenTest = tokenize(kalimatTest)
vectorTest = vectorizeTokens(uniqueTokens, tokenTest)
XTest = [vectorTest]
prediction = gnb.predict(XTest)

print("Kalimat Test:", kalimatTest, "\n")
print("Prediction:", prediction, "\n")
