# Linked list

> "Linked list is a linear data structure, in which elements are not stored at a contiguous location, rather they are linked using pointers. Linked list forms a series of connected nodes, where each node stores the data and the address of the next node."[^linked_list_definition]

## Pros
  
- The size of memory can be allocated or de-allocated at run time based on the operation insertion or deletion. Therefore linked list is useful when the size of the list is not known in advance.
- The insertion and deletion of elements are simpler than arrays since no elements need to be shifted after insertion and deletion, Just the address needed to be updated.
- As we know Linked List is a dynamic data structure the size increases or decreases as per the requirement so this avoids the wastage of memory. 
- Various advanced data structures can be implemented using a linked list like a stack, queue, graph, hash maps, etc.

## Cons
- Unlike array, linked list do not allow direct access to elements by index. Traversal is required to reach a specific node.
- Linked list requires additional memory for storing the pointers, compared to arrays.

### References

- 윤성우, <윤성우의 열혈 자료구조>
- [GeeksforGeeks](https://www.geeksforgeeks.org/what-is-linked-list/)

[^linked_list_definition]: <https://www.geeksforgeeks.org/what-is-linked-list/>
