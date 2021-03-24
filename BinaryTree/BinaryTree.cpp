#include <iostream>
using namespace std;
#define tab "\t"




template <typename T2>
class Tree 
{
	class Element  
	{	
		T2 Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(T2 Data, Element* pLeft = nullptr, Element* pRight = nullptr) : Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor: " << this << endl;
		}
		bool is_leaf()
		{
			return pLeft == pRight;
		}
		friend class Tree;
	}*Root;

public:
	void print()
	{
		print(this->Root);
		cout << endl;
	}
	void insert(T2 Data)
	{
		insert(Data, this->Root);
	}
	


	Tree() :Root(nullptr)
	{
		cout << "TConstructor: " << this << endl;
	}
	Tree(const Tree& other)
	{
		copy(other.Root);
		cout << "CopyConstructor: " << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor: " << this << endl;
	}

	void copy(Element* Root)
	{
		if (Root == nullptr)return;
		insert(Root->Data, this->Root);
		copy(Root->pLeft);
		copy(Root->pRight);
	}


	int size()
	{
		return this->Root ? count(this->Root) : 0;
	}
	T2 minValue()
	{
		if (this->Root)
			return minValue(this->Root);
		else
			return 0;
	}
	T2 maxValue()
	{
		return this->Root ? maxValue(this->Root) : 0;
	}
	T2 sum()
	{
		return sum(this->Root);
	}

	double avg()
	{
		return(double)sum(this->Root) / count(this->Root);
	}

	

private:

	void insert(T2 Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)
				Root->pLeft = new Element(Data);
			else
				insert(Data, Root->pLeft);
		}
		else if (Data>Root->Data)
		{
			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}

	}
	
	

	T2 count(Element* Root)
	{
		if (Root == nullptr) return 0;
		return Root->is_leaf() ? 1 : count(Root->pLeft) + count(Root->pRight) + 1;		
	}

	T2 minValue(Element* Root)
	{
		if (Root->pLeft == nullptr) return Root->Data;
		else return minValue(Root->pLeft);
	}

	T2 maxValue(Element* Root)
	{
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}

	T2 sum(Element* Root)
	{
		return Root ? sum(Root->pLeft) + sum(Root->pRight) + Root->Data : 0;
	}
	
	void print(Element* Root)
	{
		if (Root == nullptr)
		{
			return;
		}
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}

};



//#define CHEK_TYPENAME_INT

void main()
{
	setlocale(LC_ALL, "ru");
#ifdef CHEK_TYPENAME_INT
	int n;
	cout << "Введите количество элементов: "; cin >> n;
	Tree<int> T;
	for (size_t i = 0; T.size() < n; i++)
	{
		T.insert(rand() % 100);
	}
	T.print();
	cout << "Минимальное значение в дереве: " << T.minValue() << endl;
	cout << "Максимальное значение в дереве: " << T.maxValue() << endl;
	cout << "Количетво элементов дерева: " << T.size() << endl;
	cout << "Сумма элементов дерева: " << T.sum() << endl;
	cout << "Среднее арифметическое элементов дерева: " << T.avg() << endl;
	Tree<int> T2 = T;
	T2.print();
#endif // CHEK_TYPENAME_INT

	
	Tree<double> T;
	T.insert(5.3);
	T.insert(3.4);
	T.insert(6.2);
	T.insert(7.1);
	T.insert(8.7);
	T.insert(10.2);
	T.print();
}