#include <unordered_set>
#include <vector>
#include <map>
#include <iostream>
#define ll long long
using namespace std;

ll solve(vector<int> v) {
    map<tuple<int, int, int>, int> mp1;
    map<pair<int, int>, int> mps[3];
    ll res = 0;
    for (int i = 2; i < v.size(); i++) {
        res += mps[0][{v[i-1], v[i]}]++;
        res += mps[1][{v[i-2], v[i]}]++;
        res += mps[2][{v[i-2], v[i-1]}]++;
        res -= (mp1[{v[i-2], v[i-1], v[i]}]++) * 3;
    }
    cout << res << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        vector<int> v;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int val; cin >> val;
            v.push_back(val);
        }
        solve(v);
    }
}