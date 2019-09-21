//C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef pair<ii, ii> rect;

int getIntersect(ii a, ii b) {
    if (a.first > b.first && a.second < b.second) {
        return a.second - a.first;

    } else if (a.first < b.first && a.first < b.second && a.second > b.second) {
        return b.second - b.first;

    } else if (a.first >= b.first && a.first <= b.second) {
        return b.second - a.first;

    } else if (a.second >= b.first && a.second <= b.second) {
        return a.second - b.first;

    }

    return 0;
}

ll getIntersect(rect &a, rect &b) {
    ll dx = getIntersect({a.first.first, a.second.first}, {b.first.first, b.second.first});
    ll dy = getIntersect({a.first.second, a.second.second}, {b.first.second, b.second.second});

    return dx * dy;
}

ll getS(rect &a) {
    return 1ll * (a.second.first - a.first.first) * (a.second.second - a.first.second);
}

void cut(rect &a, rect &container) {
    int minX = container.first.first;
    int maxX = container.second.first;
    int minY = container.first.second;
    int maxY = container.second.second;

    a.first.first = max(min(a.first.first, maxX), minX);
    a.second.first = max(min(a.second.first, maxX), minX);

    a.first.second = max(min(a.first.second, maxY), minY);
    a.second.second = max(min(a.second.second, maxY), minY);
}

int writeRect(rect &rect) {
    cin >> rect.first.first;
    cin >> rect.first.second;
    cin >> rect.second.first;
    cin >> rect.second.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    rect w, a, b;

    writeRect(w);
    writeRect(a);
    writeRect(b);

    cut(a, w);
    cut(b, w);

    ll rest = getS(w) - getIntersect(w, a) - getIntersect(w, b) + getIntersect(a, b);

    cout << (rest > 0 ? "YES" : "NO") << endl;
    return 0;
}

//B
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//
//int run() {
//
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie();
//    cout.tie();
//
//    int n, res = 0;
//    cin >> n;
//
//    vii v(n);
//
//    for (int i = 0; i < n; i++) {
//        cin >> v[i].first;
//        v[i].second = i + 1;
//    }
//
//    sort(v.begin(), v.end(), [](ii a, ii b){
//        return a.first > b.first;
//    });
//
//    for (int i = 0; i < n; i++) {
//        res += v[i].first * i + 1;
//    }
//
//    cout << res << endl;
//
//    for (auto &i : v) cout << i.second << " ";
//    cout << endl;
//
//    return  0;
//}


//A
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int, int> ii;
//
//int run() {
//
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie();
//    cout.tie();
//
//    int n, res = 0;
//    string s;
//
//    cin >> n >> s;
//
//    for (int i = 0; i < n; i += 2) {
//        if (s[i] != s[i + 1]) continue;
//
//        s[i] = (s[i] == 'a') ? 'b' : 'a';
//        res++;
//    }
//
//    cout << res << endl;
//    cout << s << endl;
//
//    return  0;
//}