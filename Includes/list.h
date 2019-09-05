#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <iostream>

#define END -1

template <class type>
struct Element
{
	Element(type data, Element *next = NULL)
	{
		_data = data;
		_next = next;
	}
	Element(const Element* other)
	{
		_next = other->_next;
		_data = other->_data;
	}
	type _data;
	Element *_next;
};

template<class type>
class List
{
public:
	// Defined in list.cpp
							List();
							List(const List &other);
							List(const std::initializer_list<type>& init);
							List(const type* init, int size);
 							~List();

	// Defined in operations.cpp
	void					insert(const type& data, const unsigned int index = END);
	void					insert(const type *data, const unsigned int length, const unsigned int start = END);
	void					insert(const std::initializer_list<type>& data, const unsigned int start = END);
	void					push_back(const type& data);
	void					push_front(const type& data);
	type					pop_back();
	type					pop_front();
	List					*remove(const unsigned int start, const unsigned int end = END);

	// defined in operators.cpp
	template <class T>
	friend std::ostream&	operator<<(std::ostream& os, const List<T>& list);
	template <class T>
	friend List<T>			operator+(const List<T>& a, const List<T>& b);
	template <class T>
	friend List<T>			operator-(const List<T>& a, const T& value);

	type&					operator[](const unsigned int index);
	List&					operator=(const List& other);
	List&					operator+=(const List& b);
	List&					operator-=(const type& value);

	// defined in access.cpp
	type&					at(const unsigned int index);
	type					*data() const;
	type&					back();
	type&					front();
	unsigned int			getsize() const;

private:
	Element<type> 			*_begin;
	unsigned int			_size;

	// defined in access.cpp
	Element<type>			*_at(const unsigned int index);

	// defined in operations.cpp
	void					createElement(const type& data, Element<type> *next = NULL);
	type					removeElement(const unsigned int index);
};

#include "access.cpp"
#include "list.cpp"
#include "operations.cpp"
#include "operators.cpp"

#endif