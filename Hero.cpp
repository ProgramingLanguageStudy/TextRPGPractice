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
	cout << name_ << " Hero ��ü�� �Ҹ�Ǿ����ϴ�." << endl;
}

void Hero::PrintInfo()
{
	// Battler�� PrintInfo()�� ����ġ ǥ�� �߰�
	cout << "===== [" << name_ << "����] =====" << endl;
	cout << "����: " << level_ + 1 << endl;
	cout << "ü��: " << current_hp_ << " / " << max_hp_ << endl;
	cout << "���ݷ�: " << damage_ << endl;
	cout << "����ġ: " << current_exp_ << " / " << max_exp_ << endl;
	cout << "========================" << endl;
}

void Hero::Die()
{
	// Battler�� Die() ��� ���� ���� ���� �޼��� ���
	// "��! ���⼭ �����ٴ�..."
	// "���ΰ� ~~�� ������ ����Ǿ����ϴ�."
	cout << "��... ���� �״ٴ�..." << endl;
	cout << "����� ������ ����Ǿ����ϴ�" << endl;
}

bool Hero::TryHeal()
{
	if (heal_count_ <= 0) {
		cout << GetName() << "��(��) �� Ƚ���� ��� ����߽��ϴ�." << endl;
		return false;
	}

	int heal_amount = max_hp_ / 5;

	if (current_hp_ + heal_amount > max_hp_) {
		heal_amount = max_hp_ - current_hp_;
	}

	current_hp_ += heal_amount;
	heal_count_--;  // �� Ƚ�� ����

	cout << GetName() << "��(��) " << heal_amount << "��ŭ ü���� ȸ���մϴ�." << endl;
	cout << "���� �� Ƚ��: " << heal_count_ << endl;
	PrintInfo();
	return true;
}

int Hero::GetHealCount()
{
	return heal_count_;
}

void Hero::AddExp(int amount)
{
	// amount��ŭ ���� ����ġ ����
	// ���� ����ġ�� �ִ� ����ġ�� �Ѿ��� ��
	// �׸�ŭ ���� ����ġ�� ���ҽ�Ű�� ������!

	// (�����ϸ� ���� �� �� ����ġ �̿�)
	current_exp_ += amount;
	cout << name_ << "��(��) " << amount << "�� ����ġ�� ȹ���ߴ�." << endl;

	int level_up_count = 0;		// �̹� ������ �� ������ ����
	int total_hp_gain = 0;		// �̹� �������� ü�� ������
	int total_damage_gain = 0;	// �̹� �������� ���ݷ� ������
	int hp_by_level = 5;		// ü�� ���� ���
	int damage_by_level = 1;	// ���ݷ� ���� ���

	while (current_exp_ >= max_exp_)
	{
		current_exp_ -= max_exp_;
		max_exp_ *= 2; // ����ġ�� ����
		level_up_count++;

		// ���� ������ ����� ���� ü�°� ���ݷ� ������ ���
		int hp_gain = hp_by_level * (level_ + 1);
		int damage_gain = damage_by_level * (level_ + 1);

		// �ѹ��� ������ ������ �ø� ����� ������ ���
		total_hp_gain += hp_gain;
		total_damage_gain += damage_gain;

		LevelUp(hp_gain, damage_gain);
	}

	if (level_up_count > 0)
	{
		cout << name_ << "�� ������ " << level_up_count << "��ŭ �ö���!" << endl;
		cout << ">> �ִ�ü���� " << total_hp_gain << "��ŭ �����Ͽ���." << endl;
		cout << ">> ���ݷ��� " << total_damage_gain << "��ŭ �����Ͽ���." << endl;
		
		current_hp_ = max_hp_; // ������ Ư������ �ִ�ü�� ȸ��
		heal_count_ = 3;
		cout << name_ << "�� ü���� ������ ȸ���Ǿ���." << endl;
	}
}

void Hero::LevelUp(int hp_gain, int damage_gain)
{
	// �ִ� ����ġ�� ������ 2��� ����
	// ü��, ���ݷ� ������ ����
	// ���� ����

	level_++;
	max_hp_ += hp_gain;
	damage_ += damage_gain;
}