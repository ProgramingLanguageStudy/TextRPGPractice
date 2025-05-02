#include <iostream>
#include "InventoryGame.h"

int Item::count_ = 0;
const int Item::kMinPrice = 0;
const int Item::kMaxPrice = 10000;

Item::Item(string name, string script, int price) : id_(count_+1000)
{
    name_ = name;
    script_ = script;
    price_ = price;

    count_++;
    
}

Item::~Item()
{

}

void Item::PrintInfo() const
{
    //cout << "===== 아이템 정보 =====" << endl;
    //cout << "아이템 ID: " << id_ << endl;
    cout << "아이템 이름: " << name_ << endl;
    cout << "아이템 정보: " << script_ << endl;
    cout << "아이템 가격: " << price_ << endl << endl;
    //cout << "===== 아이템 정보 =====" << endl << endl;
}

int Item::GetPrice() const
{
    if (price_ < kMinPrice)
    {
        cout << "가격이 너무 낮습니다. 올바른 가격을 입력해주세요." << endl;
    }
    if (price_ > kMaxPrice)
    {
        cout << "가격이 너무 높습니다. 올바른 가격을 입력해주세요." << endl;
    }

    return price_;
}



string Item::GetName() const
{
    return name_;
}

Potion::Potion(string name, string script, int price) : Item(name, script, price)
{

}
Potion::~Potion()
{

}
void Potion::Use()
{
    cout << name_ << "을(를) 사용했습니다!" << endl << endl;
    cout << script_ << endl;
}

Equipment::Equipment(string name, string script, int price) : Item(name, script, price)
{

}
Equipment::~Equipment()
{

}
void Equipment::Use()
{
    cout << name_ << "을(를) 착용했습니다!" << endl << endl;
}

Inventory::Inventory()
{
    inventory_count_ = 0;
}

Inventory::~Inventory()
{

}

bool Inventory::AddItem(Item* item)
{
    if (inventory_count_ >= kMaxSize) {
        cout << "인벤토리가 가득 찼습니다. 먼저 정리해주세요." << endl << endl;
        return false;
    }

    items[inventory_count_++] = item;
    /*cout << "인벤토리에 " << item->GetName() << "(이)가 추가되었습니다." << endl;
    cout << "현재 인벤토리 칸: " << inventory_count_ << "/" << kMaxSize << endl;*/
    return true;
}

void Inventory::PrintInventory()
{
    cout << "===== 인벤토리 정보 =====" << endl;
    for (int i = 0;i < inventory_count_;++i)
    {
        items[i]->PrintInfo();
    }
    cout << "현재 보관중인 아이템 수: " << inventory_count_ << "/" << kMaxSize << endl << endl;
}

void Inventory::UseItem(int index)
{
    if (index < 0 || index > inventory_count_) {
        cout << "잘못된 인덱스입니다." << endl;
        return;
    }

    items[index]->Use();

    // 사용한 아이템을 제거하고 뒤의 아이템을 앞으로 당기기
    for (int i = index; i < inventory_count_; ++i) {
        items[i] = items[i + 1];
    }
    items[inventory_count_ - 1] = nullptr;
    inventory_count_--;
}

Player::Player(string name, int gold)
{
    name_ = name;
    gold_ = gold;
}

Player::~Player()
{

}

void Player::BuyItem(Item& item)
{
    string itemName = item.GetName();
    int itemPrice = item.GetPrice();
    
    if (gold_ < itemPrice)
    {
        cout << "골드가 " << (itemPrice - gold_) << "원 부족하여 " << itemName << "을(를) 구입할 수 없습니다." << endl <<endl;
        return;
    }

    if (inventory.AddItem(&item) == false)
    {
        cout << "인벤토리가 가득 차서 구매할 수 없습니다." << endl;
        return;
    }
    
    gold_ -= itemPrice;

    cout << itemName << "을(를) 구입하셨습니다." << endl;
    cout << "남은 골드: " << gold_ << endl << endl;
}

void Player::PrintStatus()
{
    cout << "===== 플레이어 정보 =====" << endl;
    cout << "이름: " << name_ << endl;
    cout << "보유중인 골드: " << gold_ << endl << endl;
    inventory.PrintInventory();
    
}

void Player::UseItem(int index)
{
    inventory.UseItem(index);
    inventory.PrintInventory();
}

void InventoryGame()
{
    Potion potion1("체력 물약", "체력을 50 회복합니다.", 1000);
    Potion potion2("마나 물약", "마나를 30 회복합니다.", 500);
    Potion potion3("엉결불 물약", "화염 공격력을 1 증가시킵니다.", 3000);
    Potion potion4("얼음무구 물약", "얼음 공격력을 1 증가시킵니다.", 3000);
    Potion potion5("번갯불 물약", "전기 공격력을 1 증가시킵니다.", 3000);

    Equipment equipment1("검", "물리 공격력 10", 5000);
    Equipment equipment2("지팡이", "마법 공격력 10", 5000);
    Equipment equipment3("화염 부적", "화염 공격력 20", 5000);
    Equipment equipment4("얼음 왕관", "얼음 공격력 20", 5000);
    Equipment equipment5("번개 창", "번개 공격력 20", 5000);

    Player player("모험가", 10000);

    player.BuyItem(potion1);
    player.BuyItem(potion2);
    player.BuyItem(potion3);

    player.BuyItem(equipment1);
    player.BuyItem(equipment2);

    player.PrintStatus();

    player.UseItem(1);
    player.UseItem(2);
}

int main()
{
    InventoryGame();
}