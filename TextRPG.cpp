#include "TextRPG.h"

using namespace std;

void TextRPG::Start()
{
	CreateHero();
	RunBattleLoop();
}

void TextRPG::CreateHero()
{
	cout << "===== 텍스트 RPG에 오신 것을 환영합니다! =====" << endl;

	string hero_name;
	cout << "당신의 이름을 입력하세요: ";
	cin >> hero_name;

	hero_ = make_unique<Hero>(hero_name);
	hero_->PrintInfo();
}

unique_ptr<Enemy> TextRPG::GenerateRandomEnemy()
{
    // random_index를 0~2 사이 값으로 설정
    int random_index = rand() % 3;

    switch (random_index)
    {
    case 0:
        return make_unique<Slime>();
    case 1:
        return make_unique<Goblin>();
    case 2:
        return make_unique<Orc>();
    default:
        return make_unique<Slime>();
    }
}

void TextRPG::RunBattleLoop()
{
    int defeated_enemy_count = 0;

    while (hero_->IsAlive())
    {
        unique_ptr<Enemy> enemy = GenerateRandomEnemy();

        FightEnemy(*enemy);

        if (hero_->IsAlive())
        {
            defeated_enemy_count++;
            hero_->AddExp(enemy->GetExpReward());
            cout << "\n" << enemy->GetName() << "을(를) 처치했습니다!" << endl;
        }
        else
        {
            cout << "\n총 " << defeated_enemy_count << "마리의 적을 물리쳤습니다." << endl;
        }
        //delete enemy; // 유니크 포인터는 delete 필요 X
    }
}

void TextRPG::FightEnemy(Enemy &enemy)
{
    cout << "!!! 적이 나타났습니다: " << enemy.GetName() << " !!!" << endl;
    hero_->PrintInfo();
    enemy.PrintInfo();
    enemy.SpeakOnAppear();
    //cout << "보상 경험치: " << enemy.GetExpReward() << endl;

    // 주인공 Battler와 적 Battler가 모두 살아 있는 동안 반복되는 루프
    while (hero_->IsAlive() && enemy.IsAlive())
    {
        cout << "\n무엇을 하시겠습니까?" << endl;
        cout << "1. 공격 2. 상태 확인 3. 회복(남은 횟수: " << hero_->GetHealCount() << ")" << endl;
        cout << "> ";

        int choice;
        cin >> choice;

        // cin.fail()은 입력이 실패했는지 여부를 반환해 주는 함수
        if (cin.fail())
        {
            cin.clear();    // cin의 입력 실패 에러 로그 지우는 함수
            cin.ignore(1000, '\n'); // 입력을 1000 글자 동안 '\n'를 만날 때까지 무시해라
            cout << "숫자를 입력해 주세요." << endl;
            continue;       // 이번 루프를 즉시 종료하는 키워드
        }

        switch (choice)
        {
        case 1:
            hero_->Attack(enemy);
            if (enemy.IsAlive())
            {
                cout << endl;
                enemy.Attack(*hero_);
            }
            break;
        case 2:
            hero_->PrintInfo();
            enemy.PrintInfo();
            break;
        case 3:
            if (hero_->TryHeal()) {
                hero_->PrintInfo();
                cout << endl;
            }
            else {
                cout << "회복할 횟수가 남아 있지 않습니다. 다른 행동을 선택하세요." << endl;
                continue; 
            }
            break;
        default:
            cout << "잘못된 입력입니다. 다시 선택하세요." << endl;
            continue;
            break;
        }
    }
}
