#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull =  unsigned long long;
using ld = long double;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using t3 = tuple<int, int, int, int>;

#define endl "\n"
#define ft first
#define sd second
#define openfiles ifstream cin ("check.in"); ofstream cout ("check.out");
#define pb push_back
#define eb emplace_back
#define in insert
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int INF = 1000000010;
const ll INFLL = 1000000000010000010;
const ld EPS = 0.0000001;
const ll MOD = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define mt make_tuple
#define g0(x) get<0>(x)
#define g1(x) get<1>(x)
#define g2(x) get<2>(x)
#define g3(x) get<3>(x)

int n;
vector<pair<int, int>> G;
vector<int> isRoot;
vector<int> N;

bool dfs(int x, int l, int r) {
    if (N[x] <= l || N[x] >= r) return false;
    if (G[x].first != -1) {
        if (!dfs(G[x].first, l, N[x])) {
            return false;
        }
    }
    if (G[x].second != -1) {
        if (!dfs(G[x].second, N[x], r)) {
            return false;
        }
    }
    return true;
}

#define KlishkevichVadimka
signed main()
{
#ifdef KlishkevichVadimka
    openfiles
#endif
    faster;
    clock_t zzz = clock();

    cin >> n;

    if (n == 0) {
        cout << "YES\n";
        return 0;
    }

    G.resize(n);
    isRoot.resize(n, 1);
    N.resize(n);
    for (int i = 0; i < n; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        l--, r--;
        if (l != -1) {
            isRoot[l] = 0;
        }
        if (r != -1) {
            isRoot[r] = 0;
        }
        N[i] = x;
        G[i] = {l, r};
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (isRoot[i] && root == -1) root = i;
        else if (root == -1) {
            cout << "NO\n";
            return 0;
        }
    }

    if (root == -1) {
        cout << "NO\n";
        return 0;
    }

    bool cool = dfs(root, -INF, INF);

    if (cool) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    cerr << endl << "Time : " << ld(clock() - zzz) / CLOCKS_PER_SEC;
}