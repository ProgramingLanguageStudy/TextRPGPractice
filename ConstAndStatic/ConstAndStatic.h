#pragma once
#include <iostream>

using namespace std;

/*
헤더파일 따로 만들기 권장
함수 정의 시 const 적용 가능한 함수에는 const 적용

연습문제. 몬스터 도감 만들기
1) Monster 클래스를 만들어 주세요. Monster는 각자
아이디, 이름, 최대 체력, 현재 체력을 가집니다.

2) Monster 생성자를 만들고 생성자 리스트를 활용해 멤버변수들을 초기화해 주세요.
Monster 생성자는 매개변수로 이름, 체력을 가집니다.
정적 변수를 활용해 각 Monster 객체가 고유한 아이디를 가지도록 해 주세요.
정적 상수 kMinHp, kMaxHp를 사용해
각 Monster의 최대 체력이 kMinHp ~ kMaxHp 사이의 값만 갖도록 해 주세요.

3) Monster에 자신의 아이디, 이름, 최대 체력, 현재 체력을 콘솔창에 보여 주는
PrintInfo() 함수를 만들어 주세요.

4) Monster 클래스에 현재까지 생성된 몬스터 수를 반환하는
GetTotalCount() 정적 함수를 만들어 주세요.

5) main() 함수에서 Monster 객체를 3마리 이상 생성해 주세요.

6) main() 함수에서 Monster 클래스의 GetTotalCount() 함수를 활용해 현재까지 생성된
몬스터 객체 수를 출력해 주세요.

7) main() 함수에서 Monster 포인터 배열을 만들고 생성된 Monster 객체들을 배열에 저장해 주세요.

8) main() 함수에서 Monster 포인터 배열과 for문을 활용해 각 Monster의 PrintInfo() 함수를 실행해
각 Monster의 정보를 출력해 주세요.
*/

class Monster
{
public:
	Monster(string name, int max_hp);
	~Monster();

	void PrintInfo();
	bool isNormal();

	static int GetTotalCount()
	{
		return counter_;
	}

private:
	static const int kMinHp = 0;
	static const int kMaxHp = 999;

	static int counter_;

	const int id_;

	string name_;
	int max_hp_;
	int current_hp_;
};

int Monster::counter_ = 0;


/*
연습 문제. 스킬 사용 기록 시스템
1) ISkillUser라는 인터페이스를 만들어 주세요.
UseSkill() 함수를 포함해 주세요.

2) ISkillUser를 상속받는 SkillHero라는 부모 클래스를 만들어 주세요.
SkillHero는 멤버 변수로 이름, 최대 마나, 현재 마나를 갖습니다.
또한, 자신의 이름, 최대 마나, 현재 마나를 출력하는 PrintInfo() 함수를 갖습니다.

3) SkillHero 클래스에 정적 변수 카운터를 추가해
객체가 생성될 때마다 해당 카운터가 1 증가하도록 해 주세요.
해당 카운터를 외부에 반환하는 정적 함수 GetTotalCount()를 만들어 주세요.

4) SkillHero를 상속받는 Warrior, Mage 클래스를 만들어 주세요.
각각의 클래스는 스킬 사용 시 고유한 상수 마나 소모량을 갖습니다.(static const)
UseSkill() 함수를 구현하고
해당 함수에서 마나를 소모하고 스킬 사용에 대한 메시지를 출력하게 해 주세요.
메시지 출력 시 소모한 마나도 같이 출력되게 해 주세요.

5) main() 함수에서 Warrior와 Mage 객체를 각각
ISkillUser 타입의 유니크 포인터로 생성하고
UseSkill() 함수를 실행해 주세요.

6) main() 함수에서 SkillHero 클래스의 GetTotalCount() 함수를 사용해
현재까지 생성된 Hero 객체 수를 출력해 주세요.
*/
class ISkillUser
{
public:
	virtual void UseSkill() = 0;
	virtual ~ISkillUser() = default;
	virtual void PrintInfo() const = 0;
};

class SkillHero : public ISkillUser
{
public:
	SkillHero(string name, int max_mp);
	virtual ~SkillHero();

	void PrintInfo() const override;

	static int GetTotalCount()
	{
		return hero_counter_;
	}

protected:
	static int hero_counter_;

	string name_;
	int max_mp_;
	int current_mp_;
};

class Warrior : public SkillHero
{
public:
	Warrior(string name, int max_mp);
	virtual ~Warrior();
	void UseSkill() override;

private:
	static const int kWarriorSkill1;
	
};

class Mage : public SkillHero
{
public:
	Mage(string name, int max_mp);
	virtual ~Mage();
	void UseSkill() override;

private:
	static const int kMageSkill1;
	
};