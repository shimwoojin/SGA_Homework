#pragma once

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct _weapon
{
    char name[50];
    int damage;
    int range;
}weapon;

weapon w1 = { "������ Į", 10,1 };
weapon w2 = { "������ Ȱ", 10,2 };
weapon w3 = { "�ֽ� Ȱ", 10,3 };

typedef struct _level
{
    int lv;
    int exp;
}Level;

Level lv1 = { 1,50 };
Level lv2 = { 2,100 };
Level lv3 = { 3,150 };
Level lv4 = { 4,200 };
Level lv5 = { 5,250 };

typedef struct _Player
{
    char name[50];
    Level* p_level;
    int exp;
    int hp;
    int attack;
    float critical;
    float atk_ignore;
    weapon* equip_weapon;
}Player;

typedef struct _monster
{
    char name[50];
    int hp;
    int attack;
    int exp;
    float atk_ignore;
}Monster;

const Monster m1 = { "WhiteGoblin",100,20,50,0.0 };
const Monster m2 = { "BlackGoblin",120,25,75,0.0 };
const Monster m3 = { "GreenGoblin",150,30,100,0.0 };

typedef enum
{
    blank = 0,
    wall,
    player,
    monster,
} object;

typedef enum
{
    up = 'w',
    down = 's',
    left = 'a',
    right = 'd',
    up_atk = '8',
    down_atk = '5',
    left_atk = '4',
    right_atk = '6',
    attack = 32,     // space��
} move_dir;

typedef struct
{
    int x;
    int y;
} location;

int map[HEIGHT][WIDTH] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,3,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},//5
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//10
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,3,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},//15
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,3,0,0,0,0,0,0,0,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//20
};

void move(location* const p, const location* const dir);
Monster init_monster(char name[], int hp, int attack, float atk_ignore);
void print_p_info(Player* player);
void mini_rpg(Player* player);
void print_map();
Player init_player();

void mini_rpg(Player* player)
{
    location p;
    p.x = 1;
    p.y = 1;

    location dir;
    dir.x = 0;
    dir.y = 0;

    move_dir key;

    while (1)
    {
        print_map();
        print_p_info(player);

        key = (move_dir)_getch();

        switch (key)
        {
        case up:
            dir.x = 0;
            dir.y = -1;
            break;
        case down:
            dir.x = 0;
            dir.y = 1;
            break;
        case left:
            dir.x = -1;
            dir.y = 0;
            break;
        case right:
            dir.x = 1;
            dir.y = 0;
            break;
        case up_atk:
            //TODO:�Ÿ��� ���� atk����
            break;
        case down_atk:
            break;
        case left_atk:
            break;
        case right_atk:
            break;
        case attack:
            printf("����������\n");
            break;
            
        default:
            break;
        }
        move(&p, &dir);

    }






}

void print_map()
{
    system("cls");

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            switch (map[y][x])
            {
            case blank:
            {
                printf("  ");
            }break;
            case wall:
            {
                printf("��");
            }break;
            case player:
            {
                printf("��");
            }break;
            case monster:
            {
                printf("��");
            }break;
            default:
                break;
            }
        }
        printf("\n");
    }

}

void move(location* const p, const location* const dir)
{
    location dest;
    dest.x = p->x + dir->x;
    dest.y = p->y + dir->y;

    object dest_obj = (object)map[dest.y][dest.x];

    switch (dest_obj)
    {
    case blank:
        map[p->y][p->x] = blank;
        map[dest.y][dest.x] = player;
        p->x = dest.x;
        p->y = dest.y;
        break;

    case wall:
    case player:
        break;

    case monster:
        printf("�� ����!\n");
        Sleep(1000);
        printf("�� óġ!\n");
        Sleep(1000);
        map[p->y][p->x] = blank;
        map[dest.y][dest.x] = player;
        p->x = dest.x;
        p->y = dest.y;
        break;
    default:
        break;
    }
}

Player init_player()
{

    Player p1 = {
        {NULL},
        &lv1,
        0,
        200,
        50,
        0.3,
        0.2,
        &w1
    };
    printf("�̸��� �Է��Ͻÿ� : ");
    scanf_s("%s", p1.name, sizeof(p1.name));

    return p1;
}


Monster init_monster(char name[], int hp, int attack, float atk_ignore)
{
    Monster m =
    {
        *name,
        hp,
        attack,
        atk_ignore
    };
    return m;
}

void print_p_info(Player* player)
{
    printf("�÷��̾��� �̸� : %s\n", player->name);
    printf("�÷��̾��� LV : %d\n", player->p_level->lv);
    printf("���������� �䱸 ����ġ�� : %d\n", player->p_level->exp);
    printf("�÷��̾��� ���� exp : %d\n", player->exp);
    printf("�÷��̾��� hp : %d\n", player->hp);
    printf("�÷��̾��� ���ݷ� : %d\n", player->attack);
    printf("�÷��̾��� ũ��Ƽ�� Ȯ�� : %.2f\n", player->critical);
    printf("�÷��̾��� ȸ�� Ȯ�� : %.2f\n", player->atk_ignore);
    printf("\n");
}