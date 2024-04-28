# Heap

> "A Heap is a complete binary tree data structure that satisfies the heap property: for every node, the value of its children is less than or equal to its own value. Heaps are usually used to implement priority queues, where the smallest (or largest) element is always at the root of the tree."[^GeeksforGeeks]

## ADT

- Insert[^add]
- Extract[^extract]
- Heapify[^heapify]

## References

- 윤성우, <윤성우의 열혈 자료구조>
- [GeeksForGeeks](https://www.geeksforgeeks.org/heap-data-structure/)

[^GeeksforGeeks]: https://www.geeksforgeeks.org/heap-data-structure/
[^add]: Adds a new element to the heap while maintaining the heap property. When inserting, new element is added to the last position of heap. Then compare priority with the parent node and swap each other if new node has higher priority. Repeat this process until new node is located properly in terms of priority.
[^extract]: Removes the maximum or minimum element from the heap and returns it. After extracting root node, the last node(located in the rightest position of the last level of complete binary tree) is swapped with the root node and then keep comparing and swapping with the children nodes until proper location found.
[^heapify]: Converts an arbitrary binary tree into a heap.
