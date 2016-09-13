# C. Sonya and Queries

Today Sonya learned about long integers and invited all her friends to share the fun. Sonya has an initially empty multiset with integers. Friends give her t queries, each of one of the following type:

<ul>
<li> +  ai — add non-negative integer ai to the multiset. Note, that she has a multiset, thus there may be many occurrences of the same integer. </li>
<li> -  ai — delete a single occurrence of non-negative integer ai from the multiset. It's guaranteed, that there is at least one ai in the multiset. </li>
<li> ? s — count the number of integers in the multiset (with repetitions) that match some pattern s consisting of 0 and 1. </li>
<p> In the pattern, 0 stands for the even digits, while 1 stands for the odd. Integer x matches the pattern s, if the parity of the i-th from the right digit in decimal notation matches the i-th from the right digit of the pattern. If the pattern is shorter than this integer, it's supplemented with 0-s from the left. Similarly, if the integer is shorter than the pattern its decimal notation is supplemented with the 0-s from the left. </p>
<p> For example, if the pattern is s = 010, than integers 92, 2212, 50 and 414 match the pattern, while integers 3, 110, 25 and 1030 do not. </p>

#### Input
The first line of the input contains an integer t (1 ≤ t ≤ 100 000) — the number of operation Sonya has to perform.

Next t lines provide the descriptions of the queries in order they appear in the input file. The i-th row starts with a character ci — the type of the corresponding operation. If ci is equal to '+' or '-' then it's followed by a space and an integer ai (0 ≤ ai < 1018) given without leading zeroes (unless it's 0). If ci equals '?' then it's followed by a space and a sequence of zeroes and onse, giving the pattern of length no more than 18.

It's guaranteed that there will be at least one query of type '?'.

It's guaranteed that any time some integer is removed from the multiset, there will be at least one occurrence of this integer in it.

#### Output
For each query of the third type print the number of integers matching the given pattern. Each integer is counted as many times, as it appears in the multiset at this moment of time.

#### Examples

###### input
12<br>
\+ 1 <br>
\+ 241  <br>
\? 1  <br>
\+ 361  <br>
\- 241  <br>
? 0101  <br>
\+ 101  <br>
\? 101  <br>
\- 101  <br>
\? 101  <br>
\+ 4000  <br>
\? 0  <br>

###### output
2<br>
1<br>
2<br>
1<br>
1<br>
<br>
######input
4<br>
\+ 200<br>
\+ 200<br>
\- 200<br>
\? 0<br>

###### output
1
