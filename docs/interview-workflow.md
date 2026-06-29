# Interview Workflow

> **A repeatable framework for approaching every coding interview problem with clarity, structure, and confidence.**

---

# Objective

The purpose of this workflow is to eliminate randomness during interviews.

Instead of relying on intuition alone, every problem should be approached using the same systematic process.

The goal is to demonstrate:

* Structured thinking
* Strong communication
* Correct algorithm selection
* Clean implementation
* Optimization ability
* Engineering mindset

---

# The Interview Pipeline

Every coding interview follows the same workflow.

```text
Understand

↓

Clarify

↓

Examples

↓

Brute Force

↓

Recognize Pattern

↓

Optimize

↓

Explain

↓

Code

↓

Dry Run

↓

Complexity

↓

Follow-ups
```

Never skip a step.

---

# Phase 1 — Understand the Problem

Do not rush into solving.

Read the problem carefully.

Identify

* Input
* Output
* Constraints
* Objective

Restate the problem in your own words.

Example:

> "Given an array of integers, I need to find the longest subarray satisfying condition X."

This confirms understanding and avoids hidden misunderstandings.

---

# Phase 2 — Ask Clarifying Questions

Clarify assumptions before coding.

Examples

* Can the input contain duplicates?
* Can numbers be negative?
* Can the array be empty?
* Are values sorted?
* Is the input mutable?
* What are the constraints?
* Is extra space allowed?

Good questions demonstrate engineering maturity.

---

# Phase 3 — Work Through Examples

Take a small example.

Then manually solve it.

Observe

* Patterns
* Repeated work
* State transitions
* Invariants

Never skip examples.

---

# Phase 4 — Think Brute Force

Always start with the simplest correct solution.

Explain

* Approach
* Time Complexity
* Space Complexity

This establishes the optimization journey.

Interviewers expect this.

---

# Phase 5 — Pattern Recognition

This is the most important step of the interview.

The biggest mistake candidates make is asking:

> "Which LeetCode problem is this?"

Instead, ask:

> "Which algorithmic pattern naturally fits this problem?"

Google evaluates your ability to identify reusable techniques rather than recall specific solutions.

---

## Recognition Framework

Work through these questions mentally.

### 1. What is the input?

* Array
* String
* Matrix
* Linked List
* Tree
* Graph
* Stream
* Interval
* Number
* Trie

---

### 2. What is being asked?

* Search
* Count
* Maximum
* Minimum
* Existence
* Construction
* Ordering
* Connectivity
* Optimization
* Enumeration

---

### 3. What are the constraints?

Examples

```
n <= 20
```

Backtracking

---

```
n <= 1000
```

O(n²) acceptable

---

```
n <= 100000
```

Need O(n log n) or O(n)

---

```
Multiple Queries
```

Preprocessing

---

### 4. Which keywords appear?

| Keyword       | Possible Pattern             |
| ------------- | ---------------------------- |
| Subarray      | Sliding Window / Prefix Sum  |
| Subsequence   | DP                           |
| Kth Largest   | Heap                         |
| Sorted        | Binary Search / Two Pointers |
| Connected     | Graph                        |
| Shortest Path | BFS / Dijkstra               |
| Interval      | Greedy                       |
| Prefix        | Trie / Prefix Sum            |
| Ancestor      | Tree                         |
| Maximum Sum   | Kadane / DP                  |
| Merge         | Two Pointers / Heap          |

---

### 5. Which pattern naturally fits?

Examples

```
Sorted Array
↓

Binary Search
```

```
Longest Substring
↓

Sliding Window
```

```
Cycle Detection
↓

Fast & Slow Pointer
```

```
Grid Exploration
↓

BFS / DFS
```

```
Repeated State
↓

Dynamic Programming
```

Do not force a pattern.

Let the constraints guide you.

---

# Phase 6 — Optimization

Once the brute force solution is explained, improve it gradually.

Never jump directly to the optimal solution.

Interviewers want to see your reasoning.

Explain each improvement.

Example

```
O(n³)

↓

O(n²)

↓

O(n log n)

↓

O(n)
```

For every optimization explain

* What redundancy is removed?
* What observation is being used?
* Why does complexity improve?

---

# Phase 7 — Explain the Algorithm

Before touching the keyboard, explain your solution.

Use this structure.

```
Idea

↓

Data Structures

↓

Algorithm

↓

Correctness

↓

Complexity
```

A confident explanation often matters as much as the implementation.

---

# Phase 8 — Implementation

Now write the code.

While coding

* Use meaningful variable names.
* Keep functions small.
* Avoid unnecessary comments.
* Think aloud while coding.
* Maintain consistent formatting.

Do not rush.

Correct code is faster than debugging rushed code.

---

# Implementation Checklist

Before writing code ask

