# DSA Alternating Topic Tracks

> Pattern-first execution model for the DSA journey.

---

## Core Idea

Study **two DSA topics in parallel**, but **never study both topics in the same session**.

Each topic progresses **one pattern at a time**.

The sessions alternate:

```text
Day 1  → Topic A — Pattern 1
Day 2  → Topic B — Pattern 1
Day 3  → Topic A — Pattern 2
Day 4  → Topic B — Pattern 2
Day 5  → Topic A — Pattern 3
Day 6  → Topic B — Pattern 3
...
```

So the execution model is:

```text
A1 → B1 → A2 → B2 → A3 → B3 → A4 → B4 → ...
```

---

# Topic Pair Sequence

| Pair | Topic A | Topic B |
|---|---|---|
| 1 | Binary Trees | Sliding Window |
| 2 | Binary Search Trees | Two Pointers |
| 3 | Stack | Arrays |
| 4 | Linked List | Queue |
| 5 | Heap | Greedy |
| 6 | Graphs | Recursion & Backtracking |
| 7 | Dynamic Programming | Hashing |
| 8 | Trie | Advanced Strings |
| 9 | Binary Search | Bit Manipulation |
| 10 | Sorting | Mathematics |

---

# Pair 1 — Binary Trees + Sliding Window

```text
D1  → Binary Trees — Pattern 1
D2  → Sliding Window — Pattern 1

D3  → Binary Trees — Pattern 2
D4  → Sliding Window — Pattern 2

D5  → Binary Trees — Pattern 3
D6  → Sliding Window — Pattern 3

...
```

---

# Pair 2 — Binary Search Trees + Two Pointers

```text
D1  → BST — Pattern 1
D2  → Two Pointers — Pattern 1

D3  → BST — Pattern 2
D4  → Two Pointers — Pattern 2

D5  → BST — Pattern 3
D6  → Two Pointers — Pattern 3

...
```

---

# Pair 3 — Stack + Arrays

```text
D1  → Stack — Pattern 1
D2  → Arrays — Pattern 1

D3  → Stack — Pattern 2
D4  → Arrays — Pattern 2

D5  → Stack — Pattern 3
D6  → Arrays — Pattern 3

...
```

---

# Pair 4 — Linked List + Queue

```text
D1  → Linked List — Pattern 1
D2  → Queue — Pattern 1

D3  → Linked List — Pattern 2
D4  → Queue — Pattern 2

D5  → Linked List — Pattern 3
D6  → Queue — Pattern 3

...
```

---

# Pair 5 — Heap + Greedy

```text
D1  → Heap — Pattern 1
D2  → Greedy — Pattern 1

D3  → Heap — Pattern 2
D4  → Greedy — Pattern 2

D5  → Heap — Pattern 3
D6  → Greedy — Pattern 3

...
```

---

# Pair 6 — Graphs + Recursion & Backtracking

```text
D1  → Graphs — Pattern 1
D2  → Recursion & Backtracking — Pattern 1

D3  → Graphs — Pattern 2
D4  → Recursion & Backtracking — Pattern 2

D5  → Graphs — Pattern 3
D6  → Recursion & Backtracking — Pattern 3

...
```

---

# Pair 7 — Dynamic Programming + Hashing

```text
D1  → Dynamic Programming — Pattern 1
D2  → Hashing — Pattern 1

D3  → Dynamic Programming — Pattern 2
D4  → Hashing — Pattern 2

D5  → Dynamic Programming — Pattern 3
D6  → Hashing — Pattern 3

...
```

---

# Pair 8 — Trie + Advanced Strings

```text
D1  → Trie — Pattern 1
D2  → Advanced Strings — Pattern 1

D3  → Trie — Pattern 2
D4  → Advanced Strings — Pattern 2

D5  → Trie — Pattern 3
D6  → Advanced Strings — Pattern 3

...
```

---

# Pair 9 — Binary Search + Bit Manipulation

```text
D1  → Binary Search — Pattern 1
D2  → Bit Manipulation — Pattern 1

D3  → Binary Search — Pattern 2
D4  → Bit Manipulation — Pattern 2

D5  → Binary Search — Pattern 3
D6  → Bit Manipulation — Pattern 3

...
```

---

# Pair 10 — Sorting + Mathematics

```text
D1  → Sorting — Pattern 1
D2  → Mathematics — Pattern 1

D3  → Sorting — Pattern 2
D4  → Mathematics — Pattern 2

D5  → Sorting — Pattern 3
D6  → Mathematics — Pattern 3

...
```

---

# Topic Completion Rule

Topics will **not** be forced to have the same number of patterns.

Example:

```text
Topic A
A1
A2
A3
A4
A5
A6
A7
A8
A9
A10  ← finishes

Topic B
B1
B2
B3
B4
B5
B6
B7
B8
B9
B10
B11
...
```

If Topic A finishes first:

```text
A10
 ↓
Next Topic A → C1

B10
 ↓
Continue Topic B → B11
```

The sequence becomes:

```text
A1 → B1
A2 → B2
A3 → B3
...
A10 → B10
C1 → B11
C2 → B12
...
```

---

# Session Rule

## One Day = One Pattern

A session focuses on **one pattern only**.

Example:

```text
Binary Trees — DFS
```

The session should cover:

1. Pattern understanding
2. Recognition signals
3. Core template
4. Complexity
5. Representative problems
6. Interview-style practice
7. Short revision

Then stop.

The next day switches to the other topic.

---

# Why This Structure

This system provides:

- **Interleaving** — different problem-solving styles are mixed over time.
- **Spaced exposure** — a topic returns after a gap instead of disappearing for weeks.
- **Pattern-first learning** — each session has a specific pattern target.
- **Continuous progression** — both topics move forward independently.
- **Better retention** — returning to a topic requires recalling what was previously learned.
- **Interview realism** — real interviews mix problem types rather than giving a single topic for an entire session.

---

# Important Constraint

The pairing system does **not** override prerequisites.

If a topic has an important dependency, that dependency must be established first.

Examples:

```text
Recursion
   ↓
Binary Trees
   ↓
BST
   ↓
Heap
```

and:

```text
Trees + Queue + Stack
          ↓
        Graphs
```

The topic-pair system is an **execution strategy**, not a replacement for the DSA dependency roadmap.

---

# Master Execution Model

```text
                 DSA ROADMAP
                     │
                     ▼
              Select Topic A
              Select Topic B
                     │
                     ▼
              ┌──────────────┐
              │   Day 1      │
              │   A — P1     │
              └──────────────┘
                     │
                     ▼
              ┌──────────────┐
              │   Day 2      │
              │   B — P1     │
              └──────────────┘
                     │
                     ▼
              ┌──────────────┐
              │   Day 3      │
              │   A — P2     │
              └──────────────┘
                     │
                     ▼
              ┌──────────────┐
              │   Day 4      │
              │   B — P2     │
              └──────────────┘
                     │
                     ▼
                    ...
                     │
                     ▼
             Topic A finishes
                     │
                     ▼
          Replace A with Topic C
                     │
                     ▼
              C1 → B(next)
                     │
                     ▼
                   Repeat
```

---

# Final Rule

> **Never finish an entire topic before starting the next one.**

Instead:

> **Finish one pattern → switch topic → finish one pattern → switch back.**

```text
A1 → B1 → A2 → B2 → A3 → B3 → ...
```

This is the standard execution model for the DSA project.
