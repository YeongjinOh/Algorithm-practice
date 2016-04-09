#No.4416   Prime Distance

##Prblem

The branch of mathematics called number theory is about properties of numbers. One of the areas that has captured the interest of number theoreticians for thousands of years is the question of primality. A prime number is a number that is has no proper factors (it is only evenly divisible by 1 and itself). The first prime numbers are 2,3,5,7 but they quickly become less frequent. One of the interesting questions is how dense they are in various ranges. Adjacent primes are two numbers that are both primes, but there are no other prime numbers between the adjacent primes. For example, 2,3 are the only adjacent primes that are also adjacent numbers.  
  
Your program is given 2 numbers: L and U (1<=L<U<=2,147,483,647), and you are to find the two adjacent primes C1 and C2 (L<=C1<C2<=U) that are closest (i.e. C2-C1 is the minimum). If there are other pairs that are the same distance apart, use the first pair. You are also to find the two adjacent primes D1 and D2 (L<=D1<D2<=U) where D1 and D2 are as distant from each other as possible (again choosing the first pair if there is a tie).

##Input

Each line of input will contain two positive integers, L and U, with L < U. The difference between L and U will not exceed 1,000,000.  

##Output

For each L and U, the output will either be the statement that there are no adjacent primes (because there are less than two primes between the two given numbers) or a line giving the two pairs of adjacent primes.  

##Example

####input

2 17  
14 17

####output

2,3 are closest, 7,11 are most distant.  
There are no adjacent primes.

##Limitation

Time : 1(s)  
Memory : 128MB
