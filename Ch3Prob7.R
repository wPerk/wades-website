
#####Online HW Chapter 3 Problem 7#####
#####
#####Since problems 7, 8, and 9 use the same data, .csv file labeled "Ch3Prob789"
#####

#Import data from file using location address
Ch3Prob789<- read.csv(file = 'C:\\Users\\Wade\\Documents\\School\\KSU\\STAT 2332\\Online HW\\Ch 3 Online HW Data\\Ch3Prob789.csv')

#Print out first few observations to get the column name.
head(Ch3Prob789)

#Sample mean
result.mean <- mean(Ch3Prob789$Caffeine_.mg.)
print(result.mean)

#Sample median
result.median <- median(Ch3Prob789$Caffeine_.mg.)
print(result.median)

#Sample variance (round your final answer to 2 decimal places)
var(Ch3Prob789$Caffeine_.mg.)

#Standard deviation (round your final answer to 2 decimal places)
sd(Ch3Prob789$Caffeine_.mg.)


###ANSWERS###
# Mean = 207.05
# Median = 206
# Variance = 657.3132
# Standard Deviation = 25.63812