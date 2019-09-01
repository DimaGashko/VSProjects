#include <bits/stdc++.h>

using namespace std;

int run() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int &a : arr) {
        cin >> a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << run() << endl;
    }

    return 0;
}

/*
// B

int run() {
    int n, res = 0, minIndex = 0;
    cin >> n;

    vector<int> arr(n);
    map<int, int> m;

    for (int &a : arr) {
        cin >> a;
        m[a]++;
    }

    vector<int> sorted(arr.begin(), arr.end());
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < n - 1; i++) {
        m[arr[i]]--;

        while (m[sorted[minIndex]] < 1) {
            minIndex++;
        }

        if (arr[i] > sorted[minIndex]) {
            res++;
        }

    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << run() << endl;
    }

    return 0;
}*/

/*
// A

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int &a : arr) {
        cin >> a;
    }

    vector<int> res;

    for (int &a : arr) {
        int sum = 0;

        for (int &b : arr) {
            sum += ((b - a) % 2 != 0) ? 1 : 0;
        }

        res.push_back(sum);
    }

    sort(res.begin(), res.end());

    cout << res[0] << endl;

    return 0;
}


 */