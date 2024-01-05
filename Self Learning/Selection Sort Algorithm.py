array = [19,13,10,29,90,57,88,12,45,78,5,99,34,63] # Array which will be sorted

for out in range (0, len(array) - 1): # outer loop from all the elements
    min = out # minimum will be set as the first value because at that index this is minimum
    for inner in range(out + 1, len(array)): # inner loop which will start from one index after the min
        if(array[inner] < array[min]): #it will check if every index after the min is smallest or not
            min = inner
            
    temp = array[out] # if true then swap that elements
    array[out] = array[min]
    array[min] = temp

print(array)