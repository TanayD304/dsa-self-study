# Part 7 — STL Utilities & Modern C++ Essentials

> **Containers and algorithms solve problems. Utilities make your code cleaner, safer, and more expressive.**

---

# Introduction

Modern C++ provides several utility classes that appear frequently in competitive programming, interviews, and production code.

The most important are:

```
Utilities

├── pair
├── tuple
├── array
├── optional
├── variant
├── string_view
├── move
├── swap
├── exchange
├── tie
├── structured bindings
└── make_pair / make_tuple
```

Most Google interview solutions use at least one of these.

---

# std::pair

## Overview

A pair stores exactly **two values**.

The values may be of different types.

```cpp
pair<int,string> p;
```

Think of it as

```
First

↓

Second
```

---

# Creating Pairs

```cpp
pair<int,string> p;

p.first=1;

p.second="Alice";
```

or

```cpp
pair<int,string> p={1,"Alice"};
```

or

```cpp
auto p=make_pair(1,"Alice");
```

---

# Accessing Members

```cpp
cout<<p.first;

cout<<p.second;
```

---

# Comparison

Pairs compare lexicographically.

Suppose

```
(1,5)

(2,3)
```

Comparison

```
1<2

↓

True
```

If first values are equal,

second values are compared.

```
(2,5)

(2,9)

↓

5<9
```

---

# Sorting Vector of Pairs

Default

```cpp
sort(v.begin(),v.end());
```

Sorts

```
First

↓

Second
```

Automatically.

---

# Custom Sorting

Sort by second.

```cpp
sort(v.begin(),
     v.end(),

[](auto &a,
   auto &b){

return a.second<
       b.second;

});
```

---

# Common Uses

✅ Coordinates

```
(x,y)
```

---

✅ Graph

```
(node,weight)
```

---

✅ Heap

```
(distance,node)
```

---

✅ Intervals

```
(start,end)
```

---

# std::tuple

---

# Overview

A tuple stores

```
Multiple Values
```

of possibly different types.

Unlike pair,

it supports any number of elements.

Example

```cpp
tuple<int,string,double> t;
```

---

# Creating Tuple

```cpp
auto t=make_tuple(
1,
"Alice",
95.5
);
```

---

# Accessing Values

Use

```cpp
get<0>(t);

get<1>(t);

get<2>(t);
```

Unlike pair,

no

```
first

second
```

members.

---

# Structured Bindings (C++17)

Before C++17

```cpp
auto p=make_pair(1,2);

cout<<p.first;
```

Now

```cpp
auto [x,y]=p;
```

Very common.

---

Tuple

```cpp
auto [id,name,marks]=t;
```

Cleaner.

---

# Why Structured Bindings Matter

Graph traversal

Instead of

```cpp
auto p=q.front();

int node=p.first;

int dist=p.second;
```

Simply

```cpp
auto [node,dist]=q.front();
```

Much cleaner.

---

# std::tie()

Unpacks values.

Example

```cpp
int x,y;

tie(x,y)=p;
```

Equivalent

```
x=p.first

y=p.second
```

---

# ignore

Sometimes

only one value needed.

```cpp
int x;

tie(x,ignore)=p;
```

---

# std::array

Although already discussed,

remember

```cpp
array<int,5>
```

Advantages

✅ STL compatible

✅ Fixed size

✅ Stack allocation

---

# std::optional (C++17)

Sometimes

a function

may not return a value.

Instead of

```
-1

NULL

Magic Numbers
```

Use

```cpp
optional<int>
```

Example

```cpp
optional<int> find(){

return {};

}
```

Meaning

```
No Value
```

---

Returning value

```cpp
return 10;
```

---

Checking

```cpp
if(ans){

cout<<*ans;

}
```

Safer.

---

# value()

Retrieve

```cpp
ans.value();
```

Throws exception

if empty.

---

# value_or()

Provide default.

```cpp
ans.value_or(0);
```

---

# std::variant (C++17)

Stores

one of several types.

Example

```cpp
variant<
int,
double,
string
> data;
```

Later

```cpp
data=10;

data="Hello";

data=3.14;
```

Useful

when exact type changes.

---

# get()

```cpp
get<int>(data);
```

---

# holds_alternative()

```cpp
holds_alternative<int>(data);
```

Safe checking.

---

# std::string_view (C++17)

Huge performance improvement.

Suppose

```cpp
string s="Hello";
```

Passing

```cpp
string
```

copies data.

Instead

```cpp
string_view
```

creates

view only.

No copying.

---

Visualization

```
String

Hello World

^^^^^^^^

View
```

---

Advantages

✅ Faster

✅ No allocation

✅ Read only

---

Limitation

Underlying string

must remain alive.

---

# std::move

One of the most misunderstood features.

