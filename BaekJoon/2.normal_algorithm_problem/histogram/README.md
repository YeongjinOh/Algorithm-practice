#No.1725	Largest Rectangle in a Histogram

##Problem

A histogram is a polygon composed of a sequence of rectangles aligned at a common base line. The rectangles have equal widths but may have different heights.  


Usually, histograms are used to represent discrete distributions, e.g., the frequencies of characters in texts. Note that the order of the rectangles, i.e., their heights, is important. Calculate the area of the largest rectangle in a histogram that is aligned at the common base line, too. The figure on the right shows the largest aligned rectangle for the depicted histogram.  

##Input

The input contains several test cases. Each test case describes a histogram and starts with an integer n, denoting the number of rectangles it is composed of. You may assume that 1&le;n&le;100000. Then follow n integers h<sub>1</sub>, ..., h<sub>n</sub>, where 0&le;h<sub>i</sub>&le;1000000000. These numbers denote the heights of the rectangles of the histogram in left-to-right order. The width of each rectangle is 1. A zero follows the input for the last test case.  

##Output

For each test case output on a single line the area of the largest rectangle in the specified histogram. Remember that this rectangle must be aligned at the common base line.  

##Example

####input

7  
2  
1  
4  
5  
1  
3  
3  

####output

8  

##Limitation

Time : 2(s)  
Memory : 128MB