* Have I initialized everything?
* What happens for empty input?
* Am I accessing valid indices?
* Will integer overflow occur?
* Are edge cases handled?

---

# Phase 9 — Dry Run

Never say

> "I'm done."

Instead

Run your solution manually.

Use a small example.

Verify

* Variables
* Loops
* Pointer movement
* Recursion
* State transitions
* Final answer

Many bugs disappear during the dry run.

---

# Phase 10 — Complexity Analysis

Always state

## Time Complexity

Worst Case

Average Case (if different)

Best Case (if relevant)

---

## Space Complexity

Extra memory used

Recursive stack (if applicable)

Auxiliary structures

---

Explain *why* the complexity is correct.

Do not simply recite Big-O notation.

---

# Phase 11 — Edge Cases

Before submitting mentally test

* Empty input
* One element
* Two elements
* Duplicate values
* Negative numbers
* Maximum constraints
* Minimum constraints
* Overflow
* Invalid input
* Already sorted
* Reverse sorted

Interviewers often introduce these as follow-up questions.

---

# Phase 12 — Follow-up Questions

Google frequently asks

## Can this use less memory?

---

## Can this be faster?

---

## What if the data arrives as a stream?

---

## What if the input doesn't fit into memory?

---

## What if updates happen continuously?

---

## Can this run in parallel?

---

## How would you scale this?

---

## What assumptions did you make?

Think beyond the coding problem.

Demonstrate engineering thinking.

---

# Communication Guidelines

During the interview

Do

* Explain your reasoning.
* Think aloud.
* Discuss trade-offs.
* Confirm assumptions.
* Admit uncertainty honestly.
* Ask clarifying questions.

Avoid

* Silent coding.
* Guessing.
* Memorizing solutions.
* Defending incorrect assumptions.
* Ignoring interviewer hints.

---

# If You Get Stuck

Do not panic.

Follow this recovery process.

```
Stop

↓

Restate the problem

↓

Summarize what is known

↓

Identify constraints

↓

Return to brute force

↓

Look for redundancy

↓

Derive optimization
```

Most interview recoveries begin by revisiting the brute-force solution.

---

# Final Submission Checklist

Before saying "Done"

* Problem understood
* Assumptions clarified
* Brute force explained
* Pattern identified
* Optimal algorithm derived
* Correctness explained
* Code compiled mentally
* Dry run completed
* Complexity discussed
* Edge cases covered
* Follow-up questions anticipated

---

# The Interview Mindset

Remember:

The interviewer is not looking for someone who memorized 600 problems.

They are looking for an engineer who can

* Analyze unfamiliar problems
* Choose appropriate abstractions
* Justify design decisions
* Communicate effectively
* Adapt to new constraints

Your goal is not merely to produce working code.

Your goal is to demonstrate the thinking process of a software engineer.

# Phase 13 — Correctness Proof

Before moving to implementation, be able to justify why the algorithm is correct.

Every algorithm should answer four questions.

## 1. Why does this algorithm work?

Explain the core idea that guarantees correctness.

Avoid saying:

> "It just works."

Instead explain the reasoning.

---

## 2. What invariant is maintained?

Examples

* Window always satisfies the condition.
* Left pointer never moves backwards.
* Queue always stores candidates in decreasing order.
* DP state always represents the optimal answer up to index *i*.

The invariant is often the strongest correctness argument.

---

## 3. Why can't the algorithm miss a valid answer?

Explain why every valid candidate is considered.

---

## 4. Why can't it produce an invalid answer?

Explain why every generated answer satisfies the problem constraints.

---

# Phase 14 — Trade-off Discussion

Software engineering is about trade-offs.

Discuss alternatives whenever possible.

Example

| Approach    | Time       | Space | Advantages    | Disadvantages |
| ----------- | ---------- | ----- | ------------- | ------------- |
| Brute Force | O(n²)      | O(1)  | Simple        | Slow          |
| Hash Map    | O(n)       | O(n)  | Fast          | Extra memory  |
| Sorting     | O(n log n) | O(1)  | Deterministic | Changes order |

Always explain **why** you selected one approach over another.

---

# Phase 15 — Pattern Reflection

After solving the problem, classify it.

## Pattern

Example

```
Sliding Window
```

---

## Recognition Signals

Example

* Longest subarray
* Contiguous
* Window expands and shrinks
* Maintain frequency

---

## Related Patterns

Example

* Prefix Sum
* Two Pointers
* Monotonic Queue

---

## Common Mistakes

Write down

* What confused you?
* What almost made you choose the wrong pattern?
* What would help recognize it faster next time?

---

# Phase 16 — Google Follow-up Thinking

Google interviews rarely end after the optimal solution.

Think about how the problem changes under different constraints.

## Large Data

What if the input is too large to fit in memory?

---

## Streaming

