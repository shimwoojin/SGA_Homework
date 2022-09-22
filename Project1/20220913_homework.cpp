/*
	1. 비트 플래그 : 바이트의 개별 비트

	- bool형이 1바이트에 true, false의 2가지 상태만 표시 가능한거에 비해
	- 비트 플래그는 1바이트에 해당하는 8비트에서 8개 각각의 상태 표시 가능
*/

/*
	2. 논리 연산자 문제

	1 --> true (&&, &) false	=> false
	2 --> true (||, |) false	=> true
	3 --> true (&&, ||, &) true	=> true
	4 --> (!) true				=> false
	5 --> (!) false				=> true
*/

#pragma region BMI_Calculator
/*
	// BMI 계산기

	double height = 0, weight = 0, BMI = 0;

	printf("당신의 현재 키는 몇cm인가요? : \n");
	scanf_s("%lf", &height);
	printf("당신의 현재 체중은 몇kg 인가요? : \n");
	scanf_s("%lf", &weight);

	BMI = weight / ((height*height) / 10000);

	printf("당신의 BMI : %.2lf입니다.\n\n", BMI);
	if (BMI > 25)
		printf("당신은 비만입니다. 체중을 조절하세요.\n\n");
*/
#pragma endregion

#pragma region Exchange_Rate_Calculator
/*
	// 환율 계산기
	// 2022.09.11 기준

	// 1달러	<->		1380.06원
	// 1원		<->		0.00072달러

	printf("=========================\n");
	printf("\t환율계산기\n");
	printf("=========================\n\n\n");

	while (1) {
		int choose_button = 0;
		printf("한화 -> 달러가 궁금하면 1번 : \n");
		printf("달러 -> 한화가 궁금하면 2번 : \n");
		printf("더 이상 궁금하지 않다면 3번 : \n\n");
		scanf_s("%d", &choose_button);

		if (choose_button == 1)
		{
			double kor_money=0, usa_money=0.00072, Exchange_rate=0;
			printf("가지고 있는 한화를 입력하세요. : \n");
			scanf_s("%lf", &kor_money);
			Exchange_rate = kor_money * usa_money;
			printf("당신의 한화는 달러로 %.5lf$ 입니다.\n\n", Exchange_rate);

		}
		else if (choose_button == 2)
		{
			double kor_money = 1380.06, usa_money = 0, Exchange_rate = 0;
			printf("가지고 있는 달러를 입력하세요. : \n");
			scanf_s("%lf", &usa_money);
			Exchange_rate = kor_money * usa_money;
			printf("당신의 달러는 한화로 %.2lf\\ 입니다.\n\n", Exchange_rate);

		}
		else
		{
			break;

		}

	}
*/

#pragma endregion


#include <stdio.h>

int main() {

	// 환율 계산기
	// 2022.09.11 기준

	// 1달러	<->		1380.06원
	// 1원		<->		0.00072달러

	printf("=========================\n");
	printf("\t환율계산기\n");
	printf("=========================\n\n\n");

	while (1) {
		int choose_button = 0;
		printf("한화 -> 달러가 궁금하면 1번 : \n");
		printf("달러 -> 한화가 궁금하면 2번 : \n");
		printf("더 이상 궁금하지 않다면 3번 : \n\n");
		scanf_s("%d", &choose_button);

		if (choose_button == 1)
		{
			double kor_money = 0, usa_money = 0.00072, Exchange_rate = 0;
			printf("가지고 있는 한화를 입력하세요. : \n");
			scanf_s("%lf", &kor_money);
			Exchange_rate = kor_money * usa_money;
			printf("당신의 한화는 달러로 %.5lf$ 입니다.\n\n", Exchange_rate);

		}
		else if (choose_button == 2)
		{
			double kor_money = 1380.06, usa_money = 0, Exchange_rate = 0;
			printf("가지고 있는 달러를 입력하세요. : \n");
			scanf_s("%lf", &usa_money);
			Exchange_rate = kor_money * usa_money;
			printf("당신의 달러는 한화로 %.2lf\\ 입니다.\n\n", Exchange_rate);

		}
		else
		{
			break;

		}

	}
	

}
