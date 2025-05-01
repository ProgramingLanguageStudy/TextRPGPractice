
#include <iostream>

using namespace std;

/*
다중 상속
하나의 자식 클래스가 여러 부모 클래스를 상속받는 것.
(C#은 단일 상속만 가능. 여러 클래스를 동시에 상속받을 수 없다.)

다이아몬드 상속
C++에서 둘 이상의 부모 클래스가 같은 조상 클래스를 상속받는 구조에서
자식 클래스가 이 부모들을 상속받을 때 생기는 문제

*/

class Animal
{
public:
    string name;
    Animal()
    {
        cout << "Animal 생성자" << endl;
    }
    void Speak()
    {
        cout << name << "이(가) 소리칩니다." << endl;
    }
};

class Walker : virtual public Animal
{
public:
    Walker()
    {
        cout << "Walker 생성자" << endl;
    }
    void Walk()
    {
        cout << name << "이(가) 걷는다." << endl;
    }
};

class Flyer : virtual public Animal
{
public:
    Flyer()
    {
        cout << "Flyer 생성자" << endl;
    }
    void Fly()
    {
        cout << name << "이(가) 날아오른다." << endl;
    }
};

class Bat : public Walker, public Flyer
{
public:
    Bat()
    {
        cout << "Bat 생성자" << endl;
    }
};

int main()
{
    Bat bat;
    bat.Fly();
    bat.Walk();

    // Walker의 부모인 Animer에 있는 걸 사용해야 하는지
    // Flyer의 부모인 Animer에 있는 걸 사용해야 하는지 모호하다.
    //bat.name = "박귀";        // 모호성 오류
    //bat.Speak();              // 모호성 오류
    bat.Walker::name = "박쥐";
    bat.Walker::Speak();

    bat.Flyer::name = "박쥐박쥐";
    bat.Flyer::Speak();

    // 가상 상속을 했을 경우
    Bat bat2;
    bat2.name = "가상상속 박쥐";
    bat2.Speak();
}