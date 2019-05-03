#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> arr {a, b, c};
    sort(arr.begin(), arr.end());

    int t = arr[2] - arr[1] - arr[0] + 1;
    if (t < 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << t << endl;

    return 0;
}