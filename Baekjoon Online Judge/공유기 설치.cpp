/*
binary Search
21110번 공유기 설치 

*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int i, j, n, c;

bool check(vector<int>& v, int mid, int k) {
	int cnt = 1;
	int start = v[0];

	for (i = 1; i < v.size(); i++) {
		if (v[i] - start >= mid) {
			cnt++;
			start = v[i];
		}
	}

	return cnt >= k;
}

int main() {
	scanf("%d %d", &n, &c);

	vector<int> v(n);

	for (i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end()); // 들어온 값 정렬
	int start = 1;
	int end = v[n - 1] - v[0];
	int ans = start;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (check(v, mid, c)) {
			if (ans < mid)
				ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	printf("%d\n", ans);
	return 0;
}