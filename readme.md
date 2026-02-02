# 💡 TLE 1000 Rating — CP Concepts Quick Review

> *Open this file when revisiting the repo. Review patterns in <2 minutes. No code — just the insight.*

**Repository**: [Sadbin-Rahman-43/TLE-1000-RATING](https://github.com/Sadbin-Rahman-43/TLE-1000-RATING)  
**Source**: [TLE Eliminators CP Sheet](https://www.tle-eliminators.com/cp-sheet)

---

## 📊 Progress Overview

| Pattern Category | Problems Solved | Mastery Level |
|-----------------|----------------|---------------|
| Sorting & Indexing | 3 | ⭐⭐⭐ |
| Greedy Algorithms | 2 | ⭐⭐ |
| Two Pointers / Sliding Window | 2 | ⭐⭐ |
| Prefix Sums | 1 | ⭐⭐ |
| Priority Queue / Simulation | 1 | ⭐⭐ |
| Bit Manipulation | 1 | ⭐⭐ |
| Geometry / Math | 1 | ⭐ |

---

## 🔑 Core Patterns

### 1️⃣ Indexed Sorting
**Core Insight**: Preserve original indices while sorting to track position-dependent operations

```cpp
vector<pair<int, int>> arr;        // {value, original_index}
sort(arr.begin(), arr.end());
for (auto [val, idx] : arr) { ... }  // C++17 structured bindings
```

| Problem | Difficulty | Time | Link |
|---------|-----------|------|------|
| Array Merging | 1000 | O(n log n) | [Problem](https://codeforces.com/problemset/problem/1831/B) |
| Shoe Shuffling | 1000 | O(n log n) | [Problem](https://codeforces.com/problemset/problem/1691/B) |

**When to use**: 
- Operation cost depends on original position after sorting
- Need to map sorted values back to original indices
- Ranking/ordering problems with position tracking

**Common Pitfall**: Forgetting to store index before sorting → impossible to reconstruct original order

---

### 2️⃣ Most Significant Bit (MSB)
**Core Insight**: Find the highest set bit to determine power-of-2 boundaries

```cpp
int msb = floor(log2(n));  // #include <cmath>
// or: 31 - __builtin_clz(n)  (GCC, n > 0)
```

| Problem | Difficulty | Time | Link |
|---------|-----------|------|------|
| Roof Construction | 1000 | O(n) | [Problem](https://codeforces.com/problemset/problem/1632/B) |

**When to use**: 
- Need highest power of 2 ≤ n (binary jumps, segment trees)
- XOR minimization problems
- Binary representation analysis

**Common Pitfall**: `log2()` has floating-point errors for huge `n` → prefer `__builtin_clz` when possible

**Related Concepts**: `__builtin_popcount()`, `__builtin_ctz()` (count trailing zeros)

---

### 3️⃣ Geometry Height Invariance
**Core Insight**: When base is fixed, height remains constant regardless of transformations

```
Area = base × height
→ If base is fixed, height stays constant during transformations
```

| Problem | Difficulty | Time | Link |
|---------|-----------|------|------|
| Triangles on a Rectangle | 1000 | O(n) | [Problem](https://codeforces.com/problemset/problem/1620/B) |

**When to use**: 
- Rectangle/triangle area problems with coordinate constraints
- One dimension is bounded/fixed
- Maximization problems on grids

**Aha moment**: Skip complex area calculations — height doesn't change when base is fixed

---

### 4️⃣ Priority Queue Simulation
**Core Insight**: Process events by TIME, not by value — simulate chronological order

```cpp
// Process events by TIME (not value!)
priority_queue<event, vector<event>, greater<>> pq;  // min-heap by time
```

| Problem | Difficulty | Time | Link |
|---------|-----------|------|------|
| Monsters | 1000 | O(n log n) | [Problem](https://codeforces.com/problemset/problem/1810/B) |

**When to use**: 
- Entities arrive/act over time (monsters, queries, events)
- Simulation with temporal ordering
- Scheduling problems

**Note**: Took **240 minutes** to solve, watched solution afterward  
**Key Insight**: Identify the correct ordering criterion (time vs. value vs. other attributes)

---

### 5️⃣ Sliding Window (Two Pointers)
**Core Insight**: Maintain a valid window by expanding right, shrinking left

```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    add(a[right]);
    while (invalid()) remove(a[left++]);
    update_answer();
}
```

| Problem | Difficulty | Time | Link |
|---------|-----------|------|------|
| Luke is a Foodie | 1000 | O(n) | [Problem](https://codeforces.com/problemset/problem/1704/B) |
| Ski Resort | 1000 | O(n) | [Problem](https://codeforces.com/problemset/problem/1840/C) |

**When to use**: 
- Subarray with constraint (sum ≤ K, max-min ≤ D, etc.)
- Contiguous elements with monotonic property
- "Find longest/shortest subarray satisfying X"

**Key Pattern**: Expand right → shrink left until valid → record answer

**Variations**:
- Fixed window size: `if (right - left + 1 == k)`
- Variable window: `while (invalid())`
- Count subarrays: Add `(right - left + 1)` to answer

---

### 6️⃣ Prefix Sum for Range Queries
**Core Insight**: Precompute cumulative sums for O(1) range queries

```cpp
vector<long long> pref(n+1);
for (int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i];
long long range_sum = pref[r] - pref[l];  // [l, r)
```

| Problem | Difficulty | Time | Link |
|---------|-----------|------|------|
| Beautiful Array | 1000 | O(n) | [Problem](https://codeforces.com/problemset/problem/1783/B) |

**When to use**: 
- Many range sum queries on static array
- Subarray sum problems
- Difference array for range updates

**Bonus Techniques**:
- **XOR prefix**: `pref[r] ^ pref[l]` gives XOR of range
- **2D prefix sum**: `pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i][j]`
- **Modular sums**: Works with `(pref[r] - pref[l] + MOD) % MOD`

---

### 7️⃣ Greedy: Sort by Ratio
**Core Insight**: Minimize weighted sum by sorting by value/weight ratio

```cpp
sort(items.begin(), items.end(), [](auto &a, auto &b) {
    return a.value * b.weight < b.value * a.weight;  // avoid float division
});
```

| Problem | Difficulty | Time | Link |
|---------|-----------|------|------|
| Divan and a New Project | 1000 | O(n log n) | [Problem](https://codeforces.com/problemset/problem/1614/B) |

**When to use**: 
- Minimize/maximize weighted sum (e.g., time × cost)
- Fractional knapsack
- Job scheduling with deadlines

**Why it works**: Sorting by value/weight ratio gives optimal order (exchange argument proof)

**Common Pitfall**: Using floating-point division → use cross-multiplication instead

---

## 🧰 Quick Reference: Template Snippets

### Fast I/O
```cpp
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
```

### Common Macros
```cpp
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, n) for (int i = (a); i < (n); i++)
```

### Min/Max Heap
```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;  // min-heap
priority_queue<int> maxHeap;  // max-heap (default)
```

### Frequency Map
```cpp
map<T, int> freq;
for (auto x : arr) freq[x]++;
```

### Binary Search
```cpp
// Find first element >= x
auto it = lower_bound(all(v), x);
// Find first element > x
auto it = upper_bound(all(v), x);
```

---

## 🎯 Problem-Solving Checklist

Before coding, ask yourself:

- [ ] **What is the constraint?** (n ≤ 10^5 → O(n log n) is safe)
- [ ] **Is there a pattern?** (Check this README first!)
- [ ] **What's the natural ordering?** (Time? Value? Index?)
- [ ] **Can I sort?** (Will it break the problem?)
- [ ] **Do I need to preserve indices?** (Use `pair<value, index>`)
- [ ] **Is it a subarray problem?** (Try sliding window or prefix sum)
- [ ] **Is it greedy?** (Can I prove the exchange argument?)

---

## 📌 How to Use This File

1. **Before contests**: Scan patterns (60 seconds) to refresh muscle memory
2. **After solving**: Add **one new pattern** here before closing your editor
3. **When stuck**: Ask *"Which pattern from this list fits?"* before reading editorial
4. **Weekly review**: Update mastery levels and add related problems

> ✅ **Golden Rule**: If you can't write the core insight in 1 sentence, you don't own the pattern yet.

---

## 🔗 Additional Resources

- [TLE Eliminators CP Sheet](https://www.tle-eliminators.com/cp-sheet) - Problem source
- [Codeforces](https://codeforces.com/) - Practice platform
- [CP Algorithms](https://cp-algorithms.com/) - Algorithm reference
- [USACO Guide](https://usaco.guide/) - Structured learning path

---

## 📝 Notes & Reflections

### Biggest Lessons Learned
1. **Always identify the event ordering** (Monsters problem - 240 min wasted)
2. **Preserve indices when sorting** (Saves debugging time)
3. **Read constraints carefully** (They hint at the solution complexity)

### Next Patterns to Master
- [ ] Binary Search on Answer
- [ ] Graph BFS/DFS
- [ ] Dynamic Programming (1D)
- [ ] Number Theory (GCD/LCM)
- [ ] String Hashing

---

*Last Updated: 2026-02-02*