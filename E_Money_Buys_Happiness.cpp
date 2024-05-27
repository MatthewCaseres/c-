#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
using ll = long long;

struct Val {
    int month;
    ll balance;
    int happiness;

    ll balance_at_time(int t, ll salary) const {
        return (t - month) * salary + balance;
    }
};

// Helper function to print an El struct
std::ostream& operator<<(std::ostream& os, const Val& el) {
    os << "{Month: " << el.month
       << ", Balance: " << el.balance
       << ", Happiness: " << el.happiness << "}";
    return os;
}

// Function to print a std::map
template <typename K, typename V>
void printMap(const std::map<K, V>& m) {
    for (const auto& [key, value] : m) {
        std::cout << key << " => " << value << std::endl;
    }
}


void solve() {
    int m; cin >> m;
    ll salary; cin >> salary;
    int t = 0;
    ll balance = 0;
    map<int, Val> mp = {{0, {0, 0, 0}}};
    std::map<int, Val> temp;
    while (t < m) {
        ll cost; cin >> cost;
        int cur_happiness; cin >> cur_happiness;
        for (auto rit = mp.rbegin(); rit != mp.rend(); ++rit) {
            Val& mp_val = rit->second;
            ll purchased_balance = mp_val.balance_at_time(t, salary) - cost;
            int purchased_happiness = mp_val.happiness + cur_happiness;
            if (purchased_balance < 0) 
                continue;
            if (mp.count(purchased_happiness) && purchased_balance < mp[purchased_happiness].balance_at_time(t, salary))
                continue;
            temp[purchased_happiness] = {t, purchased_balance, purchased_happiness};
        }
        for (const auto& entry: temp) {
            mp[entry.first] = entry.second;
        }
        temp.clear();
        t += 1;
    }
    cout << mp.rbegin()->first << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}