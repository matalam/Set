#include<string>
#include <iostream>
#include "CNode.h"
using namespace std;

class CList
{

private:
	CNode* pc_head;
	CNode* pc_tail;
	int i_size;

public:
	CList();
	CList(const CList& pcOther);
	~CList();

	bool bIsEmpty();
	bool bAddElem(CNode cElem);


};
