#include <bits/stdc++.h>

typedef unsigned int uint;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l = -1, r = -1, t = 0;
    cin >> n;

    vector<int> arr(2 * n);
    vector<pair<int, int>> pairs;

    for (auto &item : arr) {
        cin >> item;
    }

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] != arr[i]) continue;

        if (l == -1) {
            l = i;
        }
        else {
            r = i - 1;
            pairs.emplace_back(l, r);
            t++;
            l = -1;
            r = -1;
        }
    }

    if (r == -1 && l != -1) {
        t++;
        if (l < arr.size() - 1){
            pairs.emplace_back(l, l + 1);
        } else {
            pairs.emplace_back(l - 3, l);
        }

    }

    cout << t << "\n";

    for (auto &item : pairs) {
        cout << item.first + 1 << " " << item.second + 1 << "\n";
    }

    return 0;
}

/*
  // выборы
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
}*/
