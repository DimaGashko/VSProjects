#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    std::vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        int index;
        cin >> index;

        vec[index - 1]++;
        if (vec[index - 1] > floor(n / 2.0)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
