
#####Online HW Chapter 3 Problem 6#####

Ch3Prob6<- read.csv(file = 'C:\\Users\\Wade\\Documents\\School\\KSU\\STAT 2332\\Online HW\\Ch 3 Online HW Data\\Ch3Prob6.csv')
#Import data from file using location address

head(Ch3Prob6)	#Print out first few observations to get the column name.

boxplot(Ch3Prob6$InflationRate, horizontal = TRUE)		#This will create a popup of the boxplot.

#There are 5 dots on right side of box plot. These represent the 5 outliers.


###Answers:
#The distribution is (right skewed) and has (high variability). <-- HIGH because the whiskers are LONG
#
#There are (5 outliers).

###Feedback on Answers:
#Boxplots are typically not described by the standard deviation.
#If the whiskers of the box plot are LONG,  the distribution has HIGH variability.
#If the whiskers of the box plot are SHORT, the distribution has LOWER variability.