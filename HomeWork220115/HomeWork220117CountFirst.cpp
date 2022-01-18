// HomeWork220115.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
int StringCount(const char* _Text) {
    int Count = 0;
    while (0 != _Text[Count])
    {
        Count += 1;
    }

    return Count;
}
bool StringCompare(const char* _Left, const char* _Right)
{
    int  i = 0;
    for (; 0 != _Left[i] && 0 != _Right[i];i += 1)
    {
        if (_Left[i] != _Right[i])
        {
            return false;
        }
    }
    if (0 == _Left[i] && 0 != _Right[i])
    {
        return false;
    }
    return true;
}

int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
    if (_Text == nullptr || _FindStr == nullptr)
    {
        return -1;
    }
    int TextCount = StringCount(_Text);
    int FindCount = StringCount(_FindStr);
    if (_Start < 0 || _Start > TextCount)
    {
        return -1;
    }
    for (int i = _Start; i < TextCount; i += 1)
    {
        if (_Text[i] == _FindStr[0])
        {
            if (true == StringCompare(&_Text[i], &_FindStr[0]))
            {
                return i;
            }
        }
    }

    return -1;
}


int main()
{
    // 실패
    int Count = CountFirst("aaa eee aaa eeee", 7, "eee");
    int a = 0;
  
}
