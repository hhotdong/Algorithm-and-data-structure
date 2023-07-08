# Binary search

- "...search algorithm that finds the position of a target value within a sorted array. Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array."[^binary_search_definition]

| Complexity       | Big-O       | Iterations                         |
| :--------------- | :---------- | :--------------------------------: |
| Time(worst case) | O(logn)     | floor(log<sub>2</sub>n + 1)[^iter] |
| Space            | O(1)        | -                                  |

## Note

- The array must be sorted to apply binary search.
- Binary search is faster than linear search except for small arrays.
- Binary search can be used for efficient approximate matching like query for rank[^rank_description], predecessor[^predecessor_description], successor[^successor_description], nearest neighbours and range[^range_description].

### References

- https://en.wikipedia.org/wiki/Binary_search_algorithm

[^rank_description]: The number of smaller elements. Rank queries can be performed with the procedure for finding the leftmost element.
[^predecessor_description]: Predecessor queries can be performed with rank queries. If the rank of the target value is r, its predecessor is r − 1.
[^successor_description]: For successor queries, the procedure for finding the rightmost element can be used. If the result of running the procedure for the target value is r, then the successor of the target value is r+1.
[^range_description]: Once the ranks of the two values are known, the number of elements greater than or equal to the first value and less than the second is the difference of the two ranks.
[^binary_search_definition]: https://en.wikipedia.org/wiki/Binary_search_algorithm
[^iter]: n * (1/2)^k = 1
