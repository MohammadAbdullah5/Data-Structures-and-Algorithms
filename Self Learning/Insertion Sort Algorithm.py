array = [54,23,11,9,98,45,61,83,75,39,5,18,91,49,41]

for out in range(1, len(array)): # loop from the 2nd element, 1st element alone is always sortec
    temp = array[out] # put the first unsorted element in a temporary variable
    inner = out # inner loop starts from outer loop variable index
    while(inner > 0 and array[inner - 1] > array[inner]): # it loops while checking if arrays first unsorted variable is less than previous if yes then swap and decrement the index
        array[inner], array[inner - 1] = array[inner - 1], array[inner] # shifting to right and unsorted will be to the hole element
        inner -= 1 # decrement
    array[inner] = temp # hole element will be filled with unsorted element initialized at start

print(array)