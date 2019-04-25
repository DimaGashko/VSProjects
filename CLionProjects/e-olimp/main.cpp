#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int n, k, m;
    cin >> n >> k >> m;

    vector<string> vocab(n);
    vector<int> weights(n);
    vector<vector<int>> groups(k);
    std::map<string, int> groupMap;

    for (auto &a : vocab) cin >> a;
    for (auto &a : weights) cin >> a;

    for (int i = 0; i < k; i++) {
        int len;
        cin >> len;

        groups[i] = vector<int>(len);

        for (auto &el : groups[i]) {
            cin >> el;
            el--;

            groupMap[vocab[el]] = i;
        }
    }

    for (auto &g : groups) {
        sort(g.begin(), g.end(), [&weights](int a, int b) {
            return weights[a] < weights[b];
        });
    }

    long long res = 0;

    for (int i = 0; i < m; i++) {
        string word;
        cin >> word;

        res += weights[groups[groupMap[word]][0]];
    }

    cout << res << endl;

    return 0;
}