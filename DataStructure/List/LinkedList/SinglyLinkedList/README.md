# Singly linked list

> "A singly linked list is a special type of linked list in which each node has only one link that points to the next node in the linked list."[^singly_linked_list_definition]

## Cons

- Accessing an element in a singly linked list requires traversing the list from the head to the desired node, making it slow for random access operations compared to arrays.
- It requires additional memory for storing the pointers to the next node in each element, resulting in increased memory overhead compared to arrays.
- It's is vulnerable to data loss if a node’s next pointer is lost or corrupted, as there is no way to traverse the list and access other elements.
- It's is not suitable for parallel processing, as updating a node requires exclusive access to its next pointer, which cannot be easily done in a parallel environment.
- It does not support backward traversing.

## Usage

- Used to implement memory pools, in which memory is allocated and deallocated as needed.
- Used to implement linked list in databases, allowing for fast insertion and deletion operations.
- Used to efficiently represent polynomials and sparse matrices, where most elements are zero.
- Used in operating systems for tasks such as scheduling processes and managing system resources.

## Note

- If you want to retain the order of added elements in singly linked list, new node must be added to tail and it requires a pointer to tail.[^pointer_to_tail]
- In singly linked list, dummy node makes it possible to handle the first node(after dummy node) consistently with the following nodes.[^dummy_node_1] Furthermore, it's comfortable to remove an element at certain index by tracking the previous node as well as the current node.[^dummy_node_2]

### References

- 윤성우, <윤성우의 열혈 자료구조>
- [GeeksforGeeks](https://www.geeksforgeeks.org/singly-linked-list-definition-meaning-dsa/)

[^singly_linked_list_definition]: https://www.geeksforgeeks.org/singly-linked-list-definition-meaning-dsa/
[^pointer_to_tail]: Actually, list doesn't have to ensure the order of added elements.
[^dummy_node_1]: Because a pointer to head always points to dummy node, the node which is added firstly would be located after dummy node.
[^dummy_node_2]: Because dummy node can be tracked as a previous node for the first element.
