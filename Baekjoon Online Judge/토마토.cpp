#include<stdio.h>
/*
배열을 사용한 큐를 이용하여 BFS를 구현한다.
문제 푸는 시에 문제점 
1. 배열의 크기에 대한 간과점
2. 큐의 크기 
3. 코드 정확도
*/
#define size_x 1005
#define size_y 1005

int map[size_x][size_y];
int check[size_x][size_y];
int q[1000050][2];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int head = 0, tail = 0;
int x, y;
int main() {
	int M, N;
	int i, j;
	scanf("%d %d", &M, &N);
	for (i = 0; i <= N + 1; i++) {
		for (j = 0; j <= M + 1; j++) {
			map[i][j] = -1; 
			check[i][j] = 0;
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q[tail][0] = i;
				q[tail][1] = j; // 매번 익은 애들을 큐에 저장한다.
				tail++;
			}
		}
	}
	
	while (head < tail) {
		x = q[head][0];
		y = q[head][1];
		head++;
		for (i = 0; i < 4; i++) {
			if (x + dx[i] <= N && y + dy[i] <= M && x + dx[i] >= 1 && y + dy[i] >= 1 && map[x + dx[i]][y + dy[i]] == 0) {
				map[x + dx[i]][y + dy[i]] = 1;
				check[x + dx[i]][y + dy[i]] = check[x][y] + 1; // 몇일 걸리는 지 check 한다.
				q[tail][0] = x + dx[i];
				q[tail][1] = y + dy[i]; // 이번에 익은 애들을 큐에 저장한다.
				tail++;
			}
		}
	}
	int days=0, count=0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			if (days < check[i][j]) {
				days = check[i][j];
			}
			if (map[i][j] == 0)
				count = 1;
		}
	}
	if (count == 1)
		printf("-1\n");
	else
		printf("%d\n", days);
	return 0;
}