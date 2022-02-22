#pragma once
#include <assert.h>

template<typename DataType>
class GameArray
{
private:
	size_t Size_;
	DataType* ArrData_;

public:
	size_t GetCapacity()
	{
		return Size_;
	}

	DataType& GetData(size_t _Index) const
	{
		return ArrData_[_Index];
	}

	DataType& operator[](size_t _Index)
	{
		if (Size_ <= _Index)
		{
			assert(false);
		}

		return ArrData_[_Index];
	}

	inline void operator=(const GameArray& _Other)
	{
		ReSize(_Other, Size_);

		// 이걸 쉘로우 카피
		// 혹은 얕은 복사라고 한다.
		// this->ArrData_ = _Other.ArrData_;
		// this->Size_ = _Other.Size_;

		// 이걸 딥 카피
		// 혹은 깊은 복사라고 한다.
		for (size_t i = 0; i < this->Size_; i++)
		{
			this->ArrData_[i] = _Other.ArrData_[i];
		}
	
		return;
	}

	inline void AllValueSetting(const DataType& Data)
	{
		for (size_t i = 0; i < this->Size_; i++)
		{
			this->ArrData_[i] = Data;
		}
	}

	inline void Release()
	{
		if (nullptr != ArrData_)
		{
			delete[] ArrData_;
			ArrData_ = nullptr;
		}
	}

	void ReSize(size_t _Size)
	{
		// Release();
		DataType* PrevData = ArrData_;
		ArrData_ = new DataType[_Size];

		size_t Size = Size_ > _Size ? _Size : Size_;

		for (size_t i = 0; i < Size; i++)
		{
			ArrData_[i] = PrevData[i];
		}

		if (nullptr != PrevData)
		{
			delete PrevData;
			PrevData = nullptr;
		}

		Size_ = _Size;
	}

public:
	GameArray()
		: ArrData_(nullptr)
		, Size_(0)
	{
	}
	GameArray(size_t _Size)
		: ArrData_(nullptr)
		, Size_(0)
	{
		ReSize(_Size);
	}
	~GameArray() 
	{
		Release();
	}
};

template<typename DataType>
class GameVectorSort
{
private:
	GameArray<DataType> ArrData_;
	size_t Size_;

public:
	size_t capacity()
	{
		return ArrData_.GetCapacity();
	}

	size_t size()
	{
		return Size_;
	}

	void resize(size_t _SizeData)
	{
		ArrData_.ReSize(_SizeData);
		Size_ = _SizeData;
	}

	void reserve(size_t _SizeData)
	{
		ArrData_.ReSize(_SizeData);
		ArrData_.AllValueSetting(0);
	}

	void pop_Back()
	{
		--Size_;
	}

	void push_back(const DataType& _Data)
	{
		if (Size_ >= ArrData_.GetCapacity())
		{
			ArrData_.ReSize((size_t)((Size_ + 1) * 1.5f));
		}
		ArrData_[Size_] = _Data;
		++Size_;
		BubbleSort();
	}
	void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void BubbleSort()
	{
		size_t Size = Size_;
		for (size_t i = 0; i < Size - 1; i++)
		{
			for (size_t j = 0; j < (Size - i) - 1; j++)
			{
				if (ArrData_[j] > ArrData_[j + 1])
				{
					swap(ArrData_[j], ArrData_[j + 1]);
					/*int temp = ArrData_[j + 1];
					ArrData_[j + 1] = ArrData_[j];
					ArrData_[j] = temp;*/
				}
			}
		}
	}



	DataType& operator[](const size_t _Index)
	{
		if (Size_ <= _Index)
		{
			assert(false);
		}
		
		return ArrData_[_Index];
	}

public:
	GameVectorSort()
		:Size_(0)
	{
	}

	GameVectorSort(const GameVectorSort& _Other)
		: Size_(_Other.Size_)
	{
		resize(_Other.Size_);

		ArrData_[0] = _Other.ArrData_.GetData(0);
	}
};