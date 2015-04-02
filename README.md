# Numbers-Letters

Description
In the early 80’s, a popular TV show on Dutch television was ‘Cijfers en Letters’ (Numbers and Letters). This game consisted of two game elements, in which the main goal was to outclass your opponent. Letters is a game in which you are given a number of letters with which you should form the longest Dutch word possible. Since Dutch is a very hard language to learn we will postpone implementation of this game element until after the contest. 
For the second game element ‘Numbers’ 5 different numbers are chosen, together with a target number. The aim is to use some arithmetic on (some of) the five numbers to form the target number. Each number can be used only once. It might not be possible to form the target number given the input numbers, in that case the largest number smaller than the target number that can be calculated should be given. The only mathematical operations allowed are: +, -, *, /.  All intermediate results should be integers, so division is not always allowed (e.g. (2*2)/4 is OK, but 2*(2/4) is not). 

Examples: 
- If the 5 numbers are 1, 2, 3, 7 and 100 and the target number is 573, the target number can be reached as follows: (((100-1)*2)-7)*3. -If the 5 numbers are 3, 26, 78, 12 and 17, and the target number is 30, the target number can be reached as follows: (78*3)-(12*17). 
- If the 5 numbers are 67, 69, 58, 22, 2, and the target number is 929, the target number cannot be reached, but the largest number smaller than the target number that can be reached is 923 = (22-(67-58))*(69+2). 
Your assignment is to write a program that calculates the best approximation from below of the target number using arithmetic on the 5 given numbers. Note that if it is not possible to reach the exact number, you should give the largest reachable number below the target number.

Input
The first line contains the number of runs, N. The next N lines consist of six numbers separated by a space. The first 5 numbers Mi, 1≤Mi≤100, are the numbers you can use to calculate the target number. The sixth number is the target number T, 0≤T≤1000.

Output
The output consists of N rows, each containing the best approximation of the target number using the 5 given numbers.

Sample Input
3
1 2 3 7 100 573
3 26 78 12 17 30
67 69 58 22 2 929

Sample Output
573
30 
923