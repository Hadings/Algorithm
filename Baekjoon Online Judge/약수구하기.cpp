#include<stdio.h>

int main() {
	int big, k,i,j;
	int arr[200];
	int count = 0;
	int temp;
	scanf("%d %d", &big, &k);

	for (i = 0; i < 200; i++) {
		arr[i] = 0;
	}
	for (i = 1; i <= big; i++) {
		if (big %i == 0) {
			arr[count] = i;
			count++;
		}
	}
	
	for (i = 0; i <= count; i++) {
		for (j = i; j <= count; j++) {
			if (arr[i] <= arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("%d\n", arr[k - 1]);
	return 0;
}