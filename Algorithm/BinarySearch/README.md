# Binary search

- "...search algorithm that finds the position of a target value within a sorted array. Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array."[^binary_search_definition]

## Performance

| Complexity       | Big-O       | Iterations                         |
| :--------------- | :---------- | :--------------------------------: |
| Time(worst case) | O(logn)     | floor(log<sub>2</sub>n + 1)[^iter] |
| Space            | O(1)        | -                                  |

[![example image](./images/binary_search_example.png "Image from Wikipedia")]([https://en.khanacademy.org/computing/computer-science/algorithms/asymptotic-notation/a/asymptotic-notation](https://en.wikipedia.org/wiki/Binary_search_algorithm#Procedure_for_finding_the_leftmost_element))

- In the worst case, binary search makes floor(log<sub>2</sub>n + 1) iterations of the comparison loop. This is because the worst case is reached when the search reaches the deepest level of the tree, and there are always floor(log<sub>2</sub>n + 1) levels in the tree for any binary search.
- The worst case may also be reached when the target element is not in the array. If n is one less than a power of two, then this is always the case. Otherwise, the search may perform floor(log<sub>2</sub>n + 1) iterations if the search reaches the deepest level of the tree. However, it may make floor(log<sub>2</sub>n) iterations, which is one less than the worst case, if the search ends at the second-deepest level of the tree.
- On a sorted array, binary search can jump to distant memory locations if the array is large, unlike algorithms(such as linear search and linear probing in hash tables) which access elements in sequence. This adds slightly to the running time of binary search for large arrays on most systems.
- Binary search is faster than linear search except for small arrays.

## Note

- The array must be sorted to apply binary search.
- Sorted arrays with binary search are a very inefficient solution when insertion and deletion operations are interleaved with retrieval, taking log n time for each such operation. In addition, sorted arrays can complicate memory use especially when elements are often inserted into the array. There are other data structures that support much more efficient insertion and deletion. Binary search can be used to perform exact matching and set membership (determining whether a target value is in a collection of values). There are data structures that support faster exact matching and set membership. However, unlike many other searching schemes, binary search can be used for efficient <b>approximate matching</b>, usually performing such matches in log<sub>2</sub>n time regardless of the type or structure of the values themselves. In addition, there are some operations, like finding the smallest and largest element, that can be performed efficiently on a sorted array.
- Binary search can be used for efficient approximate matching like query for rank[^rank_description], predecessor[^predecessor_description], successor[^successor_description], nearest neighbours and range[^range_description].

### References

- https://en.wikipedia.org/wiki/Binary_search_algorithm

[^rank_description]: The number of smaller elements. Rank queries can be performed with the procedure for finding the leftmost element.
[^predecessor_description]: Predecessor queries can be performed with rank queries. If the rank of the target value is r, its predecessor is r − 1.
[^successor_description]: For successor queries, the procedure for finding the rightmost element can be used. If the result of running the procedure for the target value is r, then the successor of the target value is r+1.
[^range_description]: Once the ranks of the two values are known, the number of elements greater than or equal to the first value and less than the second is the difference of the two ranks.
[^binary_search_definition]: https://en.wikipedia.org/wiki/Binary_search_algorithm
[^iter]: n * (1/2)^k = 1
