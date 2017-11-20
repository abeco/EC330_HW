This is a repository of my homeworks from EC330 - Algorithms and Data Structures.
The actual assignments don't exist anymore, presumably so the teacher can reuse them in future semesters, so I'll explain to the best of my ability what the purpose of each HW was (although I think my code is generally very readable).

HW2: It looks like HW2_NEW was just a function to read in a file containing lines of integers separated by spaces and terminated by the constant TERMINATOR which was set to -999999. Pretty straightfoward.
MaxProduct looks like an extrapolation of that, which reads the lines in and returns the maximum product of the integers from a given input file with their direct neighbors. e.g. input: 2 3 -1 maxproduct: 6.
Problem4a is a string search algorithm and Problem4b takes two input files and merges them into a single output file with the contents of both.

HW3: Just a handwritten template implementation of a linked list, specified/tested for int and char 

HW4: Read in a bunch of coordinates from an input text file, and print the points that are on the same line if the line has 4 or more points. I'll admit my function naming wasn't ideal here, but I wanted to see if the Teaching Assistant was actually grading the homework, or just running it and making sure it produced the correct output. Also I did this pretty late at night.

HW5: Just a Cuckoo Hash Table implementation. I realize it's not the best implementation because if the inputs create an infinite loop, it just exits. I could improve on it by expanding the table if an infinite loop occurs, but that wasn't a part of the HW

HW6: This was a HW to do a bunch of operations on a really large data set which I couldn't push because it was too large. The first task was to find and count all the 'words' in the data set, and the second task was to find the longest pangram. I don't know what the third task was, but I never got to it.

HW7: This was a HW to find the minimum distance from the top left corner of a maze to the bottom right. The input maze was made of 1's and 0's and I had to return the shortest path of adjacent 1's to get from one corner to the other. I used an adjaceny list to represent the maze as a graph, and then implemented Dijkstra's Algorithm. I'm prouder of the way this one came out than the last one. Also, excuse the rambling comments. I figured showing my thought process couldn't hurt my grade.

HW8: So this last HW was to transform one tree into a different one with the same elements through rotation. The concept was to turn the first tree into a right chain (such that no node has a left child) and record the steps it would take to turn the second into the same right chain, and then do the opposite rotation on the parent node