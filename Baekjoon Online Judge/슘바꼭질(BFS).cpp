#include<cstdio>
#include<queue>
using namespace std;

// ������ Ǯ���� bfs������ �ٸ���, visited �迭�� ���� ������ ����
int n,k;
int visited[100001] = { 0, };
queue<int> q;

int bfs() {
	// ť�� ������ ��ġ put, visited �迭�� 1 �߰�
	q.push(n);
	visited[n] = 1;
	// bfs start
	while (!q.empty()) {
		// ť�� ������, �����̰� ������ ��ġ�� �����ߴ��� check
		int p = q.front();
		q.pop();
		if (p == k)
			return visited[p] - 1;
		// ��ȯ��
		// ������ ���� ��ġ -1dl 0���� ũ�ų� ����, �湮�� ���� �������, ���� ������ ������ 1���� �� ť�� �ֱ�
		if (p - 1 >= 0 && visited[p - 1] == 0) {
			visited[p - 1] = visited[p] + 1;
			q.push(p - 1);
		}
		// ������ ���� ��ġ�� +1�� 100000���� �۰ų� ���� �湮�� �� ���� ���
		if (p + 1 <= 100000 && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}
		// ���纸�� �ι� ��ġ�� �湮 ���
		if (2 * p <= 100000 && visited[2 * p] == 0) {
			visited[2 * p] = visited[p] + 1;
			q.push(2 * p);
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	printf("%d\n", bfs());

	return 0;
}