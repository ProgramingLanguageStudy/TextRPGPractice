#pragma once
#include "Enemy.h"
#include "Hero.h"

using namespace std;

class TextRPG
{
public:
	/// <summary>
	/// 게임을 시작하는 함수
	/// </summary>
	void Start();

private:
	//Hero* hero_;
	unique_ptr<Hero> hero_;

	/// <summary>
	/// 주인공 캐릭터를 생성하는 함수
	/// </summary>
	void CreateHero();

	/// <summary>
	/// 랜덤한 적 캐릭터를 생성해 반환하는 함수
	/// </summary>
	/// <returns>생성된 랜덤 적 캐릭터</returns>
	unique_ptr<Enemy> GenerateRandomEnemy();

	/// <summary>
	/// 배틀 루프를 실행하는 함수
	/// </summary>
	void RunBattleLoop();

	/// <summary>
	/// 적과 전투를 진행하는 함수
	/// </summary>
	/// <param name="enemy"></param>
	void FightEnemy(Enemy& enemy);

};

