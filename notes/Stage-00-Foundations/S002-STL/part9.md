# Part 9 — STL Interview Patterns, Pitfalls, Best Practices & Google Follow-ups

> **Knowing STL syntax is expected. Knowing when, why, and how to use STL is what differentiates a Google-level engineer.**

---

# Introduction

Most candidates know

```cpp
vector<int>

unordered_map<int,int>

sort()
```

Very few understand

- Why one container is better than another
- Hidden complexity
- Iterator invalidation
- Cache locality
- Memory trade-offs
- Which STL algorithm already solves the problem

Google interviewers care about the second group.

---

# Pattern 1 — Frequency Counting

Recognition

```
Frequency

Duplicate

Occurrences

Count
```

Immediately think

```cpp
unordered_map
```

Example

```cpp
unordered_map<int,int> freq;

for(int x:nums)

freq[x]++;
```

Complexity

```
O(n)
```

---

# Pattern 2 — Fast Lookup

Recognition

```
Exists?

Visited?

Seen Before?

Contains?
```

Use

```cpp
unordered_set
```

instead of

```cpp
vector
```

Wrong

```
O(n)
```

Correct

```
O(1)
```

---

# Pattern 3 — Ordered Data

Recognition

```
Sorted

Smallest

Largest

Next Greater

Previous Smaller
```

Think

```
set

map
```

---

# Pattern 4 — Top K

Recognition

```
Top K

K Largest

K Smallest

Highest Priority
```

Think

```cpp
priority_queue
```

NOT

Repeated sorting.

---

# Pattern 5 — Sliding Window

Recognition

```
Subarray

Substring

Longest

Shortest

Window
```

Container

```
deque
```

sometimes

or

```
unordered_map
```

for frequency.

---

# Pattern 6 — Coordinates

Instead of

```cpp
class Point{

};
```

Use

```cpp
pair<int,int>
```

Simple.

Readable.

---

# Pattern 7 — Graph

Edge

```
(node,weight)
```

Store

```cpp
pair<int,int>
```

Adjacency List

```cpp
vector<
vector<pair<int,int>>
>
```

Industry standard.

---

# Pattern 8 — BFS

Recognition

```
Minimum Steps

Level Order

Shortest Path

Unweighted Graph
```

Immediately

```cpp
queue
```

---

# Pattern 9 — DFS

Recognition

```
Recursion

Backtracking

Traversal
```

Think

```
stack
```

or recursion.

---

# Pattern 10 — Binary Search

Never implement manually unless required.

Prefer

```cpp
lower_bound()

upper_bound()

binary_search()
```

Cleaner.

Less error-prone.

---

# Pattern 11 — Sorting Custom Objects

Instead of

large compare functions

Use lambda.

```cpp
sort(v.begin(),

v.end(),

[](auto &a,

auto &b){

return a.score>b.score;

});
```

---

# Pattern 12 — Removing Elements

Wrong

```cpp
remove(...)
```

Correct

```cpp
erase(

remove(...),

end()

);
```

Interview classic.

---

# Pattern 13 — Construct Objects In Place

Instead of

```cpp
push_back(
pair<int,int>(1,2)
);
```

Use

```cpp
emplace_back(
1,
2
);
```

Cleaner.

Faster.

---

# Pattern 14 — Return Multiple Values

Instead of

creating

temporary struct.

Use

```cpp
tuple<>
```

or

```cpp
pair<>
```

---

# Pattern 15 — Read Only Strings

Instead of

```cpp
string
```

parameter.

Prefer

```cpp
string_view
```

if modification not needed.

---

# Pattern 16 — Selection Problems

Need

Median

Kth Largest

Kth Smallest

Don't sort.

Think

```
nth_element
```

Average

```
O(n)
```

---

# Pattern 17 — Running Sum

Need

```
Prefix

Running Total
```

Use

```cpp
partial_sum()
```

or

```cpp
accumulate()
```

---

# Pattern 18 — Generate Values

Need

```
1 2 3 4 5
```

Don't write loop.

Use

```cpp
iota()
```

---

# Pattern 19 — Reverse

Don't manually swap.

Use

```cpp
reverse()
```

---

# Pattern 20 — Rotate

Need

```
12345

↓

34512
```

Use

```cpp
rotate()
```

---

# Common STL Pitfalls

---

## Pitfall 1

Using

```
map
```

instead of

```
unordered_map
```

when ordering isn't needed.

Lose

```
log n
```

performance.

---

## Pitfall 2

Using vector

for membership checks.

Wrong

```cpp
find(v.begin(),
v.end(),
x);
```

Correct

```cpp
unordered_set
```

---

## Pitfall 3

Forgetting

priority_queue

is Max Heap.

---

## Pitfall 4

Calling

```cpp
v[i]
```

without checking bounds.

Prefer

```cpp
v.at(i)
```

when safety matters.

---

## Pitfall 5

Using

```
operator[]
```

on map

just to check existence.

Wrong

```cpp
mp[key]
```

Creates entry.

Correct

```cpp
mp.find(key)

!=

mp.end()
```

or (C++20)

```cpp
mp.contains(key)
```

---

## Pitfall 6

Passing vector

by value.

Wrong

```cpp
void solve(

vector<int> v

)
```

Correct

```cpp
void solve(

const vector<int>& v

)
```

Avoids copy.

---

## Pitfall 7

Ignoring reserve()

Repeated reallocations.

---

## Pitfall 8

Using list

because insertion

is O(1).

Reality

Need iterator first.

Search

still

```
O(n)
```

---

