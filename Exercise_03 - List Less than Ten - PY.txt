#Website: https://www.practicepython.org/

#Take a list, say for example this one:
#   a = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
#and write a program that prints out all the elements
#of the list that are less than 5.

#Extras:
# 1. Instead of printing the elements one by one, make
#     a new list that has all the elements less than 5
#     from this list in it and print out this new list.
# 2. Write this in one line of Python.
# 3. Ask the user for a number and return a list that
#     contains only elements from the original list a
#     that are smaller than that number given by the user.

# Define Variables
a = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]

# Determine Which Elements are Less than 5 and Print
for number in range(0, 11):
    if a[number] < 5:
        print(a[number])

#Addition_1 to Initial Program:
# Combine Challenges 1 and 2
print(a[number] for a[number] in a if a[number] < 5)














#------ The Following Block of Code Does Not Work------
# Define Additional Variables
#count = 0
# Create and Fill New List
#for number in range(0, 11):
#    if a[number] < 5:
#        b[number] = a[number]
#        count += 1

# Print the New List
#for number in range(0, count):      
#    print(b[number])




#
#
#*****INCOMPLETE*****#
#
#
