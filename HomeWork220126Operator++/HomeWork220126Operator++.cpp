// HomeWork220126Operator++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

class MyInt
{
private:
    int Value;

public:
    MyInt& operator += (int _value)
    {
        this->Value += 1;
        return *this;
    }
    MyInt& operator ++ ()
    {
        this->Value += 1;
        return *this;
    }
    MyInt operator ++(int)
    {
        MyInt temp = this->Value;
        *this += 1;
        return temp;
    }
    MyInt operator= (const MyInt& _Other)
    {
        this->Value = _Other.Value;
        return *this;
    }

public:
    MyInt()
        : Value()
    {
    }
    MyInt(int _Value)
        : Value(_Value)
    {
    }
};

#include <iostream>

int main()
{
    MyInt int0 = MyInt(0);
    MyInt int1 = MyInt(0);
    int0 = MyInt(++int1);
    int0 = MyInt(int1++);
    int a = 0;
}
