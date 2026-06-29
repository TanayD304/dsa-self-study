# Pattern Recognition Guide

> **The fastest interviewer is not the one who codes first. It is the one who recognizes the pattern first.**

---

# Purpose

The objective of this guide is to train your brain to identify the correct algorithmic pattern before writing a single line of code.

Interview success depends far more on selecting the correct approach than on typing fast.

This document serves as your decision-making framework.

---

# Recognition Philosophy

Every problem can be viewed as:

```text
Input

↓

Observation

↓

Pattern

↓

Algorithm

↓

Implementation
```

Most candidates jump directly from the problem statement to implementation.

Strong engineers spend time identifying the underlying pattern.

---

# Pattern Recognition Framework

For every problem, answer these questions in order.

---

## Step 1 — Identify the Input

What is the primary data structure?

* Array
* String
* Matrix
* Linked List
* Tree
* Graph
* Interval
* Stream
* Number
* Trie

---

## Step 2 — Identify the Goal

What is being asked?

* Search
* Maximum
* Minimum
* Count
* Exists?
* Construct
* Optimize
* Traverse
* Partition
* Merge

---

## Step 3 — Read the Constraints

Constraints eliminate many algorithms.

### Very Small

```
n <= 20
```

Think

* Backtracking
* Bitmask
* Meet in the Middle

---

### Medium

```
n <= 2000
```

Think

* O(n²)

---

### Large

```
n <= 100000
```

Think

* O(n)
* O(n log n)

---

### Huge

```
n >= 10⁶
```

Need

* Linear algorithms
* Streaming
* Constant space

---

# Recognition Decision Tree

```
Problem

↓

Array?

↓

YES
```

---

## Is it contiguous?

YES

↓

Subarray

↓

Need longest?

↓

Sliding Window

---

Need exact sum?

↓

Prefix Sum

---

Need maximum sum?

↓

Kadane

---

Need range queries?

↓

Prefix Sum

---

Need kth element?

↓

Heap

---

Need sorted answer?

↓

Sorting

---

Already sorted?

↓

Binary Search

↓

Two Pointers

---

# If NOT contiguous

Subsequence

↓

Dynamic Programming

---

Need combinations?

↓

Backtracking

---

Need ordering?

↓

Sorting

---

Need frequency?

↓

Hash Map

---

# String Decision Tree

```
String

↓

Substring?

↓

Sliding Window
```

---

Need prefix?

↓

Trie

---

Need palindrome?

↓

Two Pointers

↓

DP

↓

Manacher

---

Need pattern matching?

↓

KMP

↓

Rolling Hash

---

# Linked List Decision Tree

Cycle?

↓

Fast Slow

---

Reverse?

↓

Pointer Manipulation

---

Merge?

↓

Two Pointers

---

Intersection?

↓

Fast Slow

---

# Tree Decision Tree

Traversal?

↓

DFS

↓

BFS

---

Need shortest path?

↓

BFS

---

Need ancestor?

↓

LCA

---

Need subtree information?

↓

DFS

↓

Tree DP

---

Need ordering?

↓

BST

---

# Graph Decision Tree

Connected?

↓

DFS

↓

BFS

---

Shortest Path?

↓

Unweighted

↓

BFS

---

Weighted

↓

Dijkstra

---

Negative Weights

↓

Bellman Ford

---

Cycle?

↓

DFS

↓

Union Find

---

Need ordering?

↓

Topological Sort

---

Need components?

↓

DFS

↓

Union Find

---

# Dynamic Programming Recognition

Ask

Does the problem have

* Optimal Substructure?
* Overlapping Subproblems?

If yes

↓

DP

---

DP Recognition Keywords

* Maximum
* Minimum
* Count Ways
* Possible?
* Partition
* Subsequence
* Edit
* Transform

---

# Greedy Recognition

Ask

Can a local optimal decision always remain globally optimal?

If yes

↓

Greedy

Examples

* Intervals
* Scheduling
* Activity Selection
* Huffman
* Jump Games

---

# Binary Search Recognition

Binary Search is NOT only for arrays.

Recognize it when

Answer space is ordered.

Examples

* Minimum speed
* Maximum value
* Smallest feasible
* Largest valid
* Capacity
* Days
* Distance

Ask

Can I check whether an answer is valid?

If YES

↓

Binary Search on Answer

---

# Heap Recognition

Keywords

* Top K
* Kth Largest
* Kth Smallest
* Running Median
* Priority
* Stream

↓

Heap

---

# Stack Recognition

Keywords

* Next Greater
* Previous Smaller
* Parentheses
* Undo
* Expression
* Histogram

↓

Stack

---

# Queue Recognition

Keywords

* Level Order
* BFS
* First In First Out
* Multi Source

↓

Queue

---

# Prefix Sum Recognition

Keywords

* Subarray Sum
* Range Sum
* Running Sum
* Equal Prefix

↓

Prefix Sum

---

# Hash Map Recognition

Keywords

* Frequency
* Lookup
* Duplicate
* Pair
* Count

↓

Hash Map

---

# Trie Recognition

Keywords

* Prefix
* Dictionary
* Auto Complete
* Word Search

↓

Trie

---

# Union Find Recognition

Keywords

* Connectivity
* Dynamic Graph
* Merge Sets
* Components

↓

DSU

---

# Backtracking Recognition

Keywords

* Generate All
* Combinations
* Permutations
* Sudoku
* N Queens

↓

Backtracking

---

# Common False Positives

| Looks Like     | Actually     |
| -------------- | ------------ |
| Sliding Window | Prefix Sum   |
| Binary Search  | Two Pointers |
| DFS            | BFS          |
| Greedy         | DP           |
| Heap           | Sorting      |
| Stack          | Two Pointers |

Always verify with constraints.

---

# Recognition Checklist

Before coding ask

* What is the input?
* What is the output?
* What are the constraints?
* Which operations repeat?
* What information should be remembered?
* Can previous work be reused?
* Does the input have order?
* Is there monotonicity?
* Is there optimal substructure?
* Is there overlapping computation?

---

# Pattern Priority

Always consider patterns in roughly this order.

1. Hashing
2. Two Pointers
3. Sliding Window
4. Prefix Sum
5. Binary Search
6. Stack
7. Queue
8. Heap
9. Recursion
10. Backtracking
11. Trees
12. Graphs
13. Greedy
14. Dynamic Programming
15. Trie
16. Advanced Data Structures

Choose the simplest pattern that satisfies the constraints.

---

# The 30-Second Rule

Within the first 30 seconds of reading a problem, you should be able to identify:

* Input type
* Constraints
* Pattern candidates
* Expected complexity
* First brute-force approach

If you cannot, continue analyzing the problem before attempting to code.

---

# Final Principle

> **Do not ask "Which problem is this?"**

Instead ask:

> **"Which pattern naturally explains this problem?"**

That single shift in thinking is what separates problem memorizers from engineers who can solve unfamiliar interview questions.
