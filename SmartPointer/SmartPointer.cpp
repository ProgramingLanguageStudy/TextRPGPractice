#include <iostream>
#include <memory>

using namespace std;

// 스마트 포인터(Smart Pointer)
// 자동으로 메모리를 관리해 주는 똑똑한 포인터
// new, delete 없이 객체의 소유권과 생명 주기를 자동으로 관리해 준다.

// #include <memory> 필요
// using namespace std;

// 1. 유니크 포인터
// 오직 한 포인터만 객체를 가리킬 수 있다.
// 유니크 포인터 변수가 해제될 때 객체도 같이 소멸한다.
// 유용한 상황: 객체를 사용하는 대부분의 경우

// 2. 공유 포인터
// 여러 공유 포인터가 한 객체를 가리킬 수 있다.
// 참조 카운터가 존재해 참조 카운트가 0이 되면 자동으로 객체가 소멸한다.
// 유용한 상황
// 여러 객체가 특정 리소스를 공유할 때처럼 참조가 여러 곳에서 이뤄지는 구조

class Animal
{
public:
    Animal(string name)
    {
        name_ = name;
    }

    virtual void SpeakOnAppear()
    {
        cout << "[" << name_ << "] 입장!" << endl;
    }
    void SpeakOnDeath()
    {
        cout << "[" << name_ << "] 퇴장!" << endl;
    }

    // 부모 클래스 역할을 하는 클래스의 소멸자는
    // 어지간하면 가상 소멸자 사용
    virtual ~Animal()
    {
        SpeakOnDeath();
    }

    string GetName()
    {
        return name_;
    }

private:
    string name_;
};

class Dog : public Animal
{
public:
    Dog(string name) : Animal(name)
    {
        SpeakOnAppear();
    }

    void SpeakOnAppear() override
    {
        cout << "강아지 ";
        Animal::SpeakOnAppear();
    }

    ~Dog()
    {
        cout << "강아지 ";
    }
};

unique_ptr<Dog> GenerateDog()
{
    return make_unique<Dog>("딸기");
}

void Greet(Animal& animal)
{
    cout << animal.GetName() << "와(과) 인사를 나눕니다." << endl;
}

void Greet(Animal* animal)
{
    cout << animal->GetName() << "와(과) 인사를 나눕니다." << endl;
}

void GreetWithoutPointer(Animal animal)
{
    cout << animal.GetName() << "와(과) 인사를 나눕니다." << endl;
}

void Greet(unique_ptr<Animal> animal)
{
    cout << animal->GetName() << "와(과) 인사를 나눕니다." << endl;
}

void UniquePointerStudy()
{
    cout << "----- 유니크 포인터 선언 -----" << endl;
    //Dog* dog_ptr = new Dog("포인터 방식");
    //delete dog_ptr;

    // unique_ptr<T>: T에 해당 포인터에 사용할 자료형
    // unique_ptr<자료형> 변수명 = make_unique<자료형>(생성자 인자들);
    unique_ptr<Dog> dog1 = make_unique<Dog>("초코");

    //unique_ptr<Dog> dog1_copy = dog1; // X. 유니크 포인터는 오직 하나만 가능
    //Dog* dog_ptr = dog1; // X. 자료형이 다름

    cout << "----- 유니크 포인터 선언 -----" << endl << endl;
    
    cout << "----- 유니크 포인터 함수에서 반환하기 -----" << endl;

    unique_ptr<Animal> dog2 = GenerateDog();

    cout << "----- 유니크 포인터 함수에서 반환하기 -----" << endl << endl;
    
    cout << "----- 유니크 포인터를 함수로 넘기기 -----" << endl;

    Greet(*dog1);       // 참조 전달. 사용 권장.
    Greet(dog1.get());  // 위험한 방식.
    GreetWithoutPointer(*dog1); // 객체 복사됨(매개변수로 넘긴 시점에 값 복사)
    // 매개변수로 넘기면 Animal animal = *dog1;이 발생
    //Greet(dog1);    // unique_ptr<Animal> animal = dog1;      X. 유니크 포인터는 복사 불가
    Greet(make_unique<Animal>("수박"));   // unique_ptr<Animal> animal = make_unique<Animal>("수박");
    cout << "----- 유니크 포인터를 함수로 넘기기 -----" << endl << endl;

    cout << "----- 유니크 포인터를 소유권 이전 -----" << endl;
    //unique_ptr<Animal> dog3 = dog2; X
    unique_ptr<Animal> dog3 = move(dog2);   // dog2는 nullptr가 된다.
    cout << "----- 유니크 포인터를 소유권 이전 -----" << endl << endl;
}

void GreetShared(shared_ptr<Animal> animal)
{
    cout << animal->GetName() << "와(과) 인사를 나눕니다." << endl;
    cout << "animal의 참조 카운트: " << animal.use_count() << endl;
}

class A;
class B;

class A
{
public:
    shared_ptr<B> b_ptr_;
    ~A()
    {
        cout << "A 소멸됨" << endl;
    }
};

class B
{
public:
    // weak_ptr는 참조 카운트를 증가시키지 않는 shared_ptr
    weak_ptr<A> a_ptr_;
    ~B()
        {
        cout << "B 소멸됨" << endl;
        }
};

void SharedPointerStudy()
{
    cout << "----- 공유 포인터 사용 -----" << endl;
    shared_ptr<Animal> dog1 = make_shared<Dog>("바닐라");
    cout << "dog1의 참조 카운트: " << dog1.use_count() << endl;
    
    shared_ptr<Animal> dog2 = dog1; // 복사 가능(참조 카운트 증가)

    cout << "dog1의 참조 카운트: " << dog1.use_count() << endl;
    cout << "dog2의 참조 카운트: " << dog2.use_count() << endl;

    Greet(*dog1);
    GreetShared(dog1);
    cout << "----- 공유 포인터 사용 -----" << endl << endl;
    
    cout << "----- 순환 참조 -----" << endl;
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    cout << "a의 참조 카운트: " << a.use_count() << endl;     // 1(a)
    cout << "b의 참조 카운트: " << b.use_count() << endl;     // 1(b)

    a->b_ptr_ = b;
    b->a_ptr_ = a;

    cout << "a의 참조 카운트: " << a.use_count() << endl;     // 1(a)
    cout << "b의 참조 카운트: " << b.use_count() << endl;     // 2(b, b_ptr_)

    cout << "----- 순환 참조 -----" << endl << endl;


}

int main()
{
    //UniquePointerStudy();
    SharedPointerStudy();
}

