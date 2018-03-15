item_list = [
  {'name': 'a', 'weight': 100, 'value': 200000},
  {'name': 'b', 'weight':  11, 'value':  25000},
  {'name': 'c', 'weight':  50, 'value':  50000},
  {'name': 'd', 'weight':  40, 'value':  30000},
  {'name': 'e', 'weight': 100, 'value': 190000},
  {'name': 'f', 'weight': 300, 'value': 200000},
  {'name': 'g', 'weight': 200, 'value': 150000},
  {'name': 'h', 'weight':  50, 'value':  20000},
  {'name': 'i', 'weight':  80, 'value':  60000},
  {'name': 'j', 'weight':  90, 'value':  40000}
]

# Add density to each item. density = value/weight
for item in item_list:
  item['density'] = float(item['value'])/float(item['weight'])

# initialize knapsack
knapsack = []
knapsack_capacity = 500
full = False

# fill up the knapsack
while not full:
  available_item_list = [item for item in item_list if not (item in knapsack)]
  best_item = max(available_item_list, key=lambda item: item['density'])
  if best_item['weight'] < knapsack_capacity:
    knapsack.append(best_item)
    knapsack_capacity -= best_item['weight']
  else:
    full = True

# show the result
print('Items taken:')
for item in knapsack:
  print(item)

# show the weight
print(sum([item['weight'] for item in knapsack]))
# show the value
print(sum([item['value'] for item in knapsack]))