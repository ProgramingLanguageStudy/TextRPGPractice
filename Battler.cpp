#include "Battler.h"

using namespace std;

Battler::Battler()
{

}

Battler::Battler(string name, int hp, int damage)
{
	name_ = name;
	max_hp_ = hp;
	current_hp_ = max_hp_;
	damage_ = damage;
}

Battler::~Battler()
{
	cout << name_ << " Battler 객체가 소멸되었습니다." << endl;
}

string Battler::GetName()
{
	return name_;
}

void Battler::SetName(string name)
{
	name_ = name;
}

void Battler::PrintInfo()
{
	cout << "===== [" << name_ << "정보] =====" << endl;
	cout << "레벨: " << level_ + 1 << endl;
	cout << "체력: " << current_hp_ << " / " << max_hp_ << endl;
	cout << "공격력: " << damage_ << endl;
	cout << "========================" << endl;
}

void Battler::TakeDamage(int amount)
{
	current_hp_ -= amount;
	if (current_hp_ < 0)
	{
		current_hp_ = 0;
	}

	cout << name_ << "이(가) " << amount << "의 피해를 입었습니다." << endl;

	if (current_hp_ <= 0)
	{
		Die();
	}
}

void Battler::Attack(IDamageable& target)
{
	if (current_hp_ <= 0)
	{
		return;
	}
	cout << GetName() << "이(가) " << target.GetName() << "을(를) 공격합니다!" << endl;
	target.TakeDamage(damage_);
}

void Battler::Die()
{
	cout << name_ << "이(가) 사망했습니다." << endl;
}

bool Battler::IsAlive()
{
	return current_hp_ > 0;
}