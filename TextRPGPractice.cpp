#include <iostream>
#include "TextRPG.h"

using namespace std;

// 클래스(class)
// 클래스는 객체를 만들기 위한 설계도
// 객체(object, 개체)를 생성하는 틀

// 객체(object)
// 클래스를 바탕으로 만들어낸 실제 데이터(인스턴스)
// 실제로 메모리에 저장된 존재

// 똑같은 클래스에서 만들어진 객체라고 해도
// 갖고 있는 데이터들의 종류만 같을 뿐 실제 값들은 다 다를 수 있다.

// 객체의 중요성
// 게임 속 모든 개별 요소가 "객체"로 표현될 수 있다.
// 플레이어, 몬스터, 무기, 아이템, NPC, 퀘스트, 스킬, 맵 등등
// 각자는 자신이 수행해야 하는 기능(역할)이 있다.

// 게임 속 모든 개별 요소를 구조화하여 효율적으로 관리
// 플레이어.공격(몬스터);    player.attack(monster);
// 플레이어.이동(방향);      player.move(+1);   palyer.move(-1);

// 부품화/모듈화가 가능
// 프로그램을 어떤 부품들로 나누고 그것들이 한데 모여 프로그램을 동작

// -> 이렇게 객체를 중심으로 프로그램을 구성하는 방식 객체 지향

//class Battler
//{
//    // 접근 한정자
//    // public: 클래스 외부에서 해당 멤버에 접근 가능
//    // private: 클래스 외부에서 해당 멤버에 접근 불가능
//
//    // 구조체는 접근 한정자를 적지 않으면 기본이 public
//    // 클래스는 접근 한정자를 적지 않으면 기본이 private
//
//    // 멤버 변수들은 정말 특수한 경우가 아니면 private으로 사용(캡슐화)
//    // 어떤 객체의 멤버 변수들이 외부의 제어에 의지해서 작동하게 만들면 안 된다.
//
//private:
//    // ----- 멤버 변수 ----- //
//    string name_ = "주인공";         // 캐릭터 이름
//    int max_hp_ = 100;               // 최대 체력
//    int current_hp_ = 100;           // 현재 체력
//    int damage_ = 10;                // 공격력
//    // ----- 멤버 변수 ----- //
//
//public:
//    // 생성자(Constructor)
//    // 객체가 생성될 때 자동으로 호출되는 함수
//
//    // 1. 기본 생성자
//    //Battler()
//    //{
//    //    // 멤버 변수들이 기본값 설정해 둔 대로 설정됨.
//    //}
//
//    // 2. 사용자 정의 생성자
//    // 사용자 정의 생성자가 하나라도 있으면
//    // 반드시 생성자를 사용해서 객체를 만들어야 한다.
//    Battler(string name, int hp, int damage)
//    {
//        name_ = name;
//        max_hp_ = hp;
//        current_hp_ = max_hp_;
//        damage_ = damage;
//    }
//
//    // 소멸자(Destructor)
//    // 객체가 파괴될 때(메모리에서 해제될 때) 자동으로 호출되는 함수
//    ~Battler() {
//        cout << name_ << " Battler 객체가 소멸되었습니다." << endl;
//    }
//
//    // Getter 함수
//    // 외부에서 데이터를 읽어들일 수 있도록 값을 반환해 주는 함수
//    string GetName()
//    {
//        return name_;
//    }
//
//    // Setter 함수
//    // 외부에서 데이터를 수정할 수 있도록 해 주는 함수
//    void SetName(string name)
//    {
//        name_ = name;
//    }
//
//
//    /// <summary>
//    /// 배틀러의 정보를 출력해 주는 함수
//    /// </summary>
//    void PrintInfo()
//    {
//        cout << "===== [" << name_ << "정보] =====" << endl;
//        cout << "체력: " << current_hp_ << " / " << max_hp_ << endl;
//        cout << "공격력: " << damage_ << endl;
//        cout << "========================" << endl;
//    }
//
//    /// <summary>
//    /// 대미지를 입는 함수
//    /// </summary>
//    /// <param name="amount">입을 대미지 양</param>
//    void TakeDamage(int amount)
//    {
//        current_hp_ -= amount;
//        if (current_hp_ < 0)
//        {
//            current_hp_ = 0;
//        }
//
//        cout << name_ << "이(가) " << amount << "의 피해를 입었습니다." << endl;
//        
//    }
//
//    // C언어 스타일 함수
//    /*void Attack(Battler* target)
//    {
//        target->TakeDamage(damage_);
//
//        cout << name_ << "이(가)" << target->name_ << "을(를) 공격합니다!" << endl;
//
//        C++ 스타일 함수*/
//    void Attack(Battler& target)
//    {
//        if (current_hp_ <= 0)
//        {
//            return;
//        }
//        cout << GetName() << "이(가) " << target.GetName() << "을(를) 공격합니다!" << endl;
//        target.TakeDamage(damage_);
//        cout << target.GetName() << "의 남은 체력은 " << target.current_hp_ << "입니다." << endl;
//    }
//
//    void Heal()
//    {
//        int heal_amount = max_hp_ * 0.2;
//        if (current_hp_ + heal_amount > max_hp_)
//        {
//            heal_amount = max_hp_ - current_hp_;
//        }
//        current_hp_ += heal_amount;
//        cout << GetName() << "이(가) " << heal_amount<< "만큼 체력을 회복합니다." << endl;
//        cout << GetName() << "의 남은 체력은 " << current_hp_ << "입니다." << endl;        
//    }
//
//    bool IsAlive()
//    {
//        return current_hp_ > 0;
//    }
//};

