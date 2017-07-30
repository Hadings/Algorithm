#include<stdio.h>

/*
���� : DFS or BFS
���� : ����� ����
���� :
1. ��������� ȿ������ �����������̸� ���� => �Ѹ����� ��� ������ ������ �ٸ� ���߷� �̵��� �� �ִ�.
2. �� ������ �����¿� �� ���⿡ �ٸ� ���߰� ��ġ�� ��쿡 ���� �������ִٶ�� ����.
3. ���� �������ִ� ���ߵ��� �� ������ �����ִ��� �����ϸ� �� �� ������ �����̰� �ʿ����� �� �� �ִ�.
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
	int dx[4] = { -1,1,0,0 }; // ���� ������
	int dy[4] = { 0,0,-1,1 }; // �Ʒ� ��

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


