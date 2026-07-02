# S002 — C++ STL Mastery Handbook

> **Stage 00 — Foundations**
> **Difficulty:** ⭐
> **Estimated Duration:** 3–4 Hours
> **Confidence Goal:** ⭐⭐⭐⭐⭐ (Can Teach)

---

# About This Handbook

This handbook is a complete reference for the C++ Standard Template Library (STL), designed for Google SDE-2 interview preparation.

Unlike traditional STL notes that only list syntax, this handbook focuses on:

- Engineering intuition
- Internal implementation
- Time & space complexity
- Memory layout
- Cache locality
- Iterator behavior
- Interview patterns
- Modern C++ best practices
- Google interview follow-ups

The objective is not to memorize APIs but to understand **why**, **when**, and **how** each STL component should be used.

---

# Learning Objectives

After completing this handbook, you should be able to:

- Select the appropriate STL container within seconds.
- Explain the internal implementation of major STL containers.
- Analyze time and space complexity confidently.
- Understand iterator categories and invalidation rules.
- Use STL algorithms instead of writing unnecessary loops.
- Write clean modern C++17/20 code.
- Answer Google-style STL follow-up questions confidently.

---

# Handbook Structure

---

## Part 1 — STL Architecture & Sequence Containers

### STL Overview

- What is STL?
- STL Philosophy
- Generic Programming
- STL Architecture
- Components of STL

### Sequence Containers

- `std::vector`
  - Internal Memory Layout
  - Dynamic Growth
  - Amortized Analysis
  - Size vs Capacity
  - reserve()
  - resize()
  - push_back()
  - emplace_back()
  - Complexity
  - Iterator Invalidation
  - Interview Notes

---

## Part 2 — Sequence Containers (Continued)

### std::array

- Internal Structure
- Operations
- Complexity
- Use Cases

### std::deque

- Block Memory Layout
- Random Access
- Front/Back Operations
- Complexity
- Cache Performance

### std::list

- Doubly Linked List
- splice()
- merge()
- unique()
- reverse()
- Complexity
- Cache Locality

### std::forward_list

- Singly Linked List
- Complexity
- Advantages

### Sequence Container Comparison

- Complete Comparison Table
- Decision Tree
- Interview Guidelines

---

## Part 3 — Container Adaptors

### std::stack

- Internal Implementation
- Operations
- Complexity
- Applications
- Interview Patterns

### std::queue

- FIFO
- Internal Implementation
- Complexity
- BFS Applications

### std::priority_queue

- Binary Heap
- Internal Representation
- Max Heap
- Min Heap
- Custom Comparator
- Pair Heap
- Heap Algorithms
- Applications
- Complexity

---

## Part 4 — Iterators

### Introduction

- What is an Iterator?
- Generic Programming

### Iterator Basics

- begin()
- end()
- Dereferencing
- Traversal

### Iterator Categories

- Input Iterator
- Output Iterator
- Forward Iterator
- Bidirectional Iterator
- Random Access Iterator
- Contiguous Iterator

### Reverse Iterators

### Const Iterators

### Iterator Arithmetic

### advance()

### next()

### prev()

### distance()

### Iterator Invalidation

- vector
- deque
- list
- set
- map
- unordered_map

---

## Part 5 — STL Algorithms

### Non-Modifying Algorithms

- find()
- count()
- count_if()
- all_of()
- any_of()
- none_of()

### Modifying Algorithms

- fill()
- copy()
- copy_if()
- replace()
- replace_if()
- transform()

### Sorting

- sort()
- stable_sort()
- partial_sort()
- nth_element()

### Binary Search

- binary_search()
- lower_bound()
- upper_bound()
- equal_range()

### Heap Algorithms

- make_heap()
- push_heap()
- pop_heap()
- sort_heap()

### Numeric Algorithms

- accumulate()
- partial_sum()
- adjacent_difference()
- iota()

### Utility Algorithms

- reverse()
- rotate()
- partition()
- stable_partition()
- unique()
- remove()
- erase-remove idiom

### Set Algorithms

- union
- intersection
- difference

### Permutations

- next_permutation()
- prev_permutation()

---

## Part 6 — Lambdas & Comparators

### Function Objects (Functors)

### Lambda Expressions

- Syntax
- Parameters
- Return Types

### Capture Lists

- []
- [=]
- [&]
- [x]
- [&x]
- [this]

### Mutable Lambdas

### Generic Lambdas

### std::function

### Comparators

- Ascending
- Descending
- Pair Sorting
- Custom Object Sorting
- Comparator Rules
- Strict Weak Ordering

### priority_queue Comparators

### STL Function Objects

---

## Part 7 — STL Utilities & Modern C++

### pair

### tuple

### Structured Bindings

### tie()

### ignore

### optional

### variant

### string_view

### move()

### swap()

### exchange()

### make_pair()

### make_tuple()

### emplace_back()

---

## Part 8 — STL Reference Tables

### Master Complexity Table

Complete complexity comparison for

- array
- vector
- deque
- list
- forward_list
- stack
- queue
- priority_queue
- set
- multiset
- unordered_set
- map
- multimap
- unordered_map

### Memory Layout

### Cache Locality

### Memory Overhead

### Iterator Invalidation Matrix

### Ordered vs Unordered Containers

### Decision Tree

### Container Selection Guide

### STL Cheat Sheet

---

## Part 9 — Interview Patterns & Best Practices

### 20+ STL Interview Patterns

Including

- Frequency Counting
- Fast Lookup
- Ordered Data
- Top K
- Sliding Window
- Graphs
- BFS
- DFS
- Selection Problems
- Running Sum

### STL Pitfalls

### Best Practices

### Performance Tips

### Production vs Interview Code

### Google Follow-Up Discussions

### Engineer's Checklist

---

## Part 10 — Final Revision Pack

### Master Cheat Sheet

### 50 Interview Questions

### STL Rules

### Recognition Table

### Practice Roadmap

### Mastery Checklist

### Self Assessment

### 5-Minute Revision Sheet

### Git Commit

---

# Recommended Reading Order

```
Architecture
        ↓
Containers
        ↓
Iterators
        ↓
Algorithms
        ↓
Lambdas
        ↓
Utilities
        ↓
Complexity Tables
        ↓
Interview Patterns
        ↓
Revision
```

---

# Suggested Revision Plan

## Rev 1 (Day 3)

- Complexity Tables
- Container Selection
- Algorithms Cheat Sheet

---

## Rev 2 (Day 10)

- Iterator Categories
- Algorithms
- Lambdas
- Comparators

---

## Rev 3 (Day 24)

- Solve 8–10 STL-heavy problems
- Review Interview Patterns
- Complete Self Assessment

---

# Practice Problems

### Foundation

- Two Sum
- Contains Duplicate
- Valid Anagram
- Merge Sorted Array
- Intersection of Two Arrays

### Intermediate

- Group Anagrams
- Merge Intervals
- Top K Frequent Elements
- K Closest Points
- Task Scheduler

### Advanced

- Median From Data Stream
- LFU Cache
- Merge K Sorted Lists
- Sliding Window Median
- IPO

---

# Prerequisites

- S001 — Complexity Analysis

---

# Next Session

```
S003 — Merge Sort
```

---

# Completion Checklist

- [ ] Read all 10 parts
- [ ] Memorize complexity tables
- [ ] Complete 12 practice problems
- [ ] Review revision sheet
- [ ] Complete self assessment
- [ ] Push Git commit

---

# Git Commit

```text
S002 - C++ STL Mastery
```

---

> **"Master STL once. Use it for the rest of your career."**