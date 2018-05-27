#pragma once

#include<cstring>

template <class T>
class Pair
{
public:
	Pair<T>();
	Pair<T>(const Pair & other);
	Pair<T> & operator=(const Pair & other);
	~Pair<T>();

	Pair<T>(const char * key, T value);

	const char * getKey() const;
	const T& getValue() const;
	void setValue(T newValue);

private:
	char * key;
	T value;
	void copyFromOther(const Pair & other);
	void Delete();
	void setKey(const char *);
};

template<class T>
inline Pair<T>::Pair() : key(nullptr)
{
}

template<class T>
inline Pair<T>::Pair(const Pair & other)
{
	this->copyFromOther(other);
}

template<class T>
inline Pair<T> & Pair<T>::operator=(const Pair & other)
{
	if (this != &other)
	{
		copyFromOther(other);
	}
	return *this;
}


template<class T>
inline Pair<T>::~Pair<T>()
{
	this->Delete();
}

template<class T>
inline Pair<T>::Pair(const char * key, T value) : value(value)
{
	this->setKey(key);
}

template<class T>
inline const char * Pair<T>::getKey() const
{
	return this->key;
}

template<class T>
inline const T& Pair<T>::getValue() const
{
	return this->value;
}

template<class T>
inline void Pair<T>::setValue(T newValue)
{
	this->value = newValue;
}


template<class T>
inline void Pair<T>::copyFromOther(const Pair & other)
{
	this->setKey(other.key);
	this->setValue(other.value);
}

template<class T>
inline void Pair<T>::Delete()
{
	delete[] this->key;
}

template<class T>
inline void Pair<T>::setKey(const char * newKey)
{
	if (this->key) delete[] this->key;

	if (newKey)
	{
		int size = strlen(newKey) + 1;
		this->key = new char[size];
		memcpy(this->key, newKey, size);
	}

}
