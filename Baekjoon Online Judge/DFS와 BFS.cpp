#include<stdio.h>

int MAP[1001][1001]; // 맵 설정 
int D[1001] = { 0 };//출력공간 초기화
int Q[1001] = { 0 };//BFS pop으로 나오기전 저장공간
int B[1001] = { 0 };
int N, M, V; // 정점, 간선 , 탑색을 시작할 정점의 번호

void DFS(int V)
{
	printf("%d ", V); // 처음은 1
	D[V] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (MAP[V][i] == 1 && D[i] != 1)
			DFS(i);
	}
}
int head = 0, tail = 0;
void BFS(int V)
{
	int a;
	B[V] = 1;
	Q[tail++] = V; // 꼬리를 늘려가면서 추가한다 
	while (head != tail)
	{
		a = Q[head++];
		printf("%d ", a);
		for (int i = 1; i <= N; i++)  // i-> 1 2 3 4
		{
			if (MAP[a][i] == 1 && B[i] != 1)
			{
				B[i] = 1;
				Q[tail++] = i;  //추가
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &V);
	int a, b;

	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &a, &b);
		MAP[a][b] = MAP[b][a] = 1;
	}
	DFS(V);
	printf("\n");
	BFS(V);

	return 0;
}