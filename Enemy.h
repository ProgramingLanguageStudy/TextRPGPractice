#pragma once
#include "Battler.h"

using namespace std;

// Enemy 클래스는 Battler 클래스를 상속하게 된다.
// 자식 클래스로 만든 객체는 부모 클래스 변수로 사용될 수 있다.

class Enemy : public Battler
{
public:
	Enemy(string name, int hp, int damage, int level, int exp);
	virtual ~Enemy();

	int GetExpReward();

	void PrintInfo() override;	// 일종의 부모함수 덮어쓰기
	void Die() override;

	virtual void SpeakOnAppear();
	virtual void SpeakOnDeath();

private:
	int exp_reward_;
};

// final 키워드
// 클래스 뒤에 붙이면 상속 금지
// 함수 뒤에 붙이면 오버라이딩 금지
// 일반적으로 자주 쓰지 않음. 기능 확장을 염두에 두기 때문

// C#에는 sealed가 있다.
// C++의 final이든 C#의 sealed든 필수적으로 쓰이지는 않는다.

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