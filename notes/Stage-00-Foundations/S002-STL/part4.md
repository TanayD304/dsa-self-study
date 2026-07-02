# Iterators

---

# What is an Iterator?

An iterator is an object that points to an element inside a container.

Think of it as a **generalized pointer**.

Instead of writing algorithms specifically for `vector`, `list`, `deque`, etc., STL algorithms work with iterators.

This is one of the biggest design ideas behind STL.

```
Container

10   20   30   40   50

      ↑
   Iterator
```

Think of an iterator as

```
Pointer

+

Extra capabilities
```

---

# Why Do We Need Iterators?

Suppose STL did not have iterators.

Then we'd need

```
sortVector()

sortDeque()

sortArray()

sortList()
```

Instead,

we only have

```cpp
sort(begin, end);
```

Because algorithms don't know about containers.

They only know about iterators.

This is called

```
Generic Programming
```

---

# Generic Programming

One algorithm

↓

Many containers

```
sort()

↓

vector

array

deque
```

Same implementation.

Different containers.

---

# Iterator Basics

Create an iterator

```cpp
vector<int> v={10,20,30};

vector<int>::iterator it=v.begin();
```

Modern C++

```cpp
auto it=v.begin();
```

Recommended.

---

# Accessing Values

Iterator points to memory.

Use

```
*
```

to access the value.

Example

```cpp
cout<<*it;
```

Output

```
10
```

---

# Moving Iterator

```cpp
++it;
```

Now

```
20
```

Again

```cpp
++it;
```

Now

```
30
```

Visualization

```
10 20 30 40

^

++

10 20 30 40

   ^

++

10 20 30 40

      ^
```

---

# begin()

Returns iterator to first element.

```cpp
v.begin()
```

```
↓

10 20 30
```

---

# end()

One of the most misunderstood STL concepts.

`end()` **does not point to the last element.**

It points **one position after the last element.**

```
10 20 30

          ^
        end()
```

This is why loops are written as

```cpp
for(auto it=v.begin();
    it!=v.end();
    it++)
```

NOT

```cpp
<=
```

---

# Why One-Past-The-End?

Suppose container is empty.

```
begin()==end()
```

Loop naturally stops.

Very elegant.

---

# Dereferencing end()

Never do

```cpp
*v.end();
```

Undefined behavior.

Because

```
No element exists there.
```

---

# Common Traversal

```cpp
for(auto it=v.begin();
    it!=v.end();
    ++it){

cout<<*it;

}
```

---

# Range Based Loop

Modern C++

```cpp
for(auto x:v)

cout<<x;
```

Equivalent to iterator loop.

Preferred when only reading.

---

# Reference Loop

Suppose

```cpp
for(auto x:v)

x++;
```

Original vector

does NOT change.

Because

```
Copy
```

is created.

Instead

```cpp
for(auto &x:v)

x++;
```

Now

Original vector changes.

---

# Const Reference

Best for reading.

```cpp
for(const auto &x:v)

cout<<x;
```

Advantages

✅ No copying

✅ Cannot modify

Fastest option.

---

# Iterator Operations

```cpp
++it

--it

*it

it==it2

it!=it2
```

Only some iterators support

```cpp
it+5

it-3
```

Depends on iterator category.

---

# Iterator Categories

One of the most important STL concepts.

There are six categories.

```
Input Iterator

↓

Output Iterator

↓

Forward Iterator

↓

Bidirectional Iterator

↓

Random Access Iterator

↓

Contiguous Iterator (C++20)
```

Each level supports all previous operations.

---

# 1. Input Iterator

Read only.

Forward only.

Example

```
istream_iterator
```

Allowed

```
++

*

==
```

Cannot go backwards.

---

# 2. Output Iterator

Write only.

Example

```
ostream_iterator
```

Used with

```
copy()
```

---

# 3. Forward Iterator

Move only forward.

Can revisit elements.

Containers

```
forward_list

unordered_map

unordered_set
```

Allowed

```
++

*

==
```

---

# 4. Bidirectional Iterator

Move both directions.

```
++

--
```

Containers

```
list

set

map

multiset

multimap
```

Cannot

```
it+5
```

---

# 5. Random Access Iterator

Supports arithmetic.

```
it+5

it-2

it[3]

<
>

<=
```

Containers

```
vector

deque

array
```

Required by

```
sort()
```

---

# 6. Contiguous Iterator (C++20)

Newest category.

Guarantees

```
Physical adjacency
```

Containers

```
array

vector

string
```

Useful for optimizations.

---

# Category Comparison

| Feature | Input | Forward | Bidirectional | Random Access | Contiguous |
|----------|-------|----------|---------------|---------------|------------|
| Read | ✅ | ✅ | ✅ | ✅ | ✅ |
| Write | Limited | ✅ | ✅ | ✅ | ✅ |
| ++ | ✅ | ✅ | ✅ | ✅ | ✅ |
| -- | ❌ | ❌ | ✅ | ✅ | ✅ |
| +n | ❌ | ❌ | ❌ | ✅ | ✅ |
| [] | ❌ | ❌ | ❌ | ✅ | ✅ |

---

