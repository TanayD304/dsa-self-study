# STL Algorithms

> **Algorithms are the soul of STL. Containers only store data; algorithms perform the work.**

---

# Introduction

One of the biggest strengths of C++ STL is that algorithms are **container-independent**.

Algorithms operate on **iterators**, not containers.

Example

```cpp
sort(v.begin(), v.end());

sort(arr.begin(), arr.end());

sort(dq.begin(), dq.end());
```

Same algorithm.

Different containers.

This is the essence of generic programming.

---

# Categories of STL Algorithms

```
Algorithms

├── Non-Modifying
│   find
│   count
│   all_of
│   any_of
│   none_of
│
├── Modifying
│   copy
│   fill
│   transform
│   replace
│   remove
│
├── Sorting
│   sort
│   stable_sort
│   partial_sort
│   nth_element
│
├── Binary Search
│   binary_search
│   lower_bound
│   upper_bound
│   equal_range
│
├── Heap
│   make_heap
│   push_heap
│   pop_heap
│   sort_heap
│
├── Numeric
│   accumulate
│   iota
│   partial_sum
│   adjacent_difference
│
├── Set Algorithms
│   set_union
│   set_intersection
│   set_difference
│
└── Permutations
    next_permutation
    prev_permutation
```

---

# Non-Modifying Algorithms

These do not modify the container.

---

# find()

Returns iterator to first occurrence.

```cpp
vector<int> v={5,2,8,4};

auto it=find(v.begin(),v.end(),8);

if(it!=v.end())
    cout<<"Found";
```

Complexity

```
O(n)
```

---

# count()

Counts occurrences.

```cpp
count(v.begin(),v.end(),5);
```

Complexity

```
O(n)
```

---

# count_if()

```cpp
count_if(v.begin(),v.end(),
[](int x){

return x%2==0;

});
```

Count even numbers.

---

# all_of()

Returns true if every element satisfies condition.

```cpp
all_of(v.begin(),v.end(),

[](int x){

return x>0;

});
```

---

# any_of()

Returns true if at least one element satisfies condition.

---

# none_of()

Returns true if no element satisfies condition.

---

# Modifying Algorithms

---

# fill()

```cpp
vector<int> v(5);

fill(v.begin(),v.end(),10);
```

Output

```
10 10 10 10 10
```

Complexity

```
O(n)
```

---

# iota()

Sequential values.

```cpp
vector<int> v(5);

iota(v.begin(),v.end(),1);
```

Output

```
1 2 3 4 5
```

Very useful in interviews.

---

# copy()

```cpp
copy(a.begin(),a.end(),b.begin());
```

---

# copy_if()

Copy only selected elements.

```cpp
copy_if(v.begin(),
        v.end(),
        back_inserter(ans),

[](int x){

return x%2==0;

});
```

---

# transform()

Transforms elements.

```cpp
transform(v.begin(),
          v.end(),
          v.begin(),

[](int x){

return x*x;

});
```

Output

```
1 4 9 16 ...
```

---

# replace()

```cpp
replace(v.begin(),
        v.end(),
        5,
        100);
```

---

# replace_if()

Replace conditionally.

---

# swap()

```cpp
swap(a,b);
```

Constant time for most STL containers.

---

# Sorting Algorithms

---

# sort()

Most used STL algorithm.

```cpp
sort(v.begin(),v.end());
```

Ascending.

---

Descending

```cpp
sort(v.begin(),
     v.end(),
     greater<int>());
```

---

Complexity

```
O(n log n)
```

Internally

```
Introsort

=

Quick Sort

↓

Heap Sort

↓

Insertion Sort
```

Interview favorite.

---

# stable_sort()

Maintains relative order of equal elements.

Example

```
Age

20 A

20 B

18 C
```

After sorting

```
18 C

20 A

20 B
```

Notice

A remains before B.

Complexity

```
O(n log n)
```

Uses extra memory.

---

# partial_sort()

Sorts only first K elements.

Useful

Top K problems.

---

# nth_element()

One of the most underrated algorithms.

Example

Need

5th smallest.

```cpp
nth_element(v.begin(),
            v.begin()+4,
            v.end());
```

Guarantees

```
v[4]
```

contains correct value.

Everything before

smaller.

Everything after

larger.

Complexity

Average

```
O(n)
```

Much faster than sorting.

Google likes this.

---

# Binary Search Algorithms

Require sorted data.

---

# binary_search()

Returns bool.

```cpp
binary_search(v.begin(),
              v.end(),
              20);
```

Complexity

```
O(log n)
```

---

# lower_bound()

First element

```
>= target
```

Example

```
1 2 2 2 5 8

Target

2
```

Returns

First

```
2
```

---

# upper_bound()

First element

```
> target
```

Same example

Returns

```
5
```

---

# equal_range()

Returns both.

Equivalent to

```
lower_bound

+

upper_bound
```

---

# Important Formula

Occurrences

```
upper_bound

-

lower_bound
```

Very common interview trick.

---

# reverse()

```cpp
reverse(v.begin(),
        v.end());
```

Complexity

```
O(n)
```

---

# rotate()

Example

```
1 2 3 4 5

Rotate

↓

3 4 5 1 2
```

```cpp
rotate(v.begin(),
       v.begin()+2,
       v.end());
```

Excellent interview algorithm.

---

# partition()

Moves elements satisfying condition first.

```cpp
partition(v.begin(),
          v.end(),

[](int x){

return x%2==0;

});
```

Even numbers first.

Order

NOT maintained.

---

# stable_partition()

Maintains order.

More expensive.

---

# unique()

Very misunderstood.

Example

```
1 1 2 2 3
```

After

```cpp
unique(...)
```

```
1 2 3 ? ?
```

