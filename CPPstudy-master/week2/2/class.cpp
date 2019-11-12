#include"class.hpp"
linked_list::linked_list(const char *item)
{
	add_back(item);
}

linked_list::~linked_list()//꼭 동적할당 해제해줄것!
{
	while (_head != NULL)
	{
		remove_tail();
	}
}

void linked_list::add_back(const char *word) 
{
	Node *tmp = new Node;
	tmp->data = word;
	tmp->next = NULL;

	if (_head == NULL)
	{
		tmp->prev = NULL;
		_head = tmp;
	}
	else
	{
		_tail->next = tmp;
		tmp->prev = _tail;
	}
	_tail = tmp;
}

void linked_list::remove_head() {
	if (_head == NULL) 
	{
		return ;
	}
	Node *tmp = _head; 
	if (_head  == _tail)
	{
		_head = NULL; _tail = NULL;
	}
	else 
	{
		_head = _head->next;
	}
	delete tmp ;
}
void linked_list::remove_tail() {
	Node *tmp = _tail;
	if (tmp == NULL) {
		return ;
	}
	else if (_head == _tail)
	{
		_head = NULL; _tail = NULL;
		delete tmp;
	}
	else {
		_tail = _tail->prev;
		_tail->next = NULL;
		delete tmp;
		return ;
	}
}

void linked_list::remove(const char *word)
{
	if (strcmp(word, _head->data) == 0)
		remove_head();
	else if (strcmp(word, _tail->data) == 0)
		remove_tail();
	else
	{
		Node *p = find(word);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

Node * linked_list::find(const char *word)
{
	Node *p = _head;
	while (p != NULL) {
		if (strcmp(p->data, word) == 0)
			return p;
		p = p->next;
	}
	return NULL;
}


void linked_list::insert(int index, const char *word)
{
	if (index <= 0)
		return;
	Node *p = _head;
	for (int i = 1; i < index && p != NULL; i++)
		p = p->next;
	if (p != NULL)
	{
		if((p == _head && (p == _tail))| (p == _tail))//삽입노드가 처음한개or맨끝
			add_back(word);

		Node *tmp = new Node;

		tmp->data = word;
		tmp->next = p->next;
		tmp->prev = p;
		p->next = tmp;
		tmp->next->prev = tmp;
	}
	return;
}

Node* linked_list::head() const
{
	return _head;
}
Node * linked_list::tail() const
{
	return _tail;
}

void linked_list::print_all() const
{
	Node *iterator = _head;
	while (iterator != NULL)
	{
		cout << iterator->data << endl;
		iterator = iterator->next;
	}
}
