from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
iris = load_iris()
clf = DecisionTreeClassifier()

# train
clf.fit(iris.data, iris.target)
print(clf.predict([[5.9, 3, 5.1, 1.8]])) # 2
print(clf.predict([[5.1, 3.5, 1.4, 0.1]])) # 0
