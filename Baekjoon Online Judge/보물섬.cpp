/*
보물섬

이동 : 상하좌우
이동 시간 : 한 칸당 1시간 
보물 위치 : 보물은 서로간에 최단 거리로 이동하는 데 있어 가장 긴 시간 걸리는 육지 2곳

규칙 
1. 같은 곳 두번이상 안됨
2. 멀리 돌아가서는 안된다.

즉, 바다와 육지가 나뉘어져 있는 가운데 최단거리가 가장 먼 곳을 찾아라!!

내가 사용한 방법은 BFS와 queue 를 사용
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m;
char map[100][100];
int visit[100][100];
int x[2500];
int y[2500];
int queue[2][2500];
int cnt;
int front, rear;
int total_cnt;
int input_cnt;
int max;

void bfs(int f_x, int f_y, int cnt) {
	int i, j;
	//초기화 부분 필요 할듯 //
	rear = front = 0;
	queue[0][rear] = f_x;
	queue[1][rear++] = f_y;
	visit[f_x][f_y] = cnt;

	while (front < rear)
	{
		f_x = queue[0][front];
		f_y = queue[1][front++];

		if (!visit[f_x + 1][f_y] && map[f_x + 1][f_y] == 'L')
		{
			queue[0][rear] = f_x + 1;
			queue[1][rear] = f_y;
			visit[f_x + 1][f_y] = visit[f_x][f_y] + 1;
			rear++;
		}

		if (!visit[f_x - 1][f_y] && map[f_x - 1][f_y] == 'L')
		{
			queue[0][rear] = f_x - 1;
			queue[1][rear] = f_y;
			visit[f_x - 1][f_y] = visit[f_x][f_y] + 1;
			rear++;

		}

		if (!visit[f_x][f_y + 1] && map[f_x][f_y + 1] == 'L')
		{
			queue[0][rear] = f_x;
			queue[1][rear] = f_y + 1;
			visit[f_x][f_y + 1] = visit[f_x][f_y] + 1;
			rear++;
		}

		if (!visit[f_x][f_y - 1] && map[f_x][f_y - 1] == 'L')
		{
			queue[0][rear] = f_x;
			queue[1][rear] = f_y - 1;
			visit[f_x][f_y - 1] = visit[f_x][f_y] + 1;
			rear++;
		}
	}
	if (visit[f_x][f_y] > max) max = visit[f_x][f_y];
}

int main()
{
	int i, j;
	total_cnt = 1;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", map[i]);

	// 육지 좌표 인식
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (map[i][j] == 'L')
			{
				x[input_cnt] = i;
				y[input_cnt++] = j;
			}
		}
	}

	for (i = 0; i < input_cnt; i++) {
		bfs(x[i], y[i], 1);
		memset((void*)visit, 0, sizeof(int) * 100 * 100);
	}

	printf("%d\n", max-1);

	return 0;
}
