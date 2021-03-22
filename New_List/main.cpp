#include <iostream>
using namespace std;

template<class T>

class Element 
{
	
protected:
	template<class T2>
	<T2> Data;
	Element* pNext;
	Element* pPrev;
public:
	Element(T Data, Element* pNext = nullptr): Data(Data), pNext(pNext)
	{
		cout << "EConst: " << this << endl;
	}
	~Element()
	{
		cout << "EDest:" << this << endl;
	}
};

class List : public Element <class T>
{
	Element* Tail;
	Element* Head;

public:
	List()
	{
		Tail = nullptr;
		Head = nullptr;
		cout << "Lconst: " << this << endl;
	}
};