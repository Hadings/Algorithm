#include<stdio.h>

/*
유형 : DFS or BFS
문제 : 유기농 배추
내용 :
1. 해충방지에 효과적인 배추흰지렁이를 구입 => 한마리라도 살고 있으면 인접한 다른 배추로 이동할 수 있다.
2. 한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있다라고 간주.
3. 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다.
*/

int map[51][51];
int check[51][51];

int width, height, k;
int x, y, i, j;

void init(){

	for (i = 0; i <= height; i++) {
		for (j = 0; j <= width; j++) {
			map[i][j] = check[i][j] = 0;
		}
	}
}

void dfs(int x,int y) {
	int nexty, nextx;
	int dx[4] = { -1,1,0,0 }; // 왼쪽 오른쪽
	int dy[4] = { 0,0,-1,1 }; // 아래 위

	for (i = 0; i < 4; i++) {
		nexty = y + dy[i];
		nextx = x + dx[i];

		if (nexty >= 0 && nexty < height && nextx >= 0 && nextx < width) {
			if (map[nexty][nextx] == 1 && check[nexty][nextx] == 0) {
				check[nexty][nextx] = check[y][x];
				dfs(nexty, nextx);
			}
		}
	}
}
int search() {
	int count = 1;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				check[i][j] = count++;
				dfs(i, j);
			}
		}
	}

	return count - 1;
}


int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &width, &height, &k);
		init();
		for (i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		
		printf("%d\n", search());
	}
	return 0;
}


