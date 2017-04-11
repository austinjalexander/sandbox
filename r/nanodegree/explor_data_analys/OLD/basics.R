data(diamonds)

qplot(data = diamonds, x = carat, y = price, color = cut) + 
  scale_color_brewer(palette = 'Accent')

getwd()
setwd('~/r/nanodegree/explor_data_analys')

statesInfo <- read.csv('stateData.csv')

subset(statesInfo, state.region == 1)

stateSubset <- statesInfo[statesInfo$state.region == 1,]
head(stateSubset, 2)
dim(stateSubset)

stateSubsetBracket <- statesInfo[statesInfo$state.region == 1,]
head(stateSubsetBracket, 2)
dim(stateSubsetBracket)

reddit <- read.csv('reddit.csv')
getwd()
setwd('~/r/nanodegree/explor_data_analys/')

table(reddit$employment.status)
summary(reddit)

levels(reddit$children.range)

levels(reddit$age.range)

reddit$age.range = ordered(reddit$age.range, levels = c("Under 18", "18-24", "25-34", "35-44", "45-54", "55-64", "65 or Above"))
library(ggplot2)
qplot(data = reddit, x = age.range)
