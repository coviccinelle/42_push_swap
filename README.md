#  🔢 **Push_swap** 🛃 - _Because Swap_push isn't as natural_
![til](https://github.com/coviccinelle/42_push_swap/blob/main/push_swap.gif)

## Summary
This project involves sorting data on two stacks using a limited set of instructions with the goal of achieving the lowest number of actions. The main program, push_swap, must calculate and display the smallest program, consisting of Push_swap language instructions, to sort the integers received as arguments.


![til](https://github.com/coviccinelle/42_push_swap/blob/main/push_swap_visualize.gif)

### Contents
1. [Introduction](#introduction)
2. [Objectives](#objectives)
3. [Common Instructions](#common-instructions)
4. [Mandatory Part](#mandatory-part)
   - [Rules](#the-rules)
   - [Example](#example)
   - [The "push_swap" program](#the-push_swap-program)

## Introduction
The Push_swap project is a straightforward algorithm project where the goal is to sort data using two stacks and a set of instructions.

## Objectives
The learning objectives include rigor, the use of C, and understanding basic algorithms, focusing on their complexity.

## Common Instructions
- Project must be written in C.
- Compliance with the Norm.
- No unexpected exits or memory leaks.
- Submission of a Makefile.
- Separate bonus rule in Makefile for bonus files/functions.
- Use of libft is allowed.

## Mandatory Part

### The Rules
- Two stacks named a and b.
- Stack a contains a random set of negative and/or positive numbers.
- Stack b is initially empty.
- Sort numbers in ascending order in stack a using specific operations.

### Example
An example illustrates the effect of some instructions on sorting a random list of integers using both stacks.
![image](https://github.com/coviccinelle/42_push_swap/assets/51762886/03f1c42c-cd27-44ea-b571-82ea4e81368d)


### The "push_swap" program

![image](https://github.com/coviccinelle/42_push_swap/assets/51762886/6c3b0ff3-0b0d-483d-8944-7176b77fd3bf)

- Program name: push_swap
- Turn in files: Makefile, *.h, *.c
- Arguments: stack a (list of integers)
- External functs.: read, write, malloc, free, exit, ft_printf (or equivalent)
- Libft authorized: Yes
- Description: Sort stacks with the lowest possible number of operations.

![image](https://github.com/coviccinelle/42_push_swap/assets/51762886/803d89b0-797a-4177-9e64-bd95ef22d8d6)

*For detailed requirements and examples, refer to the project document.*

**Note:** A provided checker program is used to validate the correctness of push_swap's output.

```bash
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
$>
