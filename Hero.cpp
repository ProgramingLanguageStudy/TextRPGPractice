#include "Hero.h"

using namespace std;

Hero::Hero(string name) : Battler(name, 100, 10)
{
	level_ = 0;
	max_exp_ = 100;
	current_exp_ = 0;
}

Hero::~Hero()
{
	cout << name_ << " Hero 객체가 소멸되었습니다." << endl;
}

void Hero::PrintInfo()
{
	// Battler의 PrintInfo()에 경험치 표시 추가
	cout << "===== [" << name_ << "정보] =====" << endl;
	cout << "레벨: " << level_ + 1 << endl;
	cout << "체력: " << current_hp_ << " / " << max_hp_ << endl;
	cout << "공격력: " << damage_ << endl;
	cout << "경험치: " << current_exp_ << " / " << max_exp_ << endl;
	cout << "========================" << endl;
}

void Hero::Die()
{
	// Battler의 Die() 대신 게임 오버 관련 메세지 출력
	// "윽! 여기서 끝나다니..."
	// "주인공 ~~의 여정이 종료되었습니다."
	cout << "윽... 내가 죽다니..." << endl;
	cout << "당신의 여정이 종료되었습니다" << endl;
}

bool Hero::TryHeal()
{
	if (heal_count_ <= 0) {
		cout << GetName() << "은(는) 힐 횟수를 모두 사용했습니다." << endl;
		return false;
	}

	int heal_amount = max_hp_ / 5;

	if (current_hp_ + heal_amount > max_hp_) {
		heal_amount = max_hp_ - current_hp_;
	}

	current_hp_ += heal_amount;
	heal_count_--;  // 힐 횟수 차감

	cout << GetName() << "이(가) " << heal_amount << "만큼 체력을 회복합니다." << endl;
	cout << "남은 힐 횟수: " << heal_count_ << endl;
	PrintInfo();
	return true;
}

int Hero::GetHealCount()
{
	return heal_count_;
}

void Hero::AddExp(int amount)
{
	// amount만큼 현재 경험치 증가
	// 현재 경험치가 최대 경험치를 넘었을 때
	// 그만큼 현재 경험치를 감소시키고 레벨업!

	// (가능하면 레벨 업 후 경험치 이월)
	current_exp_ += amount;
	cout << name_ << "은(는) " << amount << "의 경험치를 획득했다." << endl;

	int level_up_count = 0;		// 이번 레벨업 때 증가한 레벨
	int total_hp_gain = 0;		// 이번 레벨업시 체력 증가량
	int total_damage_gain = 0;	// 이번 레벨업시 공격력 증가량
	int hp_by_level = 5;		// 체력 증가 계수
	int damage_by_level = 1;	// 공격력 증가 계수

	while (current_exp_ >= max_exp_)
	{
		current_exp_ -= max_exp_;
		max_exp_ *= 2; // 경험치통 증가
		level_up_count++;

		// 현재 레벨에 계수를 곱해 체력과 공격력 증가량 계산
		int hp_gain = hp_by_level * (level_ + 1);
		int damage_gain = damage_by_level * (level_ + 1);

		// 한번에 여러번 레벨업 시를 대비한 증가량 계산
		total_hp_gain += hp_gain;
		total_damage_gain += damage_gain;

		LevelUp(hp_gain, damage_gain);
	}

	if (level_up_count > 0)
	{
		cout << name_ << "의 레벨이 " << level_up_count << "만큼 올랐다!" << endl;
		cout << ">> 최대체력이 " << total_hp_gain << "만큼 증가하였다." << endl;
		cout << ">> 공격력이 " << total_damage_gain << "만큼 증가하였다." << endl;
		
		current_hp_ = max_hp_; // 레벨업 특전으로 최대체력 회복
		heal_count_ = 3;
		cout << name_ << "의 체력이 완전히 회복되었다." << endl;
	}
}

void Hero::LevelUp(int hp_gain, int damage_gain)
{
	// 최대 경험치가 기존의 2배로 설정
	// 체력, 공격력 일정량 증가
	// 레벨 증가

	level_++;
	max_hp_ += hp_gain;
	damage_ += damage_gain;
}