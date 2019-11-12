
//#include"class.h"


template<typename T>
linked_list<T>::linked_list(const T item)
{
	add_back(item);
}

//template<>
//linked_list<char*>::linked_list(const char *word)
//{
//	char *_word = new  char[strlen(word) + 1];
//	strcpy_s(_word, strlen(word), word);
//	add_back(_word);
//}

template<typename T>
linked_list<T>::~linked_list()//꼭 동적할당 해제해줄것!
{
	while (_head != nullptr)
	{
		remove_tail();
	}
}


template<typename T>
void linked_list<T>::add_back(const T item)
{
	Node<T> *tmp = new Node<T>{ item , nullptr , nullptr };

	if (_head == nullptr)
	{
		tmp->prev = nullptr;
		_head = tmp;
	}
	else
	{
		_tail->next = tmp;
		tmp->prev = _tail;
	}
	_tail = tmp;
}

template<typename T>
void linked_list<T>::remove_head()
{
	if (_head == nullptr)
	{
		return;
	}
	Node<T> *tmp = _head;
	if (_head == _tail)
	{
		_head = nullptr;
		_tail = nullptr;
	}
	else
	{
		_head = _head->next;
	}
	delete tmp;
}

template<typename T>
void linked_list<T>::remove_tail()
{
	Node<T> *tmp = _tail;
	if (tmp == nullptr)
	{
		return;
	}
	else if (_head == _tail)
	{
		_head = nullptr;
		_tail = nullptr;
		delete tmp;
	}
	else
	{
		_tail = _tail->prev;
		_tail->next = nullptr;
		delete tmp;
		return;
	}
}

template<typename T>
void linked_list<T>::remove(const T *item)
{
	if (item == _head->data)
		remove_head();
	else if (item == _tail->data)
		remove_tail();
	else
	{
		Node<T> *p = find(item);
		if (p == nullptr)
		{
			cout << "없는 item입니다." << endl;
			return;
		}
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}
/*
template<>
void linked_list<char *>::remove(const char *word)
{
	if (strcmp(word, _head->data) == 0)
		remove_head();
	else if (strcmp(word, _tail->data) == 0)
		remove_tail();
	else
	{
		Node<char*> *p = find(word);
		if (p == nullptr)
		{
			cout << "없는 item입니다." << endl;
			return;
		}
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}
/*/

template<typename T>
Node<T> * linked_list<T>::find(const T *item)
{
	Node<T> *p = _head;
	while (p != nullptr)
	{
		if (p->data == item)
			return p;
		p = p->next;
	}
	return nullptr;
}

/*
template<>
Node<char*> * linked_list<char *>::find(const char *word)
{
	Node<char *> *p = _head;
	while (p != nullptr)
	{
		if (strcmp(p->data, word) == 0)
			return p;
		p = p->next;
	}
	return nullptr;
}
*/


template<typename T>
void linked_list<T>::insert(int index, const T item)
{
	if (index <= 0)
		return;
	Node<T> *p = _head;
	for (int i = 1; i < index && p != nullptr; i++)
		p = p->next;
	if (p != nullptr)
	{
		if ((p == _head && (p == _tail)) | (p == _tail))//삽입노드가 처음한개or맨끝
			add_back(item);
		else
		{
			Node<T> *tmp = new Node<T>;

			tmp->data = item;
			tmp->next = p->next;
			tmp->prev = p;
			p->next = tmp;
			tmp->next->prev = tmp;
		}
	}
	return;
}

//template<>
//void linked_list<char *>::insert(int index, const char *word)
//{
//	if (index <= 0)
//		return;
//	Node<char *> *p = _head;
//	char *_word = new char[strlen(word) + 1];
//	strcpy_s(_word, strlen(_word), word);
//	
//	for (int i = 1; i < index && p != nullptr; i++)
//		p = p->next;
//	if (p != nullptr)
//	{
//		if ((p == _head && (p == _tail)) | (p == _tail))//삽입노드가 처음한개or맨끝
//			add_back(_word);
//		else {
//			Node<char *> *tmp = new Node<char *>{ _word, p->next, p };
//			/*
//			tmp->data = word;
//			tmp->next = p->next;
//			tmp->prev = p;
//			*/
//			p->next = tmp;
//			tmp->next->prev = tmp;
//		}
//	}
//	return;
//}


template<typename T>
Node<T>* linked_list<T>::head() const
{
	return _head;
}
template<typename T>
Node<T> * linked_list<T>::tail() const
{
	return _tail;
}

template<typename T>
void linked_list<T>::print_all() const
{
	Node<T> *iterator = _head;
	while (iterator != nullptr)
	{
		cout << (T)iterator->data << endl;
		iterator = iterator->next;
	}
	cout << endl;
}
