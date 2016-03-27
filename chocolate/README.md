#NO.1674 Tullia and Chocolate II

##Prblem

It has been rumored that strange and unusual creatures inhabit exotic locations around the world. Edmonton features the Tullia, a person beyond any rational explanation. She has the peculiar ability to instantly become hyperactive at the mere mention of caffeine, endangering the safety of any unfortunate individuals in the vicinity.

Your task involves taking data that was secretly observed by some acquaintances of the subject -- namely how much coffee and particularly chocolate she received -- and use it to determine her hyperactivity level. Her hyperactivity level is defined as the minimum safe distance from the subject, measured in metres.

Extensive research has shown that the following formulae approximate the effects n units of coffee or chocolate have upon the subject at t time units (seconds) following consumption.

Chocolate: H(t) = 8xn - t/12
Coffee: H(t) = 2xn - txt/79

It appears also that the Tullia is able to instantaneously imbibe such substances, and their effects are additive. Negative numbers provided by these formulae indicate the substance's effects have worn off and should not be considered. A minimum one metre safe distance from the Tullia must be maintained at all times.

##Input

There are two types of lines that can appear in input.

A data line will have the format Type Time Quantity, where Type is either the string Chocolate or Coffee, Time is a nonnegative integer, and Quantity is a positive real number indicating the number of units imbibed by the Tullia.

A query line indicates a time the Tullia's hyperactivity level is requested. It consists of the string Query followed by a nonnegative integer indicating the time of the request.

You should process all lines appearing in input. There will be at most 100 data lines (for the safety of the observers).

##Output

One line should be output for each query line appearing in input. Output lines should consist of the time of the request, and the subject's hyperactivity level at that time rounded to one decimal place. Output lines should be sorted in increasing order by request time.

##Example

####input

Query 0  
Chocolate 1 1  
Query 2  
Coffee 3 1.5  
Query 3  
Query 10  

####output

0 1.0  
2 7.9  
3 10.8  
10 9.6  

##limitation

Time : 1(s)
Memory : 128MB
