#include "Enemy.h"

using namespace std;

//Enemy::Enemy(string name, int hp, int damage, int level, int exp)
//{
//	name_ = name;
//	max_hp_ = hp;
//	current_hp_ = max_hp_;
//	damage_ = damage;
//	level_ = level;
//	exp_reward_ = exp;
//}

Enemy::Enemy(string name, int hp, int damage, int level, int exp)
	: Battler(name, hp, damage)
{
	level_ = level;
	exp_reward_ = exp;
}
Enemy::~Enemy()
{
	cout << name_ << " Enemy ��ü�� �Ҹ�Ǿ����ϴ�." << endl;
}

int Enemy::GetExpReward()
{
	return exp_reward_;
}

void Enemy::PrintInfo()
{
	cout << "===== [" << name_ << "����] =====" << endl;
	cout << "����: " << level_ + 1 << endl;
	cout << "ü��: " << current_hp_ << " / " << max_hp_ << endl;
	cout << "���ݷ�: " << damage_ << endl;
	cout << "���� ����ġ: " << exp_reward_ << endl;
	cout << "========================" << endl;
}

void Enemy::Die()
{
	SpeakOnDeath();
	Battler::Die();	// �θ��� Die() �Լ��� ����
}

void Enemy::SpeakOnAppear()
{
	cout << "������~!" << endl;
	cout << name_ << "��(��) �������Ÿ��� ��Ÿ�����ϴ�!" << endl;
}

void Enemy::SpeakOnDeath()
{
	cout << "�ٿ���...!" << endl;
}

Slime::Slime() : Enemy("������", 30, 3, 0, 500)
{
}

void Slime::SpeakOnAppear()
{
	cout << "����?" << endl;
	cout << "�Ϳ��� " << name_ << "��(��) ��Ÿ�����ϴ�!" << endl;
}

void Slime::SpeakOnDeath()
{
	cout << "����..." << endl;
}

Slime::~Slime()
{
	cout << name_ << " Slime ��ü�� �Ҹ�Ǿ����ϴ�." << endl;
}

Goblin::Goblin() : Enemy("���", 50, 5, 1,1000)
{
}

void Goblin::SpeakOnAppear()
{
	cout << "ŰŰŰ~!" << endl;
	cout << name_ << "��(��) ��� ���ڰ� ������ ��Ÿ�����ϴ�!" << endl;
}

void Goblin::SpeakOnDeath()
{
	cout << "Ű���...!" << endl;
}

Goblin::~Goblin()
{
	cout << name_ << " Goblin ��ü�� �Ҹ�Ǿ����ϴ�." << endl;
}

Orc::Orc() : Enemy("��ũ", 80, 12, 2, 1000)
{
}

void Orc::Attack(IDamageable& target)
{
	if (current_hp_ <= 0)
	{
		return;
	}

	// 1���� 10���� ���� ����
	int chance = rand() % 10 + 1;  // 1 ~ 10 ������ ��

	float finalDamage = damage_;  // �⺻ ������

	// 1~3 ������ ���� ������ 30% Ȯ���� 2�� ������
	if (chance <= 3) {
		finalDamage *= 2.0f;  // 2�� ������
		cout << GetName() << "��(��) �Ͱ��� ����Ͽ� " << target.GetName() << "��(��) 2�� �������� �����մϴ�!" << endl;
	}
	else {
		cout << GetName() << "��(��) " << target.GetName() << "��(��) �����մϴ�!" << endl;
	}

	target.TakeDamage(finalDamage);  // ���� �������� target���� ����
}

void Orc::SpeakOnAppear()
{
	cout << "������~!" << endl;
	cout << name_ << "��(��) ����� �����ϸ� ��Ÿ�����ϴ�!" << endl;
}

void Orc::SpeakOnDeath()
{
	cout << "�����...!" << endl;
}

Orc::~Orc()
{
	cout << name_ << " Orc ��ü�� �Ҹ�Ǿ����ϴ�." << endl;
}