# push_swap


 The idea is simple, You have two stacks called Stack A and Stack B.
 Stack A is given a random list of unorganized numbers. 
 You must take the random list of numbers in Stack A and sort them so that Stack A is organized from smallest to largest.
 There are only a few moves you’re allowed to used to manipulate the stacks that we’re going to call “Actions”. 
 The main goal of this project is to organize Stack A in as few actions as possible.
 
 ### Stacks and instructions

The rules the algorithm had to follow is that it can only store the number in two stacks, two arrays of int which follow the "last in, first out" principle. At the begining, the numbers given as parameters are stored in pile a. The algorithm can only use the following instructions :

(sa) swap a - Swap the first two elements of a.

(sb) swap b - Swap the first two elements of b.

(ss) sa and sb at the same time.

(pa) push a - Take the first element from top of b and put it on a.
(pb) push b - Take the first element from top of a and put it on b.
(ra) rotate a - Shift of a position all elements of a (towards the top, the first element becomes the last).
(rb) rotate b - Shift of a position all elements of b (towards the top, the first element becomes the last).
(rr) ra and rb at the same time.
(rra) reverse rotate a (towards the bottom, the last element becomes the first).
(rrb) reverse rotate b (towards the bottom, the last element becomes the first).
(rrr) rra and rrb at the same time.
