#include <stdio.h>
#include <string.h>

/*
	���� strcmp() �����ϱ�
	1. ���� ������ �ϴ� �Լ��ΰ� ? -> ���ϵǴ� ����� �� 3���� �ľ��ϱ�
	 : �� ���� ���ڿ��� ���ϴ� �Լ� -> int strcmp(const char* str1, const char* str2)
	 : ���ڿ��� ���ٸ� 0 ����, str1�� str2���� ũ�� ��� ����, str1�� str2���� ������ ���� ����
	
	2. ���� strcmp �����ϱ�
*/

int length(char string[]);
void copy(char dest[], int count, char src[]);
void catenate(char dest[], int count, char src[]);
int compare(char string1[], char string2[]);

int main()
{
	char str1[] = "woojin";
	char str2[] = "woojin";
	char str3[] = "woojin2";
	char str4[] = "qoojin";
	int com_1 = compare(str1, str2);
	int com_1_strcmp = strcmp(str1, str2);
	int com_2 = compare(str1, str3);
	int com_2_strcmp = strcmp(str1, str3);
	int com_3 = compare(str1, str4);
	int com_3_strcmp = strcmp(str1, str4);
	printf("str1�� str2�� ������ : %d\n",com_1);
	printf("str1�� str2�� ������ : %d\n",com_1_strcmp);
	printf("str1�� str3�� ������ : %d\n", com_2);
	printf("str1�� str3�� ������ : %d\n", com_2_strcmp);
	printf("str1�� str4�� ������ : %d\n", com_3);
	printf("str1�� str4�� ������ : %d\n", com_3_strcmp);
	compare(str1, str2);

	return 0;
}

int length(char string[])
{
	int count = 0;
	while (string[count] != '\0')
		count++;

	return count;
}

void copy(char dest[], int count, char src[])
{
	/*
		src�� ���ڿ� ���̰� dest�� ���� �������� ª�� ���,
		src�� ���ڿ��� dest�� �����ϴ� �Լ�
	*/
	int length_src = length(src);
	if (length_src >= count) {
		printf("���̰� �� �½��ϴ�");
		return;
	}
	for (int i = 0; i <= length_src; i++)
		dest[i] = src[i];
}

void catenate(char dest[], int count, char src[])
{
	/*
		dest�� src�� ���ڿ� ������ ���� dest�� ���� �������� ª�� ���,
		src�� ���ڿ��� dest�� ���ڿ��� �����ϴ� �Լ�
	*/

	int length_dest = length(dest);
	int length_src = length(src);

	if (length_dest + length_src < count)
		for (int i = 0; i <= length_src; i++)
			dest[length_dest + i] = src[i];

}

int compare(char string1[], char string2[])
{
	int size = length(string1);
	if (length(string1) == length(string2))
	{
		for (int i = 0; i < size; i++)
		{
			if (string1[i] > string2[i]) return 1;
			else if (string1[i] < string2[i]) return -1;
			else
			{
				printf("�� ���ڿ��� �����ϴ�.\n");
				return 0;
			}
		}

	}
	else if (length(string1) > length(string2)) return 1;
	else return -1;
	}
