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
		this->lastPtr->setNext(pNew);
	}

	bool removeFromFront(NODETYPE& removedData)
	{
		removedData = this->firstPtr->getData();

		ListNode< NODETYPE >* pCur = this->firstPtr;
		this->firstPtr = this->firstPtr->getNext;
		delete this->pCur;
	}

	bool removeFromBack(NODETYPE& removedData)
	{
		removedData = this->lastPtr->getData();

		ListNode< NODETYPE >* pCur = this->lastPtr;
		this->lastPtr = nullptr;
		delete this->pCur;
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