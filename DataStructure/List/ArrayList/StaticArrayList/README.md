# Static array list

| Operations | Time complexity(worst case) |
| :--------: | :-------------------------: |
| Access     | O(1)                        |
| Traverse   | O(n)                        |
| Insert     | O(n)[^insert_delete_time]   |
| Delete     | O(n)[^insert_delete_time]   |

## Pros

- Accessing and assignment by index is very fast.[^static_arraylist_pros_0]
- Data are located contiguously in memory(spatial locality of reference).[^static_arraylist_pros_1]
- Appending(inserting at the end of array) data is relatively fast. Same performance characteristic as removing objects at the end of the array.

## Cons

- List capacity must be specified at allocation.[^static_arraylist_cons_0]
- Memory space is wasted due to unused space which is reserved for capacity.
- Adding or removing is costly because copying occurs frequently.[^static_arraylist_cons_1]
- Set membership operation takes O(n) time.

## Usage

- When the maximum logical size is fixed(e.g. by specification), or can be calculated before the array is allocated.

# References

- 윤성우, <윤성우의 열혈 자료구조>
- [isaaccomputerscience][reference_link_0]
- [Wikipedia][reference_link_1]
- https://stackoverflow.com/questions/35401508/dynamic-array-vs-linked-list-in-c

[reference_link_0]: <https://isaaccomputerscience.org/concepts/dsa_datastruct_list?examBoard=all&stage=all>
[reference_link_1]: <https://en.wikipedia.org/wiki/Dynamic_array#cite_note-27>

[^insert_delete_time]: It takes O(1) at tail.
[^static_arraylist_pros_0]: Because access by index is internally [address of first member] + [offset] as well as good cache performance.
[^static_arraylist_pros_1]: It benefits from processor caching. Furthermore, it needs only simple calculation to find out the mid-point of array so that allows you to implement efficient sorting and searching algorithms, for example a binary seach or merge sort.
[^static_arraylist_pros_2]: When capacity has been reached, resizing is needed and it takes O(n).
[^static_arraylist_cons_0]: In other words, capacity is fixed and data cannot be added when array is full.
[^static_arraylist_cons_1]: Whenever new data is added or removed at certain index, all data whose index is bigger must be moved by one. Therefore, performance is especially poor when the operations occured near the start of the array.
