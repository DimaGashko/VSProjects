#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, c;

int get(vector<int> &costs, vector<int> &times) {
    int sum = 0, curTime = 0;

    for (int i = 0; i < n; i++) {
        curTime += times[i];
        sum += max(costs[i] - c * curTime, 0);
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> c;

    vector<int> costs(n), times(n);

    for (int &a : costs) cin >> a;
    for (int &a : times) cin >> a;

    int l = get(costs, times);

    reverse(costs.begin(), costs.end());
    reverse(times.begin(), times.end());

    int r = get(costs, times);

    if (l > r) {
        cout << "Limak" << endl;
    } else if (r > l) {
        cout << "Radewoosh" << endl;
    } else {
        cout << "Tie";
    }

    return 0;
}