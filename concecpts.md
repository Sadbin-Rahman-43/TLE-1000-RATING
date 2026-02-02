```markdown
# 💡 CP Concepts — Quick Review

> *Open this file when revisiting the repo. Review patterns in <2 minutes. No code — just the insight.*

---

## 🔑 Patterns I've Learned

### Indexed Sorting
```cpp
vector<pair<int, int>> arr;        // {value, original_index}
sort(arr.begin(), arr.end());
for (auto [val, idx] : arr) { ... }  // C++17 structured bindings
```
- **Problem**: `B_Array_merging.cpp`
- **When to use**: Operation cost depends on original position after sorting
- **Why it works**: Preserves index while sorting by value → clean unpacking

---

### Most Significant Bit (MSB)
```cpp
int msb = floor(log2(n));  // #include <cmath>
// or: 31 - __builtin_clz(n)  (GCC, n > 0)
```
- **Problem**: `B_Roof_Construction.cpp`
- **When to use**: Need highest power of 2 ≤ n (e.g., binary jumps, segment trees)
- **Caution**: `log2()` has floating-point errors for huge `n` → prefer `__builtin_clz` when possible

---

### Geometry Height Invariance
```
Area = base × height
→ If base is fixed, height stays constant during transformations
```
- **Problem**: `B_Triangles_on_a_Rectangle.cpp`
- **When to use**: Rectangle/triangle area problems with coordinate constraints
- **Aha moment**: Skip complex area calculations — height doesn't change when base is fixed

---

### Priority Queue Simulation
```cpp
// Process events by TIME (not value!)
priority_queue<event, vector<event>, greater<>> pq;  // min-heap by time
```
- **Problem**: `B_Monsters.cpp`
- **When to use**: Entities arrive/act over time (monsters, queries, events)
- **Trap I fell into**: Sorted by health instead of arrival time → wasted 240 min

---

### Sliding Window (Two Pointers)
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    add(a[right]);
    while (invalid()) remove(a[left++]);
    update_answer();
}
```
- **Problem**: `B_Luke_is_a_Foodie.cpp`
- **When to use**: Subarray with constraint (sum ≤ K, max-min ≤ D, etc.)
- **Key**: Expand right → shrink left until valid → record answer

---

### Prefix Sum for Range Queries
```cpp
vector<long long> pref(n+1);
for (int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i];
long long range_sum = pref[r] - pref[l];  // [l, r)
```
- **Problem**: `B_Beautiful_Array.cpp`
- **When to use**: Many range sum queries on static array
- **Bonus**: Works for XOR, min/max (with segment tree), modular sums

---

### Greedy: Sort by Ratio
```cpp
sort(items.begin(), items.end(), [](auto &a, auto &b) {
    return a.value * b.weight < b.value * a.weight;  // avoid float division
});
```
- **Problem**: `B_Divan_and_a_New_Project.cpp`
- **When to use**: Minimize/maximize weighted sum (e.g., time × cost)
- **Why**: Sorting by value/weight ratio gives optimal order

---

## 📌 How to Use This File

1. **Before contests**: Scan this file (60 seconds) to refresh patterns
2. **After solving**: Add **one new pattern** here before closing your editor
3. **When stuck**: Ask *"Which pattern from this list fits?"* before reading editorial

> ✅ **Rule**: If you can't write the core insight in 1 sentence, you don't own the pattern yet.
```