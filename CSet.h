#include <iostream>
#include <string>
using namespace std;

template <class Type> class CSet {
public:
	CSet();
	~CSet();
	CSet(const CSet &pcOther);
	
	int iGetAmount();
	void vInsert(Type cElem);
	void vWrite();
	bool bContains(Type cElem);
	void vAddElements(Type cTab[], int iLen);
	void vClear();

	//OPERATORS ELEM
	CSet<Type> operator -(Type &tSetElem);
	CSet<Type> operator +(Type &tSetElem);

	//OPERATORS SETS
	CSet<Type> operator +(CSet<Type> &cOtherSet);
	CSet<Type> operator -(CSet<Type> &cOtherSet);
	CSet<Type> operator *(CSet<Type> &cOtherSet);
	CSet<Type> operator =(Type &pcOther);

private:
	Type *pc_set;
	int i_amount;
};
