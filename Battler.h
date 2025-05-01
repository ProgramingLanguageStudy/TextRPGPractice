#pragma once
#include <iostream>

using namespace std;

// ���ظ� ���� �� �ִ� �������̽�
class IDamageable 
{
public:
	virtual ~IDamageable() = default;

	virtual void TakeDamage(int amount) = 0;
	virtual string GetName() = 0;
};

// ������ �� �� �ִ� �������̽�
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
	/// ��Ʋ���� �̸��� ��ȯ�� �ִ� �Լ�
	/// </summary>
	/// <returns></returns>
	string GetName() override;
	/// <summary>
	/// ��Ʋ���� �̸��� �缳���ϴ� �Լ�
	/// </summary>
	/// <param name="name"></param>
	void SetName(string name);
	/// <summary>
	/// ��Ʋ���� ������ ����� �ִ� �Լ�
	/// </summary>
	virtual void PrintInfo();		// virtual ���� �Լ�(�ڽ� Ŭ�������� �������̵尡 �����ϴ�)
	/// <summary>
	/// ������� �Դ� �Լ�
	/// </summary>
	/// <param name="amount">���� ����� ��</param>
	void TakeDamage(int amount) override;
	/// <summary>
	/// target�� �����ϴ� �Լ�
	/// </summary>
	void Attack(IDamageable& target) override;
	/// <summary>
	/// �״� �Լ�
	/// </summary>
	virtual void Die();
	/// <summary>
	/// ����ִ��� ���θ� üũ�ϴ� �Լ�
	/// </summary>
	/// <returns></returns>
	bool IsAlive();
protected:
	// ----- ��� ���� ----- //
	string name_ = "���ΰ�";         // ĳ���� �̸�
	int level_ = 0;					 // ĳ���� ����
	int max_hp_ = 100;               // �ִ� ü��
	int current_hp_ = 100;           // ���� ü��
	int damage_ = 10;                // ���ݷ�
	// ----- ��� ���� ----- //
};
