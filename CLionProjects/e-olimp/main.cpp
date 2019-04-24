#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

bool check(int x) {
    return ((x + 1) & x) == 0;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int a, b, k = 0;
    cin >> a >> b;

    while (!((a + k) % 2 == 0 && (b + k) % 2 == 0)) {
        k++;
    }

    cout << k;

    return 0;
}