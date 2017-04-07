#include <iostream>
#include <string>
#include "CSet.h"
using namespace std;

template <class Type>
CSet<Type>::CSet()
{
	i_amount = 0;
}

template <class Type>
CSet<Type>::~CSet()
{
	delete[] pc_set;
}

template <class Type>
CSet<Type>::CSet(const CSet &pcOther)
{
	i_amount = pcOther.i_amount;
	pc_set = new Type[i_amount];
	for (int i = 0; i < i_amount; i++)
		*(pc_set + i) = *(pcOther.pc_set + i);
}

template <class Type>
int CSet<Type>::iGetAmount()
{
	return i_amount;
}

template <class Type>
void CSet<Type>::vInsert(Type cElem)
{
	if (!bContains(cElem))
	{
		*(pc_set + i_amount) = cElem;
		i_amount++;
	}
}

template <class Type>
void CSet<Type>::vWrite()
{
	cout << "[ ";
	for (int i = 0; i < i_amount; i++)
	{
		cout << *(pc_set + i);
		if(i < i_amount - 1)
			cout << ", ";
	}
	cout << " ]" << endl;
}

template <class Type>
bool CSet<Type>::bContains(Type cElem)
{
	bool bFind = false;
	for (int i = 0; i < i_amount && !bFind; i++)
		if (*(pc_set + i) == cElem)
			bFind = true;

	return bFind;
}

template <class Type>
void CSet<Type>::vAddElements(Type cTab[], int iLen)
{
	Type *t_temp;
	t_temp = new Type[i_amount + iLen];

	for (int i = 0; i < i_amount; i++)
		*(t_temp + i) = *(pc_set + i);

	for (int i = 0; i < iLen; i++)
	{
		*(t_temp + i_amount) = cTab[i];
		i_amount++;
	}

	pc_set = t_temp;
}

template <class Type>
void CSet<Type>::vClear()
{
	delete[] pc_set;
	i_amount = 0;
	Type *t_temp;
	t_temp = new Type[i_amount];
	pc_set = t_temp;
}

template <class Type>
CSet<Type> CSet<Type>::operator =(Type &pcOther)
{
	i_amount = pcOther.i_amount;
	pc_set = new Type[i_amount];
	for (int i = 0; i < i_amount; i++)
		pc_set[i] = pcOther.pc_set[i];

	return *this;
}

template <class Type>
CSet<Type> CSet<Type>::operator +(Type &tSetElem)
{
	Type *t_temp;
	t_temp = new Type[i_amount + 1];
	
	for (int i = 0; i < i_amount; i++)
		*(t_temp + i) = *(pc_set + i);

	if (!bContains(tSetElem))
	{
		*(t_temp + i_amount) = tSetElem;
		i_amount++;
	}

	pc_set = t_temp;
	return *this;
}

template <class Type>
CSet<Type> CSet<Type>::operator -(Type &tSetElem)
{
	if (bContains(tSetElem))
	{
		Type *t_temp;
		t_temp = new Type[i_amount - 1];
		int iCounter = 0;

		for (int i = 0; i < i_amount; i++)
			if (*(pc_set + i) != tSetElem)
			{
				*(t_temp + iCounter) = pc_set[i];
				iCounter++;
			}

		pc_set = t_temp;
		i_amount = iCounter;
	}

	return *this;
}

template <class Type>
CSet<Type> CSet<Type>::operator -(CSet<Type> &cOtherSet)
{
	CSet c_result;
	c_result.pc_set = new Type[i_amount];
	int iCounter = 0;

	for (int i = 0; i < i_amount; i++)
		if (!cOtherSet.bContains(*(pc_set + i)))
		{
			*(c_result.pc_set + iCounter) = *(pc_set + i);
			iCounter++;
		}

	c_result.i_amount = iCounter;
	return c_result;
}

template <class Type>
CSet<Type> CSet<Type>::operator +(CSet<Type> &cOtherSet)
{
	CSet c_result;
	c_result.pc_set = new Type[i_amount + cOtherSet.i_amount];
	int iCounter = 0;

	for (int i = 0; i < i_amount; i++)
	{
		*(c_result.pc_set + i) = *(pc_set + i);
		iCounter++;
	}

	for (int i = 0; i < cOtherSet.i_amount; i++)
		if (!bContains(*(cOtherSet.pc_set + i)))
		{
			*(c_result.pc_set + iCounter) = *(cOtherSet.pc_set + i);
			iCounter++;
		}

	c_result.i_amount = iCounter;
	return c_result;
}

