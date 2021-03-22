#include <iostream>
using namespace std;
#define tab "\t"
class Tree
{
	class Element  
	{	
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) : Data(Data), pLeft(pLeft), pRight(pRight)
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
	void insert(int Data)
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
	int minValue()
	{
		if (this->Root)
			return minValue(this->Root);
		else
			return 0;
	}
	int maxValue()
	{
		return this->Root ? maxValue(this->Root) : 0;
	}
	int sum()
	{
		return sum(this->Root);
	}

	double avg()
	{
		return(double)sum(this->Root) / count(this->Root);
	}


private:

	void insert(int Data, Element* Root)
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

	int count(Element* Root)
	{
		if (Root == nullptr) return 0;
		return Root->is_leaf() ? 1 : count(Root->pLeft) + count(Root->pRight) + 1;		
	}

	int minValue(Element* Root)
	{
		if (Root->pLeft == nullptr) return Root->Data;
		else return minValue(Root->pLeft);
	}

	int maxValue(Element* Root)
	{
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}

	int sum(Element* Root)
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





void main()
{
	setlocale(LC_ALL, "ru");
	int n;	
	cout << "Введите количество элементов: "; cin >> n;
	Tree T;
	for (size_t i = 0; T.size() < n; i++)
	{
		T.insert(rand() % 100);
	}
	T.print();
	cout << "Минимальное значение в дереве: " << T.minValue() << endl;
	cout << "Минимальное значение в дереве: " << T.maxValue() << endl;
	cout << "Количетво элементов дерева: " << T.size() << endl;
	cout << "Сумма элементов дерева: " << T.sum() << endl;
	cout << "Среднее арифметическое элементов дерева: " << T.avg() << endl;
	Tree T2 = T;
	T2.print();
}