#HackerEarth&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Roy and Coin Boxesu

<p><b>Tag(s)</b> : BIT, Data Structures, Dynamic Programming, Medium</p>

##Problem

<p>Roy has N coin boxes numbered from 1 to N.</p>
 <p>Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).</p>
 <p>He does this for M number of days.</p>

 <p>After M days, Roy has a query: How many coin boxes have atleast X coins.</p>
 <p>He has Q such queries.</p>

##Input

<p> First line contains N - number of coin boxes.</p>
 <p>Second line contains M - number of days.</p>
 <p>Each of the next M lines consists of two space separated integers L and R.</p>
 <p>Followed by integer Q - number of queries.</p>
 <p>Each of next Q lines contain a single integer X.</p>


<p><b>Constraints:</b></p>
<p>1 ≤ N ≤ 1000000</p>
<p>1 ≤ M ≤ 1000000</p>
<p>1 ≤ L ≤ R ≤ N</p>
<p>1 ≤ Q ≤ 1000000</p>
<p>1 ≤ X ≤ N</p>

##Output

<p>For each query output the result in a new line.</p>

##Example

####input

7
4
1 3
2 5
1 2
5 6
4
1
7
4
2

####output

6
0
0
4

##Limitation

Time : 3(s)
Memory : 256MB

