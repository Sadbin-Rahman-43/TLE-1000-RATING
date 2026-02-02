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

###  Window/Sliding Window
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