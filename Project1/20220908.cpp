/*
	1. ��Ʈ �÷��� : ����Ʈ�� ���� ��Ʈ

	- bool���� 1����Ʈ�� true, false�� 2���� ���¸� ǥ�� �����Ѱſ� ����
	- ��Ʈ �÷��״� 1����Ʈ�� �ش��ϴ� 8��Ʈ���� 8�� ������ ���� ǥ�� ����
*/

/*
	2. �� ������ ����

	1 --> true (&&, &) false	=> false
	2 --> true (||, |) false	=> true
	3 --> true (&&, ||, &) true	=> true
	4 --> (!) true				=> false
	5 --> (!) false				=> true
*/

#pragma region BMI_Calculator
/*
	// BMI ����

	double height = 0, weight = 0, BMI = 0;

	printf("����� ���� Ű�� ��cm�ΰ���? : \n");
	scanf_s("%lf", &height);
	printf("����� ���� ü���� ��kg �ΰ���? : \n");
	scanf_s("%lf", &weight);

	BMI = weight / ((height*height) / 10000);

	printf("����� BMI : %.2lf�Դϴ�.\n\n", BMI);
	if (BMI > 25)
		printf("����� ���Դϴ�. ü���� �����ϼ���.\n\n");
*/
#pragma endregion

#pragma region Exchange_Rate_Calculator
/*
	// ȯ�� ����
	// 2022.09.11 ����

	// 1�޷�	<->		1380.06��
	// 1��		<->		0.00072�޷�

	printf("=========================\n");
	printf("\tȯ������\n");
	printf("=========================\n\n\n");

	while (1) {
		int choose_button = 0;
		printf("��ȭ -> �޷��� �ñ��ϸ� 1�� : \n");
		printf("�޷� -> ��ȭ�� �ñ��ϸ� 2�� : \n");
		printf("�� �̻� �ñ����� �ʴٸ� 3�� : \n\n");
		scanf_s("%d", &choose_button);

		if (choose_button == 1)
		{
			double kor_money=0, usa_money=0.00072, Exchange_rate=0;
			printf("������ �ִ� ��ȭ�� �Է��ϼ���. : \n");
			scanf_s("%lf", &kor_money);
			Exchange_rate = kor_money * usa_money;
			printf("����� ��ȭ�� �޷��� %.5lf$ �Դϴ�.\n\n", Exchange_rate);

		}
		else if (choose_button == 2)
		{
			double kor_money = 1380.06, usa_money = 0, Exchange_rate = 0;
			printf("������ �ִ� �޷��� �Է��ϼ���. : \n");
			scanf_s("%lf", &usa_money);
			Exchange_rate = kor_money * usa_money;
			printf("����� �޷��� ��ȭ�� %.2lf\\ �Դϴ�.\n\n", Exchange_rate);

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

	// ȯ�� ����
	// 2022.09.11 ����

	// 1�޷�	<->		1380.06��
	// 1��		<->		0.00072�޷�

	printf("=========================\n");
	printf("\tȯ������\n");
	printf("=========================\n\n\n");

	while (1) {
		int choose_button = 0;
		printf("��ȭ -> �޷��� �ñ��ϸ� 1�� : \n");
		printf("�޷� -> ��ȭ�� �ñ��ϸ� 2�� : \n");
		printf("�� �̻� �ñ����� �ʴٸ� 3�� : \n\n");
		scanf_s("%d", &choose_button);

		if (choose_button == 1)
		{
			double kor_money = 0, usa_money = 0.00072, Exchange_rate = 0;
			printf("������ �ִ� ��ȭ�� �Է��ϼ���. : \n");
			scanf_s("%lf", &kor_money);
			Exchange_rate = kor_money * usa_money;
			printf("����� ��ȭ�� �޷��� %.5lf$ �Դϴ�.\n\n", Exchange_rate);

		}
		else if (choose_button == 2)
		{
			double kor_money = 1380.06, usa_money = 0, Exchange_rate = 0;
			printf("������ �ִ� �޷��� �Է��ϼ���. : \n");
			scanf_s("%lf", &usa_money);
			Exchange_rate = kor_money * usa_money;
			printf("����� �޷��� ��ȭ�� %.2lf\\ �Դϴ�.\n\n", Exchange_rate);

		}
		else
		{
			break;

		}

	}
	

}