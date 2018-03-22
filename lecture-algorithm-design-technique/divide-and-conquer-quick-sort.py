a = [5, 3, 2, 5, 4, 7, 1, 10, 6, 8, 9]

def qsort(num_list):
  if len(num_list) <= 1:
    return num_list
  pivot = [num for num in num_list if num == num_list[0]]
  left = qsort([num for num in num_list if num < pivot[0]])
  right = qsort([num for num in num_list if num > pivot[0]])
  return left + pivot + right

print qsort(a)
#num_list.sort()
#print(num_list)