Returns

Iterator.

Container size

does NOT change.

Must use

Erase Remove Idiom.

---

# Erase Remove Idiom

Interview favorite.

Wrong

```cpp
remove(v.begin(),
       v.end(),
       5);
```

Correct

```cpp
v.erase(

remove(v.begin(),
       v.end(),
       5),

v.end()

);
```

Memorize this.

---

# remove_if()

Same idea.

```cpp
v.erase(

remove_if(

v.begin(),

v.end(),

[](int x){

return x%2;

}

),

v.end()

);
```

---

# Heap Algorithms

Rarely used directly.

---

# make_heap()

```cpp
make_heap(v.begin(),
          v.end());
```

Creates max heap.

---

# push_heap()

Adds new element.

---

# pop_heap()

Moves max element to end.

---

# sort_heap()

Converts heap into sorted range.

---

# Numeric Algorithms

---

# accumulate()

Most used.

```cpp
accumulate(v.begin(),
           v.end(),
           0);
```

Sum.

---

Product

```cpp
accumulate(

v.begin(),

v.end(),

1,

multiplies<int>()

);
```

---

# partial_sum()

Input

```
1 2 3 4
```

Output

```
1 3 6 10
```

---

# adjacent_difference()

Reverse of partial sum.

Input

```
1 3 6 10
```

Output

```
1 2 3 4
```

---

# min_element()

```cpp
*min_element(...)
```

Complexity

```
O(n)
```

---

# max_element()

```cpp
*max_element(...)
```

---

# minmax_element()

Returns both together.

One traversal.

---

# Set Algorithms

Input must be sorted.

---

# set_union()

```
A

1 2 4

B

2 3 5

↓

1 2 3 4 5
```

---

# set_intersection()

```
↓

2
```

---

# set_difference()

```
↓

1 4
```

---

# Permutations

---

# next_permutation()

Example

```
123

↓

132

↓

213
```

```cpp
next_permutation(
v.begin(),
v.end());
```

Complexity

```
O(n)
```

Interview favorite.

---

# prev_permutation()

Reverse.

---

# Lexicographical Comparison

```cpp
lexicographical_compare(...)
```

Compares

Dictionary order.

---

# Complexity Cheat Sheet

| Algorithm | Complexity |
|------------|------------|
| find | O(n) |
| count | O(n) |
| all_of | O(n) |
| any_of | O(n) |
| none_of | O(n) |
| fill | O(n) |
| copy | O(n) |
| transform | O(n) |
| replace | O(n) |
| sort | O(n log n) |
| stable_sort | O(n log n) |
| partial_sort | O(n log k) |
| nth_element | O(n) average |
| binary_search | O(log n) |
| lower_bound | O(log n) |
| upper_bound | O(log n) |
| reverse | O(n) |
| rotate | O(n) |
| partition | O(n) |
| unique | O(n) |
| remove | O(n) |
| accumulate | O(n) |
| partial_sum | O(n) |
| min_element | O(n) |
| max_element | O(n) |
| next_permutation | O(n) |

---

# Algorithm Selection Guide

Need...

```
Sort everything

↓

sort()
```

Need

```
Top K

↓

partial_sort()

priority_queue()

nth_element()
```

Need

```
Median

↓

nth_element()
```

Need

```
Existence

↓

binary_search()
```

Need

```
Count occurrences

↓

upper_bound()-lower_bound()
```

Need

```
Remove values

↓

Erase Remove Idiom
```

Need

```
Reverse

↓

reverse()
```

Need

```
Rotate

↓

rotate()
```

Need

```
Running sum

↓

partial_sum()
```

Need

```
Generate 1...n

↓

iota()
```

---

# Common Interview Mistakes

❌ Using `find()` on a sorted array instead of `binary_search()` or `lower_bound()`.

❌ Forgetting that `binary_search()`, `lower_bound()`, and `upper_bound()` require the range to be sorted.

❌ Calling `remove()` and expecting the container size to shrink.

❌ Using `sort()` when `nth_element()` solves the problem in linear average time.

❌ Forgetting that `partition()` does **not** preserve the relative order of elements.

---

# Google Interview Discussion

A strong interviewer may ask:

### Why doesn't `remove()` actually erase elements?

Because STL algorithms operate on **iterator ranges**, not on container internals. `remove()` rearranges elements and returns the new logical end. Only the container (`erase()`) can physically shrink its storage.

### Why is `nth_element()` often better than `sort()`?

If you only need the kth smallest/largest element, sorting the entire array is unnecessary.

- `sort()` → **O(n log n)**
- `nth_element()` → **O(n)** average

Choosing `nth_element()` demonstrates good algorithmic judgment.

---

# Key Takeaways

- STL algorithms are generic because they work on iterators.
- Learn the binary search family (`binary_search`, `lower_bound`, `upper_bound`) thoroughly—they appear frequently in interviews.
- Master the **Erase-Remove Idiom**; it is one of the most common STL interview questions.
- `nth_element()` is an underrated but powerful algorithm for selection problems.
- Prefer the right algorithm over writing manual loops—cleaner, safer, and often more efficient.

---

> **End of Part 5**

## Next: **Part 6 — Function Objects, Lambdas & Custom Comparators**

This chapter will cover:

- Function Objects (Functors)
- Lambda expressions (complete guide)
- Capture lists (`[]`, `[=]`, `[&]`, `[this]`, `[x]`, `[&x]`)
- Mutable lambdas
- Generic lambdas (`auto`)
- `std::function`
- Custom comparators for `sort`, `set`, `map`, and `priority_queue`
- Sorting custom classes
- Interview patterns and Google follow-ups

This is one of the most practical chapters for modern C++17/20 interviews.
