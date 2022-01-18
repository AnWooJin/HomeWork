
#include <iostream>


int StringCount(const char* _Text) {
    int Count = 0;
    while (0 != _Text[Count])
    {
        Count += 1;
    }

    return Count;
}
bool StringCompare(const char* _Left, const char* _Right, int len)
{
    int  i = len;
    int  j = 0;
    for (; 0 != _Left[i] && 0 != _Right[j] && i >= 0;)
    {
        if (_Left[i] != _Right[j])
        {
            return false;
        }
        i -= 1;
        j += 1;
    }
    if (0 == _Left[i] && 0 != _Right[i] || i < 0)
    {
        return false;
    }
    return true;
}


int CountLast(const char* _Text, int _End, const char* _FindStr)
{
    if (_Text == nullptr || _FindStr == nullptr)
    {
        return -1;
    }
    int TextCount = StringCount(_Text);
    int FindCount = StringCount(_FindStr);
    if (_End < 0 || _End > TextCount)
    {
        return -1;
    }
    for (int i = _End; i > 0; i -= 1)
    {
        if (_Text[i] == _FindStr[0])
        {
            if (true == StringCompare(&_Text[0], &_FindStr[0], i))
            {
                return i;
            }
        }
    }
    return -1;
}



int main()
{

    int Count = CountLast("12 e24e e124e", 10, "eee");
    int a = 10;


}

