# Queue

> FIFO(First In First Out)

## ADT

- enqueue
- dequeue
- peek

## Note

- In priority queue, elements with high priority are served before elements with low priority regardless of the insertion order. Priority queue can be implemented using either array or linked list. But it's hard to add a new node at last position of the heap with linked list.
- One of the ways to implement queue is using two stacks.[^queue_using_two_stacks]

## Priority queue performance

<table>
    <thead>
        <tr>
            <th>Implementation</th>
            <th>Function</th>
            <th>Big-O</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=4>Array based</td>
            <td rowspan=2>Add</td>
        </tr>
        <tr>
            <td>O(n)</td>
        </tr>
        <tr>
            <td rowspan=2>Remove</td>
        </tr>
        <tr>
            <td>O(1)</td>
        </tr>
        <tr>
            <td rowspan=2>Linked list based</td>
            <td>Add</td>
            <td>O(n)</td>
        </tr>
        <tr>
            <td>Remove</td>
            <td>O(1)</td>
        </tr>
        <tr>
            <td rowspan=2>Heap based</td>
            <td>Add</td>
            <td>O(log<sub>2</sub>n)</td>
        </tr>
        <tr>
            <td>Remove</td>
            <td>O(log<sub>2</sub>n)</td>
        </tr>
    </tbody>
</table>

### References

- [유튜브 <쉬운코드>][ref1]

[ref1]: <https://www.youtube.com/watch?v=-2YpvLCT5F8&list=PLcXyemr8ZeoR82N8uZuG9xVrFIfdnLd72&index=1>
[^queue_using_two_stacks]: https://stackoverflow.com/questions/69192/how-to-implement-a-queue-using-two-stacks/69436#69436
