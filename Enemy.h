#pragma once
#include "Battler.h"

using namespace std;

// Enemy Ŭ������ Battler Ŭ������ ����ϰ� �ȴ�.
// �ڽ� Ŭ������ ���� ��ü�� �θ� Ŭ���� ������ ���� �� �ִ�.

class Enemy : public Battler
{
public:
	Enemy(string name, int hp, int damage, int level, int exp);
	virtual ~Enemy();

	int GetExpReward();

	void PrintInfo() override;	// ������ �θ��Լ� �����
	void Die() override;

	virtual void SpeakOnAppear();
	virtual void SpeakOnDeath();

private:
	int exp_reward_;
};

// final Ű����
// Ŭ���� �ڿ� ���̸� ��� ����
// �Լ� �ڿ� ���̸� �������̵� ����
// �Ϲ������� ���� ���� ����. ��� Ȯ���� ���ο� �α� ����

// C#���� sealed�� �ִ�.
// C++�� final�̵� C#�� sealed�� �ʼ������� �������� �ʴ´�.

class Slime : public Enemy
{
public:
	Slime();
	~Slime() override;

	void SpeakOnAppear() override;
	void SpeakOnDeath() override;
};

class Goblin : public Enemy
{
public:
	Goblin();
	~Goblin() override;

	void SpeakOnAppear() override;
	void SpeakOnDeath() override;
};

class Orc : public Enemy
{
public:
	Orc();
	~Orc() override;

	void Attack(IDamageable& target) override;
	void SpeakOnAppear() override;
	void SpeakOnDeath() override;
};