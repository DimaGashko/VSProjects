#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, b, a) for (int i = (b)-1; i >= (a); --i)
#define FILL(A, value) memset(A, value, sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int MOD = 998244353;
const double Pi = acos(-1.);

const int MAX = 1000007;

VI A;
int res = 6;

void F(Int mask, Int res_mask) {
	if ((mask & res_mask) == res_mask) {
		res = min(res, SZ(A));
		return;
	}
	if (SZ(A) + 1 >= res)
		return;
	int last = 1;
	if (SZ(A)) last = A.back();
	FOR(i, last, 51) { 
		A.push_back(i);
		F(mask | (mask << i), res_mask);
		A.pop_back();
	}
}

int main(int argc, const char* argv[]) {

	int n;
	cin >> n;
	Int mask = 0;
	FOR(i, 0, n)
	{
		int x;
		cin >> x;
		mask |= (1LL << x);
	}
	F(1, mask);
	cout << res << endl;
}

