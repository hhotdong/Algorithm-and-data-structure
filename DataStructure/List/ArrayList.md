# Static array list

| Operations | Time complexity |
| :--------: | :-------------: |
| Access     | O(1)            |
| Add/Remove | O(n)            |

## Pros

- Accessing and assignment by index is very fast.[^static_arraylist_pros_0]
- Data are located contiguously in memory(spatial locality of reference).[^static_arraylist_pros_1]

## Cons

- List capacity must be specified at allocation.[^static_arraylist_cons_0]
- Memory space is wasted due to unused space which is reserved for capacity.[^static_arraylist_cons_1]
- Adding or removing is costly because copying occurs frequently.[^static_arraylist_cons_2]

## Used when

- the maximum logical size is fixed (e.g. by specification), or can be calculated before the array is allocated.

# Dynamic array

| Operations       | Time complexity |
| :--------------: | :-------------: |
| Access           | O(1)            |
| Add/Remove       | O(n)            |
| Add/Remove first | O(n)            |
| Add/Remove last  | amortized O(1)  |

## Pros

- All the [pros of static array list](#pros) included.[^dynamic_arraylist_pros_0]
- Appending(inserting at the end of array) data is relatively fast(amortized O(1)[^dynamic_arraylist_pros_1]). Same performance characteristic as removing objects at the end of the array.

## Cons

- Memory space is wasted due to unused space which is reserved for capacity.
- Adding or removing is costly because copying occurs frequently.
- Unpredictable performance when insertion or removal requires resizing.
- In a highly fragmented memory region, it may be expensive or impossible to find contiguous space for a large dynamic array.

## Used when
- the maximum logical size is unknown, or difficult to calculate, before the array is allocated.
- it is considered that a maximum logical size given by a specification is likely to change.
- the amortized cost of resizing a dynamic array does not significantly affect performance or responsiveness.

# References

- 윤성우, <윤성우의 열혈 자료구조>
- [isaaccomputerscience][reference_link_0]
- [Wikipedia][reference_link_1]
- https://stackoverflow.com/questions/35401508/dynamic-array-vs-linked-list-in-c

[reference_link_0]: <https://isaaccomputerscience.org/concepts/dsa_datastruct_list?examBoard=all&stage=all>
[reference_link_1]: <https://en.wikipedia.org/wiki/Dynamic_array#cite_note-27>

[^static_arraylist_pros_0]: Because access by index is internally [address of first member] + [offset] as well as good cache performance.
[^static_arraylist_pros_1]: It benefits from processor caching. Furthermore, it needs only simple calculation to find out the mid-point of array so that allows you to implement efficient sorting and searching algorithms, for example a binary seach or merge sort.
[^static_arraylist_cons_0]: In other words, capacity is fixed and data cannot be added when array is full.
[^static_arraylist_cons_1]: Because dynamic array implementation usually allocates more memory than necessary(since resize is a very slow operation).
[^static_arraylist_cons_2]: Whenever new data is added or removed at certain index, all data whose index is bigger must be moved by one. Therefore, performance is especially poor when the operations occured near the start of the array.
[^dynamic_arraylist_pros_0]: However, in languages like Python or Java that enforce reference semantics, the dynamic array generally will not store the actual data, but rather it will store references to the data that resides in other areas of memory. In this case, accessing items in the array sequentially will actually involve accessing multiple non-contiguous areas of memory, so the many advantages of the cache-friendliness of this data structure are lost.
[^dynamic_arraylist_pros_1]: When capacity has been reached, resizing is needed and it takes O(n).
