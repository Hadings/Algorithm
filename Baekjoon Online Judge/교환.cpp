#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int M;

// 정수 n의 10^i자리의 숫자 리턴
inline int digit(int n, int i) {
	for (int k = 0; k<i; k++) n /= 10;
	return n % 10;
}

// 정수 n의 10^i자리와 10^j자리 숫자를 교환
inline int swapDigit(int n, int i, int j) {
	char S[8];
	sprintf(S, "%d", n);
	swap(S[M - i - 1], S[M - j - 1]);
	sscanf(S, "%d", &n);
	return n;
}

int main() {
	int N, K, result = -1;
	scanf("%d %d", &N, &K);
	queue<int> Q;
	Q.push(N);
	// N의 자릿수를 세서 전역변수 M에 대입. M은 바뀔 수 없다.
	do {
		M++;
		N /= 10;
	} while (N);

	// BFS 시작
	for (int i = 0; i<K; i++) {
		int qSize = Q.size();
		bool visited[1000001] = { 0 };
		// 큐의 사이즈를 재고 visited 배열 초기화 후 시작
		for (int j = 0; j<qSize; j++) {
			int curr = Q.front();
			Q.pop();
			// 현재 값의 모든 가능한 쌍 (k, l)에 대해 시도
			for (int k = 0; k<M - 1; k++)
				for (int l = k + 1; l<M; l++)
					// l이 제일 큰 자리가 아니거나, 10^k자리가 0이 아니면 교환
					if (l<M - 1 || digit(curr, k)) {
						int next = swapDigit(curr, k, l);
						if (!visited[next]) {
							visited[next] = true;
							Q.push(next);
						}
					}
		}
	}

	// 마지막 단계가 지난 후 큐의 값들만이 정답의 후보
	while (!Q.empty()) {
		result = max(result, Q.front());
		Q.pop();
	}
	printf("%d\n", result);
}


