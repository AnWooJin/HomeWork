#include <iostream>
#include "GameVectorSort.h"

int main()
{
	GameVectorSort<int> MyVector;
	//MyVector.reserve(5);

	MyVector.push_back(static_cast<int>(0));
	MyVector.push_back(static_cast<int>(3));
	MyVector.push_back(static_cast<int>(2));
	MyVector.push_back(static_cast<int>(4));
	MyVector.push_back(static_cast<int>(1));
	
	
	for (size_t i = 0; i < MyVector.size(); i++)
	{
		std::cout << MyVector[static_cast<int>(i)] << std::endl;
		
	}
}

