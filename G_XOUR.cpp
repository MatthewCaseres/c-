#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums;
    vector<int> res;
    map<int, vector<int>> buckets;
    map<int, int> cts;
    while (n--) {
        int val;
        cin >> val;
        nums.push_back(val);
        buckets[val & ~3].push_back(val&3);
    }
    for (auto& bucket: buckets) {
        sort(bucket.second.begin(), bucket.second.end());
    }
    for (int i = 0; i < nums.size(); i++) {
        int bucket = nums[i] & ~3;
        cout << bucket + buckets[bucket][cts[bucket]++] << (i == nums.size() - 1 ? '\n' : ' ');
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}