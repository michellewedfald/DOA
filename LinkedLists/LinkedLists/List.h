#pragma once

template <typename T>
class List
{
public:
	virtual void headInsert(const T& value) = 0;
	virtual void headRemove() = 0;
	virtual void insert(const T& value, unsigned int index) = 0;
	virtual void remove(unsigned int index) = 0;
	virtual unsigned int length() = 0;
	virtual void clear() = 0;
	virtual T at(unsigned int index) = 0;
};