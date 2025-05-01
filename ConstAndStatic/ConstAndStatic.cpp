#include <iostream>
#include "ConstAndStatic.h"

using namespace std;

/*
1. const 키워드
상수화
C++에서는 읽기 전용으로 만드는 키워드
(C#에서 const는 정적 상수, readonly가 읽기 전용(초기화만 가능한 런타임 상수))

1) 변수 앞
해당 변수의 값을 수정할 수 없게 만든다.
-> 런타임 중에 변하지 않아야 하는 값을 실수로 수정하는 일이 없도록 방지
-> 객체 초기화(생성) 시에만 설정되는 멤버 변수(읽기 전용 멤버 변수)(id 값 등)
-> static 키워드와 조합해서 시스템 설정값 등에 사용할 수 있다.

2) 함수의 매개변수 앞
함수 안에서 해당 매개변수를 수정할 수 없게 만든다.

3) 멤버 함수 뒤
해당 멤버 함수가 멤버 변수를 수정하기 않게 약속한다.
=> C++에서는 멤버 함수가 멤버 변수를 수정하지 않는 경우
const 키워드를 적어 주는게 보통이다.

ex. 
- static 키워드와 조합하여 시스템 설정값을 상수로 설정하는 경우(기획 설정값은 아닌)
(체력이 음수가 된다던지, 중력이 과하게 크게 설정된다던지.
게임이 이상 동작을 일으킬 만한 경우 제한)

- Id와 같이 적 객체별로 읽기 전용인 고유값을 부여하는 경우

- 읽기 전용 함수로 객체의 상태를 읽을 때 안정성 확보

2. static 키워드
정적인
메모리상에 단 하나만 존재하도록 하는 키워드
(C# static도 동일)

1) 지역 변수 앞
함수 호출이 끝나도 값 유지

2) 멤버 변수 앞
클래스 자체 메모리에 저장되는 값
-> 해당 변수는 모든 객체가 따로 가지는 변수가 아니라
모든 객체가 공유하는 변수

3) 멤버 함수 앞
클래스 자체에서 호출하는 함수
-> 객체를 따로 만들지 않고 해당 함수를 사용 가능

ex.
- 모든 객체가 공유해야 하는 변수나 함수 사용 가능.

- 객체 없이 사용하는 유틸 함수(수학 함수 같은 것들)
(유니티의 Debug, Mathf 클래스)

*/

// 전역 상수
const int kGlobalValue = 10;

// 상수 매개변수 함수
void PrintNumber(const int num)
{
    //num *= 2;     // X. 상수라서 수정할 수 없다.
    cout << "상수 매개변수: " << num << endl;
}

// static 지역 변수를 사용하는 함수
void Count()
{
    // 함수 최초 실행 시 단 한 번만 초기화
    // 계속 유지
    static int count = 0;
    count++;
    cout << "현재 카운트" << count << endl;
}

class Character
{
public:
    // 정적 함수
    // 객체 없이 호출 가능한 함수
    // (개체의 개별 멤버 변수에 접근 불가)
    static int GetTotalCount()
    {
        return counter_;
    }

    // 생성자 초기화 리스트(Initializer List)
    // 멤버 변수들을 생성자 본문에 들어가기 전에 초기화
    // const 멤버 초기화(const는 읽기 전용 변수라서 초기화 리스트에서만 초기화 가능)
    // 기본값 없이 초기화(성능 이점)
    // 헤더 파일 사용 시에는 구현에서 작성

    Character(string name) : id_(counter_), name_(name)
    {
        max_hp_ = 100;
        current_hp_ = max_hp_;

        cout << "ID: " << id_ << ", " << name_ << " 캐릭터가 생성되었습니다." << endl;

        counter_++;
    }

    string GetName() const
    {
        //name_ += "입니다.";  // X. 읽기 전용 함수
        return name_;
    }

    int GetId() const
    {
        return id_;
    }

    int GetCurrentHp() const
    {
        return current_hp_;
    }

    void TakeDamage(int amount)
    {
        current_hp_ -= amount;
        if (current_hp_ > max_hp_)
        {
            current_hp_ = max_hp_;
        }

        if (current_hp_ < kMinHp)
        {
            current_hp_ = kMinHp;
        }
    }

private:
    // 정적 상수(모든 객체가 공유하는 상수)
    static const int kMinHp = 0;

    // 정적 변수(모든 객체가 공유하는 변수)
    static int counter_ ;

    // 읽기 전용 멤버 변수(객체마다 고유. 생성 시 한 번만 설정)
    const int id_;

    string name_;
    int max_hp_;
    int current_hp_;
};

// static 변수는 클래스 밖에서 초기화
int Character::counter_ = 0;

