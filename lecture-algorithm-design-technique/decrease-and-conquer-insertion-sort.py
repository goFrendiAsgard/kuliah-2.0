a = [10, 1, 8, 7, 4, 5, 6, 9, 3, 2]

def insertion_sort(data):
  fixed = []
  while len(data) > 0:
    maximum = max(data)
    fixed = [x for x in data if x == maximum] + fixed
    data = [x for x in data if x < maximum]
  return data + fixed

print(insertion_sort(a))