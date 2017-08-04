#include<cstdio>
#include<queue>
using namespace std;

// 기존에 풀었던 bfs문제와 다르게, visited 배열에 현재 레벨도 저장
int n,k;
int visited[100001] = { 0, };
queue<int> q;

int bfs() {
	// 큐에 수빈의 위치 put, visited 배열에 1 추가
	q.push(n);
	visited[n] = 1;
	// bfs start
	while (!q.empty()) {
		// 큐를 꺼내고, 수빈이가 동생의 위치에 도달했는지 check
		int p = q.front();
		q.pop();
		if (p == k)
			return visited[p] - 1;
		// 반환점
		// 수빈이 현재 위치 -1dl 0보다 크거나 같고, 방문한 적이 없을경우, 현재 값에서 레벨을 1증가 후 큐에 넣기
		if (p - 1 >= 0 && visited[p - 1] == 0) {
			visited[p - 1] = visited[p] + 1;
			q.push(p - 1);
		}
		// 수빈이 현재 위치의 +1이 100000보다 작거나 같고 방문한 적 없을 경우
		if (p + 1 <= 100000 && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;
			q.push(p + 1);
		}
		// 현재보다 두배 위치에 방문 노노
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