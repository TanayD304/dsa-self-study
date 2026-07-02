# Part 10 — Final Revision Pack, Google Interview Cheat Sheet & Mastery Checklist

> **This chapter is your last 30-minute revision before any coding interview.**

---

# STL Master Cheat Sheet ⭐⭐⭐⭐⭐

## Sequence Containers

| Container | Best Use | Complexity |
|------------|-----------|------------|
| `array` | Fixed-size collection | O(1) access |
| `vector` | Default dynamic array | O(1) access, O(1)* push_back |
| `deque` | Insert/Delete at both ends | O(1) front/back |
| `list` | Frequent insert/delete with iterator | O(1) insert/delete |
| `forward_list` | Memory-efficient linked list | O(1) insert/delete |

---

## Associative Containers

| Container | Internals | Search |
|------------|-----------|--------|
| `set` | Red-Black Tree | O(log n) |
| `multiset` | Red-Black Tree | O(log n) |
| `map` | Red-Black Tree | O(log n) |
| `multimap` | Red-Black Tree | O(log n) |

---

## Unordered Containers

| Container | Internals | Average |
|------------|-----------|----------|
| `unordered_set` | Hash Table | O(1) |
| `unordered_map` | Hash Table | O(1) |

Worst Case

```
O(n)
```

---

## Adaptors

| Container | Purpose |
|------------|----------|
| stack | DFS |
| queue | BFS |
| priority_queue | Top K / Heap |

---

# STL Algorithms You MUST Know

## Sorting

```
sort()

stable_sort()

partial_sort()

nth_element()
```

---

## Binary Search

```
binary_search()

lower_bound()

upper_bound()

equal_range()
```

---

## Searching

```
find()

count()

count_if()

all_of()

any_of()

none_of()
```

---

## Modifying

```
copy()

copy_if()

fill()

replace()

transform()

remove()

unique()
```

---

## Numeric

```
accumulate()

iota()

partial_sum()

adjacent_difference()
```

---

## Utility

```
reverse()

rotate()

partition()

swap()

next_permutation()
```

---

# 50 Google STL Interview Questions

## Containers

### 1

Why is vector preferred over list?

---

### 2

Difference between

```
size()

capacity()
```

---

### 3

reserve()

vs

resize()

---

### 4

Why is

```
push_back()

```

amortized O(1)?

---

### 5

What causes iterator invalidation?

---

### 6

When should deque replace vector?

---

### 7

Difference between

```
map

unordered_map
```

---

### 8

Difference between

```
set

unordered_set
```

---

### 9

How does unordered_map work internally?

---

### 10

Worst case complexity of unordered_map?

---

### 11

Why are map operations O(log n)?

---

### 12

Why doesn't unordered_map preserve order?

---

### 13

Difference between stack and deque?

---

### 14

Why is queue implemented using deque?

---

### 15

Why is priority_queue a max heap?

---

## Iterators

### 16

What is an iterator?

---

### 17

Why do algorithms use iterators?

---

### 18

Difference between

```
begin()

end()
```

---

### 19

Why does

```
end()

```

not point to last element?

---

### 20

Difference between

```
begin()

cbegin()
```

---

### 21

Random Access Iterator?

---

### 22

Bidirectional Iterator?

---

### 23

Forward Iterator?

---

### 24

Which containers support random access?

---

### 25

Which operations invalidate vector iterators?

---

## Algorithms

### 26

Difference between

```
find()

binary_search()
```

---

### 27

Difference between

```
sort()

stable_sort()
```

---

### 28

Difference between

```
lower_bound()

upper_bound()
```

---

### 29

When should

```
nth_element()

```

replace

```
sort()
```

---

### 30

Explain Erase Remove Idiom.

---

### 31

What does

```
unique()

```

actually do?

---

### 32

Difference between

```
partition()

stable_partition()
```

---

### 33

When should

```
partial_sort()

```

be used?

---

### 34

What is

```
equal_range()
```

---

### 35

Complexity of

```
accumulate()
```

---

## Lambdas

### 36

Capture by value?

---

### 37

Capture by reference?

---

### 38

What is mutable lambda?

---

### 39

Why use lambda instead of function?

---

### 40

What is decltype(cmp)?

---

## Utilities

### 41

pair vs tuple?

---

### 42

optional?

---

### 43

variant?

---

### 44

string_view?

---

### 45

move?

---

## Engineering

### 46

Why is vector cache friendly?

---

### 47

Why is list cache unfriendly?

---

### 48

Red Black Tree advantages?

---

### 49

Hash Table tradeoffs?

---

### 50

How do you choose the correct STL container?

---

# The 20 STL Rules

## Rule 1

Default to

```
vector
```

---

## Rule 2

Default Hash Map

```
unordered_map
```

---

## Rule 3

Need sorted?

```
map

set
```

---

## Rule 4

Need Top K?

```
priority_queue
```

---

## Rule 5

Need BFS?

```
queue
```

---

## Rule 6

Need DFS?

```
stack
```

---

## Rule 7

Prefer

```
auto
```

---

## Rule 8

Prefer

```
const auto&
```

---

## Rule 9

Prefer

```
emplace_back()
```

---

## Rule 10

Prefer STL algorithms.

---

## Rule 11

Reserve vector capacity.

---

## Rule 12

Never write

```
<=

>=
```

inside comparator.

---

## Rule 13

Remember iterator invalidation.

---

## Rule 14

Never dereference

```
end()
```

---

## Rule 15

Think

```
Operations

↓

Container
```

Not

```
Container

↓

Operations
```

---

## Rule 16

Cache locality matters.

---

## Rule 17

Avoid unnecessary copies.

---

## Rule 18

Use references.

---

## Rule 19

