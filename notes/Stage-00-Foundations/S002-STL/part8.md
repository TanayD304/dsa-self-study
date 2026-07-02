# Part 8 — STL Complexity Tables, Memory Layout, Iterator Invalidation & Container Selection Guide

> **This chapter is your STL revision sheet. Read it before every interview.**

---

# STL Container Classification

```
STL Containers

├── Sequence
│   ├── array
│   ├── vector
│   ├── deque
│   ├── list
│   └── forward_list
│
├── Ordered Associative
│   ├── set
│   ├── multiset
│   ├── map
│   └── multimap
│
├── Unordered Associative
│   ├── unordered_set
│   └── unordered_map
│
└── Container Adaptors
    ├── stack
    ├── queue
    └── priority_queue
```

---

# Master STL Complexity Table ⭐⭐⭐⭐⭐

| Container | Access | Search | Insert | Delete | Ordered | Duplicate | Iterator |
|-----------|:-----:|:------:|:------:|:------:|:-------:|:---------:|-----------|
| array | O(1) | O(n) | ❌ | ❌ | ❌ | ✅ | Random Access |
| vector | O(1) | O(n) | End O(1)*<br>Middle O(n) | End O(1)<br>Middle O(n) | ❌ | ✅ | Random Access |
| deque | O(1) | O(n) | Front/Back O(1)<br>Middle O(n) | Front/Back O(1)<br>Middle O(n) | ❌ | ✅ | Random Access |
| list | O(n) | O(n) | O(1)** | O(1)** | ❌ | ✅ | Bidirectional |
| forward_list | O(n) | O(n) | O(1)** | O(1)** | ❌ | ✅ | Forward |
| set | ❌ | O(log n) | O(log n) | O(log n) | ✅ | ❌ | Bidirectional |
| multiset | ❌ | O(log n) | O(log n) | O(log n) | ✅ | ✅ | Bidirectional |
| unordered_set | ❌ | O(1) avg | O(1) avg | O(1) avg | ❌ | ❌ | Forward |
| map | By Key O(log n) | O(log n) | O(log n) | O(log n) | ✅ | Keys Unique | Bidirectional |
| multimap | By Key O(log n) | O(log n) | O(log n) | O(log n) | ✅ | Keys Duplicate | Bidirectional |
| unordered_map | By Key O(1) avg | O(1) avg | O(1) avg | O(1) avg | ❌ | Keys Unique | Forward |
| stack | Top O(1) | ❌ | Push O(1) | Pop O(1) | LIFO | ✅ | ❌ |
| queue | Front O(1) | ❌ | Push O(1) | Pop O(1) | FIFO | ✅ | ❌ |
| priority_queue | Top O(1) | ❌ | Push O(log n) | Pop O(log n) | Heap | ✅ | ❌ |

\* Amortized O(1)

\** Given iterator.

---

# Memory Layout

## array

```
+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+

Contiguous
Fixed Size
```

---

## vector

```
+----+----+----+----+
| 10 | 20 | 30 | 40 |
+----+----+----+----+

Contiguous

Dynamic
```

---

## deque

```
Pointer Table

↓

+-----+-----+-----+
| * | * | * |
+-----+-----+-----+
  ↓    ↓    ↓

Block1 Block2 Block3
```

---

## list

```
NULL

↓

+---+----+---+
|P|10|N|
+---+----+---+
      ↓

+---+----+---+
|P|20|N|
+---+----+---+
```

Nodes are scattered in memory.

---

## map / set

```
Red Black Tree

        20
       /  \
     10   30
```

Balanced BST.

---

## unordered_map

```
Buckets

0 →

1 → 25 → 41

2 →

3 → 10

4 → 18 → 34
```

Hash Table.

---

## priority_queue

```
Heap

        50
      /    \
    40      30
   /  \
 20   10
```

Stored internally as

```
50 40 30 20 10
```

inside a vector.

---

# Cache Friendliness

| Container | Cache Locality |
|-----------|----------------|
| array | ⭐⭐⭐⭐⭐ |
| vector | ⭐⭐⭐⭐⭐ |
| deque | ⭐⭐⭐ |
| priority_queue | ⭐⭐⭐⭐ |
| list | ⭐ |
| forward_list | ⭐ |
| set | ⭐ |
| map | ⭐ |
| unordered_map | ⭐⭐ |

---

# Memory Overhead

| Container | Extra Memory |
|-----------|--------------|
| array | None |
| vector | Capacity Buffer |
| deque | Block Table |
| list | Two Pointers / Node |
| forward_list | One Pointer / Node |
| set | Parent + Children + Color |
| map | Same as set + Value |
| unordered_map | Buckets + Nodes |
| priority_queue | None beyond vector |

---

# Iterator Invalidation Matrix ⭐⭐⭐⭐⭐

| Container | Insert | Erase |
|-----------|--------|--------|
| array | Never | Never |
| vector | Reallocation → All Invalid<br>No Reallocation → After insertion point | Erased & Following Invalid |
| deque | May Invalidate | May Invalidate |
| list | Safe | Only Erased Iterator |
| forward_list | Safe | Only Erased Iterator |
| set | Safe | Only Erased Iterator |
| map | Safe | Only Erased Iterator |
| unordered_map | Safe unless Rehash | Only Erased Iterator |
| priority_queue | No Iterators | No Iterators |

---

# Which Iterator?

| Container | Iterator Type |
|-----------|---------------|
| array | Contiguous |
| vector | Contiguous |
| deque | Random Access |
| list | Bidirectional |
| forward_list | Forward |
| set | Bidirectional |
| map | Bidirectional |
| unordered_set | Forward |
| unordered_map | Forward |

---

# Ordered vs Unordered

## Ordered Containers

```
set

map

multiset

multimap
```

Internally

