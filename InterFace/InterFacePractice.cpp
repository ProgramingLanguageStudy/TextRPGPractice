#include <iostream>
#include <memory>

#include "InterFacePractice.h"

#pragma region 1번 문제
void Potion::Use()
{
    {
        cout << "포션을 사용하여 체력을 회복했습니다!" << endl;
    }
}

void Scroll::Use()
{
    {
        cout << "스크롤을 사용하여 마법이 발동되었습니다!" << endl;
    }
}

void Bomb::Use()
{
    {
        cout << "폭탄이 터졌습니다! 주변에 피해를 입혔습니다!" << endl;
    }
}
#pragma endregion

#pragma region 2번 문제

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

    cout << name_ << "이(가) " << amount << "의 피해를 입었습니다." << endl;
    cout << "(남은 체력: " << current_hp_ << ")" << endl;
}

void Character::Attack(IDamageable& damageable)
{
    if (current_hp_ <= 0)
    {
        return;
    }
    cout << name_ << "이(가) " << damageable.GetName() << "을(를) 공격합니다!" << endl;
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

    cout << name_ << "이(가) " << amount << "의 피해를 입었습니다." << endl;
    cout << "(남은 내구도: " << current_hp_ << ")" << endl;
}

#pragma endregion

void InterFacePractice1()
{
    cout << "----- 아이템 생성 -----" << endl;

    Potion potion;
    Scroll scroll;
    Bomb bomb;
    
    IUsable* item1 = &potion;
    IUsable* item2 = &scroll;
    IUsable* item3 = &bomb;

    cout << "----- 아이템 생성 -----" << endl << endl;

    cout << "----- 아이템 사용 테스트 -----" << endl;

    IUsable* items[3] = { item1, item2, item3 };
    for (int i = 0;i < 3;++i)
    {
        items[i]->Use();
    }

    cout << "----- 아이템 사용 테스트 -----" << endl << endl;

    cout << "----- 전투 -----" << endl;

    Character Hero("용사", 200, 10);
    Character Enemy("몬스터", 100, 5);
    Door Door("철문", 30);

    Hero.Attack(Enemy);
    Hero.Attack(Door);

    cout << "----- 전투 -----" << endl << endl;
}