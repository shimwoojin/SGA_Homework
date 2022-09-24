#include <stdio.h>
#include <string.h>

/*
	과제 strcmp() 조사하기
	1. 무슨 역할을 하는 함수인가 ? -> 리턴되는 경우의 수 3가지 파악하기
	 : 두 개의 문자열을 비교하는 함수 -> int strcmp(const char* str1, const char* str2)
	 : 문자열이 같다면 0 리턴, str1이 str2보다 크면 양수 리턴, str1이 str2보다 작으면 음수 리턴
	
	2. 직접 strcmp 구현하기
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
	printf("str1과 str2가 같은지 : %d\n",com_1);
	printf("str1과 str2가 같은지 : %d\n",com_1_strcmp);
	printf("str1과 str3이 같은지 : %d\n", com_2);
	printf("str1과 str3이 같은지 : %d\n", com_2_strcmp);
	printf("str1과 str4이 같은지 : %d\n", com_3);
	printf("str1과 str4이 같은지 : %d\n", com_3_strcmp);
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
		src의 문자열 길이가 dest의 원소 개수보다 짧을 경우,
		src의 문자열을 dest로 복사하는 함수
	*/
	int length_src = length(src);
	if (length_src >= count) {
		printf("길이가 안 맞습니다");
		return;
	}
	for (int i = 0; i <= length_src; i++)
		dest[i] = src[i];
}

void catenate(char dest[], int count, char src[])
{
	/*
		dest와 src의 문자열 길이의 합이 dest의 원소 개수보다 짧을 경우,
		src의 문자열을 dest의 문자열에 연결하는 함수
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
				printf("두 문자열은 같습니다.\n");
				return 0;
			}
		}

	}
	else if (length(string1) > length(string2)) return 1;
	else return -1;
	}
