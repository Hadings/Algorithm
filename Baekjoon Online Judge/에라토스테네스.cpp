#include<stdio.h>

int main() {
	int n, k, a[1001] = { 0,}, i, count = 0;
	scanf("%d %d", &n, &k);
	while (count != k) {
		// ������ ���� ���� ���� ���� ã�´�
		for (i = 2; i <= n; i++) {
			if (a[i] == 0)
				break;
		}
		// �� ã�Ҵµ� i�� 1000�̸� Ż��
		if (i == 1000) break;
		//i��° ���� 1�� ä�� �������� ǥ���ϰ�, ���ʷ� �� ����� ��������.
		for (int j = 1; j*i <= n; j++) {
			if (a[i*j] == 0) {
				a[i*j] = 1;
				count++;
			}
			if (count == k) {
				printf("%d", i*j);
				return 0;
			}
		}
	}

	return 0;
}