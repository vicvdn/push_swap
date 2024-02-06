# push_swap

## Learning ressources

**Algorithms**

- [Algorithms : quicksort algorithm explained](https://medium.com/karuna-sehgal/a-quick-explanation-of-quick-sort-7d8e2563629b)

- Articles about approaches of the subject :
  - [Turk algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
      * interesting takeout : we should always calculate before rotating because it can allow us to use 1 command instead of 2 (ex rr instead of ra + rb)
  - [Stacks divided in chunks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
  - [Radix Sort (not optimal)](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
 
**Doubly linked lists**

- [French article on doubly linked lists](http://sdz.tdct.org/sdz/les-listes-doublement-chainees-en-langage-c.html)

## How I approached the subject

I decided to go with the mechanical turk sorting algorithm (article linked before), knowing that it would be efficient enough to validate the project with 100/100. So how did I proceed?

- **first, I created a structure "data" containing both of my stacks** (empty then) among other things. 

- **Then I implemented the parsing** : dealing with both the case where ac = 2 and the second argument contains all the numbers to be sorted and were ac > 2 (no split needed then). I checked that I didn't have an overflow when entering a number superior to int max or inferior to int min by checking the length of the char * that is each number before going through the atol function (if ft_strlen(av[i]) > 11 -> we return an error). And checked for doubles, or other parsing errors mentionned in the subject.

- **then I filled my stack_a** with the parsed values (I created a new node for each value satisfying my parsing checks, if I encountered an error, I freed everything and returned an error). So parsing and filling of stack_a happened at the same time in a way.

- **then I coded the algorithm** :
    - I dissociated the cases were I had only 1, 2 or 3 values. I created a "mini" sort for the case where I only had three values to sort (left) in my stack_a after checking each time that the values given weren't already sorted (if so I return nothing and free everything that has been allocated).
    - If stack_a->len > 3: another dissociation of cases
        - if ```c len == 4``` => I push the first value of stack_a to stack_b, then minisort stack_a and insert back into             the right place the value in stack_b;
        - if ```c len > 4``` => I push the 2 top values of stack_a to stack_b and then look at the number of values in stack_a.
        - if ```c stack_a->len > 3``` after pushing twice to b then I'm going to calculate the cost of each node of stack_a to be inserted into the right place in stack_b and then push the "cheapest node" until I have 3 values left in stack_a to minisort.

## My progression:

First we focus on the parsing and the creation of the stack_a. Stack_b is created as well but not filled untill we start actually sorting the data.

- code an atol instead of an atoi to include int min/max and facilitate the parsing
- verify the leak when I test valgrind ./push_swap 214748364 1a 2 ->OK
- code a function to go through the params and check for doubles before the parsing one that allocates (therefore no allocation and free if not necessary)

Then we can focus on coding the various operations we are allowed to use: 
- sa
- sb
- ss
- pa
- pb
- ra
- rb
- rr
- rra
- rrb
- rrr

Cases to handle:
- parsing cases : OK
- 1 value as an arg
- 2 values as args
- 3 values as args : OK
- more than 3 values