void ConstStudy()
{
    cout << "----- const 키워드 -----" << endl;
    // 1) 전역 상수
    //kGlobalValue = 20;    // X. 상수라서 수정할 수 없다.

    // 2) 상수 매개변수 함수
    PrintNumber(20);
    
    // 3) 읽기 전용 함수
    Character character("홍길동");
    character.TakeDamage(1000);

    cout << character.GetName() << "의 현재 체력: " << character.GetCurrentHp() << endl;

    // 4) 읽기 전용 포인터
    const Character* readonly_ptr = &character;
    //readonly_ptr->TakeDamage(100);    // X. const 함수가 아닌 함수는 사용 불가.
    cout << readonly_ptr->GetName() << "의 현재 체력: " << readonly_ptr->GetCurrentHp() << endl;

    //readonly_ptr = nullptr;        // O. 포인터가 가리키는 객체를 변경할 수 있다.

    // 5) 고정 포인터(쓸모 X)
    Character* const fixed_ptr = &character;

    //fixed_ptr = nullptr;    // X. 포인터가 가리키는 객체를 변경할 수 없다.

    cout << "----- const 키워드 -----" << endl << endl;
}

void StaticStudy()
{
    cout << "----- static 키워드 -----" << endl;
    // 정적 지역 변수 사용하는 함수
    Count();
    Count();
    Count();

    // 정적 함수(객체 없이 클래스명으로 호출 가능)
    cout << "현재까지 생성된 캐릭터 수: " << Character::GetTotalCount() << endl;
    
    Character c1("김철수");
    Character c2("김영희");
    cout << "현재까지 생성된 캐릭터 수: " << Character::GetTotalCount() << endl;


    cout << "----- static 키워드 -----" << endl << endl;
}

void StaticPractice1()
{
    Monster mon1("슬라임", 50);
    Monster mon2("고블린", 1000);
    Monster mon3("오크", 100);

    cout << "생성된 몬스터 수: " << Monster::GetTotalCount() << endl;

    Monster* monster_ptr[3] = { &mon1, &mon2, &mon3 };

    for (int i = 0;i < 3;++i)
    {
        if (monster_ptr[i]->isNormal())
        {
            monster_ptr[i]->PrintInfo();
        }
    }
}

void StaticPractice2()
{
    unique_ptr<ISkillUser> warrior = make_unique<Warrior>("김전사", 100);
    unique_ptr<ISkillUser> mage = make_unique<Mage>("박법사", 200);

    warrior->UseSkill();
    mage->UseSkill();

    cout << "생성된 영웅 수: " << SkillHero::GetTotalCount() << endl;
}

int main()
{
    //ConstStudy();
    //StaticStudy();
    StaticPractice1();
    StaticPractice2();
}



Monster::Monster(string name, int max_hp) : id_(counter_)
{
    name_ = name;
    max_hp_ = max_hp;
    current_hp_ = max_hp_;

    if (max_hp_ <= kMinHp)
    {
        cout << "체력을 0 이상으로 설정해 주십시오." << endl;
        return;
    }
    else if (max_hp_ > kMaxHp)
    {
        cout << "체력을 999 이하로 설정해 주십시오." << endl;
        return;
    }

    cout << "ID: " << id_ << ", " << name_ << " 캐릭터가 생성되었습니다." << endl;

    counter_++;
}

Monster::~Monster()
{

}

void Monster::PrintInfo()
{
    cout << "===== [" << name_ << "정보] =====" << endl;
    cout << "ID: " << id_ << endl;
    cout << "체력: " << current_hp_ << " / " << max_hp_ << endl;
    cout << "========================" << endl;
}

bool Monster::isNormal()
{
    if (max_hp_ > kMaxHp)
    {
        return false;
    }
    else if (max_hp_ <= kMinHp)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int SkillHero::counter_ = 0;

SkillHero::SkillHero(string name, int max_mp)
{
    name_ = name;
    max_mp_ = max_mp;
    current_mp_ = max_mp_;

    counter_++;
}

SkillHero::~SkillHero()
{

}

void SkillHero::PrintInfo()
{
    cout << "===== [" << name_ << "정보] =====" << endl;
    cout << "마나: " << current_mp_ << " / " << max_mp_ << endl;
    cout << "========================" << endl;
}

Warrior::Warrior(string name, int max_mp)
{
    name_ = name;
    max_mp_ = max_mp;
    current_mp_ = max_mp_;

    counter_++;
}

Warrior::~Warrior()
{

}

void Warrior::UseSkill()
{
    cout << "전사가 스킬1을(를) 사용하였다!" << endl;
    cout << "소모한 마나: " << kWarriorSkill1 << endl;
    
    current_mp_ -= kWarriorSkill1;
}

Mage::Mage(string name, int max_mp)
{
    name_ = name;
    max_mp_ = max_mp;
    current_mp_ = max_mp_;

    counter_++;
}

Mage::~Mage()
{

}

void Mage::UseSkill()
{
    cout << "마법사가 스킬1을(를) 사용하였다!" << endl;
    cout << "소모한 마나: " << kMageSkill1 << endl;

    current_mp_ -= kMageSkill1;
}