// 구버전
//void Test()
//{
//    cout << "게임 시작!" << endl;
//
//    Battler hero("주인공", 100, 10);
//    hero.PrintInfo();
//
//    Battler enemy("슬라임", 30, 5);
//    enemy.PrintInfo();
//
//    hero.Attack(enemy);
//    enemy.PrintInfo();
//
//    string hero_name;
//    cout << "주인공의 이름을 입력하세요: ";
//    cin >> hero_name;
//
//    hero.SetName(hero_name);
//    hero.PrintInfo();
//}
//
//// 연습문제
////void TestProblem()
////{
////    // 1. 사용자에게서 주인공의 이름을 입력받아
////    // 주인공 캐릭터로 사용할 Battler 객체의 이름(name_)으로 설정해 주세요.
////    // 그리고 그 Battler 객체의 정보를 출력해 주세요.
////    
////    // 2. 임의의 스탯을 가진 적 캐릭터 Battler 객체를 만들고 정보를 출력해 주세요.
////    
////
////    // 3~5번은 점차 확장되는 단계
////    // 5번만 완성이 되어도 3, 4번은 풀린 문제
////    // 3. 주인공 캐릭터 객체와 적 캐릭터 객체가
////    // 순서대로 한 번씩 서로 공격하게 해 주세요.
////
////    // 4. 사용자에게서 주인공의 행동 옵션 두 가지를 정수로 입력받아
////    // 해당 옵션에 따라 다음이 진행되게 해 주세요.
////    // 1) 공격 - 주인공 Battler가 적 battler를 공격하고,
////    // 적 Battler가 주인공 battler 공격
////    // 2) 상태 확인 - 주인공 Battler와 적 Battler의 정보를 출력
////    
////    // 5. 4번의 루트가 주인공이나, 적 Battler 중 하나가 죽을 때까지
////    // 반복되게 해서 게임이 진행되게 해 주세요.
////    Battler User;
////    string hero_name;
////    cout << "주인공의 이름을 입력하세요: ";
////    cin >> hero_name;
////
////    User.SetName(hero_name);
////    User.PrintInfo();
////
////    Battler Enemy("슬라임", 30, 10);
////
////    cout << "야생의 " << Enemy.name_ << "이(가) 나타났다!!!" << endl << endl;
////
////    while (Enemy.current_hp_>0&&User.current_hp_>0)
////    {
////        int UserChoice = 0;
////        while (UserChoice != 1 && UserChoice != 2)
////        {
////            cout << "무엇을 할까요? (1. 공격한다, 2. 캐릭터 상태창 열기)" << endl;
////            cin >> UserChoice;
////            if (cin.fail()) {
////                cin.clear(); // 실패 상태 플래그 초기화
////                cin.ignore(1000, '\n'); // 잘못된 입력 무시 (버퍼 비움)
////                cout << "숫자만 입력해주세요!" << endl << endl;
////                continue; // 다시 선택
////            }
////            else if (UserChoice == 1)
////            {
////                User.Attack(Enemy);
////                if (Enemy.current_hp_ <= 0)
////                {
////                    cout << "축하합니다. " << Enemy.name_ << "을(를) 물리쳤습니다!!!" << endl << endl;
////                }
////                
////                Enemy.Attack(User);
////                if (User.current_hp_ <= 0)
////                {
////                    cout << User.name_ << "이(가) 쓰려졌습니다..." << endl << endl;
////                }
////
////            }
////            else if (UserChoice == 2)
////            {
////                User.PrintInfo();
////                Enemy.PrintInfo();
////
////                cout << endl;
////            }
////            else
////            {
////                cout << "잘못된 선택입니다. 다시 선택해주세요." << endl << endl;
////            }
////        }
////    }
////}
//
///// <summary>
///// 랜덤한 적 Battler 객체를 반환해 주는 함수
///// </summary>
//Battler GenerateRandomEnemy()
//{
//    // random_index를 0~2 사이 값으로 설정
//    int random_index = rand() % 3;
//    
//    switch (random_index)
//    {
//    case 0:
//        return Battler("슬라임", 50, 5);
//    case 1:
//        return Battler("고블린", 100, 7);
//    case 2:
//        return Battler("오크", 150, 10);
//    default:
//        return Battler("슬라임", 50, 5);
//    }
//}
//
//Battler GenerateHero()
//{
//    cout << "===== 텍스트 RPG에 오신 것을 환영합니다! =====" << endl;
//
//    string hero_name;
//    cout << "당신의 이름을 입력해주세요: ";
//    cin >> hero_name;
//
//    Battler hero = Battler(hero_name, 200, 30);
//    hero.PrintInfo();
//    return hero;
//}
//
//void FightEnemy(Battler& hero, Battler& enemy)
//{
//    cout << "!!! 적이 나타났습니다: " << enemy.GetName() << " !!!" << endl;
//    hero.PrintInfo();
//    enemy.PrintInfo();
//
//    // 주인공 Battler와 적 Battler가 모두 살아 있는 동안 반복되는 루프
//    while (hero.IsAlive() && enemy.IsAlive())
//    {
//        cout << "\n무엇을 하시겠습니까?" << endl;
//        cout << "1. 공격 2. 상태 확인 3. 회복" << endl;
//        cout << "> ";
//
//        int choice;
//        cin >> choice;
//
//        // cin.fail()은 입력이 실패했는지 여부를 반환해 주는 함수
//        if (cin.fail())
//        {
//            cin.clear();    // cin의 입력 실패 에러 로그 지우는 함수
//            cin.ignore(1000, '\n'); // 입력을 1000 글자 동안 '\n'를 만날 때까지 무시해라
//            cout << "숫자를 입력해 주세요." << endl;
//            continue;       // 이번 루프를 즉시 종료하는 키워드
//        }
//
//        switch (choice)
//        {
//        case 1:
//            hero.Attack(enemy);
//            if (enemy.IsAlive())
//            {
//                cout << endl;
//                enemy.Attack(hero);
//            }
//            break;
//        case 2:
//            hero.PrintInfo();
//            enemy.PrintInfo();
//            break;
//        case 3:
//            hero.Heal();
//            hero.PrintInfo();
//            cout << endl;
//            enemy.Attack(hero);
//            break;
//        default:
//            cout << "잘못된 입력입니다. 다시 선택하세요." << endl;
//            continue;
//            break;
//        } 
//    }  
//}
//
//void BattleLoop(Battler& hero)
//{
//    int defeated_enemy_count = 0;       // 게임 진행 동안 총 해치운 적 수
//
//    // 주인공 Battler가 살아 있는 동안 반복되는 루프
//    while (hero.IsAlive())
//    {
//        Battler enemy = GenerateRandomEnemy();
//
//        FightEnemy(hero, enemy);
//
//        if (hero.IsAlive())
//        {
//            defeated_enemy_count++;
//
//            cout << "\n" << enemy.GetName() << "을(를) 처치했습니다!" << endl;
//        }
//        else
//        {
//            cout << "\n총 " << defeated_enemy_count << "마리의 몬스터를 물리쳤습니다." << endl;
//        }
//    }
//}

int main()
{
    // time(0)
    // 현재 시각을 기준으로 하는 정수값
    // 1970년 1월 1일부터 현재까지 흐른 초 수

    // 랜덤 시드 설정
    srand(time(0));     // 한 번만 호출
    
    TextRPG game;
    game.Start();
}