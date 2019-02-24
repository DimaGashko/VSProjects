#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class QArr {
public:
	QArr(int n):
		m_n(n),
		m_arr(new long long[m_n])
	{
		for (int i = 0; i < m_n; i++) {
			m_arr[i] = 0;
		}
	}

	void q_0(int p, int q, long long v) {
		if (v == 0) return;
		if (p > q) return q_0(q, p, v);

		for (int i = p; i <= q; i++) {
			m_arr[i] += v;
		}
	}
	
	long long q_1(int p, int q) {
		if (p > q) return q_1(q, p);

		long long sum = 0;

		for (int i = p; i <= q; i++) {
			sum += m_arr[i];
		}

		return sum;
	}

	~QArr() {
		delete m_arr;
	}

private:
	
	int m_n;
	long long* m_arr;
};

int main() {
	int t, n, c;

	fin >> t;

	for (int i = 0; i < t; i++) {
		fin >> n >> c;

		QArr qArr(n);

		for (int i = 0; i < c; i++) {
			int command, p, q;
			fin >> command >> p >> q;

			p--; q--;

			if (command == 0) {
				int v;
				fin >> v;

				qArr.q_0(p, q, v);
			}
			else {
				fout << qArr.q_1(p, q) << endl;
			}
		}0

	}

	return 0;
}