#pragma once

#include"Pair.h"
#include"Vector.h"
#include<string.h>

template <class T>
class Settings
{
public:
	Settings<T>();
	Settings<T>(const Settings &);
	Settings<T> & operator=(const Settings &);
	~Settings<T>();

	void set(const char *, T);
	bool get(const char *, T & );

	int count() const;

private:
	Vector<Pair<T>> * pairs;
	void copyFromOther(const Settings&);

	//returns -1 if not found;
	int getIndexOf(const char *);
};

template<class T>
inline Settings<T>::Settings()
{
	this->pairs = new Vector<Pair<T>>();
}

template<class T>
inline Settings<T>::Settings(const Settings & other)
{
	this->copyFromOther(other);
}

template<class T>
inline Settings<T> & Settings<T>::operator=(const Settings & other)
{
	this->copyFromOther(other);
	return *this;
}

template<class T>
inline Settings<T>::~Settings<T>()
{
	delete this->pairs;
}

template<class T>
inline void Settings<T>::set(const char * key, T value)
{
	int index = this->getIndexOf(key);
	if (index >= 0)
	{
		this->pairs->operator[](index).setValue(value);
	}
	else
	{
		Pair<T> newPair(key, value);
		this->pairs->Add(newPair);
	}
}

template<class T>
inline bool Settings<T>::get(const char * key, T & value)
{
	int index = this->getIndexOf(key);
	if (index >= 0)
	{
		value = this->pairs->operator[](index).getValue();
		return true;
	}

	return false;
}

template<class T>
inline int Settings<T>::count() const
{
	return this->pairs->Size();
}

template<class T>
inline void Settings<T>::copyFromOther(const Settings & other)
{
	if (this != &other)
	{
		if (this->pairs) delete this->pairs;

		this->pairs = new Vector<Pair<T>>(*(other.pairs));
	}
}

template<class T>
inline int Settings<T>::getIndexOf(const char * key)
{
	int size = this->pairs->Size();
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(key, pairs->operator[](i).getKey())) return i;
	}
	return -1;
}
