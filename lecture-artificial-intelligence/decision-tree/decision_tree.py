from sklearn import tree
from sklearn.metrics import accuracy_score
import pandas as pd

df = pd.read_csv("./data.csv")
# print(df)
# print(df.columns)

df = df[df["Kategori"] != "?"]

x = df[["Usia", "Tinggi", "Massa", "IQ"]]
y = df["Kategori"]

# training
clf = tree.DecisionTreeClassifier()
clf.fit(x,y)

# mengukur akurasi
y_pred = clf.predict(x)
print("Akurasi", accuracy_score(y, y_pred))

# menebak apakah orang dengan usia 14, tinggi 150, massa 50, IQ 110 itu kurus, ideal, atau gemuk
print("Hasil prediksi", clf.predict([[14, 150, 50, 110]]))

