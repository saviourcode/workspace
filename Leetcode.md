# Reverse a LinkedList
1. Requirements :
    1. Three Variables: prev_ptr, current_ptr, next_ptr
    2. Break the link of current_ptr.next, and make it point to prev_ptr;
2. Pseudo
```c
Node prev_ptr = NULL;

while(current_ptr != NULL)
{
    Node next_ptr = current_ptr.next;
    head.next = prev;
    prev = head;
    current_ptr = next_ptr;
}
```
Result is stored in prev_ptr;

3. Time Complexity : O(n);
    Space Complexity: O(1);