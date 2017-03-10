# B. Verse Pattern

You are given a text consisting of n lines. Each line contains some space-separated words, consisting of lowercase English letters.

We define a syllable as a string that contains exactly one vowel any arbitrary number (possibly none) of consonants. In English alphabet following letters are considered to be vowels: 'a', 'e', 'i', 'o', 'u' and 'y'.

Each word of the text that contains at least one vowel can be divided into syllables. Each character should be a part of exactly one syllable. For example, the word "mamma" can be divided into syllables as "ma" and "mma", "mam" and "ma", and "mamm" and "a". Words that consist of only consonants should be ignored.

The verse patterns for the given text is a sequence of n integers p1, p2, ..., pn. Text matches the given verse pattern if for each i from 1 to n one can divide words of the i-th line in syllables in such a way that the total number of syllables is equal to pi.

You are given the text and the verse pattern. Check, if the given text matches the given verse pattern.

#### Input
The first line of the input contains a single integer n (1 ≤ n ≤ 100) — the number of lines in the text.

The second line contains integers p1, ..., pn (0 ≤ pi ≤ 100) — the verse pattern.

Next n lines contain the text itself. Text consists of lowercase English letters and spaces. It's guaranteed that all lines are non-empty, each line starts and ends with a letter and words are separated by exactly one space. The length of each line doesn't exceed 100 characters.

#### Output
If the given text matches the given verse pattern, then print "YES" (without quotes) in the only line of the output. Otherwise, print "NO" (without quotes).

#### Examples

###### input
3
2 2 3
intel
code
ch allenge

###### output
YES

###### input
4
1 2 3 1
a
bcdefghi
jklmnopqrstu
vwxyz

###### outpu
NO

###### input
4
13 11 15 15
to be or not to be that is the question
whether tis nobler in the mind to suffer
the slings and arrows of outrageous fortune
or to take arms against a sea of troubles

###### output
YES

#### Note
In the first sample, one can split words into syllables in the following way:

in-tel
co-de
ch al-len-ge
Since the word "ch" in the third line doesn't contain vowels, we can ignore it. As the result we get 2 syllabels in first two lines and 3 syllables in the third one.
