#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"

template <class type>
List<type>::List() : _size(0), _begin(NULL)
{}

template <class type>
List<type>::List(const List &other) : _size(other.getsize()), _begin(NULL)
{
	if (!_size)
		return ;
	Element<type> *temp = other._begin, *begin;

	while (temp)
	{
		createElement(temp->_data);
		temp = temp->_next;
	}
	begin = _begin;
	while (begin->_next)
		begin = begin->_next;
}

template <class type>
List<type>::List(const std::initializer_list<type>& init) : _size(init.size()), _begin(NULL)
{
	if (!_size)
		return ;
	decltype(_begin) begin;
	for(auto it = init.begin(); it != init.end(); it++)
		createElement(*it);
	begin = _begin;
	while (begin->_next)
		begin = begin->_next;
}

template <class type>
List<type>::List(const type* init, int size) : _size(size), _begin(NULL)
{
	int i = 1;
	if (!size)
		return ;
	_begin = new Element<type>(init[0]);
	Element<type> *begin = _begin;
	while (i < size)
	{
		begin->_next = new Element<type>(init[i]);
		begin = begin->_next;
		i++;
	}
}

template <class type>
List<type>::~List()
{
	Element<type> *temp;

	while (_begin)
	{
		temp = _begin;
		_begin = temp->_next;
		delete temp;
	}
}

#endif