#include <bits/stdc++.h>

using namespace std;

map<char, int> charsMap{
        {'A', 0}, {'B', 1}, {'C', 2},
        {'D', 3}, {'E', 4}, {'F', 5},
        {'G', 6},
        {'H', 7}, {'I', 8},
        {'J', 9},{'K', 10},
        {'L', 11}, {'M', 12},
        {'N', 13}, {'O', 14},
        {'P', 15}, {'Q', 16},
        {'R', 17}, {'S', 18},
        {'T', 19},  {'U', 20},  {'V', 21},
        {'W', 22}, {'X', 23},
        {'Y', 24}, {'Z', 25},
};

vector<char> chars{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


int find(char a, char b) {
    int r1 = 0, r2 = 0;
    int ai = charsMap[a];
    int ai_ = ai;
    int bi = charsMap[b];

    while (ai != bi) {
        if (ai == chars.size() - 1) ai = 0;
        else ai++;
        r1++;
    }

    ai = ai_;
    while (ai != bi) {
        if (ai == 0) ai = chars.size() - 1;
        else ai--;
        r2++;
    }

    return min(r1, r2);
}

int main () {


    int n;
    cin >> n;

    string s;
    cin >> s;

    int res = 100000;

    for (int i = 0; i < n - 3; i++) {
        int r = find(s[i], 'A') + find(s[i + 1], 'C') + find(s[i + 2], 'T') + find(s[i + 3], 'G');
        if (r < res) res = r;
    }

    cout << res << "\n";

    return 0;
}