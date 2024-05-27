#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
using ll = long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = 1;
    for (int j = 0; j < 20; j++) {
        int cur = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i]>>j&1) {
                ans = max(ans, i - cur);
                cur = i;
            }
        }
        if (cur!=-1) ans = max(ans, n-cur);
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}