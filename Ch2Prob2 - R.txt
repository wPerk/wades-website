
#####Online HW Chapter 2 Problem 2#####

Ch2Prob2 <- read.csv(file = 'C:\\Users\\Wade\\Documents\\School\\KSU\\STAT 2332\\Online HW\\Ch2Prob2.csv')
#import data from file using location address 

print(Ch2Prob2)		#print data to console

table(Ch2Prob2)		#tabulate all categories and report counts of each

#relative frequency = (category total)/(overall total): 
27/100	# Cognitive C

22/100	# Manual M

20/100	# None N

31/100	# Visual V

########NOTES########
# gets operator: <-
# needed to add \Ch2Prob2.csv for file address to work
# also have to double each slash like so \\