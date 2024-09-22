# Heap

> "A Heap is a complete binary tree data structure that satisfies the heap property: for every node, the value of its children is less than or equal to its own value. Heaps are usually used to implement priority queues, where the smallest (or largest) element is always at the root of the tree."[^GeeksforGeeks]

## ADT

- Insert[^add]
- Extract[^extract]
- Heapify[^heapify]

## Notes

- Heap can be implemented on either array based or linked list based. Given a node in heap, it's easy to find both parent and children node in array based heap unlike linked list based heap, where finding parent isn't easy. Therefore, removing heap element can be easily implemented in array based heap.

- In array based heap, it's comfortable to make the first element at index 0 empty because it makes indexing of parent, children a little bit more  easier to calculate.[^first_element_empty]

```cpp
    (parent index) = (left child index) / 2  // Note: Dividing with truncatation towards zero.
    (left child index) = (current index) * 2
    (right child index) = (current index) * 2 + 1
```

- Heap can be said to be loosely sorted because it compares and sorts elements only for keeping heap property.

## References

- 윤성우, <윤성우의 열혈 자료구조>
- 홍정모 연구소, <자료구조 압축코스>
- [GeeksForGeeks](https://www.geeksforgeeks.org/heap-data-structure/)

[^GeeksforGeeks]: https://www.geeksforgeeks.org/heap-data-structure/
[^add]: Adds a new element to the heap while maintaining the heap property. When inserting, new element is added to the last position of heap. Then compare priority with the parent node and swap each other if new node has higher priority. Repeat this process until new node is located properly in terms of priority.
[^extract]: Removes the root element(maximum or minimum) of the heap and returns it. After extracting root node, the last node(located in the rightest position of the last level of complete binary tree) is swapped with the root node and then keep comparing and swapping with the children nodes until proper location found.
[^heapify]: Converts an arbitrary binary tree into a heap.
[^first_element_empty]: https://stackoverflow.com/questions/22900388/why-in-a-heap-implemented-by-array-the-index-0-is-left-unused
