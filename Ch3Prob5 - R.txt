
#####Online HW Chapter 3 Problem 5#####

Ch3Prob5<- read.csv(file = 'C:\\Users\\Wade\\Documents\\School\\KSU\\STAT 2332\\Online HW\\Ch 3 Online HW Data\\Ch3Prob5.csv')
#Import data from file using location address

head(Ch3Prob5)	#Print out first few observations to get the column name.

boxplot(Ch3Prob5$Difference_.min., horizontal = TRUE)		#This will create a popup of the boxplot.


#To see if there are outlier, we need to do our formulas from the notes.
#So we need to find Q1 and Q3.
#This is not a typo. In R it's called quantile since it includes the
# lowest value as "0%" and the largest value as "100%".

quantile(Ch3Prob5$Difference_.min.) 


#You should have gotten -22.50 for Q1 (25% value), and 17.75 for Q3 (75% value).

#IQR Calculation
17.75-(-22.50)
# Should have gotten 40.25.

#Lower outlier boundary
-22.50 - 1.5*40.25
# Should have gotten -82.875.

#Upper outlier boundary
17.75 + 1.5*40.25
# Should have gotten 78.125.

#None of our values are outside of these boundaries, meaning there are no outliers.
# Furthermore, the boxplot itself does not show any additional dots outside of the
# data points (you will see this in the next question)


###Notes from Feedback:
#The distribution does not have little variability. Variability
# depends on the spread of the boxplot.
#
#In particular, the distance between the third quantile and the maximum,
#  or the distance between the first quantile and the minimum.
#
#In the boxplot, there is a larger distance between the third quantile and the maximum.

###Answers:
#The distribution of the boxplot is...
# (asymmetrical)
# (skewed right)
#  and has (high variablility)	<-- high variability because there is a larger distance between the third quantile and the maximum.
#There are...
# (no outliers)		<-- none of the data is outside of the lower or upper boundaries.




