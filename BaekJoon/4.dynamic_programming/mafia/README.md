#No.10542   mafia

##Problem

Mafia is a social game played frequently by high school competitors in informatics on summer and winter camps and national competitions, usually very late at night, drinking various fruit sodas. This game is not about winning, it's about los taking part, like in competitions.  

To solve this task, you don't need to know the rules of mafia; all you need to know is that some of the players are "mobsters" and the rest are "civilians". The mobsters know who is who, but the civilians don't. The civilians are trying to figure out who the mobsters are during the game.  

In the current round of the game, out of N surviving players so far, each one has accused exactly one other player saying that he is the mobster. The civilians were only guessing and the mobsters have accused civilians, pretending to know nothing.  

Not knowing who the mobsters are, but knowing who accused whom, determine the maximum possible number of mobsters among these players!  

##Input

The first line of input contains the integer N (2 &lt; N &lt; 500 000), the number of players. The players are labeled with integers from 1 to N.  

The K<sub>th</sub> line of input, out of the following N lines, contains the label of the player accused by the player K. (No player can accuse themselves.)  

##Output

The first and only line of output must contain the maximum possible number of mobsters.  

##Example

####input 1

3  
2  
1  
1  

####output 1

2  

####input 2

3  
2  
3  
1  

####output 2

1  


####input 3

7  
3  
3  
4  
5  
6  
4  
4  

####output 3

4  

##Limitation

Time : 1(s)  
Memory : 32MB
