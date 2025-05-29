#Website: https://www.practicepython.org/

#Ask the user for a number. Depending on whether the number is even or odd,
#print out an appropriate message to the user. Hint: how does an even / odd
#number react differently when divided by 2?

#Extras:
# 1. If the number is a multiple of 4, print out a different message.
# 2. Ask the user for two numbers: one number to check (call it num)
#     and one number to divide by (check). If check divides evenly into
#     num, tell that to the user. If not, print a different appropriate message.

# Define Variables
num = input("Enter a number, and I will determine whether it's odd or even: ")

# Determine if Odd or Even
mod = int(num) % 2

if mod > 0:
    print("You picked an odd number.")
else:
    print("You picked an even number.")

#Addition_1 to Initial Program:
# Determine if Multiple of 4
mod = int(num) % 4

if mod > 0:
    print("Your number is not a multiple of 4.")
else:
    print("Your number is a multiple of 4.")

#Addition_2 to Initial Program:
print()     # print a blank line for cleaner formatting

# Define Additional Variables
num_1 = input("Enter a value for the numerator: ")
num_2 = input("Enter a value for the denominator: ")

# Determine if num_1 Divides Evenly into num_2
mod = int(num_1) % int(num_2)

if mod > 0:
    print(num_1, "is not evenly divisible by", num_2)
else:
    print(num_1, "is evenly divisible by", num_2)
