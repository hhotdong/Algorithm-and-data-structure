# Singly linked list

## Pros

- 

## Cons

- 

## Used when

- 

## Note

- Linked list is useful when the size of the list is not known in advance.[^linkelist_pros_1]
- If you want to retain the order of added elements in singly linked list, new node must be added to tail and it requires a pointer to tail.[^pointer_to_tail]
- Dummy node makes it possible to handle the first node(after dummy node) consistently with the following nodes.[^dummy_node]

### References

- 윤성우, <윤성우의 열혈 자료구조>
- [isaaccomputerscience][reference_link_1]

[reference_link_1]: <https://isaaccomputerscience.org/concepts/dsa_datastruct_list?examBoard=all&stage=all>

[^linkelist_pros_1]: It's because the cost of adding/removing is low.
[^pointer_to_tail]: Actually, list doesn't have to ensure the order of added elements.
[^dummy_node]: Because a pointer to head always points to dummy node, the node which is added firstly would be located after dummy node.
