#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void getPrimesTo(vector<int> &res, int to) {
    const int offset = 2;
    double maxP = sqrt(to);

    // Если использовать вектор getPrimesTo на 10^6 занимает ~280ms, с массивом - 40
    bool *primes = new bool[to - offset];
    for (int i = 0; i < to - offset; i++) {
        primes[i] = true;
    }
    for (int p = 2; p <= maxP; p++) {
        for (int i = 2 * p - offset; i <= to - offset; i += p) {
            primes[i] = false;
        }
    }

    for (int i = 0; i < to - offset; i++) {
        // push_back почти не влияет на скорость, так как простых чисел максимум 80000
        if (primes[i]) res.push_back(i + offset);
    }
}

void getColumnSizes(vector<int> &nums, vector<int> &colSizes) {
    int rSize = nums.size();

    vector<int> rowSizes(rSize);
    for (int i = 0; i < rSize; i++) {
        rowSizes[i] = nums[i] / 2;
    }

    int cSize = rowSizes.back();
    colSizes = vector<int>(cSize);

    for (int i = 0; i < rSize; i++) {
        int cur = rowSizes[i] - 1;

        if (colSizes[cur] == 0) {
            colSizes[cur] = rSize - i;
        }

        for (int prev = cur - 1; colSizes[prev] == 0; prev--) {
            colSizes[prev] = colSizes[cur];
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //long long k;
    //cin >> k;

    vector<int> primes, colSizes;
    getPrimesTo(primes, 18);
    getColumnSizes(primes, colSizes);
for (int k = 0; k < 25; k++) {
    int row = k;
    int col = 1;
    int i = 0;

    for (; i < colSizes.size() && row > colSizes[i]; i++) {
        row -= colSizes[i];
        col++;
    }

    if (row > colSizes.back() && 0) {
        cout << "-1 -1" << "\n";

    } else {
        int prime = primes[row + i - 1];
        int a = col;
        int b = prime - col;

        cout << a << " " << b << "\n";
    }
}
    return 0;
}