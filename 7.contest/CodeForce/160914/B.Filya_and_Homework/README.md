# B. Filya and Homework

Today, hedgehog Filya went to school for the very first time! Teacher gave him a homework which Filya was unable to complete without your help.

Filya is given an array of non-negative integers a1, a2, ..., an. First, he pick an integer x and then he adds x to some elements of the array (no more than once), subtract x from some other elements (also, no more than once) and do no change other elements. He wants all elements of the array to be equal.

Now he wonders if it's possible to pick such integer x and change some elements of the array using this x in order to make all elements equal.

#### Input
The first line of the input contains an integer n (1 ≤ n ≤ 100 000) — the number of integers in the Filya's array. The second line contains n integers a1, a2, ..., an (0 ≤ ai ≤ 109) — elements of the array.

#### Output
If it's impossible to make all elements of the array equal using the process given in the problem statement, then print "NO" (without quotes) in the only line of the output. Otherwise print "YES" (without quotes).

#### Examples

###### input
5
1 3 3 2 1

###### output
YES

###### input
5
1 2 3 4 5

###### output
NO
