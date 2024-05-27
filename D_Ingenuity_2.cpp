#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void solve() {
    int n; cin >> n;
    string directions; cin >> directions;
    map<char, int> cts = {{'N', 0}, {'S', 0}, {'E', 1}, {'W', 1}};
    map<char, int> tots;
    for (char c: directions) {
        tots[c]++;
    }
    int up = tots['N'] - tots['S'];
    int right = tots['W'] - tots['E'];
    if ((n==2 && up==0 && right==0) || abs(up)&1 || abs(right)&1) {
        cout << "NO" << endl;
        return;
    }
    for (char c : directions) {
        cout << (cts[c]&1 ? "H" : "R");
        cts[c]++;
    }
    cout << endl;
}

int main() {
    int T;  // Number of test cases
    cin >> T;  // Read the number of test cases

    while (T--) {
        int n;  // Number of elements in the test case
        string directions;  // The string of directions or actions
        solve();
    }

    return 0;
}
