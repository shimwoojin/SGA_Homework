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

typedef struct // 구조체 이름을 생략한 익명 구조체
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
        {"고블린 전사", 100, 100,50},
        {"고블린 궁수",60,150,70}
    };
    Monster boss_table = { "고블린의 왕", 500, 100, 200 };
    int skip_trip = 0;

    printf("\n게임에 오신걸 환영합니다! \n");
    printf("당신의 이름은? : ");
    scanf_s("%s", &p.name, sizeof(p.name));

    printf("당신의 HP는 ? : ");
    scanf_s("%d", &p.hp);

    printf("당신의 atk는 ? : ");
    scanf_s("%d", &p.atk);

    p.exp = 0;
    p.gold = 0;

    printf("탐험 생략 후 보스와의 대결이 바로 하고 싶다면 1 탐험이 하고 싶다면 0 : ");
    scanf_s("%d", &skip_trip);
    if (skip_trip == 1)
    {
        p.exp = 200;
        goto ONE;
    }

    printf("===================탐험시작!!\n\n");
    srand(time(NULL));

    while (1)
    {
        if (p.hp <= 0)
        {
            printf("%s 사망 게임 종료...\n", p.name);
            break;
        }
        if (p.exp >= 200)
        {
            printf("보스와의 전투를 준비합니다...\n\n\n");
            Sleep(1000);
            break;
        }
        printf("한층 내려갑니다(이동)\n");
        Sleep(1000); // 1/1000, 1000 -> 1초
        int event_key = rand() % 6;

        switch (event_key)
        {
        case 0: //gold 증가 이벤트
        {
            int gold_50 = (rand() % 4 + 1) * 50;
            printf("%s가 보물상자 발견! 골드 +%d\n", p.name, gold_50);
            p.gold += gold_50;
            Sleep(1000);
            printf("현재 소지 골드 : %d\n", p.gold);
            Sleep(1000);
            printf("다음으로 이동합니다.\n");
            Sleep(1000);
            break;
        }
        case 1: // 생명 회복 이벤트
            printf("%s가 생명의 우물 발견! HP +100\n", p.name);
            p.hp += 100;
            Sleep(1000);
            printf("현재 체력 : %d\n", p.hp);
            Sleep(1000);
            printf("다음으로 이동합니다.\n");
            Sleep(1000);
            break;
        case 2:
            // 체력 감소 이벤트
            printf("%s가 탈모빔에 직격 당함! HP -200\n", p.name);
            p.hp -= 200;
            Sleep(1000);
            printf("현재 체력 : %d\n", p.hp);
            Sleep(1000);
            printf("다음으로 이동합니다.\n");
            Sleep(1000);
            break;
        case 3:
            // 경험치 증가 or 감소 이벤트
        {
            bool good_event = rand() % 2;
            if (good_event == true)
            {
                printf("%s가 전설의 용사의 경험 발견! EXP +150\n", p.name);
                p.exp += 150;
                Sleep(1000);
                printf("현재 경험치 : %d\n", p.exp);
                Sleep(1000);
                printf("다음으로 이동합니다.\n");
                Sleep(1000);
                break;
            }
            else
            {
                printf("%s가 어느 거지의 경험 발견! EXP -50\n", p.name);
                p.exp -= 50;
                Sleep(1000);
                printf("현재 경험치 : %d\n", p.exp);
                Sleep(1000);
                printf("다음으로 이동합니다.\n");
                Sleep(1000);
                break;
            }

        }
        case 4: // 몬스터와 전투
        {
            int m_num = rand() % 2;
            Monster m = monster_table[m_num];

            printf("%s조우! 전투시작!\n", m.name);
            Sleep(1000);

            while (1)
            {
                //플레이어 공격
                printf("%s의 공격!\n", p.name);
                Sleep(1000);
                printf("%d의 데미지!\n", p.atk);
                Sleep(1000);
                printf("%s의 체력 %d -> %d\n", m.name, m.hp, m.hp - p.atk);
                m.hp -= p.atk;
                Sleep(1000);

                if (m.hp <= 0)
                {
                    printf("%s 승리! exp + %d\n", p.name, m.exp);
                    p.exp += m.exp;
                    Sleep(1000);
                    printf("현재 경험치 : %d\n", p.exp);
                    Sleep(1000);
                    printf("다음으로 이동합니다.\n");
                    Sleep(1000);
                    break;
                }
                //몬스터 공격
                printf("%s의 공격!\n", m.name);
                Sleep(1000);
                printf("%d의 데미지!\n", m.atk);
                Sleep(1000);
                printf("%s의 체력 %d -> %d\n", p.name, p.hp, p.hp - m.atk);
                p.hp -= m.atk;
                Sleep(1000);

                if (p.hp <= 0)
                {
                    printf("%s 패배!\n", p.name);
                    Sleep(1000);
                    break;
                }

            } //while(1) // 전투

            break;
        }
        case 5: // 무기 획득 이벤트
        {
            int rand_atk = (rand() % 2 + 1) * 5;
            printf("%s가 오래된 검 발견! atk +%d\n", p.name, rand_atk);
            p.atk += rand_atk;
            Sleep(1000);
            printf("현재 atk : %d\n", p.atk);
            Sleep(1000);
            printf("다음으로 이동합니다.\n");
            Sleep(1000);
            break;
        }

        default:
            printf("잘못된 키입력 혹은 이벤트 생성X\n");
            break;
        }

    }
ONE:
    printf("\n\n");
    if (p.exp >= 200) // 보스와의 전투
    {
        Monster b = boss_table;
        printf("%s 보스 몬스터와 전투! \n", b.name);
        Sleep(1000);
        printf("%s와 %s의 주사위 던지기 대결!!\n", b.name, p.name);
        Sleep(1000);
        while (1)
        {
            int dice_b = rand() % 6 + 1;
            int dice_p = rand() % 6 + 1;
            printf("%s의 주사위 : %d || %s의 주사위 : %d\n", b.name, dice_b, p.name, dice_p);
            Sleep(1000);
            if (dice_b > dice_p)
            {
                printf("%s가 %s를 %d만큼 공격!\n", b.name, p.name, b.atk);
                Sleep(1000);
                printf("%s의 원래 체력 : %d -> 남은 체력 : %d\n", p.name, p.hp, p.hp - b.atk);
                p.hp -= b.atk;
                Sleep(1000);
            }
            else if (dice_b < dice_p)
            {
                printf("%s가 %s를 %d만큼 공격!\n", p.name, b.name, p.atk);
                Sleep(1000);
                printf("%s의 원래 체력 : %d -> 남은 체력 : %d\n", b.name, b.hp, b.hp - p.atk);
                b.hp -= p.atk;
                Sleep(1000);
            }
            else
            {
                printf("비겼습니다.\n");
                Sleep(1000);
            }

            if (b.hp <= 0 || p.hp <= 0)
            {
                printf("모험이 모두 끝났습니다!!\n");
                Sleep(1000);
                if (b.hp <= 0) {
                    printf("당신의 승리입니다. 축하합니다\n");
                    Sleep(1000);
                    break;
                }
                else
                {
                    printf("%s가 당신의 시체 위에서 승리의 댄스를 춥니다...다음엔 분발하세요 ㅜ^ㅜ\n", b.name);
                    Sleep(1000);
                    break;
                }
            }


        }
    }


}

/*
    과제 : rpg게임 업그레이드
        1. 구현안한 이벤트 구현
        2. 원래 있던 이벤트 하나 선택해서 업그레이드
        3. 추가적으로 본인이 이벤트 하나 만들기
    + 던전 입장시 선택지 만들기
*/