# Linked list

> "Linked list is a linear data structure, in which elements are not stored at a contiguous location, rather they are linked using pointers. Linked list forms a series of connected nodes, where each node stores the data and the address of the next node."[^linked_list_definition]

## Pros
  
- **Dynamic data structure**: The size of memory can be allocated or de-allocated at run time based on the operation insertion or deletion.
- **Ease of insertion/deletion**: The insertion and deletion of elements are simpler than arrays since no elements need to be shifted after insertion and deletion, Just the address needed to be updated.
- **Efficient memory utilization**: As we know Linked List is a dynamic data structure the size increases or decreases as per the requirement so this avoids the wastage of memory. 
- **Implementation**: Various advanced data structures can be implemented using a linked list like a stack, queue, graph, hash maps, etc.

## Cons

- **Random access**: Unlike arrays, linked lists do not allow direct access to elements by index. Traversal is required to reach a specific node.
- **Extra memory**: Linked lists require additional memory for storing the pointers, compared to arrays.

### References

- 윤성우, <윤성우의 열혈 자료구조>
- [GeeksforGeeks](https://www.geeksforgeeks.org/what-is-linked-list/)

[^linked_list_definition]: <https://www.geeksforgeeks.org/what-is-linked-list/>
