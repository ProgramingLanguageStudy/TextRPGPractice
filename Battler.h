#pragma once
#include <iostream>

using namespace std;

// 피해를 입을 수 있는 인터페이스
class IDamageable 
{
public:
	virtual ~IDamageable() = default;

	virtual void TakeDamage(int amount) = 0;
	virtual string GetName() = 0;
};

// 공격을 할 수 있는 인터페이스
class IAttackable
{
public:
	virtual ~IAttackable() = default;

	virtual void Attack(IDamageable& target) = 0;
};

class Battler : public IDamageable, public IAttackable
{
public:
	Battler();
	Battler(string name, int hp, int damage);
	~Battler();
	/// <summary>
	/// 배틀러의 이름을 반환해 주는 함수
	/// </summary>
	/// <returns></returns>
	string GetName() override;
	/// <summary>
	/// 배틀러의 이름을 재설정하는 함수
	/// </summary>
	/// <param name="name"></param>
	void SetName(string name);
	/// <summary>
	/// 배틀러의 정보를 출력해 주는 함수
	/// </summary>
	virtual void PrintInfo();		// virtual 가상 함수(자식 클래스에서 오버라이드가 가능하다)
	/// <summary>
	/// 대미지를 입는 함수
	/// </summary>
	/// <param name="amount">입을 대미지 양</param>
	void TakeDamage(int amount) override;
	/// <summary>
	/// target을 공격하는 함수
	/// </summary>
	void Attack(IDamageable& target) override;
	/// <summary>
	/// 죽는 함수
	/// </summary>
	virtual void Die();
	/// <summary>
	/// 살아있는지 여부를 체크하는 함수
	/// </summary>
	/// <returns></returns>
	bool IsAlive();
protected:
	// ----- 멤버 변수 ----- //
	string name_ = "주인공";         // 캐릭터 이름
	int level_ = 0;					 // 캐릭터 레벨
	int max_hp_ = 100;               // 최대 체력
	int current_hp_ = 100;           // 현재 체력
	int damage_ = 10;                // 공격력
	// ----- 멤버 변수 ----- //
};
