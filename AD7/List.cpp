#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
	count = 20;
	head = nullptr;
}

void List::append(const int& num)
{
	ListNode* newNode;
	ListNode* nodePtr;

	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}

}

bool List::insertNode(const int& num, const int& index)
{
	ListNode* newNode;
	ListNode* nodePtr;
	ListNode* previousPtr;

	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (index > count || index < 0)
		return false;
	
	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;
		previousPtr = nullptr;

		if (index == 0)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				previousPtr = nodePtr;
				nodePtr = nodePtr->next;
			}
			
			previousPtr->next = newNode;
			newNode->next = nodePtr;
		}		
	}

	count++;
	return true;
}

bool List::deleteNode(const int& num)
{

	ListNode* nodePtr;
	ListNode* previousNode = nullptr;

	if (!head)
		return false;
	
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
		else
			return false;
	}
	
	count--;
	return true;
}


void List::display()const
{
	ListNode* nodePtr;
	
	nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
}

void List::clear()
{
	ListNode* nodePtr;
	ListNode* nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		
		delete nodePtr;
		
		nodePtr = nextNode;
	}

	head = nullptr;
	count = 20;
}