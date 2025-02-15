
#####Online HW Chapter 2 Problem 13#####

Ch2Prob13 <- read.csv(file = 'C:\\Users\\Wade\\Documents\\School\\KSU\\STAT 2332\\Online HW\\Ch2Prob13.csv')

colnames(Ch2Prob13)		# need to see what the column names are
					# the object is Ch2Prob8

#install.packages("aplpack")	# install package containing back-to-back stem and leaf plots

library(aplpack)			# now need to call it
					# otherwise it is basically NOT in the console

stem.leaf.backback(Ch2Prob13$ResponseTimeNew_.min., Ch2Prob13$ResponseTimeTraditional_.min.)		# print back-to-back stem and leaf plot

###Online HW answer to problem 13 using stem-and-leaf plot...###
# The distribution of times using the new procedure is less spread
# out and the center has a lower value than the old procedure.
# Therefore, the new procedure is better.