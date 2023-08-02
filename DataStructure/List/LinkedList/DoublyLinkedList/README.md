# Doubly linked list

> "A doubly linked list (DLL) is a special type of linked list in which each node contains a pointer to the previous node as well as the next node of the linked list."[^doubly_linked_list_definition]

## Pros

- Doubly linked list can be traversed in both forward and backward directions. Due to this, insertion and deletion operation can be done efficiently because the previous or next node is given which we need for keeping it as linked list.

## Cons

- Every node requires extra memory space for a previous pointer in addition to a next pointer.[^xor_linked_list]

## Usage

- Many modern operating systems use doubly linked lists to maintain references to active processes, threads, and other dynamic objects.
- Used by various applications to maintain undo and redo functionalities. 

### References

- 윤성우, <윤성우의 열혈 자료구조>
- [Wikipedia][reference_0]
- [GeeksForGeeks][reference_1]

[reference_0]: https://en.wikipedia.org/wiki/Linked_list#cite_note-4
[reference_1]: https://www.geeksforgeeks.org/data-structures/linked-list/doubly-linked-list/

[^doubly_linked_list_definition]: https://www.geeksforgeeks.org/data-structures/linked-list/doubly-linked-list/
[^xor_linked_list]: It is possible to implement doubly linked list with a single pointer by using XOR-linking.
