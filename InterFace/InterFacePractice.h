#pragma once

using namespace std;

/*

Ŭ���� �۾� ��.
��� ���� ���� �ǰ�, �� ��ũ��Ʈ ���Ͽ��� Ŭ���� �����ؼ� ����ص� OK

��������1. �پ��� ������ �������� �������̽��� ����ϱ�
�� ���ӿ��� �� ������ �������� �����մϴ�.

���� - ����ϸ� ü���� ȸ��
��ũ�� - ����ϸ� ���� �ߵ�
��ź - ����ϸ� �����ؼ� �ֺ��� ������
(-> ���� �޽��� ���)

�� ���� �ٸ� ������ �������� �ϳ��� ������ �迭�� �����ϰ�
for������ �� ��ҵ��� ����ϵ��� ����� �ּ���.

1. Use() �Լ��� �����ϴ� IUsable�̶�� �̸��� �������̽��� ����� �ּ���.
2. IUsable�� ��ӹ��� ����, ��ũ��, ��ź Ŭ������ ���� ������ �ּ���.
3. main() �Լ����� �� �������� ��ü�� ����� IUsable* ������ �迭�� �����ϼ���.
4. for���� ���� IUsable* ������ �迭�� �� �����۵��� Use() �Լ��� ������ �ּ���.

��������2. ���� ������ ��ü�� ���ظ� �޴� ��ü �����ϱ�
�� ������ �� ������ ��ü�� �����մϴ�.
ĳ���� - ������ �� �ְ� ������ ���� ���� �ֽ��ϴ�.
�� - ������ �� ������, ������ �޾� �μ��� �� �ֽ��ϴ�.

main() �Լ����� � ĳ���� ��ü�� �ٸ� ĳ���� ��ü�� �����ϴ� �ڵ带 �����ϰ�,
� ĳ���� ��ü�� �ٸ� �� ��ü�� �����ϴ� �ڵ带 ������ �ּ���.

0. ���� �� ���� ������ �����ϴ��� �޼���.
�ǰ� �� ���� ü�� ���� �����ϴ� �޼����� ��µǾ�� �մϴ�.
1. TakeDamage(int amount) �Լ��� ���� IDamageable �������̽��� ����� �ּ���.
2. Attack(IDamageable& damageable) �Լ��� ���� IAttackable �������̽��� ����� �ּ���.
3. IAttackable, IDamageable�� ��ӹ޴� Character Ŭ������ ����� �ּ���.
4. IDamageable�� ��ӹ޴� Door Ŭ������ ����� �ּ���.
5. main() �Լ����� �� Character ��ü�� �����
�ϳ��� �ٸ� �ϳ��� �����ϰ� �� �ּ���.
6. main() �Լ��� Door ��ü�� �߰��ؼ�
Character ��ü�� �� Door ��ü�� �����ϰ� �� �ּ���.

*/

void InterFacePractice1();
#pragma region ��������1
class IUsable
{
public:
    virtual void Use() = 0;
    virtual ~IUsable() = default;
};

class Potion : public IUsable
{
public:
    void Use() override;
};

class Scroll : public IUsable
{
public:
    void Use() override;
};

class Bomb : public IUsable
{
public:
    void Use() override;
};
#pragma endregion

#pragma region ��������2
class IDamageable
{
public:
    virtual void TakeDamage(int amount) = 0;
    virtual string GetName() = 0;
    virtual int GetHp() = 0;
    virtual ~IDamageable() = default;
};

class IAttackable
{
public:
    virtual void Attack(IDamageable& damageable) = 0;
    virtual ~IAttackable() = default;
};

class Character : public IDamageable, public IAttackable
{
public:
    Character(string name, int hp, int damage);
    ~Character();

    string GetName() override;
    int GetHp() override;
    void TakeDamage(int amount) override;
    void Attack(IDamageable& damageable) override;

protected:
    string name_;
    int max_hp_;
    int current_hp_;
    int damage_;
};

class Door : public IDamageable
{
public:
    Door(string name, int hp);
    ~Door();

    string GetName() override;
    int GetHp() override;
    void TakeDamage(int amount) override;

protected:
    string name_;
    int max_hp_;
    int current_hp_;
};

#pragma endregion



