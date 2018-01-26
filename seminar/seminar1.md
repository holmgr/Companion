# Seminar 1

* First hour, go throgh assignments
* Second hour: lecture

## Assignments

### Ljutnja
* Could use slow iterative solution to generate test data
* Distribute anger rather than candy

### Spiderman
* Dynamic programing, remember max height in each step, stop if worse

### Aspen
* Greedy or DP

## Lecture: Data structures
* Time complexity is very important

### Basic
* Linear data structures: array, vector, bitset, stack, queue
* Linked list: **Never use**
* Tree-like (for **log** and **search**): prio-queue (heap), set, map

### Union/find
* Store set od disjoint sets
* Find which set an element belongs to, ~O(1)
* Merge two sets
* Disjoint sets is a forest of trees

* **Very good for Kruskal**, one set for each node in the start

### Fenwick
* Range sum queries with updates, both in O(log n)
* Construction cost: O(m log n), m number of data points
* Only stores range sums
* Binary indexed tree
* **Very common data structures**

### Segment Tree
* Harder to implement than Fenwick but a bit better performance
* O(n) construction cost
