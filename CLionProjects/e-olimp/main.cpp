#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0;

    int by100 = n / 100;
    sum += by100 * 100;
    n -= by100 * 100;

    if (n >= 66) {
        sum += 100;
        n = 0;
    } else if (n < 15) {
        sum += n * 2;
        n = 0;
    } else {
        int by20 = n / 20;
        sum += by20 * 30;
        n -= by20 * 20;

        if (n < 15) {
            sum += n * 2;
            n = 0;
        } else {
            sum += 30;
            n = 0;
        }
    }

    cout << sum << "\n";

    return 0;
}