#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// sorting function with a customized function passed in argument
template <class T>
extern void		sort(T *tab, int length, int (*f)(T, T));

// swaping function that works with any type
template <class T>
extern void		swap(T *a, T *b);

// template function for reversing an array
template <class T>
extern void		rev(T *tab, int size);

// a function that apply a function for each element of an array
template <class T>
extern void		foreach(T *tab, int length, void (*f)(T));

// returns 1 if an element in the array passed in argument respects the condition
template <class T>
extern int		any_of(T * tab, int length, int (*f)(T));

// returns the number of elements that respects the condition
template <class T>
extern int		count_if(T *tab, int length, int (*f)(T));

// function that search if an element is in an array or not
template <class T>
extern T*		find(T *tab, int length, T element);

// function that search and replace each occurrence of a given value by another
template <class T>
extern void		replace(T *tab, int length, T old, T new_value); 

#endif