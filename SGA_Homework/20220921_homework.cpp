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
	printf("�������� : ");
	for (int i = 0; i < 10; i++) {
		printf("%d, ", arr[i]);
	}

	printf("\n\n");

	bubble_sort2(arr, 10);
	printf("�������� : ");
	for (int i = 0; i < 10; i++) {
		printf("%d, ", arr[i]);
	}
}

void bubble_sort(int arr[], int count)    // �Ű������� ������ �迭�� ����� ������ ����
{
	int temp;

	for (int i = 0; i < count; i++)    // ����� ������ŭ �ݺ�
	{
		for (int j = 0; j < count - 1; j++)   // ����� ���� - 1��ŭ �ݺ�
		{
			if (arr[j] > arr[j + 1])          // ���� ����� ���� ���� ����� ���� ���Ͽ�
			{                                 // ū ����
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;            // ���� ��ҷ� ����
			}
		}
	}
}

void bubble_sort2(int arr[], int count)    // �Ű������� ������ �迭�� ����� ������ ����
{
	int temp;

	for (int i = 0; i < count; i++)    // ����� ������ŭ �ݺ�
	{
		for (int j = 0; j < count - 1; j++)   // ����� ���� - 1��ŭ �ݺ�
		{
			if (arr[j] < arr[j + 1])          // ���� ����� ���� ���� ����� ���� ���Ͽ�
			{                                 // ū ����
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;            // ���� ��ҷ� ����
			}
		}
	}
}