#####Online HW Chapter 3 Problem 3#####
#
#Question asks: Find...
#A)sample mean and sample median
#B)mode if it exists, and
#C)Multiply each score by the degree of difficulty, 2.3.
#  Then find the sample mean for this new data  set.



Ch3Prob3<- read.csv(file = 'C:\\Users\\Wade\\Documents\\School\\KSU\\STAT 2332\\Online HW\\Ch 3 Online HW Data\\Ch3Prob3.csv')
#Import data from file using location address 

head(Ch3Prob3)	#Print out first few observations to get the column name.


#PART - A) 
result.mean <- mean (Ch3Prob3$Score)		#Sample Mean (X-BAR)
print(result.mean)

result.median <- median(Ch3Prob3$Score)		#Sample Median (X-TILDE)
print(result.median)

###Answers:
# Mean (x-bar) = 6.82
# Median (x-tilde) = 7
########################


#PART - B)
# R doesn't have a default option to find the mode. 
# We need to install a package called "modeest, then add it 
#  to the library, then call the mlv function (most likely value).

#install.packages("modeest")		#I don't think this is needed after the initial installation
library(modeest)
mlv(Ch3Prob3$Score, method = "mfv")

###Answer:
# Mode (M) = 7
########################


#PART - C)
Ch3Prob3$ScoreMULTIPLIED <- Ch3Prob3$Score * 2.3	#Multiply column by 2.3. Let's create a new column for these values.

head(Ch3Prob3)							#Let's print the first few observations to make sure the new column was made.

result.mean <- mean(Ch3Prob3$ScoreMULTIPLIED)		#Sample mean for the new column.
print(result.mean)

###Answer:
# New Mean (x-bar_new) = 15.686
########################


###HW NOTES###
#
#Mode (M)
#Mean is x-bar
#Median is x-tilde
#
#Data Distribution:	mean vs median
#skewed right if	 	x-bar > x-tilde
#symmetric if		x-bar = x-tilde
#skewed left if		x-bar	< x-tilde

