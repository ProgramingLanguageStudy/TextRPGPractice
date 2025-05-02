#pragma once
#include <iostream>

using namespace std;

//연습문제.인벤토리 시스템 만들기
//



//1. IUsable 인터페이스 만들기
//void Use() 함수를 강제하는 IUsable 인터페이스를 만들어 주세요.
//
class IUsable
{
public:
	virtual void Use() = 0;
	virtual ~IUsable() = default;
};

//2. Item 클래스 만들기
//1) IUsable을 상속받는 Item 클래스를 만들어 주세요.
//2) 멤버 변수로 고유 번호(int), 이름, 설명, 가격(int)을 선언해 주세요.
//3) 정적 변수로 아이템 생성 수 카운터(int), 시스템상 최소 가격, 최대 가격을 설정해 주세요.
//4) 이름, 설명, 가격을 매개변수로 하는 생성자를 만들어 주세요.
//고유 번호는 카운터에 따라 자동으로 부여합니다.
//가격은 시스템상 최소 가격, 최대 가격 사이로 보정합니다.
//5) 멤버 함수로
//아이템 정보를 콘솔창에 출력하는 void PrintInfo()
//가격을 외부에 반환하는 int GetPrice()
//이름을 외부에 반환하는 string GetName()
//을 만들어 주세요.
//읽기 전용 함수는 const 키워드를 명시해 주세요.

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

//3. Potion과 Equipment 클래스 만들기
//1) Item 클래스를 상속받는 Potion 클래스를 만들어 주세요.
//Potion은 사용 시 "HP를 회복합니다!" 메시지를 출력합니다.
//
//2) Item 클래스를 상속받는 Equipment 클래스를 만들어 주세요.
//Equipment는 사용 시 "{이름} 장비를 착용했습니다!"를 출력합니다.

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

//4. Inventory 클래스 만들기
//1) 아이템들을 보관하는 Inventory 클래스를 만들어 주세요.
//2) 멤버 변수로 크기가 10인 Item * 포인터 배열과 현재 보관 중인 아이템 수를 가집니다.
//Item * 포인터 배열은(Item * items[10] = {}; 같은 형식으로 선언해 초기화할 수 있습니다.)
//(정적 상수 kMaxSize = 10을 도입해 아이템 배열의 크기를 설정할 수 있습니다.)
//3) 멤버 함수로
//아이템을 추가하는 bool AddItem(Item* item) 함수를 구현해 주세요.
//아이템 보관 성공 시 true, 아이템 보관 실패 시(배열이 꽉 차서) false를 반환합니다.
//4) 보관 중인 모든 아이템 정보를 출력하는 void PrintInventory() 함수를 구현해 주세요.
//5) 배열에서 index번째 아이템을 사용(Use())하는 void UseItem(int index) 함수를 구현해 주세요.

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

//5. Player 클래스 만들기
//1) 멤버 변수로 이름, 골드(int), 인벤토리 객체를 가집니다.
//2) 이름, 골드를 매개변수로 받는 생성자를 만들어 주세요.
//3) 멤버 함수로
//아이템을 구매하는 void BuyItem(Item* item) 함수를 구현해 주세요.
//골드 부족 시, 인벤토리가 꽉 찼을 시 예외 처리가 필요합니다.
//4) 이름, 골드, 인벤토리 정보(PrintInventory())를 출력하는 void PrintStatus()
//함수를 구현해 주세요.
//5) index번째 아이템을 사용(Use())하는 void UseItem(int index) 함수를 구현해 주세요.

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

//6. main() 함수에서 수행
//1) 임의의 Potion, Equipment 객체들을 여러 개 생성해 주세요.
//2) Player 객체를 생성해 주세요.
//3) Player가 Potion, Equipment 객체들을 여러 개 구매하게 해 주세요.
//4) Player가 임의의 인덱스 아이템을 여러 개 사용하게 해 주세요.