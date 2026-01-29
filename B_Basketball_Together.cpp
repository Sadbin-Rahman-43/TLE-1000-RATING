#include <bits/stdc++.h>
using namespace std;

// ---------------- Typedefs ----------------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using str = string;

// ---------------- Macros ----------------
#define endl "\n"
#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define repan(i, a, n) for (int i = (a); i <= (n); i++)
#define per(i, a, n) for (int i = (n) - 1; i >= (a); i--)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define bs(v) sort(all(v), greater<int>())
#define sb(v) sort(all(v))
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)
#define MOD 1000000007LL
#define PI 3.14159265358979323846
#define INFi 1000000000
#define INF 3000000000000000000LL
#define LG 20

const double EPSILON = 1e-9;

// ---------------- Utility Functions ----------------
bool isInteger(double num) { return fabs(num - floor(num)) < EPSILON; }

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int Bit(int mask, int b) { return (mask >> b) & 1; }

template <class T>
bool ckmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool ckmax(T &a, const T &b)
{
    if (b > a)
    {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll modPow(ll base, ll exp, ll mod)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

inline void YES() { cout << "YES" << endl; }
inline void NO() { cout << "NO" << endl; }

// ---------------- Debugging Helpers ----------------
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << endl
template <class T>
void dbgvec(const T &v)
{
    cerr << "[";
    for (auto &x : v)
        cerr << x << " ";
    cerr << "]\n";
}
#else
#define dbg(x)
#define dbgvec(v)
#endif

// ---------------- Common Template Functions ----------------
template <class T>
T sum_vector(const vector<T> &v)
{
    T sum = 0;
    each(x, v) sum += x;
    return sum;
}

template <class T>
void print_vector(const vector<T> &v, char sep = ' ')
{
    each(x, v) cout << x << sep;
    cout << endl;
}

// ---------------- Solve Function ----------------
void solve()
{
    ll n, d,w=0;
    cin >> n >> d;
    
    vl a(n);
    each(x, a)
            cin >>
        x;
        bs(a);
    for(int i = 0, j = n; i < j; i++)
      {
            int s= 0;
            while(s<= d && j != i)
            {
                  s+= a[i];
                  if(s<= d) j--;
            }
            if(s> d) w++;
      }
    cout << w << endl;
}

int main()
{
    fastio;
    int t = 1;
    // cin >> t;
    rep(i, 0, t) solve();
    return 0;
}