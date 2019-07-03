from sklearn.naive_bayes import GaussianNB
gnb = GaussianNB()
data = [
  [4.0, 2.5],
  [4.0, 3.5],
  [2.8, 1.5],
  [3.5, 1.8],
  [5.1, 4.9],
  [2.0, 2.1]
  ]
newData = [[4.0, 4.0]]
target = [0, 1, 0, 0, 1, 1]
gnb.fit(data, target)
y_pred = gnb.predict(newData)
print(data)
print(target)
print(newData)
print(y_pred)
