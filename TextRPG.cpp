#include "TextRPG.h"

using namespace std;

void TextRPG::Start()
{
	CreateHero();
	RunBattleLoop();
}

void TextRPG::CreateHero()
{
	cout << "===== �ؽ�Ʈ RPG�� ���� ���� ȯ���մϴ�! =====" << endl;

	string hero_name;
	cout << "����� �̸��� �Է��ϼ���: ";
	cin >> hero_name;

	hero_ = make_unique<Hero>(hero_name);
	hero_->PrintInfo();
}

unique_ptr<Enemy> TextRPG::GenerateRandomEnemy()
{
    // random_index�� 0~2 ���� ������ ����
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
            cout << "\n" << enemy->GetName() << "��(��) óġ�߽��ϴ�!" << endl;
        }
        else
        {
            cout << "\n�� " << defeated_enemy_count << "������ ���� �����ƽ��ϴ�." << endl;
        }
        //delete enemy; // ����ũ �����ʹ� delete �ʿ� X
    }
}

void TextRPG::FightEnemy(Enemy &enemy)
{
    cout << "!!! ���� ��Ÿ�����ϴ�: " << enemy.GetName() << " !!!" << endl;
    hero_->PrintInfo();
    enemy.PrintInfo();
    enemy.SpeakOnAppear();
    //cout << "���� ����ġ: " << enemy.GetExpReward() << endl;

    // ���ΰ� Battler�� �� Battler�� ��� ��� �ִ� ���� �ݺ��Ǵ� ����
    while (hero_->IsAlive() && enemy.IsAlive())
    {
        cout << "\n������ �Ͻðڽ��ϱ�?" << endl;
        cout << "1. ���� 2. ���� Ȯ�� 3. ȸ��(���� Ƚ��: " << hero_->GetHealCount() << ")" << endl;
        cout << "> ";

        int choice;
        cin >> choice;

        // cin.fail()�� �Է��� �����ߴ��� ���θ� ��ȯ�� �ִ� �Լ�
        if (cin.fail())
        {
            cin.clear();    // cin�� �Է� ���� ���� �α� ����� �Լ�
            cin.ignore(1000, '\n'); // �Է��� 1000 ���� ���� '\n'�� ���� ������ �����ض�
            cout << "���ڸ� �Է��� �ּ���." << endl;
            continue;       // �̹� ������ ��� �����ϴ� Ű����
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
                cout << "ȸ���� Ƚ���� ���� ���� �ʽ��ϴ�. �ٸ� �ൿ�� �����ϼ���." << endl;
                continue; 
            }
            break;
        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �����ϼ���." << endl;
            continue;
            break;
        }
    }
}
