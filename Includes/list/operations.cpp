#ifndef OPERATIONS_CPP
#define OPERATIONS_CPP

#include "list.h"

template <class type>
void	List<type>::createElement(const type& data, Element<type> *next)
{
	if(!_begin)
	{
		_begin = new Element<type>(data);
		return ;
	}
	auto begin = _begin;

	while (begin && begin->_next != next)
		begin = begin->_next;
	(begin || !next) ? begin->_next = new Element<type>(data, next) : _begin = new Element<type>(data, _begin);
}

template <class type>
type	List<type>::removeElement(const unsigned int index)
{
	decltype(_begin) temp, before;
	type data;
	if (!_size)
		throw std::out_of_range("Empty list");
	if (_size == 1)
	{
		data = _begin->_data;
		delete _begin;
		_size--;
		_begin = NULL;
		return (data);
	}
	if (!index)
	{
		temp = _begin;
		_begin = _begin->_next;
	}
	else
	{
		before = _at(index - 1);
		temp = before->_next;
		before->_next = temp->_next;
	}
	data = temp->_data;
	_size--;
	delete temp;
	return (data);
}

template <class type>
void	List<type>::insert(const type& data, const unsigned int index)
{
	if (index != END)
		createElement(data, _at(index));
	else
		createElement(data);
	_size++;
}

template <class type>
void	List<type>::insert(const std::initializer_list<type>& data, const unsigned int start)
{
	unsigned int i = (_begin) ? start : 0;
	for (auto it = data.begin(); it != data.end(); it++)
		insert(*it, ((i == END) ? i : i++));
}

template <class type>
void	List<type>::insert(const type *data, const unsigned int length, const unsigned int start)
{
	unsigned int i = (_begin) ? start : 0;
	for (int j = 0; j < length; j++)
		insert(data[j], ((i == END) ? i : i++));
}

template <class type>
void	List<type>::push_back(const type& data)
{
	insert(data);
}

template <class type>
void	List<type>::push_front(const type& data)
{
	insert(data, 0);
}

template <class type>
List<type>					*List<type>::remove(const unsigned int start, const unsigned int end)
{
	List<type>* result = new List<type>();

	if (END != end && (end >= _size || start >= _size))
		throw std::out_of_range("start or end greater than size of List");
	else if (start >= _size)
		throw std::out_of_range("start or end greater than size of List");
	if (end != END && end < start)
		throw std::logic_error("In List::remove, we cannot have end < start");
	if (start == end && !end)
		result->push_back(removeElement(0));
	for (unsigned int i = 0, ending = ((end == END) ? (_size - start) : (end - start)); i < ending; i++)
		result->push_back(removeElement(start));
	return (result);
}

template <class type>
type	List<type>::pop_back()
{
	auto temp = remove(_size - 1);
	type result = (*temp)[0];
	delete temp;

	return (result);
}

template <class type>
type	List<type>::pop_front()
{
	auto temp = remove(0, 0);
	type result = (*temp)[0];
	delete temp;

	return (0);
}

#endif