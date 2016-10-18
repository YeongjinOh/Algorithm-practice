#No.2865 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;EKIPA

##Problem

In a galaxy far, far away, a programming contest is taking place. Your task is to choose the participants!   

N students have applied, and each one of them has some knowledge in each of M different categories. Knowledge can be represented as a real number. You can send at most K students to the contest, but no student can compete in more than one category. Multiple students can compete in a single category.  

For each student, their knowledge of each category is given.   

Choose participants for a contest and categories they will compete in, so that the sum of knowledge is maximal. 

##Input

The first line of input contains integers N, M and K (1 ≤ M ≤ 100, 1 ≤ K ≤ N ≤ 100).   

Each of the next M lines describes knowledge for one category.  

In each line, there are N pairs (i, s), where i is the index of the student, and s is a positive real number representing their knowledge of corresponding category (0 ≤ s ≤ 10). Pairs are given in order of decreasing knowledge. Students are numbered from 1 to N.  

In each line, every student will apear exactly once. 



##Output

The first and the only output line should contain maximum sum of knowledge chosen students can have, with exactly one digit in decimal part.   
 
##Example

####input

4 4 3  
4 5.0 2 4.0 3 2.0 1 1.0  
2 2.0 3 1.0 1 0.5 4 0.3  
4 6.0 3 5.0 2 2.0 1 0.0  
1 4.0 2 3.0 4 0.6 3 0.3

####output

15.0  

##Limitation

Time : 1(s)  
Memory : 128MB
