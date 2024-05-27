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
    int n; cin >> n;
    set<int> sets[2];
    map<int, int> mp;
    vector<int> nums(n);
    int lowMod = -1;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] == 1) lowMod = i%2;
    }
    for(int i = 0; i < n; i++) {
        if (i%2 == lowMod) {
            sets[0].insert(nums[i]);
        } else {
            sets[1].insert(nums[i]);
        }
    }
    int val = 1;
    for(auto rit = sets[0].rbegin(); rit != sets[0].rend(); ++rit) {
        mp[*rit] = val++;
    }
    for(auto rit = sets[1].rbegin(); rit != sets[1].rend(); ++rit) {
        mp[*rit] = val++;
    }
    for (int i = 0; i < n; ++i) {
        cout << mp[nums[i]] << (i == nums.size() - 1 ? '\n' : ' ');
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}