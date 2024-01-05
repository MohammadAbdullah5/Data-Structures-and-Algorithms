array = [19,13,10,29,90,57,88,12,45,78,5,99,34,63] # Array which will be sorted
for i in range(len(array), 1, -1): # outer loop 
    for j in range(0, len(array) - 1): # inner loop
        if(array[j] > array[j + 1]):
            temp = array[j]
            array[j] = array[j + 1]
            array[j + 1] = temp
print(array)