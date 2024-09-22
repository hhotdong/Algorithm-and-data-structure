# Tree

> "A tree data structure is a hierarchical structure that is used to represent and
> organize data in a way that is easy to navigate and search. It is a collection of nodes
> that are connected by edges and has a hierarchical relationship between the nodes."[^tree_definition]
>
> "In computer science, a tree is a widely used abstract data type that represents a hierarchical tree structure with a set of connected nodes. Each node in the tree can be connected to many children (depending on the type of tree), but must be connected to exactly one parent,[1] except for the root node, which has no parent (i.e., the root node as the top-most node in the tree hierarchy). These constraints mean there are no cycles or "loops" (no node can be its own ancestor), and also that each child can be treated like the root node of its own subtree, making recursion a useful technique for tree traversal."[^tree_definition_1]

## Note

- Linked list fits well when implementing tree data structure. However, array can also be used specifically when the tree would be traversed frequently.

## Terms

  - Root node: Node which doesn't have a parent node. It's starting point of tree.

  - Leaf node(terminal node): Node which doesn't have any children node. A node can be both root and leaf node, if the tree has only one node.
 
  - Degree of node: The number of children nodes.
 
  - Degree of tree: The biggest degree of all nodes in a tree.

  - Subtree: All nodes except root can be seen as a root node of certain subtree.

  - Full binary tree: All nodes except leaves have two children nodes.

  - Complete binary tree: All nodes except leaf level have two children nodes. Children of leaf nodes are filled from left to right.

### References

- 윤성우, <윤성우의 열혈 자료구조>
  
- 홍정모 연구소, <자료구조 압축코스>

[^tree_definition]: https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/

[^tree_definition_1]: https://en.wikipedia.org/wiki/Tree_(data_structure)
