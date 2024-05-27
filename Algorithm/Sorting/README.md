## Performance

| Sorting algorithm  | Comparision(worst, best)                   | Assignment(worst, best)                    | Memory              | Stability[^def_stability] |
| :----------------- | :----------------------------------------- | :----------------------------------------- | :------------------ | :------------------------ |
| Selection          | O(n<sup>2</sup>), O(n<sup>2</sup>)         | O(n), O(n)                                 | O(1)                | X                         |
| Bubble             | O(n<sup>2</sup>), O(n<sup>2</sup>)         | O(n<sup>2</sup>), O(1)                     | O(1)                | O                         |
| Insertion          | O(n<sup>2</sup>), O(n)                     | O(n<sup>2</sup>), O(n)                     | O(1)                | O                         |
| Heap               | O(nlog<sub>2</sub>n), O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n), O(nlog<sub>2</sub>n) | O(1)                | X                         |
| Merge              | O(nlog<sub>2</sub>n), O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n), O(nlog<sub>2</sub>n) | O(n)                | O                         |
| Quick              | O(nlog<sub>2</sub>n), O(n<sup>2</sup>)     | ?                                          | O(log<sub>2</sub>n) | X                         |

## Note

- Selection sort may seem to perform better than buble sort in worst case. However, it's meaningless to compare those because bubble sort makes no assignment in best case. Furthermore, input data isn't always arranged worstly.

- Bubble sort can be faster in best case by implementing with a boolean flag to check if the input data is sorted every for-loop and exits early before all for-loops are performed. This kind of optimization cannot be applied to selection sort.

- Swap in bubble sort performs 3 assignments, on the other hand, shift in insertion sort performs 1 assignment.

- Insertion sort performs fast when the most of input data is already sorted.

- Merge sort of array based implementation requires extra memories, but it's not applied to linked list based implementation.

- In worst case, assignment operation is performed 3 times more than comparison operation because it requires 3 assignments to swap elements. In Big-O notation, this amount of difference is ignored.

- Quick sort is usually done in-place with O(log n) stack space.

### Reference

- 윤성우, <윤성우의 열혈 자료구조>
- 홍정모 연구소, <자료구조 압축코스>

[^def_stability]: "A sorting algorithm is stable if it keeps the relative order of equal elements." - https://www.baeldung.com/cs/selection-sort-stable
