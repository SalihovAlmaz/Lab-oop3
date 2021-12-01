
#include <iostream>
using namespace std;

template<typename T>
class storage // класс хранилище
{
public:
	
	storage();
	int GetSize();
	void pushBack(T data);
	void popFront();
	void popBack();
	void clear();
	void pushFront(T data);
	void RemoveAt(int index);
	void RemoveAt_noDel(int index);
	void insert(T value, int index);
	T& operator[] (const int index);
	~storage();


private:
	template<typename T>
	class Node   // класс элемента
	{
	public:
		Node* pNext;   // адрес след. элемента
		T data;        // инф. хранящиеся в элементе
		Node(T data = T(), Node *pNext=nullptr) //конструктор элемента списка
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node<T>* head;      // обьявление указателя на первый элемент списка
	int Size;  // обьялвение переменной, где хранится размер с списка
};
template<typename T>
storage<T> ::storage() { // конструктор по умолчанию у класса хранилище 
	Size = 0;
	head = nullptr;
}
template<typename T>
storage<T> ::~storage() {
	clear();
}

template<typename T>
int storage<T>::GetSize()
{
	return Size;
}

template<typename T>
void storage<T>::pushBack(T data)  // функция добавления элемента в конец списка
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size=Size+1;
}

template<typename T>
void storage<T>::popFront()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size = Size - 1;
}

template<typename T>
void storage<T>::popBack()
{
	RemoveAt(Size - 1);
}

template<typename T>
void storage<T>::clear()
{
	while (Size)
	{
		popFront();
	}
}

template<typename T>
void storage<T>::pushFront(T data)
{
	
	head = new Node<T>(data,head);
	Size = Size + 1;

}

template<typename T>
void storage<T>::RemoveAt(int index)
{
	if (index == 0) {
		popFront();
	}
	else
	{
		Node<T>* now = head;
		for (int i = 0; i < index-1; i++)
		{
			now = now->pNext;
		}
		Node<T>* Del = now->pNext;
		now->pNext = Del->pNext;
		delete Del;
		Size = Size - 1;
	}
}

template<typename T>
void storage<T>::RemoveAt_noDel(int index)
{
	if (index == 0) {
		popFront();
	}
	else
	{
		Node<T>* now = head;
		for (int i = 0; i < index - 1; i++)
		{
			now = now->pNext;
		}
		Node<T>* Del = now->pNext;
		now->pNext = Del->pNext;
		Del->pNext = nullptr;
		Size = Size - 1;
	}
}

template<typename T>
void storage<T>::insert(T data, int index)
{
	if (index==0)
	{
		pushFront(data);
	}
	else {
		Node<T>* now = head;

		for (int i = 0; i < index - 1; i++)
		{
			now = now->pNext;
		}
		Node<T>* newNode = new Node<T>(data, now->pNext);
		now->pNext = newNode;
		Size = Size + 1;
	}
}

template<typename T>
T& storage<T>::operator[](const int index)
{
	int cout = 0;
	Node<T>* current = this->head;
	


		while (current != nullptr)
		{
			if (cout == index) {

				return current->data;
			}
			current = current->pNext;
			cout = cout + 1;
		}
	
	
}






int main()
{
	setlocale(LC_ALL, "rus");
	storage<int> сontainer;
    int randFunc = 0;
    int a = 0;
    int index = 0;
    unsigned int start_time = clock();
    /*storage.first();*/
    for(int i = 0; i < 100; i++){
        randFunc = 1/*rand() % 3*/;
        switch(randFunc){
        case 0:
            a = rand() % 25;
			сontainer.pushFront(a);
            cout << i << ": add node " << a << "\n";
            break;
        case 1:
            a = rand() % 25;
            index = rand() % (сontainer.GetSize() + 1);
			сontainer.insert(a, index);
            cout << i << ": add node index  " << a << " " << index << "\n";
            break;
        case 2:
            index = rand() % (сontainer.GetSize() + 1);
			сontainer.RemoveAt(index);
            cout << i << ": popIndex | " << index << "\n";
            break;
        default:
            break;
        }
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    for(int i=0;i<сontainer.GetSize();i++)
		cout << сontainer[i] << "\n";
    cout << "\n\n\n" << search_time << "\n\n\n";
}