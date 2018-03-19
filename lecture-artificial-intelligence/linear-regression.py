from sklearn.linear_model import LinearRegression
lg = LinearRegression()

x = [[2], [4], [3], [6], [8], [8], [10]]
y = [10, 9, 6, 6, 6, 3,  2]
lg.fit(x,y)
predict_y = lg.predict([[12]])
print(predict_y)