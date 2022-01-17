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

int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
    int TextCount = StringCount(_Text);
    int FindCount = StringCount(_FindStr);
    int Find_idx = _Start;
    bool check = false;
    if (_Start < 0 || _Start > TextCount)
    {
        return -1;
    }
    while (Find_idx + (FindCount - 1) < TextCount)
    {
        for (; _Text[Find_idx] != _FindStr[0] && Find_idx < TextCount; Find_idx += 1);
        if (_Text[Find_idx] == _FindStr[0])
        {
            for (int i = 0; i < FindCount; i += 1)
            {
                if (_Text[Find_idx + i] == _FindStr[i])
                {
                    check = true;
                }
                else
                {
                    check = false;
                    break;
                }
            }
        }
        if (check == true)
        {
            return Find_idx;
        }
        Find_idx += 1;
    }
    return -1;
}

int CountLast(const char* _Text, int _End, const char* _FindStr)
{
    return -1;
}


int main()
{
    // 실패
    int Count = CountFirst("aaa eee ttt asdfasd eee", 4, "kee");
  
}
