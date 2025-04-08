# Get Minimum of stack

## Brute Force
- Create an extra stack name minStack, check data with currentMin value and the push accordingly
- Note that when you push to main stack , you also push to min stack, even pop operation too

## Advanced Stack (Space Complexity: O(n))
- A seperate struct containing pointers to both the stacks, mainstack and minstack
- struct{struct Stack* main; struct Stack* min;};

## Adv Stack, improved SC (O(1))
- We only push to min stack when the value being pushed onto the main stack is less than or equal to the current min value.
- We only pop when value we pop from main stack is equal to the one on the min stack
