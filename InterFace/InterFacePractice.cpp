#include <iostream>
#include <memory>

#include "InterFacePractice.h"

#pragma region 1�� ����
void Potion::Use()
{
    {
        cout << "������ ����Ͽ� ü���� ȸ���߽��ϴ�!" << endl;
    }
}

void Scroll::Use()
{
    {
        cout << "��ũ���� ����Ͽ� ������ �ߵ��Ǿ����ϴ�!" << endl;
    }
}

void Bomb::Use()
{
    {
        cout << "��ź�� �������ϴ�! �ֺ��� ���ظ� �������ϴ�!" << endl;
    }
}
#pragma endregion

#pragma region 2�� ����

Character::Character(string name, int hp, int damage)
{
    name_ = name;
    max_hp_ = hp;
    current_hp_ = max_hp_;
    damage_ = damage;
}

Character::~Character()
{

}

string Character::GetName()
{
    return name_;
}

int Character::GetHp()
{
    return current_hp_;
}

void Character::TakeDamage(int amount)
{
    current_hp_ -= amount;
    if (current_hp_ < 0)
    {
        current_hp_ = 0;
    }

    cout << name_ << "��(��) " << amount << "�� ���ظ� �Ծ����ϴ�." << endl;
    cout << "(���� ü��: " << current_hp_ << ")" << endl;
}

void Character::Attack(IDamageable& damageable)
{
    if (current_hp_ <= 0)
    {
        return;
    }
    cout << name_ << "��(��) " << damageable.GetName() << "��(��) �����մϴ�!" << endl;
    damageable.TakeDamage(damage_);
}

Door::Door(string name, int hp)
{
    name_ = name;
    max_hp_ = hp;
    current_hp_ = max_hp_;
}

Door::~Door()
{

}

string Door::GetName()
{
    return name_;
}

int Door::GetHp()
{
    return current_hp_;
}

void Door::TakeDamage(int amount)
{
    current_hp_ -= amount;
    if (current_hp_ < 0)
    {
        current_hp_ = 0;
    }

    cout << name_ << "��(��) " << amount << "�� ���ظ� �Ծ����ϴ�." << endl;
    cout << "(���� ������: " << current_hp_ << ")" << endl;
}

#pragma endregion

void InterFacePractice1()
{
    cout << "----- ������ ���� -----" << endl;

    Potion potion;
    Scroll scroll;
    Bomb bomb;
    
    IUsable* item1 = &potion;
    IUsable* item2 = &scroll;
    IUsable* item3 = &bomb;

    cout << "----- ������ ���� -----" << endl << endl;

    cout << "----- ������ ��� �׽�Ʈ -----" << endl;

    IUsable* items[3] = { item1, item2, item3 };
    for (int i = 0;i < 3;++i)
    {
        items[i]->Use();
    }

    cout << "----- ������ ��� �׽�Ʈ -----" << endl << endl;

    cout << "----- ���� -----" << endl;

    Character Hero("���", 200, 10);
    Character Enemy("����", 100, 5);
    Door Door("ö��", 30);

    Hero.Attack(Enemy);
    Hero.Attack(Door);

    cout << "----- ���� -----" << endl << endl;
}