#####Online HW Chapter 3 Problem 1#####
#
#Question asks: Find the sample median.
#

Ch3Prob1<- read.csv(file = 'C:\\Users\\Wade\\Documents\\School\\KSU\\STAT 2332\\Online HW\\Ch 3 Online HW Data\\Ch3Prob1.csv')
#Import data from file using location address 

head(Ch3Prob1)	#Print out first few observations to get the column name.


#To get the median of the column, we put the name that we called the object 
# followed by a dollar sign and then the name of the column.

result.median <- median(Ch3Prob1$ex03.08)

print(result.median)