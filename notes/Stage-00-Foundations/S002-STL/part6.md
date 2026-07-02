# Part 6 — Function Objects, Lambdas & Custom Comparators

> **Modern C++ relies heavily on lambdas and function objects. Google interviewers expect you to use them naturally rather than writing unnecessary helper functions.**

---

# Introduction

Suppose we want to sort an array in descending order.

Instead of writing

```cpp
bool compare(int a,int b){
    return a>b;
}

sort(v.begin(),v.end(),compare);
```

Modern C++ allows

```cpp
sort(v.begin(),v.end(),
[](int a,int b){
    return a>b;
});
```

Much cleaner.

Much more readable.

---

# What is a Callable?

A callable is anything that can be invoked like a function.

Examples

```
Function

Lambda

Functor

Function Pointer

std::function
```

All of these are accepted by STL algorithms.

---

# Function Pointer

Old C style.

```cpp
bool cmp(int a,int b){
    return a>b;
}

sort(v.begin(),v.end(),cmp);
```

Works.

But limited.

---

# Function Object (Functor)

A class that overloads

```cpp
operator()
```

Example

```cpp
struct Compare{

    bool operator()(int a,int b){

        return a>b;

    }

};
```

Usage

```cpp
sort(v.begin(),
     v.end(),
     Compare());
```

Notice

```
Compare()
```

behaves like a function.

---

# Why Functors Exist

Unlike normal functions,

functors can store state.

Example

```cpp
struct Multiply{

    int factor;

    Multiply(int x):factor(x){}

    int operator()(int value){

        return value*factor;

    }

};
```

Usage

```cpp
Multiply twice(2);

cout<<twice(10);
```

Output

```
20
```

---

# Functor vs Function

| Feature | Function | Functor |
|----------|----------|----------|
| Stores State | ❌ | ✅ |
| Faster Inlining | Sometimes | Usually |
| Custom Behavior | Limited | Excellent |

Modern C++ often replaces functors with lambdas.

---

# Lambda Expressions

A lambda is an anonymous function.

General syntax

```cpp
[capture](parameters)
{
    body
};
```

Example

```cpp
[](int a,int b){

    return a>b;

}
```

---

# Lambda Anatomy

```cpp
[capture]

(parameters)

mutable

-> return_type

{

body

}
```

Most of the time

only capture and parameters matter.

---

# Simplest Lambda

```cpp
[](){

    cout<<"Hello";

};
```

---

# Lambda with Parameters

```cpp
[](int a,int b){

    return a+b;

}
```

---

# Lambda with Return Type

Usually inferred.

Explicit version

```cpp
[](int a,int b)->int{

    return a+b;

}
```

---

# Capture List

Most confusing lambda topic.

Fortunately,

only six capture styles matter.

---

# Empty Capture

```cpp
[]
```

Captures nothing.

Most common in STL.

Example

```cpp
sort(v.begin(),
     v.end(),

[](int a,int b){

return a>b;

});
```

---

# Capture by Value

```cpp
[=]
```

Copies every outside variable.

Example

```cpp
int x=10;

auto f=[=](){

cout<<x;

};
```

Changing x later

does not affect lambda.

---

# Capture by Reference

```cpp
[&]
```

References all variables.

Example

```cpp
int sum=0;

for(int x:v){

[&](){

sum+=x;

}();

}
```

Original variable changes.

---

# Capture Specific Variable

```cpp
[x]
```

Only x copied.

---

# Capture Specific Variable by Reference

```cpp
[&x]
```

Only x referenced.

---

# Mixed Capture

```cpp
[x,&y]
```

x copied.

y referenced.

Very useful.

---

# Capturing this

Inside classes

```cpp
[this]
```

Allows access to member variables.

---

# Mutable Lambda

Normally

captured values

cannot change.

Example

```cpp
int x=10;

auto f=[x](){

x++;

};
```

Compilation error.

Need

```cpp
mutable
```

Example

```cpp
auto f=[x]() mutable{

x++;

};
```

Only local copy changes.

Original x remains same.

---

# Generic Lambda

C++14

```cpp
auto cmp=[](auto a,
            auto b){

return a>b;

};
```

Works for

```
int

double

pair

...
```

Very useful.

---

# Immediately Invoked Lambda

Can execute instantly.

```cpp
[](){

cout<<"Hello";

}();
```

Rare.

But elegant.

---

# Lambda as Variable

```cpp
auto square=[](int x){

return x*x;

};
```

Usage

```cpp
square(5);
```

---

# Lambdas with Algorithms

Sort descending

```cpp
sort(v.begin(),
     v.end(),

[](int a,int b){

return a>b;

});
```

---

Count even numbers

```cpp
count_if(v.begin(),
         v.end(),

[](int x){

return x%2==0;

});
```

---

Transform

```cpp
transform(v.begin(),
          v.end(),
          v.begin(),

[](int x){

return x*x;

});
```

---

# std::function

Sometimes

exact lambda type

is unknown.

Use

```cpp
function<int(int,int)> add=
[](int a,int b){

return a+b;

};
```

