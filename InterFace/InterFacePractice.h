#pragma once

using namespace std;

/*

클래스 작업 시.
헤더 파일 만들어도 되고, 이 스크립트 파일에서 클래스 정의해서 사용해도 OK

연습문제1. 다양한 종류의 아이템을 인터페이스로 사용하기
이 게임에는 세 종류의 아이템이 존재합니다.

포션 - 사용하면 체력을 회복
스크롤 - 사용하면 마법 발동
폭탄 - 사용하면 폭발해서 주변에 데미지
(-> 관련 메시지 출력)

이 서로 다른 종류의 아이템을 하나의 포인터 배열에 저장하고
for문으로 각 요소들을 사용하도록 만들어 주세요.

1. Use() 함수를 강제하는 IUsable이라는 이름의 인터페이스를 만들어 주세요.
2. IUsable을 상속받은 포션, 스크롤, 폭탄 클래스를 각각 정의해 주세요.
3. main() 함수에서 각 아이템의 객체를 만들고 IUsable* 포인터 배열에 저장하세요.
4. for문을 통해 IUsable* 포인터 배열의 각 아이템들의 Use() 함수를 실행해 주세요.

연습문제2. 공격 가능한 객체와 피해를 받는 객체 설계하기
이 게임은 두 종류의 객체가 존재합니다.
캐릭터 - 공격할 수 있고 공격을 받을 수도 있습니다.
문 - 공격할 수 없지만, 공격을 받아 부서질 수 있습니다.

main() 함수에서 어떤 캐릭터 객체가 다른 캐릭터 객체를 공격하는 코드를 실행하고,
어떤 캐릭터 객체가 다른 문 객체를 공격하는 코드를 실행해 주세요.

0. 공격 시 누가 누구를 공격하는지 메세지.
피격 시 남은 체력 등을 포함하는 메세지가 출력되어야 합니다.
1. TakeDamage(int amount) 함수를 갖는 IDamageable 인터페이스를 만들어 주세요.
2. Attack(IDamageable& damageable) 함수를 갖는 IAttackable 인터페이스를 만들어 주세요.
3. IAttackable, IDamageable을 상속받는 Character 클래스를 만들어 주세요.
4. IDamageable을 상속받는 Door 클래스를 만들어 주세요.
5. main() 함수에서 두 Character 객체를 만들어
하나가 다른 하나를 공격하게 해 주세요.
6. main() 함수에 Door 객체를 추가해서
Character 객체가 그 Door 객체를 공격하게 해 주세요.

*/

void InterFacePractice1();
#pragma region 연습문제1
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

#pragma region 연습문제2
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



