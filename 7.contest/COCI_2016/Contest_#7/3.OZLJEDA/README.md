#NO.11956   OZLJEDA

##Problem

Due to the frantical usage of the racket to kill flies, Marin has sustained a serious bodily injury known to the medical community as epicondylitis lateralis humeri. His grandma has advised smearing rakija over it, the doctor has prescribed a strong painkiller, but Marin has ignored every single advice and decided to look for the answer in integer sequences.  

He has discovered a previously undiscovered sequence of integers and called it the xorbonacci sequence. The nth element in the sequence is denoted with xn. The sequence is defined recursively in the following way:  

<ul>
<li>x1 = a1,</li>
<li>x2 = a2,</li>
<li>...</li>
<li>xk = ak,</li>
<li>xn = xn−1 ⊕ xn−2 ⊕ ... ⊕ xn−k, n > k</li>
</ul>
Because of a reason only known to Marin, he determined that all his sorrows will go away if you answer his Q queries defined with numbers l and r. The answer to the query is represented with the value  

<ul>
<li>xl ⊕ xl+1 ⊕ ... ⊕ xr−1 ⊕ xr</li>
</ul>

Help Marin and answer his queries.  

Please note: The operation ⊕ is the operation of binary XOR.  

##Input

The first line of input contains the integer K (1 ≤ K ≤ 100 000) from the task.  

The following line contains K integers that represent the first K elements in the xorbonacci sequence.  

All numbers are smaller than 1018.  
 
The following line contains the integer Q (1 ≤ Q ≤ 106) from the task.  

The ith of the following Q lines contains two integers li and ri (1 ≤ li ≤ ri ≤ 1018) that represent Marin’s ith query.  

##Output

Each of the following Q lines of output must contain the answers to Marin’s queries, the order being the same as the input.  

##Example

####input 1

4  
1 3 5 7  
3  
2 2  
2 5  
1 5  

####output 1

3  
1  
0  

####input 2

5  
3 3 4 3 2  
4  
1 2  
1 3  
5 6  
7 9  

####output 2

0  
4  
7  
4  

##Limitation

Time : 1(s)  
Memory : 64MB