Can store

Functions

Functors

Lambdas

Function pointers

---

# Performance

```
Lambda

Fastest

↓

Functor

↓

Function Pointer

↓

std::function
```

`std::function`

uses type erasure.

Small runtime overhead.

---

# Comparators

A comparator decides ordering.

Must return

```
true

if first argument

should come before

second.
```

---

Ascending

```cpp
bool cmp(int a,int b){

return a<b;

}
```

---

Descending

```cpp
bool cmp(int a,int b){

return a>b;

}
```

---

# Sorting Pairs

Default

```cpp
pair<int,int>
```

Sorted by

```
first

↓

second
```

Lexicographically.

---

Custom

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

Sort by second descending

```cpp
return a.second>
       b.second;
```

---

# Sorting Custom Objects

```cpp
struct Student{

string name;

int marks;

};
```

```cpp
sort(v.begin(),
     v.end(),

[](const Student &a,
   const Student &b){

return a.marks<
       b.marks;

});
```

---

# Comparator Rules

Comparator must satisfy

Strict Weak Ordering.

Practically,

remember

Never write

```cpp
return a<=b;
```

Correct

```cpp
return a<b;
```

Otherwise

Undefined Behavior.

Interview favorite.

---

# Comparator for set

```cpp
struct Compare{

bool operator()(int a,
                int b) const{

return a>b;

}

};

set<int,Compare> s;
```

Descending set.

---

# Comparator for map

```cpp
map<int,
    string,
    Compare>
```

---

# Comparator for priority_queue

Max Heap

(default)

```cpp
priority_queue<int>
```

Min Heap

```cpp
priority_queue<
int,
vector<int>,
greater<int>
> pq;
```

---

Custom

```cpp
struct Compare{

bool operator()(pair<int,int> a,
                pair<int,int> b){

return a.second>
       b.second;

}

};
```

---

# Lambda Comparator for Heap

```cpp
auto cmp=[](auto a,
            auto b){

return a.second>
       b.second;

};

priority_queue<
pair<int,int>,
vector<pair<int,int>>,
decltype(cmp)
> pq(cmp);
```

One of the most useful interview patterns.

---

# Common STL Function Objects

Already available.

```cpp
greater<int>()

less<int>()

equal_to<int>()

not_equal_to<int>()
```

Arithmetic

```cpp
plus<int>()

minus<int>()

multiplies<int>()

divides<int>()
```

Logical

```cpp
logical_and<>

logical_or<>

logical_not<>
```

---

# Common Interview Mistakes

❌ Using

```cpp
<=
```

inside comparator.

---

❌ Forgetting

priority_queue

is Max Heap.

---

❌ Capturing everything

with

```cpp
[&]
```

when unnecessary.

Capture only what you need.

---

❌ Using std::function everywhere.

Prefer

```
auto
```

unless polymorphism is required.

---

# Google Follow-up Questions

### Why are lambdas preferred over normal functions?

Expected Answer

- Local
- Readable
- Can capture state
- Better optimization opportunities
- No unnecessary global functions

---

### Why is std::function slower?

Because it uses

```
Type Erasure
```

and may perform indirect calls.

---

### Why must comparators satisfy Strict Weak Ordering?

Sorting algorithms assume the comparison is consistent.

Violating this assumption leads to undefined behavior.

---

### Why use decltype(cmp) in priority_queue?

Every lambda has a unique compiler-generated type.

`decltype(cmp)` refers to that exact type.

---

# Cheat Sheet

| Task | Best Choice |
|------|-------------|
| Descending Sort | `greater<int>()` or lambda |
| Sort Pair by Second | Lambda |
| Sort Custom Class | Lambda |
| Min Heap | `greater<T>` |
| Max Heap | Default |
| Stateful Callable | Functor |
| Local Comparator | Lambda |
| Generic Comparator | Generic Lambda |
| Runtime Polymorphism | `std::function` |

---

# Key Takeaways

- Lambdas are anonymous functions and are the preferred way to pass custom behavior to STL algorithms.
- Understand capture lists (`[]`, `[=]`, `[&]`, `[x]`, `[&x]`, `[this]`) thoroughly.
- Use generic lambdas (`auto`) whenever appropriate in modern C++.
- Comparators must implement **strict weak ordering**—never use `<=` or `>=`.
- `decltype(cmp)` is required when using a lambda as the comparator type for `priority_queue`.
- Prefer `auto` and lambdas over `std::function` unless runtime flexibility is required.

---

> **End of Part 6**

## Next: **Part 7 — STL Utilities & Modern C++ Essentials**

We'll cover:

- `std::pair`
- `std::tuple`
- Structured Bindings (C++17)
- `std::optional`
- `std::variant`
- `std::string_view`
- `std::array`
- `std::span` (C++20 overview)
- Utility helpers (`move`, `swap`, `exchange`, `tie`, `make_pair`, `make_tuple`)
- Interview use cases and best practices

This chapter will complete the "Modern C++ Toolkit" needed for Google-level coding interviews.
