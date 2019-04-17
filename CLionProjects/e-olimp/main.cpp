#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;

    set<int> nums;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.insert(tmp);
    }

    int size = nums.size();

    if (size > 3) {
        cout << "-1\n";
        return 0;
    }

    int res = -1;
    vector<int> ns(nums.begin(), nums.end());

    if (size == 2) {
        int d = ns[1] - ns[0];

        res = (d % 2 == 0) ? d / 2 : d;

    } else if (size == 3) {
        res = (ns[1] - ns[0] == ns[2] - ns[1]) ? ns[1] - ns[0] : -1;
    } else if (size == 1) {
        res = 0;
    }

    cout << (res != -1 ? abs(res) : res) << endl;

    return 0;
}