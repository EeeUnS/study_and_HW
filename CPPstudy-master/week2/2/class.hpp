#ifndef CLASS_HPP
#define CLASS_HPP
#include<iostream>
#include"cstdlib"
#include<cstring>

using namespace std;

typedef struct node
{
	 const char *data; 
	 struct node *next;
	 struct node *prev;

}Node;

class linked_list
{
public:
	linked_list(const char *word) ;
	~linked_list();
	void add_back(const char *word);
	Node *head() const;
	Node *tail() const;
	void remove_head();
	void remove_tail();
	void insert(int index, const char *word); 
	void print_all() const;
	void remove(const char *word);
private:
	Node * _head = NULL;
	Node * _tail = NULL;
	Node * find(const char *word);
};

#endif