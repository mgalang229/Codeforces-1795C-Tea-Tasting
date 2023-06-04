#include <bits/stdc++.h>
using namespace std;

/*

1
7
8 6 1 8 5 1 2
1 1 4 5 3 4 3

ans:
1 2 9 8 6 3 2

--------------------

1
7
8 7 7 9 7 7 6
2 1 1 5 4 4 3

ans:
2 2 3 19 9 7 6

*/

void test_case(int& tc) {
	int n;
	cin >> n;
	long long a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector<long long> sum(n + 1, 0);
	for (int i = 0; i < n; i++) // prefix sum
		sum[i+1] = sum[i] + b[i];
	// cout << "prefix sum:\n";
	// for (long x : sum)
	// 	cout << x << " ";
	// cout << "\n";
	long long cnt[n+1], add[n+1];
	memset(cnt, 0, sizeof(cnt));
	memset(add, 0, sizeof(add));
	for (int i = 0; i < n; i++) {
		// rewrite pref[j] - pref[i] <= a[i] as pref[j] <= a[i] + pref[i] (to perform binary search)
		// we needed to get pref[j] - pref[i] because the tasters are popping off from the front
		// pref[j] without subtracting pref[i] is insufficient because we are not popping off from the front
		int j = upper_bound(sum.begin(), sum.end(), a[i] + sum[i]) - sum.begin() - 1;
		// cout << a[i] << " + " << sum[i] << " = " << sum[j] << "\n";

		cnt[i] += 1; // start usage here
		cnt[j] -= 1; // stop usage here (there's an offset by 1)
		add[j] += a[i] - sum[j] + sum[i]; // remaining tea to be tasted (next taster will receive this)
	}
	// cout << "ans:\n";
	for (int i = 0; i < n; i++) {
		// cout << cnt[i] << " " << b[i] << " " << add[i] << " = ";
		cout << cnt[i] * b[i] + add[i] << " ";
		// cout << "\n";
		cnt[i+1] += cnt[i]; // drag usage from i to j - 1 -> O(n)
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