# Which Container Provides Which Iterator?

| Container | Iterator Type |
|------------|---------------|
| vector | Random Access + Contiguous |
| array | Random Access + Contiguous |
| deque | Random Access |
| list | Bidirectional |
| forward_list | Forward |
| set | Bidirectional |
| map | Bidirectional |
| unordered_map | Forward |
| unordered_set | Forward |

Memorize this table.

Interviewers love asking it.

---

# Reverse Iterators

Normal

```
10 20 30

↑

begin()
```

Reverse

```
10 20 30

        ↑

rbegin()
```

Example

```cpp
for(auto it=v.rbegin();
    it!=v.rend();
    ++it)

cout<<*it;
```

Output

```
30

20

10
```

---

# Const Iterators

Suppose

```cpp
const vector<int> v={1,2,3};
```

Need

```cpp
auto it=v.cbegin();
```

Cannot modify values.

Safer.

---

# Iterator Arithmetic

Random Access only.

```cpp
it+5

it-2

it+=3

it-=4
```

Distance

```cpp
it2-it1
```

Constant time.

Only for random access iterators.

---

# advance()

Works for every iterator.

```cpp
advance(it,5);
```

Even list iterators.

Complexity

Depends on iterator type.

---

# next()

Returns advanced iterator.

Original unchanged.

```cpp
auto it2=next(it);
```

---

# prev()

Returns previous iterator.

```cpp
auto it2=prev(it);
```

---

# distance()

Computes distance.

```cpp
distance(begin,end);
```

Complexity

Random Access

```
O(1)
```

Forward/Bidirectional

```
O(n)
```

Google follow-up favorite.

---

# Iterator Invalidation

Very important.

Many bugs come from invalid iterators.

---

## vector

| Operation | Iterator Valid? |
|-----------|----------------|
| push_back (no reallocation) | ✅ |
| push_back (reallocation) | ❌ |
| insert | ❌ after insertion point |
| erase | ❌ erased and following |

---

## deque

Insertion at ends

Usually

```
May invalidate
```

Middle insertion

```
Often invalidates
```

---

## list

Insert

```
Safe
```

Erase

Only erased iterator becomes invalid.

Everything else

Safe.

Huge advantage.

---

## set/map

Insert

```
Safe
```

Erase

Only erased iterator invalid.

---

## unordered_map

Insert

Usually safe.

Rehash

Everything invalid.

---

# Common Iterator Mistakes

❌ Dereferencing end()

```cpp
*v.end()
```

Undefined behavior.

---

❌ Incrementing end()

```cpp
++v.end();
```

Undefined.

---

❌ Using iterator after erase()

```cpp
v.erase(it);

cout<<*it;
```

Wrong.

---

Correct

```cpp
it=v.erase(it);
```

---

❌ Using iterator after vector reallocation.

---

# Iterator vs Pointer

| Feature | Pointer | Iterator |
|----------|----------|-----------|
| Raw Memory | ✅ | ❌ |
| Container Aware | ❌ | ✅ |
| Generic | ❌ | ✅ |
| Algorithms | ❌ | ✅ |

Think

```
Iterator

=

Smart Pointer
```

---

# Google Interview Questions

1. Why do STL algorithms use iterators instead of containers?

2. Why does `end()` point past the last element?

3. Which containers support Random Access Iterators?

4. Why can't `sort()` work on a `list`?

5. Why is `distance()` O(n) for lists?

6. Which operations invalidate vector iterators?

7. Difference between `begin()` and `cbegin()`?

8. Difference between `++it` and `it++`?

Expected answer:

Prefer

```cpp
++it
```

because it avoids creating a temporary object for some iterator types.

---

# Best Practices

✅ Prefer `auto` for iterators.

```cpp
auto it=v.begin();
```

---

✅ Prefer range-based loops when possible.

---

✅ Use `const auto&` when only reading.

---

✅ Use `++it` instead of `it++`.

---

✅ Never dereference `end()`.

---

✅ Remember iterator invalidation rules.

---

# Key Takeaways

- Iterators are the bridge between containers and algorithms.
- `begin()` points to the first element; `end()` points one past the last.
- Different containers expose different iterator categories based on their capabilities.
- `vector`, `array`, and `deque` support random access; `list` and `map` do not.
- Iterator invalidation rules vary by container and are essential for writing correct STL code.
- Modern C++ favors `auto`, range-based loops, and `const auto&` for clean, efficient code.

---

> **End of Part 4**

### Coming Next — **Part 5: STL Algorithms (The Heart of STL)**

We'll cover in depth:

- `sort`, `stable_sort`, `partial_sort`
- `nth_element`
- Binary search family (`binary_search`, `lower_bound`, `upper_bound`, `equal_range`)
- `reverse`, `rotate`, `partition`
- `find`, `count`, `all_of`, `any_of`, `none_of`
- `remove`, `unique`, Erase-Remove Idiom
- Heap algorithms
- Numeric algorithms (`accumulate`, `iota`, `partial_sum`, `adjacent_difference`)
- Set algorithms
- Permutations
- Complexity table
- Interview tricks and Google follow-ups

This is arguably the most important chapter after `vector`.