## Pitfall 9

Sorting repeatedly.

Example

Need maximum after every insertion.

Wrong

```
Sort

Sort

Sort
```

Correct

```
priority_queue
```

---

## Pitfall 10

Writing loops

for existing algorithms.

Example

Instead of

```cpp
for(...)
```

Think

```
count

transform

find

fill

copy
```

---

# STL Best Practices

---

## Prefer auto

Instead of

```cpp
vector<int>::iterator
```

Write

```cpp
auto it=v.begin();
```

---

## Prefer const reference

```cpp
const vector<int>&
```

Avoid unnecessary copies.

---

## Prefer range-based loops

Instead of

```cpp
for(int i=0;
...
```

Use

```cpp
for(auto &x:v)
```

Cleaner.

---

## Prefer emplace_back()

Especially

for

```
pair

tuple

class
```

---

## Prefer STL algorithms

Readable.

Optimized.

Well tested.

---

## Keep Comparators Simple

Only express ordering.

No side effects.

---

# Interview STL Decision Framework

Before choosing a container, ask:

### 1. How do I access data?

- Random access → `vector`
- Sequential → `list`
- Both ends → `deque`

---

### 2. How do I search?

- Ordered → `map` / `set`
- Fast average lookup → `unordered_map` / `unordered_set`

---

### 3. How do I insert?

- End only → `vector`
- Front & back → `deque`
- Known iterator → `list`

---

### 4. Do I need ordering?

Yes

↓

```
map

set
```

No

↓

```
unordered_map

unordered_set
```

---

# STL Micro-Optimizations

### reserve()

```cpp
vector<int> v;

v.reserve(100000);
```

Avoid reallocations.

---

### shrink_to_fit()

Release unused capacity.

```cpp
v.shrink_to_fit();
```

Request only.

Not guaranteed.

---

### emplace()

Avoid temporary objects.

---

### move()

Avoid unnecessary copies.

---

### string_view

Avoid copying strings.

---

### ++it

Prefer

```cpp
++it
```

over

```cpp
it++
```

for iterators.

---

# Production vs Interview

| Interview | Production |
|------------|------------|
| Optimize for clarity | Optimize for maintainability |
| Use STL aggressively | Use STL aggressively |
| Simpler code wins | Readability wins |
| Minimize bugs | Minimize bugs |
| Avoid premature optimization | Profile before optimizing |

---

# Google Follow-Up Discussions

### Why is vector the default container?

Expected Answer

- Excellent cache locality
- Low memory overhead
- Fast traversal
- Random access
- Amortized O(1) insertion at end

---

### Why isn't unordered_map always better?

Because

- Worst case O(n)
- More memory
- No ordering
- Hashing overhead

---

### Why prefer STL algorithms?

Because they are

- Generic
- Optimized
- Less error-prone
- Easier to read

---

### Why does Google care about STL knowledge?

Because software engineers solve problems using existing, well-tested abstractions instead of reinventing data structures.

---

# Common Google Coding Style

Instead of

```cpp
for(int i=0;

i<v.size();

i++)
```

Prefer

```cpp
for(const auto &x:v)
```

---

Instead of

```cpp
vector<pair<int,int>>
```

Use

```cpp
using pii=pair<int,int>;
```

Cleaner.

---

Instead of

magic numbers

Use

```cpp
constexpr int INF=1e9;
```

---

# STL Recognition Cheat Sheet

| Problem Clue | STL Choice |
|--------------|------------|
| Frequency | unordered_map |
| Unique | unordered_set |
| Ordered | set |
| Ordered Key-Value | map |
| Top K | priority_queue |
| BFS | queue |
| DFS | stack |
| Coordinates | pair |
| Multiple Return | tuple |
| Kth Smallest | nth_element |
| Sorted Search | lower_bound |
| Remove Elements | erase-remove |
| Running Sum | accumulate / partial_sum |

---

# The Engineer's Checklist

Before coding, ask yourself:

- ❓ Is there an STL algorithm that already solves this?
- ❓ Is there a better container for these operations?
- ❓ Am I paying an unnecessary O(log n) or O(n)?
- ❓ Can I avoid copying by using references?
- ❓ Will iterator invalidation be a problem?
- ❓ Is ordering actually required?
- ❓ Can I improve readability with a lambda or structured bindings?

If the answer improves your solution, use the STL feature.

---

# Final Google Advice

A Google interviewer is **not** impressed because you manually implemented a heap.

They're impressed because you recognized that a `priority_queue` is the right abstraction, explained why it's appropriate, understood its complexity and trade-offs, and wrote clean, bug-free code.

That is engineering thinking.

---

# Key Takeaways

- Choose STL containers based on **operations**, not familiarity.
- Prefer existing STL algorithms over handwritten implementations when they express the intent clearly.
- Understand the hidden costs: copying, iterator invalidation, cache locality, and hashing overhead.
- Small STL decisions often separate a good solution from an excellent one.
- Write code that is correct, expressive, and easy for another engineer to understand.

---

> **End of Part 9**

## Next: **Part 10 — Final Revision Pack & Google Interview Cheat Sheet**

The final chapter will include:

- ⭐ 50 most important STL interview questions
- ⭐ One-page STL cheat sheet
- ⭐ Last-minute revision notes
- ⭐ Common Google follow-ups
- ⭐ Practice roadmap
- ⭐ Curated STL problems (40+)
- ⭐ STL mastery checklist
- ⭐ "Can Teach" self-assessment sheet

This will complete your **S002 – C++ STL Mastery Handbook**. 🚀