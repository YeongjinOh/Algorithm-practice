#NO.11957   OTPOR

##Problem

Mirko has been a very good boy, so he got exactly what he wanted for his birthday, a "Young physicist" kit! In the kit, there are N types of resistors, connecting wires and an ohmmeter. If a resistor is of type i, it provides a resistance of precisely Ri ohms.  

As we all know, resistors can be connected in two different ways, in series and parallel. Also, we know that the complete circuit of resistors can be replaced with one resistor of the resistance equal to the equivalent resistance of the circuit. When the circuit is series, it is written in the following way:  

<p align="center">(R<sub>1</sub>-R<sub>2</sub>-R<sub>3</sub>-...-R<sub>K</sub>)</p>

and the following formula holds:  

<p align="center">R<sub>ekv</sub> = R<sub>1</sub> + R<sub>2</sub> + R<sub>3</sub> + ... + R<sub>K</sub></p>

When the circuit is parallel, it is written in the following way:  

<p align="center">(R<sub>1</sub>|R<sub>2</sub>|R<sub>3</sub>|...|R<sub>K</sub>)</p>

and the following formula holds:  

<p align="center">R<sub>ekv</sub> = 1/(1/R<sub>1</sub> + 1/R<sub>2</sub> + 1/R<sub>3</sub> + ... + 1/R<sub>K</sub>)</p>

Mirko was excited to bring his new toy to school, where he showed it to all his friends. Unfortunately for him, the teacher also noticed the toy. She quickly connected a circuit and is now asking Mirko to tell her the equivalent resistance of the circuit. Help Mirko and answer the teacher’s question!  

##Input

<p>The first line of input contains the integer N (1 ≤ N ≤ 9) from the task.</p>

<p>The following line contains N real numbers R<sub>i</sub> (0 &lt; R<sub>i</sub> &lt; 100) from the task.</p>

<p>The last line contains the circuit S, that will not be longer than 100 000 characters. S will only consist of the following characters: ’R’, ’1’ – ’9’, ’(’, ’)’, ’-’ and ’|’. The number of pairs of brackets will be minimal, and the brackets will be paired properly. Inside of a pair of brackets, there will not be the character ’-’ and the character ’|’ at the same time. The circuit will only consist of the resistors from the kit and it is possible that not all types of resistors are used, or that one type of resistor is used several times.</p>


##Output

The first and only line of output must contain the number from the task. A deviation from the official solution of ±0.00001 is tolerated.  

##Example

####input 1 

3  
2 3 6  
(R1-R2-R3)  

####output 1

11.00000  

####input 2

3  
2 3 6  
(R1|R2|R3)  

####output 2

1.00000  

####input 3

5  
5.0 5.0 5.0 5.0 5.0  
((R1-(R2|R3)-(R4|R5))|(R1-(R2|R3)-(R4|R5)))  

####output 3

5.00000  

##Limitation

Time : 1(s)  
Memory : 64MB
