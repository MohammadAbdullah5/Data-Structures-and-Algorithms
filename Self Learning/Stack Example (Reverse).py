input = input("Enter a word to reverse: ")

output = ""
stack = []
for i in range(0, len(input)):
    stack.append(input[i])

while(len(stack) > 0):
    ch = stack.pop()
    output += ch
print(output)