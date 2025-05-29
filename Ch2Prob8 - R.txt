
#####Online HW Chapter 2 Problem 8#####

Ch2Prob8 <- read.csv(file = 'C:\\Users\\Wade\\Documents\\School\\KSU\\STAT 2332\\Online HW\\Ch2Prob8.csv')

colnames(Ch2Prob8)		# need to see what the column names are
					# the object is Ch2Prob8

install.packages("aplpack")	# install package containing back-to-back stem and leaf plots

library(aplpack)			# now need to call it
					# otherwise it is basically NOT in the console

stem.leaf.backback(Ch2Prob8$Lower_.F., Ch2Prob8$Upper_.F.)		# print back-to-back stem and leaf plot

# If you are not able to do back-to-back stem and leaf
# plot you can print the stem and leaf plots individually,
# but the format can get distorted

stem.leaf.backback(Ch2Prob8$Lower_.F., scale=4)		# formatting can be fixed with scale = n, where n > 1

stem.leaf.backback(Ch2Prob8$Upper_.F.)			# scale not needed for this plot