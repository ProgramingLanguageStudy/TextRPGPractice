#pragma once
#include <iostream>

using namespace std;

//��������.�κ��丮 �ý��� �����
//



//1. IUsable �������̽� �����
//void Use() �Լ��� �����ϴ� IUsable �������̽��� ����� �ּ���.
//
class IUsable
{
public:
	virtual void Use() = 0;
	virtual ~IUsable() = default;
};

//2. Item Ŭ���� �����
//1) IUsable�� ��ӹ޴� Item Ŭ������ ����� �ּ���.
//2) ��� ������ ���� ��ȣ(int), �̸�, ����, ����(int)�� ������ �ּ���.
//3) ���� ������ ������ ���� �� ī����(int), �ý��ۻ� �ּ� ����, �ִ� ������ ������ �ּ���.
//4) �̸�, ����, ������ �Ű������� �ϴ� �����ڸ� ����� �ּ���.
//���� ��ȣ�� ī���Ϳ� ���� �ڵ����� �ο��մϴ�.
//������ �ý��ۻ� �ּ� ����, �ִ� ���� ���̷� �����մϴ�.
//5) ��� �Լ���
//������ ������ �ܼ�â�� ����ϴ� void PrintInfo()
//������ �ܺο� ��ȯ�ϴ� int GetPrice()
//�̸��� �ܺο� ��ȯ�ϴ� string GetName()
//�� ����� �ּ���.
//�б� ���� �Լ��� const Ű���带 ����� �ּ���.

class Item : public IUsable
{
public:
	Item(string name, string script, int price);
	virtual ~Item();
	virtual void Use() = 0;

	void PrintInfo() const;
	int GetPrice() const;
	string GetName() const;

		
protected:
	const int id_;
	
	static int count_;
	static const int kMinPrice;
	static const int kMaxPrice;

	string name_;
	string script_;
	int price_;

};

//3. Potion�� Equipment Ŭ���� �����
//1) Item Ŭ������ ��ӹ޴� Potion Ŭ������ ����� �ּ���.
//Potion�� ��� �� "HP�� ȸ���մϴ�!" �޽����� ����մϴ�.
//
//2) Item Ŭ������ ��ӹ޴� Equipment Ŭ������ ����� �ּ���.
//Equipment�� ��� �� "{�̸�} ��� �����߽��ϴ�!"�� ����մϴ�.

class Potion : public Item
{
public:
	Potion(string name, string script, int price);
	virtual ~Potion();
	void Use() override;
};

class Equipment : public Item
{
public:
	Equipment(string name, string script, int price);
	virtual ~Equipment();
	void Use() override;
};

//4. Inventory Ŭ���� �����
//1) �����۵��� �����ϴ� Inventory Ŭ������ ����� �ּ���.
//2) ��� ������ ũ�Ⱑ 10�� Item * ������ �迭�� ���� ���� ���� ������ ���� �����ϴ�.
//Item * ������ �迭��(Item * items[10] = {}; ���� �������� ������ �ʱ�ȭ�� �� �ֽ��ϴ�.)
//(���� ��� kMaxSize = 10�� ������ ������ �迭�� ũ�⸦ ������ �� �ֽ��ϴ�.)
//3) ��� �Լ���
//�������� �߰��ϴ� bool AddItem(Item* item) �Լ��� ������ �ּ���.
//������ ���� ���� �� true, ������ ���� ���� ��(�迭�� �� ����) false�� ��ȯ�մϴ�.
//4) ���� ���� ��� ������ ������ ����ϴ� void PrintInventory() �Լ��� ������ �ּ���.
//5) �迭���� index��° �������� ���(Use())�ϴ� void UseItem(int index) �Լ��� ������ �ּ���.

class Inventory
{
public:
	Inventory();
	~Inventory();

	bool AddItem(Item* item);
	void PrintInventory();
	void UseItem(int index);

protected:
	int static const kMaxSize = 10;

	Item* items[kMaxSize] = {};
	int inventory_count_;
};

//5. Player Ŭ���� �����
//1) ��� ������ �̸�, ���(int), �κ��丮 ��ü�� �����ϴ�.
//2) �̸�, ��带 �Ű������� �޴� �����ڸ� ����� �ּ���.
//3) ��� �Լ���
//�������� �����ϴ� void BuyItem(Item* item) �Լ��� ������ �ּ���.
//��� ���� ��, �κ��丮�� �� á�� �� ���� ó���� �ʿ��մϴ�.
//4) �̸�, ���, �κ��丮 ����(PrintInventory())�� ����ϴ� void PrintStatus()
//�Լ��� ������ �ּ���.
//5) index��° �������� ���(Use())�ϴ� void UseItem(int index) �Լ��� ������ �ּ���.

class Player
{
public:
	Player(string name, int gold);
	~Player();

	void BuyItem(Item& item);
	void PrintStatus();
	void UseItem(int index);

protected:
	string name_;
	int gold_;
	Inventory inventory;
};

//6. main() �Լ����� ����
//1) ������ Potion, Equipment ��ü���� ���� �� ������ �ּ���.
//2) Player ��ü�� ������ �ּ���.
//3) Player�� Potion, Equipment ��ü���� ���� �� �����ϰ� �� �ּ���.
//4) Player�� ������ �ε��� �������� ���� �� ����ϰ� �� �ּ���.