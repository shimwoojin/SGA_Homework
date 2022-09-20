#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Array2();
void bubble_sort(int arr[], int count);
void bubble_sort2(int arr[], int count);

int main()
{
	Array2();

	return 0;
}


void Array2()
{
	srand(time(NULL));
	int arr[10] = {};
	for (int i = 0; i < 10; i++) {
		arr[i] = rand();
	}
	bubble_sort(arr, 10);
	printf("오름차순 : ");
	for (int i = 0; i < 10; i++) {
		printf("%d, ", arr[i]);
	}

	printf("\n\n");

	bubble_sort2(arr, 10);
	printf("내림차순 : ");
	for (int i = 0; i < 10; i++) {
		printf("%d, ", arr[i]);
	}
}

void bubble_sort(int arr[], int count)    // 매개변수로 정렬할 배열과 요소의 개수를 받음
{
	int temp;

	for (int i = 0; i < count; i++)    // 요소의 개수만큼 반복
	{
		for (int j = 0; j < count - 1; j++)   // 요소의 개수 - 1만큼 반복
		{
			if (arr[j] > arr[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
			{                                 // 큰 값을
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;            // 다음 요소로 보냄
			}
		}
	}
}

void bubble_sort2(int arr[], int count)    // 매개변수로 정렬할 배열과 요소의 개수를 받음
{
	int temp;

	for (int i = 0; i < count; i++)    // 요소의 개수만큼 반복
	{
		for (int j = 0; j < count - 1; j++)   // 요소의 개수 - 1만큼 반복
		{
			if (arr[j] < arr[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
			{                                 // 큰 값을
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;            // 다음 요소로 보냄
			}
		}
	}
}