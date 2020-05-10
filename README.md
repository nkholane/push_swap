# push_swap


 The idea is simple, You have two stacks called Stack A and Stack B.
 Stack A is given a random list of unorganized numbers. 
 You must take the random list of numbers in Stack A and sort them so that Stack A is organized from smallest to largest.
 There are only a few moves you’re allowed to used to manipulate the stacks that we’re going to call “Actions”. 
 The main goal of this project is to organize Stack A in as few actions as possible.
 
 ### Stacks and instructions

The rules the algorithm had to follow is that it can only store the number in two stacks, two arrays of int which follow the "last in, first out" principle. At the begining, the numbers given as parameters are stored in pile a. The algorithm can only use the following instructions :

| Name | Effect |
|:----:|:------:|
| pa | Push the top number of stack b onto stack a |
| pb | Push the top number of stack a onto stack b |
| ra | Places the top number of stack a to the bottom of stack a |
| rb | Places the top number of stack b to the bottom of stack b |
| rr | Equivalent of ra rb |
| rra | Places the bottom number of stack a at the top of stack a |
| rrb | Places the bottom number of stack b at the top of stack b |
| rrr | Equivalent of rra rrb |
| sa | Swaps the two top numbers of stack a |
| sb | Swaps the two top numbers of stack b |
| ss | Equivalent of sa sb |
