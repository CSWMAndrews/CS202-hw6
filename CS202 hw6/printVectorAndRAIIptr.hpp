#ifndef Homework6_hpp
#define Homework6_hpp

#include <iostream>
#include <ostream>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;

using std::cout;

template <typename T>
void printVector(ostream& returnStream, std::vector<T> inVec)
{
	for (unsigned int begin = 0; begin < inVec.size(); begin++)
	{
		cout << "main print call\n";
		returnStream << inVec[begin] << std::endl;
	}
}

template <typename T>
class RAIIPtr
{
public:
	RAIIPtr(T*);
	~RAIIPtr();

	T& operator*();
	T* operator->();
private:
	T* _ptr;
};

template <typename T>
RAIIPtr<T>::RAIIPtr(T* test)
{
	cout << "call 0\n";
	this->_ptr = test;
}

template <typename T>
T& RAIIPtr<T>::operator*()
{

	cout << "call 1\n";
	return *_ptr;
}

template <typename T>
RAIIPtr<T>::~RAIIPtr()
{
	cout << "call 2\n";
	delete _ptr;
}

template <typename T>
T* RAIIPtr<T>::operator->()
{
	cout << "call 3\n";
	return _ptr;
}

#endif //Homework6_hpp
