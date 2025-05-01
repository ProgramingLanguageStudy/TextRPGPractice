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
	cout << name_ << " Battler ��ü�� �Ҹ�Ǿ����ϴ�." << endl;
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
	cout << "===== [" << name_ << "����] =====" << endl;
	cout << "����: " << level_ + 1 << endl;
	cout << "ü��: " << current_hp_ << " / " << max_hp_ << endl;
	cout << "���ݷ�: " << damage_ << endl;
	cout << "========================" << endl;
}

void Battler::TakeDamage(int amount)
{
	current_hp_ -= amount;
	if (current_hp_ < 0)
	{
		current_hp_ = 0;
	}

	cout << name_ << "��(��) " << amount << "�� ���ظ� �Ծ����ϴ�." << endl;

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
	cout << GetName() << "��(��) " << target.GetName() << "��(��) �����մϴ�!" << endl;
	target.TakeDamage(damage_);
}

void Battler::Die()
{
	cout << name_ << "��(��) ����߽��ϴ�." << endl;
}

bool Battler::IsAlive()
{
	return current_hp_ > 0;
}