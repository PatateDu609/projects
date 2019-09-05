#ifndef ACCESS_CPP
#define ACCESS_CPP

#include "list.h"

template <class type>
unsigned int	List<type>::getsize() const
{
	return (_size);
}

template <class type>
Element<type>	*List<type>::_at(const unsigned int index)
{
	if (index > _size)
		throw std::invalid_argument( "Invalid index" );
	int i = 0;
	auto begin = _begin;
	while (i != index)
	{
		begin = begin->_next;
		i++;
	}
	return (begin);
}

template <class type>
type&			List<type>::at(const unsigned int index)
{
	if (index >= _size)
		throw std::invalid_argument( "Invalid index" );
	return (_at(index)->_data);
}

template <class type>
type&			List<type>::back()
{
	auto begin = _begin;

	while (begin->_next)
		begin = begin->_next;
	return (begin->_data);
}

template <class type>
type&			List<type>::front()
{
	return (_begin->_data);
}

template <class type>
type	*List<type>::data() const
{
	if (!_size)
		return (NULL);
	type *result = new type[_size];
	Element<type> *begin = _begin;
	int i = 0;

	while (i < _size)
	{
		result[i] = begin->_data;
		begin = begin->_next;
		i++;
	}
	return (result);
}

#endif