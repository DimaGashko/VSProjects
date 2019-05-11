#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int getDivs(int n) {
    int divs = 1;
    double limit = sqrt(n);

    for (int i = 2; i < limit; i++) {
        if (n % i == 0) divs += 2;
    }

    if ((int)limit == limit) {
        divs++;
    }

    return divs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    cout << getDivs(n) << endl;

    return 0;
}