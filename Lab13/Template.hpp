#pragma once
#include <iostream>
#include <string>

template< class NODETYPE > class List; // forward declaration
template<class NODETYPE>
class ListNode
{
	friend class List< NODETYPE >; // make List a friend

public:

	ListNode(const NODETYPE& newData)// copy constructor
	{
		this->data = newData;
		this->nextPtr = nullptr;
	}

	NODETYPE getData() const // return data in the node
	{
		return this->data;
	}

	ListNode< NODETYPE >* getNext() const
	{
		return this->nextPtr;
	}

	void setNext(ListNode<NODETYPE>* newnode)
	{
		this->nextPtr = newnode;
	}

private:

	NODETYPE data; // data
	ListNode< NODETYPE >* nextPtr; // next node in the list

};



template< class NODETYPE >
class List
{
public:

	List() // constructor
	{
		this->firstPtr = nullptr;
		this->lastPtr = nullptr;
	}

	~List() // destructor
	{
		while (this->firstPtr != nullptr)
		{
			ListNode< NODETYPE >* pCur = this->firstPtr;
			this->firstPtr = this->firstPtr->getNext();
			delete pCur;
		}
	}

	void insertAtFront(const NODETYPE& newData)
	{
		ListNode< NODETYPE >* pNew = this->getNewNode(newData);
		pNew->setNext(this->firstPtr);
		this->firstPtr = pNew;
	}

	void insertAtBack(const NODETYPE& newData)
	{
		ListNode< NODETYPE >* pNew = this->getNewNode(newData);
		ListNode< NODETYPE >* pCur = this->firstPtr;
		if (pCur != nullptr)
		{
			while (pCur->getNext() != nullptr)
			{
				pCur = pCur->getNext();
			}
			pCur->setNext(pNew);
			this->lastPtr = pNew;
		}
		else
		{
			this->firstPtr = pNew;
			this->lastPtr = pNew;
		}
	}

	bool removeFromFront(NODETYPE& removedData)
	{
		removedData = this->firstPtr->getData();

		ListNode< NODETYPE >* pCur = this->firstPtr;
		this->firstPtr = this->firstPtr->getNext;
		delete this->pCur;
		return true;
	}

	bool removeFromBack(NODETYPE& removedData)
	{
		removedData = this->lastPtr->getData();

		ListNode< NODETYPE >* pCur = this->lastPtr;
		this->lastPtr = nullptr;
		delete this->pCur;
		return true;
	}

	bool isEmpty() const
	{
		if (this->firstPtr == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void print() const
	{
		ListNode< NODETYPE >* pCur = this->firstPtr;
		
		while (pCur != nullptr)
		{
			std::cout << pCur->getData() << std::endl;

			pCur = pCur->getNext();
		}
	}

private:

	ListNode< NODETYPE >* firstPtr; // pointer to first node
	ListNode< NODETYPE >* lastPtr; // pointer to last node
	// Utility function to allocate a new node
	ListNode< NODETYPE >* getNewNode(const NODETYPE& newData)
	{
		ListNode<NODETYPE>* pNew = new ListNode<NODETYPE>(newData);
		return pNew;
	}

};

template< class NODETYPE >
class Queue : private List<NODETYPE>
{
public:

	void enqueue(const NODETYPE& newdata)
	{
		this->insertAtBack(newdata);
	}

	void dequeue()
	{
		this->removeFromFront();
	}

	void printQ()
	{
		this->print();
	}
};