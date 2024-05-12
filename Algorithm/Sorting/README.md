## Performance

| Sorting algorithm  | Comparision(worst, best)            | Assignment(worst, best) | Stability[^def_stability] |
| :----------------- | :---------------------------------- | :---------------------- | :------------------------ |
| Selection          | O(n<sup>2</sup>), O(n<sup>2</sup>)  | O(n), O(n)              | X                         |
| Bubble             | O(n<sup>2</sup>), O(n<sup>2</sup>)  | O(n<sup>2</sup>), O(1)  | O                         |
| Insertion          | O(n<sup>2</sup>), O(n)              | O(n<sup>2</sup>), O(n)  | O                         |

## Note

- Selection sort may seem to perform better than buble sort in worst case. However, it's meaningless to compare those because bubble sort makes no assignment in best case. Furthermore, input data isn't always arranged worstly.

- Bubble sort can be faster in best case by implementing with a boolean flag to check if the input data is sorted every for-loop and exits early before all for-loops are performed. This kind of optimization cannot be applied to selection sort.

- Insertion sort performs fast when the most of input data is already sorted.

- In worst case, assignment operation is performed 3 times more than comparison operation because it requires 3 assignments to swap elements. In Big-O notation, this amount of difference is ignored.

?? 버블정렬의 swap은 3회의 대입연산을 수행하는데 비해 삽입정렬의 shift는 1회의 대입연산을 수행한다.

### Reference

- 윤성우, <윤성우의 열혈 자료구조>
- 홍정모 연구소, <자료구조 압축코스>

[^def_stability]: "A sorting algorithm is stable if it keeps the relative order of equal elements." - https://www.baeldung.com/cs/selection-sort-stable
