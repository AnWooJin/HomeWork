#include <iostream>

int main()
{
	{
		int Arr[10] = { 0, };
		int Index = 0;
		while (Index < 10)
		{
			// 0 부터 시작해서
			Arr[Index] = 2 + (Index * 2);
			Index += 1;
			// 0 제외
			// 2 4 8 10 12 14 16 18 
			// 배열이 가득찰때까지 짝수로만 채워주세요
		}
	}

	{
		int Arr[10] = { 0, };
		int Index = 0;
		while (Index < 10)
		{
			// 0 부터 시작해서
			Arr[Index] = 1 + (Index * 2);
			Index += 1;
			// 0 제외
			// 2 4 8 10 12 14 16 18 
			// 배열이 가득찰때까지 홀수로만 채워주세요
		}

		int a = 0;
	}
}