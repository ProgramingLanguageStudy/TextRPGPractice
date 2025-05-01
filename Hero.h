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
	/// 힐 횟수가 충분하면 힐을 하고 true를 반환,
	/// 힐 횟수가 모자라면 false를 반환
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

