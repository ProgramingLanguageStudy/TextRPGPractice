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
	cout << name_ << " Enemy 객체가 소멸되었습니다." << endl;
}

int Enemy::GetExpReward()
{
	return exp_reward_;
}

void Enemy::PrintInfo()
{
	cout << "===== [" << name_ << "정보] =====" << endl;
	cout << "레벨: " << level_ + 1 << endl;
	cout << "체력: " << current_hp_ << " / " << max_hp_ << endl;
	cout << "공격력: " << damage_ << endl;
	cout << "보상 경험치: " << exp_reward_ << endl;
	cout << "========================" << endl;
}

void Enemy::Die()
{
	SpeakOnDeath();
	Battler::Die();	// 부모의 Die() 함수를 실행
}

void Enemy::SpeakOnAppear()
{
	cout << "으르렁~!" << endl;
	cout << name_ << "이(가) 으르렁거리며 나타났습니다!" << endl;
}

void Enemy::SpeakOnDeath()
{
	cout << "꾸에엑...!" << endl;
}

Slime::Slime() : Enemy("슬라임", 30, 3, 0, 500)
{
}

void Slime::SpeakOnAppear()
{
	cout << "뀨우우?" << endl;
	cout << "귀여운 " << name_ << "이(가) 나타났습니다!" << endl;
}

void Slime::SpeakOnDeath()
{
	cout << "뀨우우..." << endl;
}

Slime::~Slime()
{
	cout << name_ << " Slime 객체가 소멸되었습니다." << endl;
}

Goblin::Goblin() : Enemy("고블린", 50, 5, 1,1000)
{
}

void Goblin::SpeakOnAppear()
{
	cout << "키키키~!" << endl;
	cout << name_ << "이(가) 기분 나쁘게 웃으며 나타났습니다!" << endl;
}

void Goblin::SpeakOnDeath()
{
	cout << "키요오...!" << endl;
}

Goblin::~Goblin()
{
	cout << name_ << " Goblin 객체가 소멸되었습니다." << endl;
}

Orc::Orc() : Enemy("오크", 80, 12, 2, 1000)
{
}

void Orc::Attack(IDamageable& target)
{
	if (current_hp_ <= 0)
	{
		return;
	}

	// 1부터 10까지 난수 생성
	int chance = rand() % 10 + 1;  // 1 ~ 10 사이의 값

	float finalDamage = damage_;  // 기본 데미지

	// 1~3 사이의 값이 나오면 30% 확률로 2배 데미지
	if (chance <= 3) {
		finalDamage *= 2.0f;  // 2배 데미지
		cout << GetName() << "이(가) 맹공을 사용하여 " << target.GetName() << "을(를) 2배 데미지로 공격합니다!" << endl;
	}
	else {
		cout << GetName() << "이(가) " << target.GetName() << "을(를) 공격합니다!" << endl;
	}

	target.TakeDamage(finalDamage);  // 최종 데미지를 target에게 전달
}

void Orc::SpeakOnAppear()
{
	cout << "끄흐흐~!" << endl;
	cout << name_ << "이(가) 당신을 위협하며 나타났습니다!" << endl;
}

void Orc::SpeakOnDeath()
{
	cout << "우오오...!" << endl;
}

Orc::~Orc()
{
	cout << name_ << " Orc 객체가 소멸되었습니다." << endl;
}