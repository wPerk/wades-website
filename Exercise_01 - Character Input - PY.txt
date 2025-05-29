#Website: https://www.practicepython.org/

#Create a program that asks the user to enter their name and their age.
#Print out a message addressed to them that tells them the year that they
#will turn 100 years old. Note: for this exercise, the expectation is that
#you explicitly write out the year (and therefore be out of date the next year).
#If you want to do this in a generic way, see exercise 39.a

#Extras:
# 1. Add on to the previous program by asking the user for another number and
#     printing out that many copies of the previous message. (Hint: order of
#     operations exists in Python)
# 2. Print out that many copies of the previous message on separate lines.
#     (Hint: the string "\n is the same as pressing the ENTER button)

# Define User Input Variables
name = input("What is your name? ")
age = input("What is your age? ")
cur_year = 2024

# Calculate Year at 100 Years Old
fin_year = (100 - int(age)) + cur_year

# Print Message Addressed to User
print("You will turn 100 years old in the year", fin_year)

#Addition_1 to Initial Program:
# Define Additional Variable
print()     # print a blank line for cleaner formatting
other_num = input("Please enter a value for the number of copies of the previous statement: ")

# Print Statement as Many Times as the Given Number Indicates
# NOTE: I think I can complete this with either a 'for' or 'while' loop

# Using for loop...
print()     # print a blank line for cleaner formatting
for number in range(1, int(other_num) + 1):
    print(name,"will turn 100 years old in the year", fin_year)

# Using while loop...
# Define Additional Variable
count = 0

print()     # print a blank line for cleaner formatting
while count < int(other_num):
    print(name,"will turn 100 years old in the year", fin_year)
    count += 1


