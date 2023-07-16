# Circular linked list

> "In the last node of a linked list, the link field often contains a null reference, a special value is used to indicate the lack of further nodes. A less common convention is to make it point to the first node of the list; in that case, the list is said to be 'circular' or 'circularly linked'"[^circular_linked_list_definition]

## Pros

- Any node can be a starting point. We can traverse the whole list by starting from any point. We just need to stop when the first visited node is visited again. 
- Useful for implementation of a queue. Unlike this implementation, we don’t need to maintain two pointers for front and rear if we use a circular linked list. We can maintain a pointer to the last inserted node and the front can always be obtained as next of last.
- Useful in applications to repeatedly go around the list. For example, when multiple applications are running on a PC, it is common for the operating system to put the running applications on a list and then cycle through them, giving each of them a slice of time to execute, and then making them wait while the CPU is given to another application. It is convenient for the operating system to use a circular list so that when it reaches the end of the list it can cycle around to the front of the list.
- Circular doubly linked list is used for the implementation of advanced data structures like the Fibonacci Heap.
- Implementing a circular linked list can be relatively easy compared to other more complex data structures like trees or graphs.

## Cons

- Compared to singly linked lists, circular lists are more complex.
- Reversing a circular list is more complicated than singly or doubly reversing a circular list.
- It is possible for the code to go into an infinite loop if it is not handled carefully.
- It is harder to find the end of the list and control the loop.
- Although circular linked lists can be efficient in certain applications, their performance can be slower than other data structures in certain cases, such as when the list needs to be sorted or searched.

## Usage

- Multiplayer games use this to give each player a chance to play.
- Used to organize multiple running applications on an operating system. These applications are iterated over by the OS.
- Used in resource allocation problems.
- Used to implement circular buffers.

### References

- 윤성우, <윤성우의 열혈 자료구조>
- [Wikipedia][reference_link_0]
- [GeeksforGeeks][reference_link_1]

[reference_link_0]: https://en.wikipedia.org/wiki/Linked_list
[reference_link_1]: https://www.geeksforgeeks.org/circular-linked-list/

[^circular_linked_list_definition]: https://en.wikipedia.org/wiki/Linked_list
