# Problem
There is a function organized by your college. There are a total of $n$ events $e_1, e_2, \dots, e_n$. You are skilled at all the events and you can win the first prize by just participating in the event.
Let the first prize amount for the events are $p_1, p_2, \dots, p_n$. But there is a problem, the events might be overlapping i.e. two events might be taking place at the same time or one event can be longer and can overlap few other events.
So, the events have waiting times associated with them i.e. $w_1, w_2, \dots, w_n$ i.e. if we participate in event $e_i$, then we cannot participate in the subsequent $w_i$ number of events.
Now, your goal is to attain maximum profit by choosing the events wisely. Hence, solve this problem.

# Algorithm
We notice that if our sequence of events is $e_1, e_2, \dots, e_n$ and we choose an event then the profit can be maximized by simply maximing the profit on the rest of the sequence from which we are allowed to choose next, without worrying about what events we chose upto that point.\
This gives rise to our recursive algorithm. Suppose `find` is a function that takes in the $p_is$  and the $w_is$ and outputs the maximum profit and the optimal set of events that gives rise to the maximum profit. So, our required answer is:
- $profit_max = find((p_1,\dots,p_n) , (w_1,\dots,w_n))$.
- set of events that lies in our optimal choice of events $e_{i_1},\dots,e_{i_k}$.

We state the $i^{th}$ step of recursion below:
- $e_i$ might or might not be present in our optimal set of events.
- Suppose, it is present then the $profit_1 = p_i + find((p_{w_i+1},\dots,p_n) , (w_{w_i+1},\dots,w_n))$
- Suppose, it is not present then the $profit_2 = find((p_{i+1},\dots,p_n) , (w_{i+1},\dots,w_n))$
- Therefore, the $profit_{max} = \max(profit_1, profit_2)$
- If $profit_1 \geq profit_2$, we add $e_i$ to the set of optimal events generated while calculating $profit_1$
- Otherwise, we keep the optimal events generated while calculating $profit_2$
- We return ($profit_{max}$, optimal events)

# Worst Case Complexity
In the worst case we will traverse all the events one by one and at each step we will make two recursive calls which inturn will again move one by one and hence, the first find function will complete in $n$ steps. Now, the result of each intermediate step is saved. Thus, all other find functions will run in $O(1)$ time. Thus, the time complexity is $O(n)$. The space complexity is $O(n)$.

# Implementation
Initialization step:
- A list of $p_is$ and $w_is$.
- start index, which starts at $0$ which is incremented at every step.

Base Case:
- If start index exceeds the length of the $p_is$ list, we return 0.

Implementation Detail:
- We save the values all the intermediate $find((p_{i},\dots,p_n) , (w_{i},\dots,w_n))$, which can be reused as and when required (Dynamic Programming).

Code:
```
def find(prizes, waits, table = None, events = None, start = 0):
    
    # Initializing if None
    if table is None:
        table = dict()
    if events is None:
        events = set()
    
    # Base Case
    if start >= len(prizes):
        return 0, events
    # Table Look-Up
    if start in table:
        return table[start]
    
    # Calculating the profit if `start` indexed event was selected
    start_selected = find(prizes, waits, table, events, start + waits[start] + 1)
    profit_1 = prizes[start] + start_selected[0]
    # Calculating the profit if `start` indexed event was not selected
    start_not_selected = find(prizes, waits, table, events, start + 1)
    profit_2 = start_not_selected[0]
    # Checking if start was included in optimal event set or not
    if profit_1 >= profit_2:
        # If included then append start index to event set 
        events = start_selected[1].copy()
        events.add(start+1)
    else:
        # If not included then copy the event set for the second choice
        events = start_not_selected[1]
        
    # Updating DP Table
    table[start] = (max(profit_1, profit_2), events)   
    return table[start]
```
