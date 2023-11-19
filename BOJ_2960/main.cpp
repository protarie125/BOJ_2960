#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int N, K;
vb sieve;
vi remo;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> N >> K;

	sieve = vb(N + 1, true);
	sieve[0] = false;
	sieve[1] = false;

	for (auto i = 2; i <= N; ++i) {
		if (sieve[i]) {
			sieve[i] = false;
			remo.push_back(i);

			for (auto j = i + i; j <= N; j += i) {
				if (sieve[j]) {
					remo.push_back(j);
				}

				sieve[j] = false;
			}
		}

		if (K <= remo.size()) {
			break;
		}
	}

	cout << remo[K - 1];

	return 0;
}