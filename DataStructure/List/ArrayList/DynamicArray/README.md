# Dynamic array

| Operations | Time complexity(worst case) |
| :--------: | :-------------------------: |
| Access     | O(1)                        |
| Traverse   | O(n)                        |
| Insert     | O(n)[^amortized_time]       |
| Delete     | O(n)[^amortized_time]       |

## Pros[^dynamic_arraylist_pros_0]

- Accessing and assignment by index is very fast.[^dynamic_arraylist_pros_1]
- Data are located contiguously in memory(spatial locality of reference).[^dynamic_arraylist_pros_2]
- Appending(inserting at the end of array) data is relatively fast. Same performance characteristic as removing objects at the end of the array.
- More flexible due to resizability of array.

## Cons

- Memory space is wasted due to unused space which is reserved for capacity.[^dynamic_arraylist_cons_1]
- Adding or removing is costly because copying occurs frequently.
- Set membership operation takes O(n) time.
- Unpredictable performance when insertion or removal requires resizing.
- In a highly fragmented memory region, it may be expensive or impossible to find contiguous space for a large dynamic array.

## Usage
- When the maximum logical size is unknown, or difficult to calculate, before the array is allocated.
- When it is considered that a maximum logical size given by a specification is likely to change.
- When the amortized cost of resizing a dynamic array does not significantly affect performance or responsiveness.

# References

- 윤성우, <윤성우의 열혈 자료구조>
- [isaaccomputerscience][reference_link_0]
- [Wikipedia][reference_link_1]
- https://stackoverflow.com/questions/35401508/dynamic-array-vs-linked-list-in-c

[reference_link_0]: <https://isaaccomputerscience.org/concepts/dsa_datastruct_list?examBoard=all&stage=all>
[reference_link_1]: <https://en.wikipedia.org/wiki/Dynamic_array#cite_note-27>

[^amortized_time]: It takes O(n) at head but amortized O(1) at tail. In other words, it takes O(1) if capacity isn't reached. However, when capacity has been reached, resizing is needed and it takes O(n).
[^dynamic_arraylist_pros_0]: In languages like Python or Java that enforce reference semantics, the dynamic array generally will not store the actual data, but rather it will store references to the data that resides in other areas of memory. In this case, accessing items in the array sequentially will actually involve accessing multiple non-contiguous areas of memory, so the many advantages of the cache-friendliness of this data structure are lost.
[^dynamic_arraylist_pros_1]: Because access by index is internally [address of first member] + [offset] as well as good cache performance.
[^dynamic_arraylist_pros_2]: It benefits from processor caching. Furthermore, it needs only simple calculation to find out the mid-point of array so that allows you to implement efficient sorting and searching algorithms, for example a binary seach or merge sort.
[^dynamic_arraylist_cons_1]: Because dynamic array implementation usually allocates more memory than necessary(since resize is a very slow operation).
