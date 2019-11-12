#ifndef CLASS_HPP
#define CLASS_HPP

#include<iostream>
#include"cstdlib"
#include<cstring>

using namespace std;

template<typename object>
struct Node
{
	const object data;
	Node<object> *next;
	Node<object> *prev;
};

template<typename T>

class linked_list
{
public:
	
	linked_list(const T item); //check
	//template<>linked_list(const char *word); //check
	~linked_list();//check

	void add_back(const T item);
	Node<T> *head() const;
	Node<T> *tail() const;
	void remove_head();
	void remove_tail();
	void insert(int index, const T item);
	//template<> void insert(int index, const char *word);

	void print_all() const;
	void remove(const T *item);
	//template<>void remove(const char *word);

private:
	Node<T> * _head = nullptr;
	Node<T> * _tail = nullptr;
	//template<>Node<char *> * find(const char *item);
	Node<T> * find(const T *item);
};

#include"class.hpp"
#endif