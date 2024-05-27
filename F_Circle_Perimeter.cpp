#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
using ll = long long;

set<pair<ll, ll>> visited;

int dfs(ll x, ll y, ll r) {
    if (x <= 0 || visited.count({x, y})) {
        return 0;
    }
    visited.insert({x, y});
    ll dist = x * x + y * y;
    ll lower = r * r, upper = (r+1) * (r+1);
    int res = (lower <= dist) && (dist < upper);
    if (dist < upper)
        res += dfs(x, y+1, r);
    if (dist > lower)
        res += dfs(x-1, y, r);
    return res;
}

void solve() {
    visited.clear();
    int r; cin >> r;
    int x = r, y = 0;
    cout << dfs(x, y, r) * 4 << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}