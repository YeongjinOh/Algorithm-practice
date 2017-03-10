# A. Broken Clock

You are given a broken clock. You know, that it is supposed to show time in 12- or 24-hours HH:MM format. In 12-hours format hours change from 1 to 12, while in 24-hours it changes from 0 to 23. In both formats minutes change from 0 to 59.

You are given a time in format HH:MM that is currently displayed on the broken clock. Your goal is to change minimum number of digits in order to make clocks display the correct time in the given format.

For example, if 00:99 is displayed, it is enough to replace the second 9 with 3 in order to get 00:39 that is a correct time in 24-hours format. However, to make 00:99 correct in 12-hours format, one has to change at least two digits. Additionally to the first change one can replace the second 0 with 1 and obtain 01:39.

#### Input
The first line of the input contains one integer 12 or 24, that denote 12-hours or 24-hours format respectively.

The second line contains the time in format HH:MM, that is currently displayed on the clock. First two characters stand for the hours, while next two show the minutes.

#### Output
The only line of the output should contain the time in format HH:MM that is a correct time in the given format. It should differ from the original in as few positions as possible. If there are many optimal solutions you can print any of them.

#### Examples

###### input
24
17:30

###### output
17:30

###### input
12
17:30

###### output
07:30

###### input
24
99:99

###### output
09:09


