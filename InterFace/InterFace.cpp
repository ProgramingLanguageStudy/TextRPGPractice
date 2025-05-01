#include <iostream>
#include <memory>
#include "InterFacePractice.h"

using namespace std;

/*
1. 인터페이스(Interface)란?
- 객체가 가져야 할 기능을 미리 정해 놓는 규약
일종의 객체 사용법. 프로젝트를 함께하는 개발자들 사이의 약속.
어떤 객체가 특정 기능들을 구현하고 있다고 미리 정해 두는 것.

클래스들이 공통적으로 가져야 할 함수의 이름과 형식을 미리 정해 두고
구체적인 구현은 각 클래스에서 정의한다.
즉, 이 객체는 이런 동작을 할 수 있다는 것을 보장하는 역할을 한다.

2. 인터페이스의 필요성
서로 다른 클래스들을 코드로 다루고 싶을 때,
클래스마다 함수 이름이나 사용법이 다르면 불가능하다.
공통 인터페이스를 강제해서 서로 다른 클래스도 같은 방식으로 사용할 수 있게 만든다.

서로 전혀 다른 역할의 클래스들이라 해도
공통된 기능이 있으면 인터페이스를 통해 동일한 변수로 제어할 수 있다.

Attackable
IDamagable
IMovable
IHealable

예를 들어, 무기 시스템
IWeapon 클래스는 구체적인 구현은 전혀 없이 함수의 이름과 형식만 미리 선언.
IWeapon을 상속하는 Sword, Bow, Wand 같은 구체적인 클래스들이
Attack()의 세부 구현을 정의한다.
서로 다 다르게 동작하면서도 공통적으로 Attack()이라는 기능을 갖게 강제한다.
Sword, Bow, Wand는 모두 전혀 다른 클래스지만,
모두 IWeapon 자료형 변수를 통해 동일한 방식으로 Attack() 기능을 사용할 수 있다.


3. 순수 가상 클래스(Pure Virtual Class, Pure Abstract Class - 추상 클래스)
C++에서는 인터페이스 기능을 따로 제공하지 않고
순수 가상 클래스로 인터페이스를 만들어서 사용한다.

- 순수 가상 함수만 가진 클래스
- 객체를 직접 만들 수 없다.

순수 가상 함수
virtual void 함수이름() = 0;
구현이 없는 함수
반드시 자식 클래스에서 override해서 사용해야 한다.
*/

// 인터페이스 클래스명은 맨앞에 'I'를 써 준다.

class IInterface
{
public:
    // 순수 가상 함수
    // =0. 구현이 없고 자식 클래스가 반드시 override해서 구현해야 하는 가상 함수
    virtual void DoSomething() = 0;

    // 가상 소멸자(인터페이스 활용 시 필수)
    // defualt. 기본값. 구현을 직접 정의하지 않고 소멸자 기본 형태로 사용.
    virtual ~IInterface() = default;
};

class IWalkable
{
public:
    virtual void Walk() = 0;
    virtual ~IWalkable() = default;
};

class Human : public IWalkable
{
public:
    void Walk() override
    {
        cout << "사람이 두 발로 걷는다." << endl;
    }
};

class Dog : public IWalkable
{
public:
    void Walk() override
    {
        cout << "강아지가 네 발로 걷는다." << endl;
    }
};

void DoWalking(IWalkable& walkable)
{
    walkable.Walk();
}

// 연습문제.
// IWalkable을 상속받는 Cat 클래스를 만들고
// Human, Dog와 동일하게 사용해 주세요.

class Cat : public IWalkable
{
public:
    void Walk() override
    {
        cout << "고양이가 네 발로 걷는다." << endl;
    }
};

int main()
{
#pragma region Example
//
//    //IWalkable walkable; // 사용 불가. 순수 가상 클래스. 추상 클래스.
//
//    Human human;
//    Dog dog;
//
//    IWalkable* walker0 = &human;
//    IWalkable* walker1 = &dog;
//
//    walker0->Walk();
//    walker1->Walk();
//
//    DoWalking(human);
//    DoWalking(dog);
//
//    Cat cat;
//    IWalkable* walker2 = &cat;
//    walker2->Walk();
//    DoWalking(cat);
//
//    IWalkable* walkers[3] = { walker0, walker1, walker2 };
//    for (int i = 0;i < 3;++i)
//    {
//        walkers[i]->Walk();
//    }
//
#pragma endregion
    InterFacePractice1();
}