```
Balanced BST
```

Complexity

```
O(log n)
```

Maintains sorted order.

---

## Unordered Containers

```
unordered_set

unordered_map
```

Internally

```
Hash Table
```

Average

```
O(1)
```

No ordering guarantee.

---

# When Should I Use Which?

## Need Random Access?

↓

```
vector
```

---

Need insertion at both ends?

↓

```
deque
```

---

Need many insertions/deletions with iterator?

↓

```
list
```

---

Need unique sorted values?

↓

```
set
```

---

Need frequency counting?

↓

```
unordered_map
```

---

Need sorted key-value?

↓

```
map
```

---

Need Top K?

↓

```
priority_queue
```

---

Need BFS?

↓

```
queue
```

---

Need DFS?

↓

```
stack
```

---

Need compile-time fixed size?

↓

```
array
```

---

# Decision Tree

```
Need Dynamic Size?

↓

NO

↓

array

↓

YES

↓

Need Random Access?

↓

YES

↓

Need Fast Front Insert?

↓

YES

↓

deque

↓

NO

↓

vector

↓

Need Sorted?

↓

YES

↓

Need Key-Value?

↓

YES

↓

map

↓

NO

↓

set

↓

Need Fast Lookup?

↓

YES

↓

unordered_map

↓

unordered_set

↓

Need LIFO?

↓

stack

↓

Need FIFO?

↓

queue

↓

Need Highest Priority?

↓

priority_queue
```

---

# Time vs Space Trade-Off

| Container | Fast | Memory Efficient |
|-----------|------|------------------|
| array | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ |
| vector | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ |
| deque | ⭐⭐⭐⭐ | ⭐⭐⭐ |
| list | ⭐⭐ | ⭐ |
| map | ⭐⭐⭐ | ⭐⭐ |
| unordered_map | ⭐⭐⭐⭐⭐ | ⭐⭐ |

---

# STL Selection Cheat Sheet

| Requirement | Best Choice |
|------------|-------------|
| Dynamic Array | vector |
| Fixed Array | array |
| Fast Front & Back | deque |
| Linked List | list |
| Frequency Count | unordered_map |
| Ordered Keys | map |
| Ordered Unique Values | set |
| Fast Lookup | unordered_set |
| Top K | priority_queue |
| DFS | stack |
| BFS | queue |
| Coordinates | pair |
| Multiple Return Values | tuple |

---

# Common Interview Questions

### Why is vector usually preferred over list?

Answer

- Better cache locality
- Lower memory overhead
- Faster traversal
- Simpler memory layout

---

### Why is unordered_map average O(1)?

Because hashing distributes keys into buckets.

---

### Why can unordered_map become O(n)?

Hash collisions.

Poor hash function.

All elements in one bucket.

---

### Why isn't deque contiguous?

Because it uses multiple fixed-size memory blocks.

This enables efficient insertions at both ends.

---

### Why are map operations O(log n)?

Internally

```
Red Black Tree
```

Height

```
log n
```

---

### Why is priority_queue push O(log n)?

Heapify Up.

Tree height

```
log n
```

---

# STL Performance Ranking

### Fastest Traversal

```
array

↓

vector

↓

deque

↓

unordered_map

↓

map

↓

list
```

---

### Fastest Lookup

```
unordered_map

↓

unordered_set

↓

map

↓

set

↓

vector
```

---

### Fastest Insertion

```
list

↓

deque

↓

vector(end)

↓

map

↓

set
```

---

# Interview Golden Rules

✅ Default to **vector** unless another container clearly fits.

✅ Prefer **unordered_map** over **map** unless ordering is required.

✅ Prefer **emplace_back()** for complex objects.

✅ Never ignore iterator invalidation.

✅ Reserve vector capacity when size is known.

✅ Remember that **priority_queue** is a max-heap by default.

✅ Use `lower_bound()` and `upper_bound()` instead of writing your own binary search when appropriate.

---

# One-Page Revision Sheet

## Sequence Containers

```
array
↓

Fixed

vector
↓

Default

deque
↓

Both Ends

list
↓

Iterator Stability

forward_list
↓

Memory Saving
```

---

## Associative

```
map

↓

Sorted

unordered_map

↓

Fast

set

↓

Unique

multiset

↓

Duplicates
```

---

## Adaptors

```
stack

↓

DFS

queue

↓

BFS

priority_queue

↓

Top K
```

---

## Algorithms to Memorize

```
sort()

stable_sort()

nth_element()

lower_bound()

upper_bound()

binary_search()

reverse()

rotate()

partition()

unique()

remove()

accumulate()

iota()

next_permutation()
```

---

# Final STL Commandments

1. Default to `vector`.
2. Think in terms of **complexity**, not syntax.
3. Know **why** a container is fast, not just **how** to use it.
4. Never memorize APIs without understanding the underlying data structure.
5. Prefer STL algorithms over handwritten loops whenever they clearly express your intent.
6. Cache locality matters in real-world performance.
7. Choose the container based on **operations**, not habit.

---

# Key Takeaways

- STL container selection is driven by **access patterns**, **update patterns**, and **ordering requirements**.
- Time complexity alone does not determine performance—cache locality and memory layout often matter more.
- Iterator invalidation rules are a favorite interview topic and a common source of bugs.
- `vector` and `unordered_map` should be your default choices unless the problem requires something else.
- Master the complexity table and decision tree—they let you choose the right container in seconds.

---

> **End of Part 8**

## Next: **Part 9 — STL Interview Patterns, Pitfalls, Best Practices & Google Follow-ups**

We'll cover:
- 25+ real interview STL patterns
- Common coding mistakes
- Production vs interview choices
- Advanced STL tips
- Google-specific follow-up discussions
- Micro-optimizations that matter
- "Think like an engineer" checklist