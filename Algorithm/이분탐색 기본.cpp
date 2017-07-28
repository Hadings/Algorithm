#include <stdio.h>

int BinarySearch(int dataArr[], int size, int findData)
{
	int low = 0, high = size - 1, mid;

	// high가 low보다 작아진다면 찾으려는 데이터가 데이터 집합에 없다.
	while (low <= high)
	{
		// 중앙값은 low와 high를 더한 값을 2로 나누면 된다.
		mid = (low + high) / 2;
		// 만약 찾으려는 값이 중앙값보다 작다면 high를 mid - 1로 둔다.
		if (dataArr[mid] > findData) high = mid - 1;
		// 만약 찾으려는 값이 중앙값보다 크다면 low를 mid + 1로 둔다.
		else if (dataArr[mid] < findData) low = mid + 1;
		// 중앙값과 찾으려는 값이 일치하면 mid를 반환한다.
		else return mid;
	}
	// 데이터를 찾지 못하면 -1를 반환한다.
	return -1;
}

int main()
{
	int dataArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 17, 21, 24, 26, 27, 28 };
	int length = sizeof dataArr / sizeof dataArr[0];
	int input, ret;

	while (true) {
		scanf("%d", &input);
		ret = BinarySearch(dataArr, length, input);
		if (ret != -1) printf("찾으려는 데이터는 %d번째에 있습니다.\n", ret + 1);
		else printf("데이터를 찾을 수 없습니다.\n");
	}
	return 0;
}
