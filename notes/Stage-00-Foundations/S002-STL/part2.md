# std::array

---

# Overview

`std::array` is a fixed-size container introduced in C++11.

Unlike `vector`, its size **cannot change** after creation.

Internally it is simply a wrapper around a normal C-style array with STL support.

```cpp
array<int,5> arr = {1,2,3,4,5};
```

Think of it as

```
C Array
        +
STL Functions
```

---

# Internal Memory Layout

Like vector,

elements are stored in contiguous memory.

```
Address

1000
1004
1008
1012
1016
```

Random Access

```
O(1)
```

Excellent cache locality.

---

# Why Use std::array Instead of int arr[] ?

Normal arrays

❌ No size()

❌ No iterators

❌ No STL algorithms directly

❌ Cannot be copied easily

std::array

✅ size()

✅ begin()

✅ end()

✅ front()

✅ back()

✅ fill()

✅ swap()

Works perfectly with STL algorithms.

---

# Common Operations

```cpp
array<int,5> arr = {1,2,3,4,5};

arr.size();

arr.front();

arr.back();

arr.fill(10);

sort(arr.begin(), arr.end());
```

---

# Complexity

| Operation | Complexity |
|-----------|------------|
| Access | O(1) |
| Search | O(n) |
| Modification | O(1) |
| Size | O(1) |

---

# When to Use array

✅ Fixed size known at compile time

✅ Maximum performance

✅ No reallocations

Examples

- Days of week
- Chess board rows
- Fixed lookup tables

---

# When NOT to Use

❌ Unknown size

❌ Dynamic insertion

❌ Dynamic deletion

---

# Google Follow-up

Why use std::array instead of vector?

Answer

No dynamic allocation.

Memory allocated directly with the object.

Better performance.

No capacity management.

---

# std::deque

---

# Overview

Deque means

```
Double Ended Queue
```

Unlike vector,

efficient insertion and deletion happen at **both ends**.

```
Front

↓

10 20 30 40

↑

Back
```

---

# Mental Model

Many people think deque is

```
Vector with push_front()
```

Wrong.

Internally deque is completely different.

---

# Internal Implementation

Vector

```
Single Continuous Memory Block

[ ][ ][ ][ ][ ]
```

Deque

```
Pointer Table

↓

┌────┐
│ *──┼────► Block 1
├────┤
│ *──┼────► Block 2
├────┤
│ *──┼────► Block 3
└────┘
```

A deque stores multiple fixed-size blocks.

Because of this,

adding elements at the front usually does not require shifting everything.

---

# Advantages

Fast

```
push_front()

push_back()

pop_front()

pop_back()
```

All are

```
O(1)
```

---

# Common Operations

```cpp
deque<int> dq;

dq.push_front(10);

dq.push_back(20);

dq.pop_front();

dq.pop_back();

dq.front();

dq.back();
```

---

# Complexity

| Operation | Complexity |
|-----------|------------|
| Random Access | O(1) |
| Search | O(n) |
| push_front | O(1) |
| push_back | O(1) |
| pop_front | O(1) |
| pop_back | O(1) |
| Insert Middle | O(n) |
| Erase Middle | O(n) |

---

# deque vs vector

Vector

```
Excellent

push_back()

Bad

push_front()
```

Deque

```
Excellent

push_front()

Excellent

push_back()
```

---

# Cache Performance

Because deque uses multiple memory blocks,

cache locality is worse than vector.

So

Although both provide O(1) random access,

vector is usually faster.

---

# When to Use deque

✅ Sliding Window

✅ Monotonic Queue

✅ BFS variants

✅ Need operations at both ends

---

# When NOT to Use deque

❌ If only push_back() is needed.

Vector is better.

---

# Google Follow-up

Why is deque random access O(1) despite not storing contiguous memory?

Answer

It uses a table of pointers to memory blocks.

The block index and offset are computed in constant time.

---

# std::list

---

# Overview

`std::list` is a doubly linked list.

Each node stores

```
Previous Pointer

Data

Next Pointer
```

Visualization

```
NULL

↓

10 ⇄ 20 ⇄ 30 ⇄ 40

↓

NULL
```

---

# Internal Structure

Every node is independent.

```
┌──────┐
│ Prev │
├──────┤
│ Data │
├──────┤
│ Next │
└──────┘
```

Unlike vector,

memory is **not contiguous**.

---

