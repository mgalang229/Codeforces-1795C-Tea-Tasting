#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int n;
	cin >> n;
	long long a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector<long long> sum(n + 1, 0);
	for (int i = 0; i < n; i++)
		sum[i+1] = sum[i] + b[i];
	long long cnt[n+1], add[n+1];
	memset(cnt, 0, sizeof(cnt));
	memset(add, 0, sizeof(add));
	for (int i = 0; i < n; i++) {
		int j = upper_bound(sum.begin(), sum.end(), a[i] + sum[i]) - sum.begin() - 1;
		cnt[i] += 1;
		cnt[j] -= 1;
		add[j] += a[i] - sum[j] + sum[i];	
	}
	for (int i = 0; i < n; i++) {
		cout << cnt[i] * b[i] + add[i] << " ";
		cnt[i+1] += cnt[i];
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
