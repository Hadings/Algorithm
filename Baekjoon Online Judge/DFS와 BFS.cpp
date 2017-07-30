#include<stdio.h>

int MAP[1001][1001]; // �� ���� 
int D[1001] = { 0 };//��°��� �ʱ�ȭ
int Q[1001] = { 0 };//BFS pop���� �������� �������
int B[1001] = { 0 };
int N, M, V; // ����, ���� , ž���� ������ ������ ��ȣ

void DFS(int V)
{
	printf("%d ", V); // ó���� 1
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
	Q[tail++] = V; // ������ �÷����鼭 �߰��Ѵ� 
	while (head != tail)
	{
		a = Q[head++];
		printf("%d ", a);
		for (int i = 1; i <= N; i++)  // i-> 1 2 3 4
		{
			if (MAP[a][i] == 1 && B[i] != 1)
			{
				B[i] = 1;
				Q[tail++] = i;  //�߰�
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