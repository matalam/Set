#include <string>
#include <iostream>
#include "CNode.h"
using namespace std;

CNode::CNode(void* pv_elem, CNode* pc_prev, CNode* pc_next)
{
	this->pv_elem = pv_elem;
	this->pc_prev = pc_prev;
	this->pc_next = pc_next;
}

CNode::~CNode()
{
	
}

CNode::CNode(const CNode &pcOther)
{
	*pc_prev = *pcOther.pc_prev;
	*pc_next = *pcOther.pc_next;
	pv_elem = pcOther.pv_elem;
}