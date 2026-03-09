#include <iostream>
#include "Inventory.h"

using namespace std;

// 메인 함수. 기능 구현한 거 테스트
int main()
{
	Inventory<Item>* inventory = new Inventory<Item>(0);
	inventory->AddItem(*new Item("sword", 1000));
	inventory->AddItem(*new Item("shield", 500));
	inventory->PrintAllItems();
	inventory->RemoveLastItem();
	inventory->PrintAllItems();
	Inventory<Item>* copyinven = new Inventory<Item>(*inventory);
	copyinven->PrintAllItems();
	copyinven->AddItem(*new Item("bow", 1500));
	copyinven->AddItem(*new Item("arrow", 300));
	inventory->Assign(*copyinven);
	inventory->PrintAllItems();
	inventory->SortItems();
	inventory->PrintAllItems();

	return 0;
}