Choose readability over cleverness.

---

## Rule 20

Use the highest-level STL abstraction that correctly solves the problem.

---

# STL Recognition Table

| Problem Statement | Immediately Think |
|-------------------|-------------------|
| Frequency | unordered_map |
| Unique | unordered_set |
| Ordered | set |
| Ordered Key Value | map |
| Top K | priority_queue |
| Kth Largest | priority_queue / nth_element |
| Kth Smallest | nth_element |
| DFS | stack |
| BFS | queue |
| Coordinates | pair |
| Multiple Return | tuple |
| Prefix | accumulate |
| Rotate | rotate |
| Reverse | reverse |
| Remove | erase-remove |
| Sorted Search | lower_bound |

---

# STL Practice Roadmap

## Beginner

- Two Sum
- Contains Duplicate
- Valid Anagram
- Merge Sorted Array
- Intersection of Arrays

---

## Intermediate

- Top K Frequent Elements
- Merge Intervals
- Insert Interval
- K Closest Points
- Group Anagrams
- Sort Colors
- Meeting Rooms
- Task Scheduler

---

## Advanced

- Median From Data Stream
- LFU Cache
- LRU Cache
- Skyline Problem
- Merge K Sorted Lists
- Sliding Window Median
- IPO
- Smallest Range Covering K Lists

---

# Common STL Mistakes

❌ Using `map` instead of `unordered_map`

❌ Forgetting `priority_queue` is max-heap

❌ Forgetting iterator invalidation

❌ Using `remove()` without `erase()`

❌ Using `resize()` instead of `reserve()`

❌ Using `list` when `vector` is better

❌ Writing manual binary search instead of `lower_bound()`

❌ Copying containers unnecessarily

❌ Passing vectors by value

❌ Using `operator[]` only to check existence

---

# STL Mastery Checklist

## Containers

- [ ] vector
- [ ] deque
- [ ] array
- [ ] list
- [ ] forward_list
- [ ] stack
- [ ] queue
- [ ] priority_queue
- [ ] set
- [ ] multiset
- [ ] unordered_set
- [ ] map
- [ ] multimap
- [ ] unordered_map

---

## Iterators

- [ ] begin/end
- [ ] rbegin/rend
- [ ] cbegin/cend
- [ ] Iterator Categories
- [ ] Iterator Invalidation

---

## Algorithms

- [ ] sort
- [ ] stable_sort
- [ ] nth_element
- [ ] partial_sort
- [ ] lower_bound
- [ ] upper_bound
- [ ] binary_search
- [ ] reverse
- [ ] rotate
- [ ] partition
- [ ] unique
- [ ] remove
- [ ] accumulate
- [ ] iota
- [ ] transform
- [ ] next_permutation

---

## Modern C++

- [ ] auto
- [ ] pair
- [ ] tuple
- [ ] structured bindings
- [ ] lambda
- [ ] optional
- [ ] variant
- [ ] string_view
- [ ] move
- [ ] emplace_back

---

# Self Assessment

Can you answer **YES** to these?

- [ ] I can choose the correct STL container in under **10 seconds**.
- [ ] I know the time complexity of every common STL container.
- [ ] I understand the internal implementation of vector, deque, map, unordered_map, and priority_queue.
- [ ] I know iterator invalidation rules.
- [ ] I can explain why vector is usually faster than list.
- [ ] I know when to use `map` vs `unordered_map`.
- [ ] I can use lambdas naturally.
- [ ] I know the Erase-Remove Idiom by memory.
- [ ] I know `lower_bound()` and `upper_bound()` without hesitation.
- [ ] I can explain every choice I make in an interview.

If you checked all of these, your STL foundation is interview-ready.

---

# Final Revision (5-Minute Read)

Remember only these:

```
Dynamic Array
↓

vector

-----------------

Frequency
↓

unordered_map

-----------------

Unique
↓

unordered_set

-----------------

Sorted
↓

set

map

-----------------

Top K
↓

priority_queue

-----------------

DFS
↓

stack

-----------------

BFS
↓

queue

-----------------

Binary Search
↓

lower_bound()

upper_bound()

-----------------

Remove
↓

erase(remove())

-----------------

Construct
↓

emplace_back()

-----------------

Random Access
↓

vector

array

deque

-----------------

Iterator Safety
↓

Know invalidation rules
```

---

# Final Words

STL is **not** a collection of functions to memorize.

It is a library of carefully designed abstractions that allow you to write code that is:

- Correct
- Efficient
- Readable
- Reusable
- Expressive

As a Google SDE, your goal is not to impress with clever tricks. Your goal is to choose the right abstraction, justify it, and produce clean, maintainable code.

Master the **why**, not just the **how**.

---

# Session Summary

## Session

```
S002
```

## Pattern

```
C++ STL Mastery
```

## Stage

```
Stage 00 — Foundations
```

## Confidence Goal

```
⭐⭐⭐⭐⭐

Can Teach
```

## Estimated Revision

- Rev1 → Day 3
- Rev2 → Day 10
- Rev3 → Day 24

---

# Git Commit

```text
S002 - C++ STL Mastery
```

---

> **🎉 Congratulations!**
>
> You have completed **S002 – C++ STL Mastery**.
>
> This handbook covers:
>
> - STL Architecture
> - Sequence Containers
> - Associative & Unordered Containers
> - Container Adaptors
> - Iterators
> - STL Algorithms
> - Lambdas & Comparators
> - Modern C++ Utilities
> - Complexity Tables
> - Memory Layout
> - Interview Patterns
> - Best Practices
> - Google Follow-ups
> - Final Revision Sheets
>
> You now have a comprehensive STL reference suitable for both interviews and long-term engineering use.
