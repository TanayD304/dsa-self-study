# Space Complexity

## Definition

Space Complexity measures the **extra memory (auxiliary memory)** an algorithm uses as the input size grows.

It does **NOT** measure the size of the input itself.

Instead, it measures the additional memory required to execute the algorithm.

---

## Formula

```
Space Complexity = Auxiliary Space + Recursion Stack
```

Interviewers usually ask for **auxiliary space**.

---

## Input Space vs Auxiliary Space

Suppose the input is

```cpp
vector<int> nums(n);
```

The input itself occupies **O(n)** space.

However, this is **not counted** because the input is provided by the caller.

Instead we count only the memory our algorithm allocates.

Example

```cpp
int sum = 0;

for(int x : nums)
    sum += x;
```

Extra memory:

```
sum
x
```

Space Complexity

```
O(1)
```

---

## Example 1

```cpp
int maxElement(vector<int>& nums)
{
    int mx = nums[0];

    for(int x : nums)
        mx = max(mx, x);

    return mx;
}
```

Extra memory

```
mx
x
```

Only two variables.

Space Complexity

```
O(1)
```

---

## Example 2

```cpp
vector<int> copy(vector<int>& nums)
{
    vector<int> ans;

    for(int x : nums)
        ans.push_back(x);

    return ans;
}
```

The new vector stores **n** elements.

Space Complexity

```
O(n)
```

---

## Example 3

```cpp
vector<vector<int>> matrix(n, vector<int>(n));
```

Extra memory

```
n × n
```

Space Complexity

```
O(n²)
```

---

## Example 4 — HashMap

```cpp
unordered_map<int,int> freq;

for(int x : nums)
    freq[x]++;
```

Worst case

Every element is unique.

HashMap stores **n** entries.

Space Complexity

```
O(n)
```

---

## Example 5 — Stack

```cpp
stack<int> st;

for(int x : nums)
    st.push(x);
```

Worst case

Stack contains all elements.

Space Complexity

```
O(n)
```

---

## Example 6 — Queue

```cpp
queue<int> q;
```

If every element is inserted

```
O(n)
```

---

## Example 7 — Priority Queue

```cpp
priority_queue<int> pq;
```

Stores all elements.

```
O(n)
```

---

# Recursion Space

Recursion also consumes memory.

Example

```cpp
int factorial(int n)
{
    if(n==1)
        return 1;

    return n * factorial(n-1);
}
```

Each recursive call is placed on the call stack.

Maximum depth

```
n
```

Extra memory

```
O(n)
```

---

## Binary Search Recursion

Recursive Binary Search

Depth

```
log₂ n
```

Space Complexity

```
O(log n)
```

Iterative Binary Search

```
O(1)
```

because no recursive stack exists.

---

# Common Interview Trap

Candidates often answer

```
vector<int> nums
```

↓

```
O(n)
```

Wrong.

The vector is the **input**.

Unless the algorithm creates another vector, the extra space is

```
O(1)
```

---

# Common Data Structures

| Data Structure | Extra Space |
|---------------|-------------|
| Variables | O(1) |
| Array | O(n) |
| Vector | O(n) |
| Matrix | O(n²) |
| Stack | O(n) |
| Queue | O(n) |
| Deque | O(n) |
| HashMap | O(n) |
| HashSet | O(n) |
| Priority Queue | O(n) |
| Recursion (depth n) | O(n) |
| Binary Search Recursion | O(log n) |

---

# Time vs Space

| Algorithm | Time | Space |
|-----------|------|-------|
| Linear Search | O(n) | O(1) |
| Binary Search (Iterative) | O(log n) | O(1) |
| Binary Search (Recursive) | O(log n) | O(log n) |
| Merge Sort | O(n log n) | O(n) |
| Quick Sort (Average) | O(n log n) | O(log n) |
| BFS | O(V + E) | O(V) |
| DFS (Recursive) | O(V + E) | O(V) |

---

# Space Complexity Rules

1. Count only extra memory.
2. Ignore input storage.
3. Include recursion stack.
4. Every additional data structure contributes to space complexity.
5. State both Time and Space complexity in interviews.