Normally

```cpp
string a="Hello";

string b=a;
```

Copies.

Instead

```cpp
string b=move(a);
```

Ownership transferred.

Usually

No copy.

Very fast.

---

After move

Original object

still valid

but

state unspecified.

Do not assume

its contents.

---

# std::swap

Swaps values.

```cpp
swap(a,b);
```

Complexity

Usually

```
O(1)
```

---

# std::exchange (C++14)

Replace

and

return old value.

Example

```cpp
int x=10;

int old=
exchange(x,20);
```

Result

```
old

10

x

20
```

Very elegant.

---

# make_pair()

Instead of

```cpp
pair<int,int> p(
1,
2
);
```

Use

```cpp
auto p=
make_pair(1,2);
```

Compiler

deduces types.

---

# make_tuple()

Similarly

```cpp
auto t=
make_tuple(
1,
"A",
90
);
```

---

# emplace()

Container construction.

Instead of

```cpp
v.push_back(
make_pair(1,2)
);
```

Use

```cpp
v.emplace_back(
1,
2
);
```

Avoids temporary object.

Preferred.

---

# Common Interview Patterns

---

Graph

```cpp
vector<
pair<int,int>
>
```

---

Priority Queue

```cpp
priority_queue<
pair<int,int>
>
```

---

Intervals

```cpp
vector<
pair<int,int>
>
```

---

Multiple Return Values

```cpp
tuple<>
```

---

BFS

```cpp
queue<
pair<int,int>
>
```

---

# Utility Comparison

| Utility | Stores | Typical Use |
|----------|--------|-------------|
| pair | 2 values | Coordinates, edges, intervals |
| tuple | Many values | Multiple return values |
| optional | 0 or 1 value | Safe absence of data |
| variant | One of many types | Type-safe unions |
| string_view | String reference | Fast read-only string handling |
| array | Fixed-size array | Compile-time sized collections |

---

# Common Mistakes

❌ Using tuple

when pair

is enough.

---

❌ Returning

magic numbers

instead of optional.

---

❌ Accessing moved-from object.

---

❌ Returning

string_view

to temporary string.

Example

Wrong

```cpp
string_view f(){

string s="Hello";

return s;
}
```

String destroyed.

View becomes dangling.

---

❌ Forgetting

structured bindings

copy values.

Need reference

```cpp
auto &[x,y]=p;
```

if modifications required.

---

# Google Follow-up Questions

### Why use pair instead of creating a struct?

Expected Answer

For simple two-value relationships.

If fields have semantic meaning,

a struct is usually clearer.

---

### Why is string_view faster?

Because it avoids copying.

Only stores

```
Pointer

+

Length
```

---

### Why is optional better than returning -1?

Type safety.

No ambiguity.

Expresses intent clearly.

---

### Why is move faster?

Ownership transferred.

Deep copy avoided.

---

### Difference between push_back() and emplace_back()?

`push_back()`

creates an object

then inserts it.

`emplace_back()`

constructs the object directly inside the container,

avoiding an extra copy or move.

---

# Best Practices

✅ Prefer `emplace_back()` for complex objects.

✅ Use structured bindings for readability.

✅ Use `pair` only when two values naturally belong together.

✅ Prefer `optional` over sentinel values.

✅ Use `string_view` for read-only string parameters.

✅ Use `move()` only when you no longer need the original object.

---

# Cheat Sheet

| Need | Utility |
|------|---------|
| Two values | `pair` |
| Multiple values | `tuple` |
| Unpack pair | Structured Bindings |
| Optional return | `optional` |
| Multiple possible types | `variant` |
| Read-only string | `string_view` |
| Transfer ownership | `move` |
| Replace and return old value | `exchange` |
| Construct in-place | `emplace_back` |

---

# Key Takeaways

- `pair` and `tuple` simplify grouping related values.
- Structured bindings (`auto [x, y]`) greatly improve readability.
- `optional` expresses "a value may not exist" without using sentinel values.
- `variant` is a type-safe alternative to unions.
- `string_view` avoids unnecessary string copies and is ideal for read-only parameters.
- `move` enables efficient ownership transfer, while `emplace_back` constructs objects directly inside containers.

---

> **End of Part 7**

## Next: **Part 8 — STL Complexity Tables, Iterator Invalidation, Memory Layout & Container Selection Guide**

This will be your **ultimate revision chapter**, including:

- ✅ Master complexity comparison table (all containers)
- ✅ Iterator invalidation matrix
- ✅ Memory layout diagrams
- ✅ Cache locality comparison
- ✅ Time vs space trade-offs
- ✅ Container decision tree
- ✅ STL interview cheat sheet
- ✅ "Which container should I use?" flowchart

This will likely become the most frequently revisited section of your STL handbook.