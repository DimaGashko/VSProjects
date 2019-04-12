#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    vector<int> arr(n);

    for (auto &el : arr) {
        cin >> el;
    }

    int a = arr[0], b = 0, c = 0;
    int ai = 0, bi = 0, ci = 0;
    int rai = 0, rci = 0;

    for (int i = 1; i <= arr.size() - 1; i++) {
        if (arr[i] < b && b != 0) {
            c = arr[i];
            ci = i;

            if (rci - rai == 0 || ci - ai < rci - rai) {
                rai = ai;
                rci = ci;
            }

            a = b;
            ai = bi;
            i = ai;
            b = 0;
        }

        else if (arr[i] <= a) {
            a = arr[i];
            ai = i;
        }
        else  {
            if (b != 0 && arr[i] != b) {
                a = b;
                ai = bi;
            }

            b = arr[i];
            bi = i;
        }
    }

    if (rci - rai == 0) cout << 0 << endl;
    else cout << rai + 1 << " " << rci + 1 << endl;

    return 0;
}