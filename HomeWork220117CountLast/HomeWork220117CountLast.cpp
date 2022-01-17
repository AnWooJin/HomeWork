
#include <iostream>

int StringCount(const char* _Text) {
    int Count = 0;
    while (0 != _Text[Count])
    {
        Count += 1;
    }

    return Count;
}



int CountLast(const char* _Text, int _End, const char* _FindStr)
{
    int TextCount = StringCount(_Text);
    int FindCount = StringCount(_FindStr);
    int Find_idx = _End;
    bool check = false;
    if (_End > TextCount || _End < 0)
    {
        return -1;
    }
    while (Find_idx - (FindCount - 1) > 0)
    {
        for (; _Text[Find_idx] != _FindStr[0] && Find_idx > 0; Find_idx -= 1);
        if (_Text[Find_idx] == _FindStr[0])
        {
            for (int i = 0; i < FindCount; i += 1)
            {
                if (_Text[Find_idx - i] == _FindStr[i])
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
        Find_idx -= 1;
    }
    return -1;
}



int main()
{

    int Count = CountLast("aaa eae asdfasd eee", 15, "eee");
    int a = 10;


}

