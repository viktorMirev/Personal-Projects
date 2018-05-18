#pragma once
#include <stdexcept>

template <class T>
class Vector
{
public:	
	Vector(int capacity);
	Vector(const Vector & other);
	Vector();
	Vector & operator=(const Vector & other);

	T& operator[](int idx);
	T operator[](int idx) const;

	void Add(const T & item);

	int Size() const;

	// returns true if it finds and remove the requested object
	bool RemoveAt(int idx);
	bool Remove(T & other);

	// returns -1 if not found
	int GetIndex(const T & refItem) const;

	
private:

	const int INITIAL_SIZE = 64;
	const int INFLATION_FACTOR = 2;

	T * data = nullptr;
	int capacity;
	int index; //the next free

	void inflate();
	void copyFromOther(const Vector<T> * other);
};

template <class T>
Vector<T>::Vector()
{
	this->capacity = INITIAL_SIZE;
	this->data = new T[this->capacity];
	index = 0;
}

template <class T>
Vector<T>::Vector(int capacity)
{
	this->capacity = capacity;
	this->data = new T[this->capacity];
	index = 0;
}

template<class T>
inline Vector<T>::Vector(const Vector & other)
{
	copyFromOther(&other);
}

template<class T>
inline Vector<T> & Vector<T>::operator=(const Vector & other)
{
	if (this != &other)
	{
		copyFromOther(&other);
	}
	
	return *this;
}


template<class T>
inline void Vector<T>::copyFromOther(const Vector<T>* other)
{
	if (data) delete[] data;

	this->capacity = other->capacity;
	this->index= other->index;
	this->data = new T[capacity];

	for (int i = 0; i < this->capacity; i++)
	{
		this->data[i] = other->data[i];
	}
}


template <class T>
inline int Vector<T>::Size() const
{
	return this->index;
}

template <class T>
inline void Vector<T>::Add(const T & other)
{
	if (this->index >= this->capacity) this->inflate();
	data[this->index] = other;
	index++;
}

template<class T>
inline int Vector<T>::GetIndex(const T & refItem) const
{
	for (int i = 0; i < this->index; i++)
	{
		if (this->data[i] == refItem) return i;
	}
	return -1;
}



template<class T>
inline bool Vector<T>::Remove(T & other)
{
	int posIdx = find(refItem);
	if (posIdx == -1) return false; //not found
	return this->RemoveAt(posIdx);
}
template <class T>
inline bool Vector<T>::RemoveAt(int index)
{
	if (index < 0 && index >= this->index) return false;

	for (int i = index + 1; i < this->index; i++)
	{
		this->data[i - 1] = this->data[i];
	}
	this->index--;

	return true;
}

template <class T>
inline T& Vector<T>::operator[](int index)
{
	if (index >= 0 && index < this->index) return this->data[index];
	throw std::out_of_range("Invalid index! Out of range");
}

template <class T>
inline T Vector<T>::operator[](int index) const
{
	if (index >= 0 && index < this->index) return this->data[index];
	throw std::out_of_range("Invalid index! Out of range");
}

template <class T>
inline void Vector<T>::inflate()
{
	int newCapacity = this->mCapacity * this->INFLATION_FACTOR + 1; // the +1 is in case someone init's it with capacity=1
	T * newArray = new T[newCapacity];

	memcpy(newArray, this->data, index * sizeof(T));

	delete[] this->data;
	this->data = newArray;
	this->capacity = newCapacity;
}