template <class Type>
CSet<Type> CSet<Type>::operator *(CSet<Type> &cOtherSet)
{
	CSet c_result;
	c_result.pc_set = new Type[i_amount + cOtherSet.i_amount];
	int iCounter = 0;

	for (int i = 0; i < i_amount; i++)
		if (!cOtherSet.bContains(*(pc_set + i)))
		{
			*(c_result.pc_set + iCounter) = *(pc_set + i);
			iCounter++;
		}

	for (int i = 0; i < cOtherSet.i_amount; i++)
		if (!bContains(*(cOtherSet.pc_set + i)))
		{
			*(c_result.pc_set + iCounter) = *(cOtherSet.pc_set + i);
			iCounter++;
		}

	c_result.i_amount = iCounter;
	return c_result;
}

int main() {
	cout << endl;
	cout << "\t DLA <INT>" << endl;
	cout << endl;

	CSet<int> nowy;
	int s_temp;
	s_temp = 1;
	nowy + s_temp;
	s_temp = 2;
	nowy + s_temp;
	s_temp = 3;
	nowy + s_temp;
	s_temp = 4;
	nowy + s_temp;

	cout << "nowy = ";
	nowy.vWrite();

	CSet<int> nowy2;
	s_temp = 0;
	nowy2 + s_temp;
	s_temp = 4;
	nowy2 + s_temp;
	s_temp = 2;
	nowy2 + s_temp;
	s_temp = 8;
	nowy2 + s_temp;
	s_temp = 0;
	nowy2 - s_temp;

	cout << "nowy2 = ";
	nowy2.vWrite();

	cout << endl;

	cout << "nowy + nowy2 =";
	(nowy + nowy2).vWrite();
	cout << "Elementów w zbiorze: " << (nowy + nowy2).iGetAmount() << endl;
	cout << endl;
	cout << "nowy - nowy2 =";
	(nowy - nowy2).vWrite();
	cout << "Elementów w zbiorze: " << (nowy - nowy2).iGetAmount() << endl;
	cout << endl;
	cout << "nowy * nowy2 =";
	(nowy * nowy2).vWrite();
	cout << "Elementów w zbiorze: " << (nowy * nowy2).iGetAmount() << endl;
	cout << endl;

	int tablica[5];

	tablica[0] = 10;
	tablica[1] = 12;
	tablica[2] = 14;
	tablica[3] = 20;
	tablica[4] = 25;

	CSet<int> nowy3;
	nowy3.vAddElements(tablica, 5);
	cout << "nowy3 = ";
	nowy3.vWrite();

	nowy3.vClear();
	cout << "nowy3 = ";
	nowy3.vWrite();

	////////////////STRING

	cout << endl;
	cout << "\t DLA <STRING>" << endl;
	cout << endl;

	CSet<string> NOWY;
	string s_temp2;
	s_temp2 = "A";
	NOWY + s_temp2;
	s_temp2 = "B";
	NOWY + s_temp2;
	s_temp2 = "C";
	NOWY + s_temp2;
	s_temp2 = "D";
	NOWY + s_temp2;

	cout << "NOWY = ";
	NOWY.vWrite();

	CSet<string> NOWY2;
	s_temp2 = "X";
	NOWY2 + s_temp2;
	s_temp2 = "D";
	NOWY2 + s_temp2;
	s_temp2 = "B";
	NOWY2 + s_temp2;
	s_temp2 = "V";
	NOWY2 + s_temp2;
	s_temp2 = "X";
	NOWY2 + s_temp2;

	cout << "NOWY2 = ";
	NOWY2.vWrite();

	cout << endl;

	cout << "NOWY + NOWY2 =";
	(NOWY + NOWY2).vWrite();
	cout << "Elementów w zbiorze: " << (NOWY + NOWY2).iGetAmount() << endl;
	cout << endl;
	cout << "NOWY - NOWY2 =";
	(NOWY - NOWY2).vWrite();
	cout << "Elementów w zbiorze: " << (NOWY - NOWY2).iGetAmount() << endl;
	cout << endl;
	cout << "NOWY * NOWY2 =";
	(NOWY * NOWY2).vWrite();
	cout << "Elementów w zbiorze: " << (NOWY * NOWY2).iGetAmount() << endl;
	cout << endl;

	string tablica2[5];

	tablica2[0] = "G";
	tablica2[1] = "L";
	tablica2[2] = "F";
	tablica2[3] = "K";
	tablica2[4] = "R";

	CSet<string> NOWY3;
	NOWY3.vAddElements(tablica2, 5);
	cout << "NOWY3 = ";
	NOWY3.vWrite();

	NOWY3.vClear();
	cout << "NOWY3 = ";
	NOWY3.vWrite();

	system("pause");
	return 0;
}