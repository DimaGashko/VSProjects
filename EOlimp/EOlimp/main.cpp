#include <iostream>
#include <string>

using namespace std;

class QArr {
public:
	QArr(int n):
		m_n(n),
		m_arr(new double[m_n])
	{
		initArr();
	}

	void q_0(int p, int q, double v) {
		for (int i = p; i <= q; i++) {
			m_arr[i] += v;
		}
	}

	double q_1(int p, int q) {
		double sum = 0;

		for (int i = p; i <= q; i++) {
			sum += m_arr[i];
		}

		return sum;
	}

	~QArr() {
		delete[] m_arr;
	}
private:

	int m_n;
	double* m_arr;

	void initArr() {
		for (int i = 0; i < m_n; i++) {
			m_arr[i] = 0;
		}
	}
};

int main() {
	int t, n, c;
	string res;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> c;

		QArr qArr(n);

		for (int i = 0; i < c; i++) {
			int command, p, q;
			cin >> command >> p >> q;

			if (command == 0) {
				double v;
				cin >> v;

				qArr.q_0(p, q, v);
			}
			else {
				res += to_string(qArr.q_1(p, q)) + "\n";
			}
		}

	}

	cout << res;

	return 0;
}