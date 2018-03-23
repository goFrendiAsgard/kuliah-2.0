from sklearn import tree
'''
Size - S: 0, M: 1, L: 2
Shape - Brick: 0, Wedge: 1, Sphere: 2, Pillar: 3
Color - Red: 0, Green: 1, Blue 2
Choice - Yes: 1, No: 0

M Brick Blue Yes
S Wedge Red No
L Wedge Red No
S Sphere Red Yes
L Pillar Green Yes
L Pillar Red No
L Sphere Green Yes
M Pillar Green ?
'''
X = [[1, 0, 2], [0, 1, 0], [2, 1, 0], [0, 2, 0], [2, 3, 1], [2, 3, 0], [2, 2, 1]]
Y = [1, 0, 0, 1, 1, 0, 1]
clf = tree.DecisionTreeClassifier()
clf = clf.fit(X, Y)
prediction = clf.predict_proba([[2, 2, 1]])
print (prediction)