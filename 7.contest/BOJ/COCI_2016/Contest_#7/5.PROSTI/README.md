#NO.11958   PROSTI

##Problem

Mirko and his older brother Slavko are playing a game. At the beginning of the game, they pick three numbers K, L, M. In the first and only step of the game, each of them picks their own K consecutive integers.  

Slavko always picks the first K integers (numbers 1, 2, ..., K). Mirko has a special demand – he wants to choose his numbers in a way that there are exactly L happy numbers among them. He considers a number happy if it meets at least one of the following requirements:  

<ul>
<li>the number is smaller than or equal to M</li>
<li>the number is prime</li>
</ul>

Out of respect to his older brother, L will be smaller than or equal to the total number of happy numbers in Slavko’s array of numbers.  


They will play a total of Q games with different values K, L, M. For each game, help Mirko find an array that meets his demand.  

##Input

The first line of input contains Q (1 ≤ Q ≤ 100 000). Each of the following Q lines contains three integers, the i th line containing integers Ki, Li, Mi (1 ≤ Ki, Mi ≤ 150, 0 ≤ Li ≤ Ki) that determine the values K, L, M that will be used in the i th game.  

##Output

Output Q lines, the i th line containing an integer, the initial number of Mirko’s array in the i th game. If an array with the initial number being smaller than or equal to 10 000 000 does not exist, output −1. If there are multiple possible solutions, output any.  

##Example

####input 1

3  
1 1 1  
2 0 2  
3 1 1  

####output 1

1  
8  
4  

####input 2

3  
4 1 1  
5 2 3  
5 0 3  

####output 2

6  
4  
24  

####input 3

4  
7 2 5  
6 1 1  
10 4 5  
6 2 2  

####output 3

6  
20  
5  
4  

##Limitation

Time : 0.5(s)  
Memory : 64MB
