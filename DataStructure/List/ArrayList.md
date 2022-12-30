# Static array list

| Operations  | Time complexity |
| :---------: | :-------------: |
| Access      | O(1)            |
| Add         | O(n)            |
| Remove      | O(n)            |

## Pros {#static-array-list-pros}

- Accessing and assignment by index is very fast.[^static_arraylist_pros_1]
- Data are located contiguously in memory.[^static_arraylist_pros_2]

## Cons

- List capacity must be specified at allocation.[^static_arraylist_cons_1]
- Adding or removing is costly because copying occurs frequently.[^static_arraylist_cons_2]

# Dynamic array

| Operations  | Time complexity |
| :---------: | :-------------: |
| Access      | O(1)            |
| Add         | O(n)            |
| Remove      | O(n)            |

## Pros

- All the [pros of static array list](#static-array-list-pros) included.
- Appending(inserting at the end of array) data is relatively fast(amortized O(1)[^dynamic_arraylist_pros_1]). Same performance characteristic as removing objects at the end of the array.

## Cons

- 

### References

- 윤성우, <윤성우의 열혈 자료구조>
- [isaaccomputerscience][reference_link_1]
- https://stackoverflow.com/questions/35401508/dynamic-array-vs-linked-list-in-c

[reference_link_1]: <https://isaaccomputerscience.org/concepts/dsa_datastruct_list?examBoard=all&stage=all>

[^static_arraylist_pros_1]: Access by index is internally [address of first member] + [offset].
[^static_arraylist_pros_2]: It benefits from processor caching. Furthermore, it needs only simple calculation to find out the mid-point of array so that allows you to implement efficient sorting and searching algorithms, for example a binary seach or merge sort.
[^static_arraylist_cons_1]: In other words, capacity is fixed and data cannot be added when array is full. It also means that memory space is wasted unless array is full.
[^static_arraylist_cons_2]: Whenever new data is added or removed at certain index, all data whose index is bigger must be moved by one.
[^dynamic_arraylist_pros_1]: When capacity has been reached, resizing is needed and it takes O(n).
