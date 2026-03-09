#pragma once
#include <iostream>

using namespace std;

class Item
{
public:
	// 생성자
	Item(string name = "Empty", int price = 0)
	{
		name_ = name;
		price_ = price;
	}

	// 아이템 정보 출력
	void PrintInfo() const
	{
		cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
	}

	string GetName() const
	{
		return name_;
	}

	int GetPrice() const
	{
		return price_;
	}

private:
	string name_;
	int price_;
};