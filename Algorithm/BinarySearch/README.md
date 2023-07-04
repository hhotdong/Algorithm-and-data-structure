# Binary search

- "...search algorithm that finds the position of a target value within a sorted array. Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array."[^binary_search_definition]

| Complexity       | Big-O       | Iterations                         |
| :--------------- | :---------- | :--------------------------------: |
| Time(worst case) | O(logn)     | floor(log<sub>2</sub>n + 1)[^iter] |
| Space            | O(1)        | -                                  |

## Note

- The array must be sorted to apply binary search.
- Binary search is faster than linear search except for small arrays.
- Binary search can be used for efficient approximate matching like query for rank[^rank_description], predecessor, successor, nearest neighbours and range.

### References

- https://en.wikipedia.org/wiki/Binary_search_algorithm

[^rank_description]: The number of smaller elements.
[^binary_search_definition]: https://en.wikipedia.org/wiki/Binary_search_algorithm
[^iter]: n * (1/2)^k = 1
