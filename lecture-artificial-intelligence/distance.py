points = [
  [6,7, 'a'],
  [6,8, 'a'],
  [7,6, 'a'],
  [3,2, 'b'],
  [2,3, 'b'],
  [3,3, 'b'],
  [9,8, 'c'],
  [10,9, 'c'],
  [9,6, 'c'],
]
newPoint = [6,9, '?']

def calculateDistance(x1,y1, x2,y2):
  return ((x2-x1)**2 + (y2-y1)**2) ** 0.5

x1 = newPoint[0]
y1 = newPoint[1]
for point in points:
  x2 = point[0]
  y2 = point[1]
  distance = calculateDistance(x1,y1,x2,y2)
  print([distance, point[2]])

