# 0x018. C- Stacks, Queues - LIFO, FIFO
- Low-level programming - Data structures and algorithms.
Group project (Susan Su and Angie Delgado)

- Important questions to answer before working on this project.\n
What do LIFO and FIFO mean?
LIFO = Last In First Out
FIFO = First In First Out
- What is a stack, and when to use it?
A stack is a data structure which follows a particular order. The order may be
LIFO of FIFO.
- What is a queue, and when to use it?
A queue is a data structute which also follows a particular order of FIFO.
- What are the common implementations of stack and queues?
The most common implementation of stack and queues when using recursive
algorithm.
- What are the most common use cases of stacks and queues?
A stack is used when you want to acquire something in the order that you put it
in or LIFO (last in, last out).
A queue is used when you want to acquire something in order of first in
last out FIFO (first in, first out).
- What is the proper way to use global variables?
A global variable is best used when the scope of it is very small.

This project is used as an interpreter for Monty ByteCodes files.
These files usually have the .m extension.

#### Task 0.
- Push pushes an element to the stack.
- Pall prints all the values on the stack, starting from the top of the stack.
#### Task 1.
- Pint - the value at the top of the stack, followed by a new line.
#### Task 2.
- Pop remove the top element of the stack.
#### Task 3.
- Swap - swaps the top two elemets of the stack.
#### Task 4.
- Add - adds the top two elements of the stack.
#### Task 5.
- Nop - implements the nop opcode, which does nothing.
#### Task 6.
- Sub - subtracts the top element of the stack from the second top element of
the stack.
#### Task 7.
- Div - divides the second top element of the stack by the top element of the
stack.
#### Task 8.
- Mul - multiplies the second top element of the stack with the top element of
the stack.
#### Task 9.
- Mod - computes the rest of the division of the second top element of the stack
by the top element of the stack.
#### Task 10.
- Comments - When the first non-space character of a line is #, treat this line
as a comment (don’t do anything).
#### Task 11.
- Pchar - prints the char at the top of the stack, followed by a new line.
#### Task 12.