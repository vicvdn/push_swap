# push_swap

## Learning ressources

**Algorithms**

- Algorithms : quicksort algorithm explained [https://medium.com/karuna-sehgal/a-quick-explanation-of-quick-sort-7d8e2563629b]

- Articles about approaches of the subject :
  - Turk algorithm : [https://medium.com/@ayogun/push-swap-c1f5d2d41e97]
      * interesting takeout : we should always calculate before rotating because it can allow us to use 1 command instead of 2 (ex rr instead of ra + rb)
  - Stacks divided in chunks : [https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a]
  - Radix Sort (not optimal) : [https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e]
 
**Doubly linked lists**

- Article in French but wel explained : [http://sdz.tdct.org/sdz/les-listes-doublement-chainees-en-langage-c.html]



**My progression:**

- code an atol instead of an atoi to include int min/max and facilitate the parsing
- verify the leak when I test valgrind ./push_swap 214748364 1a 2 ->OK
- code a function to go through the list and check if there are doubles in the data ? or maybe it is easier to do so going through the params at first (therefore no allocation and free is not necessary)
