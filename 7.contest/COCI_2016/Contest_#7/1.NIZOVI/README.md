#NO.11954   NIZOVI

##Prblem

An array in a certain programming language is defined in the following way:  

<ul>
<li>The beginning and the end of an array is denoted by an open and closed curly bracket, respectively.</li>
<li>Inside the curly braces, there are (possibly even 0) values separated by a comma (there is no comma after the last value in the array).</li>
<li>Each value can be a word (an array of lowercase letters of the English alphabet) or another array.</li>
<li>Examples of correctly defined arrays are: {}, {a,b,c}, {abc,znj,{novi,niz},pozz}.</li>
</ul>
Recently, you’ve noticed that the programming language does not throw an error if you do not place the appropriate number of spaces and new lines before or after the curly braces or the commas. Given the fact that you too mind the values being so „squished“ together, you’ve decided to get to work and modify the shape of the array in the following way:  

<ul>
<li>Each value that is not an array or denotes the beginning or the end of the array (curly braces) will be in its own line.</li>
<li>The commas are „connected“ with the value located directly before them and there is a new line after each comma.</li>
<li>After the curly bracket denoting the beginning of the array, the indentation of the content increases (shifting the output to the right) for 2 spaces.</li>
<li>Before the curly bracket denoting the end of the array ’}’, the indentation of the content decreases (shifting the output to the left) for 2 spaces.</li>
</ul>

##Input

The first line of input contains an array of characters S (1 ≤ |S| ≤ 1500), representing the array from the task.  

##Output

The output must consist of the modified version of the array from the task.  

##Example

####input 1

{abc,ono,sto}

####output 1

{  
  abc,  
  ono,  
  sto  
}  
  
  

####input 2

{}  

####output 2

{  
}  

####input 3

{znakovi}  

####output 3

{  
  znakovi  
}  


####input 4

{a,b,{c,d},e,{}}  

####output 4

{  
  a,  
  b,  
  {  
    c,  
    d  
  },  
  e,  
  {  
  }  
}  


##Limitation

Time : 1(s)  
Memory : 64MB
