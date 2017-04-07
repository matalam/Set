#include<string>
#include <iostream>
using namespace std;

class CNode
{
	friend class CList;

private:
	void* pv_elem;
	CNode* pc_next;
	CNode* pc_prev;

public:
	CNode(void* pv_elem, CNode* pc_prev, CNode* pc_next);
	CNode(const CNode &pcOther);
	~CNode();
};