What if values arrive continuously?

---

## Online Queries

What if queries arrive after preprocessing?

---

## Dynamic Updates

What if the input changes frequently?

---

## Parallel Processing

Can the solution be parallelized?

---

## Distributed Systems

How would this work across multiple machines?

---

## Memory Constraints

Can space be reduced?

---

## Readability

Would another engineer easily understand this solution?

---

# Phase 17 — Communication Checklist

Before Coding

* Restate the problem.
* Confirm assumptions.
* Explain brute force.
* Explain optimization.
* Confirm final approach.

---

During Coding

* Explain important decisions.
* Mention loop invariants.
* Explain variable names.
* Warn about tricky cases.
* Keep communication continuous.

---

After Coding

* Dry run.
* Complexity analysis.
* Edge cases.
* Possible optimizations.
* Trade-offs.

---

# Phase 18 — Interview Red Flags

Avoid these mistakes.

## Technical

* Coding immediately.
* Ignoring constraints.
* Skipping brute force.
* Hardcoding examples.
* Ignoring edge cases.

---

## Communication

* Silent coding.
* Arguing with interviewer.
* Defending incorrect logic.
* Ignoring hints.

---

## Engineering

* Poor variable names.
* Large unstructured functions.
* Magic numbers.
* Duplicate code.
* No complexity discussion.

---

# Phase 19 — Google Evaluation Rubric

Google generally evaluates across several dimensions.

| Skill                 | Description                       |
| --------------------- | --------------------------------- |
| Problem Understanding | Quickly grasps requirements       |
| Communication         | Thinks aloud clearly              |
| Pattern Recognition   | Chooses correct technique         |
| Algorithm Design      | Builds optimal solution logically |
| Coding                | Writes clean, maintainable C++    |
| Correctness           | Can justify solution              |
| Complexity            | Explains trade-offs confidently   |
| Adaptability          | Handles follow-up constraints     |

Strong candidates perform consistently across all dimensions.

---

# Phase 20 — Personal Interview Checklist

Before submitting, verify.

## Understanding

* [ ] Problem understood
* [ ] Constraints identified
* [ ] Clarifications asked

---

## Solution

* [ ] Brute force explained
* [ ] Pattern recognized
* [ ] Optimal approach derived
* [ ] Correctness justified

---

## Code

* [ ] Compiles mentally
* [ ] Proper naming
* [ ] Clean formatting
* [ ] Handles edge cases

---

## Validation

* [ ] Dry run completed
* [ ] Complexity explained
* [ ] Trade-offs discussed
* [ ] Ready for follow-ups

---

# Phase 21 — Pattern Recognition Cheat Sheet

| Problem Clue        | Likely Pattern               |
| ------------------- | ---------------------------- |
| Contiguous Subarray | Sliding Window               |
| Sorted Input        | Binary Search / Two Pointers |
| Top K               | Heap                         |
| Shortest Path       | BFS / Dijkstra               |
| Connectivity        | DFS / Union Find             |
| Prefix Matching     | Trie                         |
| Repeated State      | Dynamic Programming          |
| Interval Merge      | Greedy                       |
| Ancestor Queries    | Trees                        |
| Frequency Tracking  | Hash Map                     |

Always validate against the constraints before committing to a pattern.

---

# Phase 22 — Interview Mindset

Do not optimize for finishing first.

Optimize for demonstrating engineering thinking.

Your interviewer is observing

* How you think
* How you communicate
* How you recover from mistakes
* How you justify decisions
* How you respond to new constraints

The code is only one part of the evaluation.

---

# Phase 23 — Complete Interview Workflow

```text
Read Problem
        ↓
Understand Requirements
        ↓
Ask Clarifying Questions
        ↓
Walk Through Examples
        ↓
Develop Brute Force
        ↓
Recognize Pattern
        ↓
Optimize Solution
        ↓
Explain Algorithm
        ↓
Prove Correctness
        ↓
Discuss Trade-offs
        ↓
Implement
        ↓
Dry Run
        ↓
Complexity Analysis
        ↓
Edge Cases
        ↓
Google Follow-ups
        ↓
Final Summary
```

---

# Golden Rules

1. Never rush into coding.
2. Communicate continuously.
3. Recognition comes before implementation.
4. Derive the optimal solution instead of memorizing it.
5. Always justify correctness.
6. Test your own solution.
7. Discuss trade-offs openly.
8. Think beyond the current constraints.
9. Treat every interview as a collaborative problem-solving discussion.
10. Think like an engineer, not a competitive programmer.

---

# Final Goal

The objective of this workflow is to make every coding interview predictable.

Regardless of the problem, follow the same process.

A consistent process produces consistent performance.

The interviewer should leave with confidence that you can solve unfamiliar problems systematically, communicate effectively, and write production-quality code under pressure.
