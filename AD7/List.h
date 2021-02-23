#ifndef LIST_H
#define LIST_H

class List
{
public:
	List();
	void clear();
	void append(const int&);
	bool insertNode(const int&, const int&);
	bool deleteNode(const int&);
	void display()const;

private:
	int count;
	
	struct ListNode
	{
		int value;
		struct ListNode* next;
	};

	ListNode* head;

};

#endif // !LIST_H