# 📊 push_swap

This repository contains an algorithm for sorting data using a limited set of instructions and two stacks. The goal is to achieve the most efficient sorting possible, using as few actions as necessary. 

## Table of Contents

- [About Mandatory](#About-Mandatory)
	- [- Steps for Sorting](#Steps-for-Sorting)
	- [- The Operations](#The-Operations)
- [About BONUS](#About-Bonus)
- [Installation](#Installation)
- [Testing](#Testing)
- [Resources](#Resources)

## About Mandatory 

"Push_swap" is a program that takes a list of integers in "stack_a" as input, formatted as a list with the first argument at the top of the stack_a. The program's objective is to display the smallest possible list of instructions needed to sort "stack_a", with the smallest number at the top. The program achieves this by calculating the best rotation/swapping instructions required to sort the numbers and displays them on the standard output. The program will reject non-integer arguments, arguments that exceed integer limits, and duplicate arguments. If any of these are encountered, the program will display "Error" and exit.

#### Steps for Sorting 

I followed a documentation on someone that did greedy algorithm sort, but i got somewhere side tracked and did tri-partition quicksort algorithm.

1. First, I validate the input and populate stack_a while indexing each number. 
2. Then, I sort the numbers by pushing everything to stack_b, except for a group of three numbers that are sorted using the sort_3() function. To minimize the cost of sorting, push_to_b() prioritizes smaller numbers before larger ones. 
3. Once all the numbers are on stack_b, I assign each number a future position in stack_a and calculate two costs: cost_b, which represents the number of rotations needed to bring the number to the top of stack_b, and cost_a, which represents the number of rotations needed to bring the number to its final position in stack_a.
4. Next, I apply moves depending on where each number is located. For numbers in the lower half of the stack, I reverse rotate, while for numbers in the upper half, I rotate up. This approach optimizes the moves needed to bring each number to its final position. 
5. Once all the numbers are in stack_a, I check if they are sorted, and if not, I rotate until the lowest index is at the top.

#### The Operations

- `sa`: swap a - swap the first two elements of stack_a.
- `sb`: swap b - swap the first two elements of stack_b.
- `ss`: swap both - sa() and sb() are happening at the same time.
- `pa`: push a - take the first element from stack_b and put it on top of stack_a.
- `pb`: push b - take the first element from stack_a and put it on top of stack_b.
- `ra`: rotate a - shift all elements of stack_a up by one. The first element becomes the last one.
- `rb`: rotate b - shift all elements of stack_b up by one. The first element becomes the last one.
- `rr`: rotate both - ra() and rb() are happening at the same time.
- `rra`: reverse rotate a - shift all elements of stack_a down by one. The last element becomes the first one.
- `rrb`: reverse rotate b - shift all elements of stack_b down by one. The last element becomes the first one.
- `rrr`: reverse rotate both - rra() and rrb() are happening at the same time.

![video](https://im.ezgif.com/tmp/ezgif-1-7e39653c68.gif)

## About Bonus

The Bonus is about creating your own checker program, same behavior as "checker_Mac" or "checker_linux". The program should behave like "push_swap", except it should not calculate the best rotations/swapping. Instead, it should wait and read instructions on the standard input, and execute them on the given stack.

If stack_a is sorted and stack_b is empty after executing the instructions, the program must display "OK" on the standard output. In all other cases, it must display "KO". In case of an error, the program must display "Error". The error handling should be the same as "push_swap", including non-integer arguments, arguments that exceed integer limits, duplicates, non-existent instructions, and incorrectly formatted instructions

## Installation

### To execute the *Mandatory Part*, follow the steps below:

1. Compile the program by running the following command:
```bash
$ make
```
2. Finally, execute the program using the following command: 
```bash
$ ./push_swap 3 0 9 1
```
OR 
```bash
$ ./push_swap "3 0 9 1"
```


### To execute the *Bonus Part*, follow the steps below:

1. Compile the bonus by running the following command:
```bash
$ make bonus
```
2. Finally, execute the program using the following command: 
```bash
$ ./push_swap 3 0 9 1 | ./checker 3 0 9 1
```
OR 
```bash
$ ./push_swap "3 0 9 1" | ./checker "3 0 9 1"
```

## Testing

Tester for linux OS (comes with subject):
```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```
Tester for Mac OS (comes with subject):
```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

lfrasson tester:
```bash
$ bash lfrasson_tester.sh
```

Visualizer:
```bash
$ python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`
```

## Resources

- [Algorithm explanations](https://www.programiz.com/dsa/quick-sort)
- [Documentation on push_swap(greedy)](https://velog.io/@yecn/42seoul-%EC%8A%A4%ED%83%9D-2%EA%B0%9C%EB%A1%9C-%EC%A0%95%EB%A0%AC%ED%95%98%EA%B8%B0pushswap)
- [Project subject](https://cdn.intra.42.fr/pdf/pdf/73983/en.subject.pdf)
