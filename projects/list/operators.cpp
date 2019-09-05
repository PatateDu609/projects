#ifndef OPERATORS_CPP
#define OPERATORS_CPP

#include "list.h"

template <class type>
std::ostream&	operator<<(std::ostream& os, const List<type>& list)
{
	if (list._size)
	{
		auto begin = list._begin;

		while (begin->_next)
		{
			os << begin->_data << " ";
			begin = begin->_next;
		}
		os << begin->_data;
	}
	return (os);
}

template <class type>
type&			List<type>::operator[](const unsigned int index)
{
	return (at(index));
}

template <class type>
List<type>&		List<type>::operator=(const List& other)
{
	Element<type> *temp;

	while (_begin)
	{
		temp = _begin;
		_begin = temp->_next;
		delete temp;
	}
	_size = other._size;
	if (!_size)
		return (*this);
	_begin = new Element<type>(other._begin);

	Element<type> *begin = _begin, *current = other._begin->_next;
	while (current)
	{
		begin->_next = new Element<type>(current);
		begin = begin->_next;
		current = current->_next;
	}

	return (*this);
}

template <class type>
List<type>&		List<type>::operator+=(const List& b)
{
	Element<type> *begin = _at(_size - 1), *current = b._begin;
	_size += b._size;

	while (current)
	{
		begin->_next = new Element<type>(current);
		begin = begin->_next;
		current = current->_next;
	}
}

template <class type>
List<type>		operator+(const List<type>& a, const List<type>& b)
{
	List<type> result(a);

	result += b;
	return (result);
}

template <class type>
List<type>&		List<type>::operator-=(const type& value)
{
	Element<type> *begin = _begin;
	List<int> to_remove;
	int i = 0;

	while (begin)
	{
		if (begin->_data == value)
			to_remove.push_back(i);
		i++;
		begin = begin->_next;
	}
	i = 0;
	while (i < to_remove._size)
	{
		removeElement(to_remove[i] - i);
		i++;
	}
	return (*this);
}

template <class type>
List<type>		operator-(const List<type>& a, const type& value)
{
	List<type> result;
	Element<type> *begin = a._begin;

	while (begin)
	{
		if (begin->_data != value)
			result.push_back(begin->_data);
		begin = begin->_next;
	}
	return (result);
}

#endif