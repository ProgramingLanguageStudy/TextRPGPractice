#pragma once
#include <iostream>
#include "Battler.h"

using namespace std;

class Hero : public Battler
{
public:
	Hero(string name);
	~Hero();

	void PrintInfo() override;
	void Die() override;

	/// <summary>
	/// �� Ƚ���� ����ϸ� ���� �ϰ� true�� ��ȯ,
	/// �� Ƚ���� ���ڶ�� false�� ��ȯ
	/// </summary>
	bool TryHeal();

	int GetHealCount();

	void AddExp(int amount);
	void LevelUp(int hp_gain, int damage_gain);

private:
	int max_exp_;
	int current_exp_;
	int heal_count_ = 3;
};

