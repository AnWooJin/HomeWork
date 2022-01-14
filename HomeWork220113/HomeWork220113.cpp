#include <iostream>

void StringTrimRemove(const char* _Left, char* _Right)
{
    // *_Right = *_Left

    // 논리형

    int right_idx = 0;
    int left_idx = 0;
    for (left_idx = 0; 0 != _Left[left_idx]; left_idx += 1)
    {
        if (32 != _Left[left_idx])
        {
            _Right[right_idx] = _Left[left_idx];
            right_idx += 1;
        }
    }

    _Right[right_idx] = 0;

    return;
}

int main()
{
    char Text[10000] = { 0, };

    // "a b"

    // 좀더 처음부터 생각하세요

    // 공백을 없애라?
    // 복사를 하는데 ' '는 복사를 하지말아라.
    StringTrimRemove("safs saf", Text);

    // "aaabbbcccddd"
    printf_s(Text);
}