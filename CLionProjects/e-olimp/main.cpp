#include <bits/stdc++.h>

using namespace std;

int run() {
    int k, n, a, b;
    cin >> k >> n >> a >> b;

    if (b * n >= k) return -1;

    int res = n - max((a * n - k + 1), 0) * 1.f / (a - b);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cout << run() << endl;
    }

    return 0;
}

/* A
int getDigitsSum(int a) {
    int sum = 0;

    while (a) {
        sum += a % 10;
        a /= 10;
    }

    return sum;
}

bool isInterest(int a) {
    return getDigitsSum(a) % 4 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a;
    cin >> a;

    while (!isInterest(a)) {
        a++;
    }

    cout << a;

    return 0;
}*/