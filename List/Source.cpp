#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Адрес следующего элемента
	Element* pPrev;// Адрес предыдущего элемента
public:	
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	

	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class List;
};

class List
{
	Element* Tail;//Конечный элемент (Хвост списка)
	Element* Head;	//Указатель на начальный (нулевой) элемент списка.
public:
	List()
	{
		Tail = nullptr;
		Head = nullptr;	//Если Голова содержит 0, значит список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	int operator[](const int index)
	{
		int counter = 0;
		Element* Temp = this->Head;
		while (Temp != nullptr)
		{
			if (counter == index)
			{
				return Temp->Data;
			}
			Temp = Temp->pNext;
			counter++;
		}
	}
	

	//			Добавление элементов
	void push_front(int Data)	//Добавляет значение в начало списка
	{
		/*
		//1) Создаем новый элемент
		Element* New = new Element(Data);
		//2) Присоединяем НОВЫЙ элемент к списку
		New->pNext = Head;
		//3)Говорим, что НОВЫЙ элемент является НАЧАЛОМ (Head) списка:
		Head = New;*/

		Head = new Element(Data, Head);
	}
	void push_back(int Data)	//Добавляет значение в конец списка
	{
		if (Head == nullptr)//Если список пуст
		{
			push_front(Data);
			return;
		}
		//0) Создать элемент:
		//Element* New = new Element(Data);
		//1) Дойти до последнего элемента
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
			Temp = Temp->pNext;
		//2) Прикрепить добавляемы элемент к концу списка
		Temp->pNext = new Element(Data);
	}

	void insert(int Index, int Data)
	{
		//1) Доходим до нужного элемента:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			if (Temp->pNext == nullptr)return;
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data, Temp->pNext);
	}
	

	void pop_front()//Удаляет начальный элемент списка
	{
		Element* Temp = Head;
		Head = Head->pNext;
		delete Temp;		
	}
	void pop_back(int n)//Удаляет последний элемент списка
	{
		erase(n - 1);
	}
	void erase(int index)// Удаляет элемент по заданному индексу
	{
		if (index==0)
		{
			pop_front();
		}
		else
		{


			Element* previous = this->Head;
			for (size_t i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;

			}
			Element* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			delete toDelete;
		}
	}
	


	//			Methods
	void print()
	{
		Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это указатель, при помощи которого можно получить доступ 
		//к элементам структуры данных.
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
	}
	void print_insert(int index, int n)
	{
		if (index > (n / 2))
		{
			Element* Temp = Tail;
			while (Temp != nullptr)
			{
				cout << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
				Temp = Temp->pPrev;	//Переход на следующий элемент
			}
		}
		else
		{
			Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это указатель, при помощи которого можно получить доступ 
		//к элементам структуры данных.
			while (Temp != nullptr)
			{
				cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
				Temp = Temp->pNext;	//Переход на следующий элемент
			}
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;	//Размер списка
	cout << "Введите размер списка: "; cin >> n;
	List list;
	list.push_back(3);
	list.push_back(5);
	list.push_back(8);
	list.push_back(13);
	list.push_back(21);
	
	/*for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}*/
	/*list.print();
	list.push_back(123);
	list.print();

	int index;
	int data;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> data;
	list.insert(index, data);
	list.pop_front();
	list.pop_back(n);

	int two_index;
	cout << "Введите индекс элемента который хотите удалить: "; cin >> two_index;
	list.erase(two_index);

	cout << "____________________________________________" << endl;
	list.print();*/

	int i_index = 10;
	List list_2;
	list_2.print_insert(i_index, n);

}