# Advantages

Insertion

Deletion

Both

```
O(1)
```

if iterator is already known.

---

# Important Clarification

Finding the iterator is still

```
O(n)
```

Many candidates forget this.

Example

```cpp
list.remove(5);
```

Searching

↓

O(n)

Removing

↓

O(1)

Overall

↓

O(n)

---

# Common Operations

```cpp
list<int> l;

l.push_back(10);

l.push_front(20);

l.pop_back();

l.pop_front();

l.remove(20);

l.reverse();

l.sort();

l.unique();
```

---

# splice()

One of the most powerful list operations.

Moves nodes

without copying.

```cpp
list1.splice(it, list2);
```

Complexity

```
O(1)
```

---

# merge()

Merge two sorted lists.

```cpp
list1.merge(list2);
```

---

# unique()

Removes consecutive duplicates.

```
1 1 2 2 3

↓

1 2 3
```

---

# Complexity

| Operation | Complexity |
|-----------|------------|
| Access | O(n) |
| Search | O(n) |
| Insert | O(1) |
| Delete | O(1) |

---

# Cache Performance

Very poor.

Every node may exist in different memory locations.

CPU cache becomes ineffective.

This is why list is often slower than vector despite better theoretical insertion complexity.

---

# When to Use list

Very rarely in interviews.

Useful when

- Frequent insertion
- Frequent deletion
- Iterator stability

---

# When NOT to Use

Almost every normal interview problem.

Vector is usually better.

---

# Google Follow-up

Why is list often slower than vector?

Expected Answer

Poor cache locality.

Extra pointer storage.

Memory fragmentation.

---

# std::forward_list

---

# Overview

A singly linked list.

Each node stores

```
Data

Next Pointer
```

Only forward traversal.

```
10 → 20 → 30 → 40
```

---

# Advantages

Less memory than list.

Fast insertion.

---

# Limitations

No previous pointer.

Cannot traverse backwards.

No size() member.

---

# Complexity

| Operation | Complexity |
|-----------|------------|
| Access | O(n) |
| Search | O(n) |
| Insert | O(1) |
| Delete | O(1) |

---

# Sequence Container Comparison

| Feature | array | vector | deque | list | forward_list |
|----------|------|--------|--------|------|---------------|
| Dynamic Size | ❌ | ✅ | ✅ | ✅ | ✅ |
| Contiguous Memory | ✅ | ✅ | ❌ | ❌ | ❌ |
| Random Access | ✅ | ✅ | ✅ | ❌ | ❌ |
| Push Front | ❌ | O(n) | O(1) | O(1) | O(1) |
| Push Back | ❌ | O(1)* | O(1) | O(1) | ❌ |
| Insert Middle | O(n) | O(n) | O(n) | O(1)** | O(1)** |
| Cache Friendly | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐ | ⭐ | ⭐ |
| Iterator Stability | Excellent | Poor after reallocation | Moderate | Excellent | Excellent |

\* Amortized O(1)

\** Given an iterator to the insertion position.

---

# Sequence Container Decision Tree

```
Need fixed size?

↓

YES

↓

array

↓

NO

↓

Need random access?

↓

YES

↓

Need push_front() often?

↓

YES

↓

deque

↓

NO

↓

vector

↓

Need O(1) insertion/deletion in middle with iterator?

↓

YES

↓

list

↓

Need only forward traversal?

↓

forward_list
```

---

# Common Interview Mistakes

❌ Choosing `list` because insertion is O(1) without considering the O(n) search cost.

❌ Using `deque` when `vector` is sufficient.

❌ Forgetting that `array` size is fixed at compile time.

❌ Assuming `deque` is contiguous in memory.

❌ Believing `list` is always faster than `vector`.

---

# Key Takeaways

- `array` is a fixed-size STL wrapper around C arrays.
- `vector` is the default choice for most problems.
- `deque` excels when efficient operations are required at both ends.
- `list` provides O(1) insertion/deletion with an iterator but suffers from poor cache locality.
- `forward_list` is a memory-efficient singly linked list with forward-only traversal.
- Real-world performance often favors `vector` because of contiguous memory and cache friendliness, even when asymptotic complexities seem similar.

---

> **End of Part 2**

**Next:** Part 3 — **Container Adaptors** (`stack`, `queue`, `priority_queue`) including heap internals, custom comparators, min-heaps, max-heaps, and interview patterns.
