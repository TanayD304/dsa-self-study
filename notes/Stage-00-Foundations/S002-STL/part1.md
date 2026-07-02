# S002 — C++ STL Mastery
> Stage 00 — Foundations

---

# Session Information

| Field | Value |
|-------|-------|
| Session | S002 |
| Stage | Foundations |
| Pattern | C++ STL Mastery |
| Difficulty | ⭐ |
| Estimated Time | 3 Hours |

---

# Learning Objectives

By the end of this session you should be able to:

- Choose the correct STL container in under 10 seconds.
- Know the time complexity of every common STL operation.
- Understand how STL containers work internally.
- Know iterator invalidation rules.
- Write clean modern C++17 STL code.
- Explain STL trade-offs in interviews.
- Avoid common STL pitfalls.

---

# Prerequisites

- C++ Basics
- Functions
- Classes (basic understanding)
- Time Complexity (S001)

---

# Introduction

The Standard Template Library (STL) is one of the greatest strengths of C++.

Instead of implementing data structures from scratch every time, STL provides highly optimized, thoroughly tested, generic implementations of the most commonly used containers and algorithms.

In interviews, Google does **not** expect you to implement a dynamic array, hash table, or balanced binary search tree from scratch.

Instead, they expect you to:

- know when to use each container,
- understand its complexity,
- understand its trade-offs,
- write clean STL code confidently.

Think of STL as a toolbox.

Choosing the correct tool is far more important than memorizing every function.

---

# STL Philosophy

Many beginners think STL is simply a library of containers.

That is incorrect.

STL is actually a collection of reusable generic components designed to work together.

The five pillars of STL are:

```
                    STL

        ┌──────────────────────────┐
        │                          │
 Containers                  Algorithms
        │                          │
        └──────────┬───────────────┘
                   │
              Iterators
                   │
      Function Objects (Functors)
                   │
               Allocators
```

Every STL component is designed independently.

Algorithms never care which container they operate on.

Instead they work with **iterators**.

This design makes STL extremely flexible.

Example:

The same `sort()` algorithm works on

- vector
- deque
- array

because all three provide Random Access Iterators.

---

# Why STL Matters in Interviews

Suppose an interviewer asks:

> Find the Top K Frequent Elements.

A beginner starts thinking about implementing a heap.

An experienced engineer immediately thinks:

```
priority_queue
```

Similarly,

Need frequency?

```
unordered_map
```

Need unique sorted values?

```
set
```

Need BFS?

```
queue
```

Need DFS?

```
stack
```

Need dynamic array?

```
vector
```

The interviewer is evaluating whether you recognize the correct abstraction.

---

# STL Architecture

The STL can be divided into six major components.

```
STL

├── Containers
├── Iterators
├── Algorithms
├── Function Objects
├── Utilities
└── Allocators
```

We will study them in exactly this order.

---

# Containers

Containers store data.

There are four categories.

```
Containers

├── Sequence Containers
│
│   vector
│   deque
│   list
│   forward_list
│   array
│
├── Ordered Associative
│
│   set
│   multiset
│   map
│   multimap
│
├── Unordered Associative
│
│   unordered_set
│   unordered_map
│
└── Container Adaptors
    stack
    queue
    priority_queue
```

Each container solves a different problem.

There is no "best" container.

Only the most appropriate one.

---

# Choosing the Correct Container

Always ask yourself three questions.

## 1. How will I access data?

Random access?

Sequential access?

Front?

Back?

Middle?

---

## 2. How often do insertions happen?

Front?

Back?

Middle?

Random positions?

---

## 3. Do I need ordering?

Sorted?

Insertion order?

Hash lookup?

Priority?

Answering these three questions usually tells you which container to use.

---

# Sequence Containers

Sequence containers store elements one after another.

```
vector

1 2 3 4 5
```

```
deque

1 2 3 4 5
```

```
list

1 ↔ 2 ↔ 3 ↔ 4 ↔ 5
```

```
forward_list

1 → 2 → 3 → 4 → 5
```

```
array

Fixed Size
```

---

# std::vector

## Overview

Vector is the single most important STL container.

If you are unsure which container to use,

use vector.

Approximately 80–90% of interview problems can be solved using vector together with STL algorithms.

---

## Mental Model

Think of vector as

```
Resizable Array
```

Internally,

```
Capacity

┌───────────────────────────────┐
│ 10 │ 20 │ 30 │ 40 │    │    │
└───────────────────────────────┘

Size = 4

Capacity = 6
```

Size represents actual elements.

Capacity represents allocated memory.

These are different.

---

# Internal Memory Layout

Unlike linked lists,

vectors store elements in contiguous memory.

```
Address

1000
1004
1008
1012
1016
```

Every element is adjacent.

Because of this,

vector provides

```
O(1)
```

random access.

Example

