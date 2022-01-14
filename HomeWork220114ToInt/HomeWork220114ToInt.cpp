#include <iostream>
#include<math.h>
int StringCount(const char* _Left)
{
	int Count = 0;
	while (0 != _Left[Count])
	{
		Count += 1;
	}

	return Count;
}
int TenPow(int Value,int count)
{
	int result = Value;
	for (int i = 0; i < count; i += 1)
	{
		result *= 10;
	}
	return result;
}

int ToInt(const char* _Left)
{
	int Sum = 0;
	int Count = StringCount(_Left) - 1;
	for (int i = 0; 0 != _Left[i]; i += 1)
	{
		if (_Left[i] >= 48 && _Left[i] <= 57)
		{
			int Value = (_Left[i] - 48);
			Sum += TenPow(Value, Count - i);
		}
	}
	// '0': 48  '1':49  '2':50 '3':51 '4':52 '5':53 '6': 54 '7':55 '8':56 '9':57
	return Sum;
}


int main()
{
	int a = ToInt("984068465");
}