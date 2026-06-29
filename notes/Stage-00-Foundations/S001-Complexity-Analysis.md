# S001 — Complexity Analysis

> Stage 00 — Foundations

---

# Session Information

| Field | Value |
|------|------|
| Session | S001 |
| Pattern | Complexity Analysis |
| Difficulty | ⭐ |
| Status | Completed |

---

# Learning Objectives

- Understand Time Complexity
- Understand Space Complexity
- Analyze loops confidently
- Compare algorithms using asymptotic analysis

---

# Overview

Complexity Analysis measures how an algorithm scales as the input size (n) increases.

Instead of measuring actual execution time, we measure the growth rate of operations.

This makes algorithm analysis independent of hardware, compiler and programming language.

---

# Core Intuition

As n becomes very large, constants become insignificant.

Only the fastest-growing term matters.

Example:

100n

↓

O(n)

n² + 5n + 20

↓

O(n²)

---

# Time Complexity

Measures the number of operations performed.

Common complexities:

O(1)

Constant

O(log n)

Binary Search

O(n)

Linear Scan

O(n log n)

Merge Sort

O(n²)

Nested Loops

O(2ⁿ)

Exponential

O(n!)

Factorial

---

# Space Complexity

Measures additional memory used.

Examples:

int x;

↓

O(1)

vector<int> arr(n);

↓

O(n)

int matrix[n][n];

↓

O(n²)

---

# Rules for Calculating Complexity

## Rule 1

Sequential statements

O(1)

---

## Rule 2

Single loop

O(n)

---

## Rule 3

Nested loops

Usually O(n²)

Always inspect loop bounds.

---

## Rule 4

Independent loops

O(n + m)

---

## Rule 5

Nested loops with different variables

O(n × m)

---

## Rule 6

Halving every iteration

O(log n)

Example:

while(n > 1)
    n /= 2;

---

## Rule 7

Doubling every iteration

O(log n)

Example:

for(i=1;i<n;i*=2)

---

# Common Mistakes

❌ Assuming every nested loop is O(n²)

Always inspect the limits.

Example:

for(i=0;i<n;i++)
    for(j=i;j<n;j++)

Still O(n²), but because total iterations are:

n + (n−1) + ... + 1

Not because there are two loops.

---

# Complexity Cheat Sheet

| Pattern | Complexity |
|----------|------------|
| Single statement | O(1) |
| Single loop | O(n) |
| Nested loops | O(n²) |
| Triple nested | O(n³) |
| Divide by 2 | O(log n) |
| Multiply by 2 | O(log n) |

---

# Key Takeaways

1. Ignore constants.
2. Keep only the dominant term.
3. Analyze actual iterations, not just loop count.
4. Halving and doubling indicate logarithmic complexity.
5. Complexity describes growth, not execution time.

---

# Confidence

Recognition ⭐⭐⭐⭐☆

Implementation ⭐⭐⭐⭐⭐

Interview ⭐⭐⭐⭐☆
