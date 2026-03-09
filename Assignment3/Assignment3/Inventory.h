#pragma once
#include <iostream>
#include <algorithm>
#include "Item.h"

using namespace std;

// 아이템 가격 비교
inline bool compareItemsByPrice(const Item& a, const Item& b)
{
	return a.GetPrice() < b.GetPrice();
}

template <typename T>
class Inventory
{
public:
	// 생성자
	Inventory(int capacity = 10)
	{
		capacity_ = capacity > 0 ? capacity : 1;
		pItems_ = new T[capacity_]();
		size_ = 0;
	}

	// 소멸자
	~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}

	// 복사 생성자
	Inventory(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_]();
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}
		cout << "인벤토리 복사 완료" << endl;
	}

	// 대입 함수
	void Assign(const Inventory<T>& other)
	{
		if (this == &other) return;

		delete[] pItems_;

		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_]();
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}
		cout << "덮어쓰기 완료" << endl;
	}

	// 아이템 추가
	void AddItem(const T& item)
	{
		if (GetSize() >= GetCapacity())
		{
			Resize(capacity_ * 2);
		}
		
		pItems_[GetSize()] = item;
		++size_;

		cout << "아이템 추가: " << item.GetName() << endl << endl;
 	}

	// 마지막 아이템 제거
	void RemoveLastItem()
	{
		if (GetSize() == 0)
		{
			cout << "인벤토리가 비어있습니다." << endl << endl;
		}
		else
		{
			--size_;
		}
	}

	// 현재 아이템 수 반환
	int GetSize() const
	{
		return size_;
	}

	// 인벤토리 크기 반환
	int GetCapacity() const
	{
		return capacity_;
	}

	// 아이템 전체 출력
	void PrintAllItems() const
	{
		if (GetSize() == 0)
		{
			cout << "인벤토리가 비어있습니다." << endl << endl;
		}
		else
		{
			cout << "-----현재 인벤토리 아이템 목록-----" << endl;
			for (int i = 0; i < size_; ++i)
			{
				pItems_[i].PrintInfo();
			}
			cout << "-----------------------------------" << endl << endl;
		}
	}

	// 인벤토리 확장
	void Resize(int newCapacity)
	{
		newCapacity = newCapacity > 0 ? newCapacity : 1;
		capacity_ = newCapacity;
		size_ = size_ > capacity_ ? capacity_ : size_;
		T* newPItems = new T[newCapacity]();
		for (int i = 0; i < size_; ++i)
		{
			newPItems[i] = pItems_[i];
		}
		delete[] pItems_;
		pItems_ = newPItems;
		
		cout << "인벤토리 최대치가 변경되었습니다. 현재 인벤토리 최대치: " << GetCapacity() << endl;
	}

	// 아이템 정렬
	void SortItems()
	{
		if (size_ == 0) return;

		sort(pItems_, pItems_ + size_, compareItemsByPrice);
		cout << "인벤토리 정렬 완료" << endl;
	}

private:
	T* pItems_;
	int capacity_;
	int size_;
};