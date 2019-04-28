#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int get(int s, int v, int t) {
    return s * v + t * 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &a : arr) cin >> a;

    std::map<int, int> map;

    for (int a : arr) {
        map[a] = map[a] + 1;
    }

    int max = 0;

    for (auto item : map) {
        if (item.second > max) max = item.second;
    }

    cout << max << endl;

    return 0;
}