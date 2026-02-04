# TLE 1000 Rating Solutions

Solutions to 1000-rated problems from [TLE Eliminators CP Sheet](https://www.tle-eliminators.com/cp-sheet).

---

## Patterns & Problems

### Bit Manipulation (MSB)

Find highest set bit for power-of-2 boundaries.

```cpp
msb(n) = lower_bound(log2(n));
int msb = 31 - __builtin_clz(n);  // GCC builtin
```

**Problems:**

- [B. Roof Construction](https://codeforces.com/problemset/problem/1632/B) → `B_Roof_Construction.cpp`

---

### Geometry

Area calculations with fixed dimensions.Height reamins same inside rectangle

**Problems:**

- [B. Triangles on a Rectangle](https://codeforces.com/problemset/problem/1620/B) → `B_Triangles_on_a_Rectangle.cpp`

---

### Window/Sliding Window

Maintain valid window by expanding right, shrinking left.

```cpp
    sb(v);
    ll l = p[0].ff;
    ll r = p[0].ss;

    rep(i, 1, n)
    {
        l = max(l, p[i].ff);
        r = min(r, p[i].ss);
        if (l > r)
        {
            c++;
            l = p[i].ff;
            r = p[i].ss;

```

**Problems:**

- [B. Luke is a Foodie](https://codeforces.com/problemset/problem/1704/B) → `B_Luke_is_a_Foodie.cpp`

---

### Prefix Sum

Precompute cumulative sums for O(1) range queries.

```cpp
vector<ll> pref(n+1);
for (int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i];
ll sum = pref[r] - pref[l];  // sum of [l, r)
```

**Problems:**

- [B. Beautiful Array](https://codeforces.com/contest/1715/problem/B) → `B_Beautiful_Array.cpp`

---

```cpp
vector<pair<ll,ll>> arr;
    for (int i = 0; i < n; i++)
        arr.pb({v[i], i});

    bs(arr);

    vl res(n);

    for (int pos = 0; pos < n; pos++)
    {
        auto [val, idx] = arr[pos];
```

**Problems:**

- [B. Divan and a New Project](https://codeforces.com/problemset/problem/1614/B) → `B_Divan_and_a_New_Project.cpp`

---

### XOR Prefix Cycle (0 to n)

```cpp
long long xor_0_to_n(long long n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        default: return 0;  // case 3
    }
}
```

- **Problem**:
- [MEXor Mixup](https://codeforces.com/problemset/problem/1567/B) → `MEXor_Mixup_1567B.cpp`
- **When to use**: Need XOR of all numbers from 0 to n (O(1) instead of loop)
- **Why it works**: XOR has 4-cycle pattern due to bit symmetry

### MEX + XOR Relationship

```
MEX = a  →  array contains [0, a-1] but NOT a
Let X = xor(0..a-1)

if X == b:        answer = a          // [0..a-1] already gives XOR b
elif (X ^ b) != a: answer = a + 1      // add single number (X^b) which ≠ a
else:             answer = a + 2      // cannot add 'a' (breaks MEX), need two numbers
```

- **Problem**:
- [MEXor Mixup](https://codeforces.com/problemset/problem/1567/B) → `MEXor_Mixup_1567B.cpp`
- **Key trap**: When `(X ^ b) == a`, you _cannot_ add `a` (would break MEX) → must use two extra numbers
- **Aha moment**: MEX constraint blocks one specific value — check if your "fix number" is that blocked value

---

### Longest Common Substring (LCSUB)
```cpp
// dp[i][j] = length of common substring ending at a[i-1] and b[j-1]
int ml = 0;
for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
        if (a[i-1] == b[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1;
            ml = max(ml, dp[i][j]);
        }
        else dp[i][j] = 0;  // reset (contiguous required!)
    }
}
```
- **Problem**: `Double_ended_Strings_1506C.cpp`
- **When to use**: Minimum deletions to make two strings equal by removing from ends only
- **Why it works**: Keep the longest *contiguous* matching part → delete everything else from both strings
- **Answer formula**: `(len(a) - ml) + (len(b) - ml)`
- **Critical detail**: Reset to `0` on mismatch (unlike LCS which carries max from left/top) — we need *contiguous* match

---

> 💡 **Pattern name**: This is **Longest Common Substring** (not to be confused with Longest Common Subsequence). The `dp[i][j] = 0` on mismatch is the key difference.