```
v[500]
```

takes constant time.

---

# Why Contiguous Memory Matters

Suppose we iterate through one million integers.

CPU loads nearby memory into cache.

Since vector elements are stored together,

cache locality is excellent.

This makes vector significantly faster than linked lists even when theoretical complexity is identical.

Interview Tip

Big-O does **not** tell the whole story.

Cache locality matters.

---

# Dynamic Growth

What happens when vector becomes full?

Suppose

```
Capacity = 4

[10][20][30][40]
```

Insert another element.

There is no space.

Vector allocates a larger block.

Typically

```
Old Capacity

4

↓

New Capacity

8
```

Then copies every element.

```
Old Memory

10 20 30 40

↓

New Memory

10 20 30 40 50
```

Finally,

old memory is released.

---

# Why push_back() is Amortized O(1)

Occasionally,

reallocation costs

```
O(n)
```

because every element must be copied.

However,

this happens infrequently.

Most insertions simply place the new value into existing free space.

Therefore

Average Complexity

```
O(1)
```

Worst Case

```
O(n)
```

This is called **amortized analysis**.

Interviewers love asking this.

---

# Size vs Capacity

Example

```cpp
vector<int> v;

v.push_back(1);
v.push_back(2);
v.push_back(3);
```

```
Size

3
```

```
Capacity

4
```

These are independent.

Useful functions

```cpp
v.size();

v.capacity();

v.empty();

v.clear();
```

---

# reserve()

One of the most overlooked STL optimizations.

Suppose you know that

```
100000
```

elements will be inserted.

Instead of repeatedly reallocating,

do

```cpp
vector<int> v;

v.reserve(100000);
```

Now only one allocation happens.

Much faster.

---

# resize()

Do not confuse

```
reserve()
```

with

```
resize()
```

reserve()

Changes capacity only.

resize()

Changes actual number of elements.

Example

```cpp
vector<int> v;

v.resize(5);
```

Now

```
0 0 0 0 0
```

Five elements actually exist.

---

# Common Vector Operations

```cpp
vector<int> v;

v.push_back(10);

v.emplace_back(20);

v.pop_back();

v.front();

v.back();

v.clear();

v.empty();

v.size();

v.capacity();
```

---

# push_back() vs emplace_back()

Both insert elements.

Difference:

push_back()

Creates object first.

Then copies or moves it.

emplace_back()

Constructs object directly inside vector.

Example

```cpp
vector<pair<int,int>> v;

v.emplace_back(1,2);
```

Better than

```cpp
v.push_back({1,2});
```

Interview Rule

Prefer

```
emplace_back()
```

for complex objects.

---

# Complexity

| Operation | Complexity |
|------------|------------|
| Random Access | O(1) |
| push_back | O(1) amortized |
| pop_back | O(1) |
| insert at end | O(1) amortized |
| insert middle | O(n) |
| erase middle | O(n) |
| search | O(n) |

---

# Iterator Invalidation

One of Google's favorite STL follow-up questions.

Suppose

```cpp
auto it = v.begin();
```

Then

```cpp
v.push_back(100);
```

If reallocation occurs,

the iterator becomes invalid.

Reason:

Entire memory moved.

Never continue using invalid iterators.

---

# When Should You Use Vector?

Use vector when:

✅ Random access is needed.

✅ Insertions mostly happen at the end.

✅ Cache performance matters.

✅ Dynamic size is required.

This should be your default container.

---

# When Should You Avoid Vector?

Avoid vector when:

❌ Frequent insertion at the front.

❌ Frequent deletion from the middle.

❌ Iterator stability is critical.

---

# Common Interview Mistakes

❌ Using insert() repeatedly at the beginning.

Every insertion shifts every element.

Time

```
O(n)
```

---

❌ Calling resize() instead of reserve()

This accidentally creates unnecessary elements.

---

❌ Forgetting iterator invalidation after reallocation.

---

❌ Assuming push_back() is always O(1)

Correct answer:

```
Amortized O(1)
```

---

# Google Follow-up Questions

1. Why is vector faster than list despite both having O(n) traversal?

2. Explain amortized analysis.

3. Why does reserve() improve performance?

4. What causes iterator invalidation?

5. Why is contiguous memory cache-friendly?

6. When would deque be a better choice than vector?

---

# Key Takeaways

- `vector` is the default STL container for most interview problems.
- Contiguous memory provides excellent cache locality and O(1) random access.
- `push_back()` is amortized O(1) due to geometric growth.
- `reserve()` prevents repeated reallocations, while `resize()` changes the actual number of elements.
- Reallocation invalidates iterators, pointers, and references to vector elements.

---

> **End of Part 1 (Section A)**
>
> Next: **Part 2 — `array`, `deque`, `list`, `forward_list` (deep dive), sequence container comparison, and complete complexity tables.**