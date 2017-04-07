#include <string>
#include <iostream>
#include "CList.h"
using namespace std;

CList::CList()
{
	pc_head = NULL;
	pc_tail = NULL;
	i_size = 0;
}

CList::CList(const CList &pcOther)
{
	*pc_head = *pcOther.pc_head;
	*pc_tail = *pcOther.pc_tail;
	i_size = pcOther.i_size;
}

bool CList::bIsEmpty()
{
	return pc_head == NULL;
}

bool bAddElem(CNode cElem)
{

}

int main()
{

	system("pause");
	return 0;
}