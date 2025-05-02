#pragma once
#include <iostream>

using namespace std;

/*
������� ���� ����� ����
�Լ� ���� �� const ���� ������ �Լ����� const ����

��������. ���� ���� �����
1) Monster Ŭ������ ����� �ּ���. Monster�� ����
���̵�, �̸�, �ִ� ü��, ���� ü���� �����ϴ�.

2) Monster �����ڸ� ����� ������ ����Ʈ�� Ȱ���� ����������� �ʱ�ȭ�� �ּ���.
Monster �����ڴ� �Ű������� �̸�, ü���� �����ϴ�.
���� ������ Ȱ���� �� Monster ��ü�� ������ ���̵� �������� �� �ּ���.
���� ��� kMinHp, kMaxHp�� �����
�� Monster�� �ִ� ü���� kMinHp ~ kMaxHp ������ ���� ������ �� �ּ���.

3) Monster�� �ڽ��� ���̵�, �̸�, �ִ� ü��, ���� ü���� �ܼ�â�� ���� �ִ�
PrintInfo() �Լ��� ����� �ּ���.

4) Monster Ŭ������ ������� ������ ���� ���� ��ȯ�ϴ�
GetTotalCount() ���� �Լ��� ����� �ּ���.

5) main() �Լ����� Monster ��ü�� 3���� �̻� ������ �ּ���.

6) main() �Լ����� Monster Ŭ������ GetTotalCount() �Լ��� Ȱ���� ������� ������
���� ��ü ���� ����� �ּ���.

7) main() �Լ����� Monster ������ �迭�� ����� ������ Monster ��ü���� �迭�� ������ �ּ���.

8) main() �Լ����� Monster ������ �迭�� for���� Ȱ���� �� Monster�� PrintInfo() �Լ��� ������
�� Monster�� ������ ����� �ּ���.
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
���� ����. ��ų ��� ��� �ý���
1) ISkillUser��� �������̽��� ����� �ּ���.
UseSkill() �Լ��� ������ �ּ���.

2) ISkillUser�� ��ӹ޴� SkillHero��� �θ� Ŭ������ ����� �ּ���.
SkillHero�� ��� ������ �̸�, �ִ� ����, ���� ������ �����ϴ�.
����, �ڽ��� �̸�, �ִ� ����, ���� ������ ����ϴ� PrintInfo() �Լ��� �����ϴ�.

3) SkillHero Ŭ������ ���� ���� ī���͸� �߰���
��ü�� ������ ������ �ش� ī���Ͱ� 1 �����ϵ��� �� �ּ���.
�ش� ī���͸� �ܺο� ��ȯ�ϴ� ���� �Լ� GetTotalCount()�� ����� �ּ���.

4) SkillHero�� ��ӹ޴� Warrior, Mage Ŭ������ ����� �ּ���.
������ Ŭ������ ��ų ��� �� ������ ��� ���� �Ҹ��� �����ϴ�.(static const)
UseSkill() �Լ��� �����ϰ�
�ش� �Լ����� ������ �Ҹ��ϰ� ��ų ��뿡 ���� �޽����� ����ϰ� �� �ּ���.
�޽��� ��� �� �Ҹ��� ������ ���� ��µǰ� �� �ּ���.

5) main() �Լ����� Warrior�� Mage ��ü�� ����
ISkillUser Ÿ���� ����ũ �����ͷ� �����ϰ�
UseSkill() �Լ��� ������ �ּ���.

6) main() �Լ����� SkillHero Ŭ������ GetTotalCount() �Լ��� �����
������� ������ Hero ��ü ���� ����� �ּ���.
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