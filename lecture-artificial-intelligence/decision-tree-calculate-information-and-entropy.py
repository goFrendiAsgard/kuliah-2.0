from math import log

def information(p,n):
  p = float(p)
  n = float(n)
  p = 0.01 if p == 0 else p
  n = 0.01 if n == 0 else n
  return -p/(p+n) * log(p/(p+n), 2) -n/(p+n) * log(n/(p+n), 2)

def entropy(data):
  total = 0
  for key in data:
    total += data[key]['p']
    total += data[key]['n']
  total_entropy = 0.0
  for key in data:
    p = float(data[key]['p'])
    n = float(data[key]['n'])
    total_entropy += (p + n)/total * information(p, n)
  return total_entropy

print(information(4.0, 3.0))
data = {
  's': {'p': 1.0, 'n': 1.0},
  'm': {'p': 1.0, 'n': 0.0},
  'l': {'p': 2.0, 'n': 2.0}
}
print(entropy(data))
