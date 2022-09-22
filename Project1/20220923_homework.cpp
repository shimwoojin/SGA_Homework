//20220923_homework.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef struct _Monster
{
    char name[256];
    int hp;
    int atk;
    int exp;
}Monster;

void rpg();

typedef struct // ����ü �̸��� ������ �͸� ����ü
{
    char name[256];
    int hp;
    int atk;
    int exp;
    int gold;
}Player;

int main()
{
    rpg();
    return 0;
}

void rpg()
{
    Player p;
    Monster monster_table[2] =
    {
        {"��� ����", 100, 100,50},
        {"��� �ü�",60,150,70}
    };
    Monster boss_table = { "����� ��", 500, 100, 200 };
    int skip_trip = 0;

    printf("\n���ӿ� ���Ű� ȯ���մϴ�! \n");
    printf("����� �̸���? : ");
    scanf_s("%s", &p.name, sizeof(p.name));

    printf("����� HP�� ? : ");
    scanf_s("%d", &p.hp);

    printf("����� atk�� ? : ");
    scanf_s("%d", &p.atk);

    p.exp = 0;
    p.gold = 0;

    printf("Ž�� ���� �� �������� ����� �ٷ� �ϰ� �ʹٸ� 1 Ž���� �ϰ� �ʹٸ� 0 : ");
    scanf_s("%d", &skip_trip);
    if (skip_trip == 1)
    {
        p.exp = 200;
        goto ONE;
    }

    printf("===================Ž�����!!\n\n");
    srand(time(NULL));

    while (1)
    {
        if (p.hp <= 0)
        {
            printf("%s ��� ���� ����...\n", p.name);
            break;
        }
        if (p.exp >= 200)
        {
            printf("�������� ������ �غ��մϴ�...\n\n\n");
            Sleep(1000);
            break;
        }
        printf("���� �������ϴ�(�̵�)\n");
        Sleep(1000); // 1/1000, 1000 -> 1��
        int event_key = rand() % 6;

        switch (event_key)
        {
        case 0: //gold ���� �̺�Ʈ
        {
            int gold_50 = (rand() % 4 + 1) * 50;
            printf("%s�� �������� �߰�! ��� +%d\n", p.name, gold_50);
            p.gold += gold_50;
            Sleep(1000);
            printf("���� ���� ��� : %d\n", p.gold);
            Sleep(1000);
            printf("�������� �̵��մϴ�.\n");
            Sleep(1000);
            break;
        }
        case 1: // ���� ȸ�� �̺�Ʈ
            printf("%s�� ������ �칰 �߰�! HP +100\n", p.name);
            p.hp += 100;
            Sleep(1000);
            printf("���� ü�� : %d\n", p.hp);
            Sleep(1000);
            printf("�������� �̵��մϴ�.\n");
            Sleep(1000);
            break;
        case 2:
            // ü�� ���� �̺�Ʈ
            printf("%s�� Ż����� ���� ����! HP -200\n", p.name);
            p.hp -= 200;
            Sleep(1000);
            printf("���� ü�� : %d\n", p.hp);
            Sleep(1000);
            printf("�������� �̵��մϴ�.\n");
            Sleep(1000);
            break;
        case 3:
            // ����ġ ���� or ���� �̺�Ʈ
        {
            bool good_event = rand() % 2;
            if (good_event == true)
            {
                printf("%s�� ������ ����� ���� �߰�! EXP +150\n", p.name);
                p.exp += 150;
                Sleep(1000);
                printf("���� ����ġ : %d\n", p.exp);
                Sleep(1000);
                printf("�������� �̵��մϴ�.\n");
                Sleep(1000);
                break;
            }
            else
            {
                printf("%s�� ��� ������ ���� �߰�! EXP -50\n", p.name);
                p.exp -= 50;
                Sleep(1000);
                printf("���� ����ġ : %d\n", p.exp);
                Sleep(1000);
                printf("�������� �̵��մϴ�.\n");
                Sleep(1000);
                break;
            }

        }
        case 4: // ���Ϳ� ����
        {
            int m_num = rand() % 2;
            Monster m = monster_table[m_num];

            printf("%s����! ��������!\n", m.name);
            Sleep(1000);

            while (1)
            {
                //�÷��̾� ����
                printf("%s�� ����!\n", p.name);
                Sleep(1000);
                printf("%d�� ������!\n", p.atk);
                Sleep(1000);
                printf("%s�� ü�� %d -> %d\n", m.name, m.hp, m.hp - p.atk);
                m.hp -= p.atk;
                Sleep(1000);

                if (m.hp <= 0)
                {
                    printf("%s �¸�! exp + %d\n", p.name, m.exp);
                    p.exp += m.exp;
                    Sleep(1000);
                    printf("���� ����ġ : %d\n", p.exp);
                    Sleep(1000);
                    printf("�������� �̵��մϴ�.\n");
                    Sleep(1000);
                    break;
                }
                //���� ����
                printf("%s�� ����!\n", m.name);
                Sleep(1000);
                printf("%d�� ������!\n", m.atk);
                Sleep(1000);
                printf("%s�� ü�� %d -> %d\n", p.name, p.hp, p.hp - m.atk);
                p.hp -= m.atk;
                Sleep(1000);

                if (p.hp <= 0)
                {
                    printf("%s �й�!\n", p.name);
                    Sleep(1000);
                    break;
                }

            } //while(1) // ����

            break;
        }
        case 5: // ���� ȹ�� �̺�Ʈ
        {
            int rand_atk = (rand() % 2 + 1) * 5;
            printf("%s�� ������ �� �߰�! atk +%d\n", p.name, rand_atk);
            p.atk += rand_atk;
            Sleep(1000);
            printf("���� atk : %d\n", p.atk);
            Sleep(1000);
            printf("�������� �̵��մϴ�.\n");
            Sleep(1000);
            break;
        }

        default:
            printf("�߸��� Ű�Է� Ȥ�� �̺�Ʈ ����X\n");
            break;
        }

    }
ONE:
    printf("\n\n");
    if (p.exp >= 200) // �������� ����
    {
        Monster b = boss_table;
        printf("%s ���� ���Ϳ� ����! \n", b.name);
        Sleep(1000);
        printf("%s�� %s�� �ֻ��� ������ ���!!\n", b.name, p.name);
        Sleep(1000);
        while (1)
        {
            int dice_b = rand() % 6 + 1;
            int dice_p = rand() % 6 + 1;
            printf("%s�� �ֻ��� : %d || %s�� �ֻ��� : %d\n", b.name, dice_b, p.name, dice_p);
            Sleep(1000);
            if (dice_b > dice_p)
            {
                printf("%s�� %s�� %d��ŭ ����!\n", b.name, p.name, b.atk);
                Sleep(1000);
                printf("%s�� ���� ü�� : %d -> ���� ü�� : %d\n", p.name, p.hp, p.hp - b.atk);
                p.hp -= b.atk;
                Sleep(1000);
            }
            else if (dice_b < dice_p)
            {
                printf("%s�� %s�� %d��ŭ ����!\n", p.name, b.name, p.atk);
                Sleep(1000);
                printf("%s�� ���� ü�� : %d -> ���� ü�� : %d\n", b.name, b.hp, b.hp - p.atk);
                b.hp -= p.atk;
                Sleep(1000);
            }
            else
            {
                printf("�����ϴ�.\n");
                Sleep(1000);
            }

            if (b.hp <= 0 || p.hp <= 0)
            {
                printf("������ ��� �������ϴ�!!\n");
                Sleep(1000);
                if (b.hp <= 0) {
                    printf("����� �¸��Դϴ�. �����մϴ�\n");
                    Sleep(1000);
                    break;
                }
                else
                {
                    printf("%s�� ����� ��ü ������ �¸��� ���� ��ϴ�...������ �й��ϼ��� ��^��\n", b.name);
                    Sleep(1000);
                    break;
                }
            }


        }
    }


}

/*
    ���� : rpg���� ���׷��̵�
        1. �������� �̺�Ʈ ����
        2. ���� �ִ� �̺�Ʈ �ϳ� �����ؼ� ���׷��̵�
        3. �߰������� ������ �̺�Ʈ �ϳ� �����
    + ���� ����� ������ �����
*/