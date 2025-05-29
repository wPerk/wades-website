#####Online HW Chapter 3 Problem 2#####
#
#Question asks: Find the sample mean and sample median.
#

Ch3Prob2<- read.csv(file = 'C:\\Users\\Wade\\Documents\\School\\KSU\\STAT 2332\\Online HW\\Ch 3 Online HW Data\\Ch3Prob2.csv')
#Import data from file using location address 

head(Ch3Prob2)	#Print out first few observations to get the column name.

result.mean <- mean (Ch3Prob2$ex03.14)		#Sample Mean
print(result.mean)

result.median <- median(Ch3Prob2$ex03.14)		#Sample Median
print(result.median)

#Answer: skewed left because x-bar = 139 which is less than x-tilde = 149.


###HW NOTES###
#
#Mean is x-bar
#
#Median is x-tilde
#
#Data Distribution:	mean vs median
#skewed right if	 	x-bar > x-tilde
#symmetric if		x-bar = x-tilde
#skewed left if		x-bar	< x-tilde
