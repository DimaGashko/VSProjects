#include <bits/stdc++.h>

using namespace std;

#define IO_HACK ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"

int main() {
    IO_HACK

    int n, t, s, d;
    cin >> n >> t;

    vector<pair<int, int>> rests;

    for (int i = 0; i < n; i++) {
        cin >> s >> d;

        if (t <= s) {
            rests.emplace_back(s - t, i + 1);
        } else {
            rests.emplace_back(d - ((t - s) % d), i + 1);
        }
    }

    sort(rests.begin(), rests.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });

    cout << rests[0].second << endl;

    return 0;
}