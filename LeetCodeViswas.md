# Reverse a linked list
1. Use a temp variable for head.next
2. Idea : Break the heads pointer and point to previous
3. Sliding head and prev

```java
while (head!= null){
  temp = head.next;
  head.next = prev;
  prev = head;
  head = temp;
}
```
Time complexity : O(n)
# Palindrome


For left update max and for 
right update min on the right




