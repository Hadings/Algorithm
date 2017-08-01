#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int M;

// ���� n�� 10^i�ڸ��� ���� ����
inline int digit(int n, int i) {
	for (int k = 0; k<i; k++) n /= 10;
	return n % 10;
}

// ���� n�� 10^i�ڸ��� 10^j�ڸ� ���ڸ� ��ȯ
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
	// N�� �ڸ����� ���� �������� M�� ����. M�� �ٲ� �� ����.
	do {
		M++;
		N /= 10;
	} while (N);

	// BFS ����
	for (int i = 0; i<K; i++) {
		int qSize = Q.size();
		bool visited[1000001] = { 0 };
		// ť�� ����� ��� visited �迭 �ʱ�ȭ �� ����
		for (int j = 0; j<qSize; j++) {
			int curr = Q.front();
			Q.pop();
			// ���� ���� ��� ������ �� (k, l)�� ���� �õ�
			for (int k = 0; k<M - 1; k++)
				for (int l = k + 1; l<M; l++)
					// l�� ���� ū �ڸ��� �ƴϰų�, 10^k�ڸ��� 0�� �ƴϸ� ��ȯ
					if (l<M - 1 || digit(curr, k)) {
						int next = swapDigit(curr, k, l);
						if (!visited[next]) {
							visited[next] = true;
							Q.push(next);
						}
					}
		}
	}

	// ������ �ܰ谡 ���� �� ť�� ���鸸�� ������ �ĺ�
	while (!Q.empty()) {
		result = max(result, Q.front());
		Q.pop();
	}
	printf("%d\n", result);
}


