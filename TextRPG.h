#pragma once
#include "Enemy.h"
#include "Hero.h"

using namespace std;

class TextRPG
{
public:
	/// <summary>
	/// ������ �����ϴ� �Լ�
	/// </summary>
	void Start();

private:
	//Hero* hero_;
	unique_ptr<Hero> hero_;

	/// <summary>
	/// ���ΰ� ĳ���͸� �����ϴ� �Լ�
	/// </summary>
	void CreateHero();

	/// <summary>
	/// ������ �� ĳ���͸� ������ ��ȯ�ϴ� �Լ�
	/// </summary>
	/// <returns>������ ���� �� ĳ����</returns>
	unique_ptr<Enemy> GenerateRandomEnemy();

	/// <summary>
	/// ��Ʋ ������ �����ϴ� �Լ�
	/// </summary>
	void RunBattleLoop();

	/// <summary>
	/// ���� ������ �����ϴ� �Լ�
	/// </summary>
	/// <param name="enemy"></param>
	void FightEnemy(Enemy& enemy);

};

