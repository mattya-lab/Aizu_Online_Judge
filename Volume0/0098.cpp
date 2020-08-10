#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define MIN_SUM (-999)
#define vecInt vector<int>
#define vecvecInt vector<vector<int>>

int kadane(vecInt temp, int n)
{
	int sum = 0, max_sum = MIN_SUM;
	int local_start = 0;

	int start = -1;
	int finish = -1;

	rep(i, n) {
		sum += temp[i];
		if (sum < 0) {
			sum = 0;
			local_start = i + 1;
		}
		if (sum > max_sum) {
			max_sum = sum;
			start = local_start;
			finish = i;
		}
	}
	return max_sum;
}

int findMaxSum(vecvecInt s, int n)
{
	vecInt temp(n);
	int sum = 0;
	int max_sum = MIN_SUM;

	for (int left = 0; left < n; left++) {
		rep(i, n) temp[i] = 0;
		for (int right = left; right < n; right++) {
			rep(i, n) temp[i] += s[i][right];
			int sum = kadane(temp, n);
			max_sum = max(max_sum, sum);
		}
	}
	return max_sum;
}

int main(void)
{
	int n; cin >> n;
	vecvecInt s(n, vecInt(n));
	rep(i, n) rep(j, n) cin >> s[i][j];

	cout << findMaxSum(s, n) << endl;
	return 0;
}