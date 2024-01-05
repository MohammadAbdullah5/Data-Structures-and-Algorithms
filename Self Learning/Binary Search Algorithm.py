array = [19,13,10,29,90,57,88,12,45,78,5,99,34,63] # Array on which we will find selected key
searchKey = int(input("Enter the key to find: ")) #Enter the key to find
array.sort()


def binarySearchAlgo(array, searchKey):
    iterations = 0 # variable to count the number of iterations to find the search key
    currentIndex = 0 
    lowerBound = 0 
    upperBound = len(array) - 1 
    i = 1
    while(i == 1):
        currentIndex = (lowerBound + upperBound) // 2
        if(array[currentIndex] == searchKey):
            return array[currentIndex]

        elif(lowerBound > upperBound):
            return "null"
        
        else:
            if(searchKey < array[currentIndex]):
                upperBound = currentIndex - 1

            else:
                lowerBound = currentIndex + 1
        print(iterations)
        iterations += 1

value = binarySearchAlgo(array, searchKey)
if(value == "null"):
    print("Not Found")
else:
    print("The value is " + str(value))