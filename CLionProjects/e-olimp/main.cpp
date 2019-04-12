#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

int n, resLen = 0;
int *arr;
int *res;
bool *visited;

void init() {
    cin >> n;

    arr = new int[n];
    res = new int[n / 2];
    visited = new bool[n];

    for (int i = 0; i < n; i++) {
        arr[i] = 0;
        visited[i] = false;
    }

    for (int i = 0; i < n / 2; i++) {
        res[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        cin >> arr[i];
    }
}

int search(int l, int val) {
    int r = n - 1;

    while (r >= l) {
        int m = (l + r) / 2;

        if (arr[m] == val) {
            while (arr[m] == val && !visited[m]) {m--;}
            while (arr[m] != val || visited[m]) {m++;}

            return (arr[m] == val && !visited[m]) ? m : -1;
        }

        else if (arr[m] > val) l = m + 1;
        else if (arr[m] < val) r = m - 1;
    }

    return -1;
}

void run() {
    for (int i = 0 ; i < n; i++) {
        if (visited[i]) continue;

        int newV = int(arr[i] * 0.75);
        int index = search(i, newV);

        if (index == -1) continue;
        res[resLen++] = newV;
        visited[index] = true;
    }

}

void printRes() {
    for (int i = n / 2 - 1; i >= 0; i--) {
        cout << res[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    run();
    printRes();

    return 0;
}