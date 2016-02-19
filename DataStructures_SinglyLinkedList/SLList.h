/*	This program shows the basic use of the Singly Linked List.

	Copyright (C) 2015 - Present, George W. Wulfers

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SLLIST_H
#define SLLIST_H

#include "TNode.h"

template <class T>
class SLList
{
public:
	//Constructor. Initialize member variables
	SLList()
	{
		m_pTail = m_pHead = nullptr;
		m_iSize = 0;
	}

	//destructor. Clean up memory used by this list
	~SLList()
	{
		//check if we have any data in our list
		if (m_pHead != nullptr && m_pTail != nullptr)
		{
			TNode<T>* current = m_pHead;

			//as long as we havent found the end
			while (current != nullptr)
			{
				//get the next node and store it in next
				TNode<T>* next = current->GetNext();
				delete current;	//delete the current node
				current = next;	//then go forward
			}

			//set to null
			m_pHead = m_pTail = nullptr;
		}
	}

	//Inserting at the end of the list
	bool Insert(T iData)
	{
		//Create a new Node with the data specified
		TNode<T>* temp = new TNode<T>(iData, nullptr);

		//if start of list doesnt exist
		if (m_pHead == nullptr)
		{
			m_pHead = temp;	//set start and end to new node.
			m_pTail = temp;
			m_iSize++;	//increase our size

			return true;	//return true
		}
		else
		{
			m_pTail->SetNext(temp);	//other wise add it to the end of the list
			m_pTail = m_pTail->GetNext();	//move the tail reference to the end
			m_iSize++;	//increase size

			return true;	//return true
		}

		return false;	//failed
	}

	//Remove first node in list
	void RemoveFirst()
	{
		//as long as we have something in our list
		if (m_pHead != nullptr && m_pTail != nullptr)
		{
			TNode<T>* temp = m_pHead;	//store the start in a temp var
			m_pHead = m_pHead->GetNext();	//move the start reference node to the next node available
			delete temp;	//delete temp node
			temp = nullptr;	//set to null
			m_iSize--;
		}
	}

	//Removes last node in list
	void RemoveLast()
	{
		if (m_pHead != nullptr && m_pTail != nullptr)
		{
			TNode<T>* temp = m_pHead;

			while (temp->GetNext() != m_pTail)
			{
				temp = temp->GetNext();
			}

			//we should have the 2nd to last node in temp by now
			delete m_pTail;
			m_pTail = temp;
			m_pTail->SetNext(nullptr);
			m_iSize--;
		}
	}

	//removes node specified
	bool RemoveAt(T iData)
	{
		if (m_pHead != nullptr && m_pTail != nullptr)
		{
			TNode<T>* next = m_pHead->GetNext();
			TNode<T>* current = m_pHead;

			while (current != nullptr)
			{
				if (current->GetData() != iData)
				{
					current = next;
					next = next->GetNext();
				}
				else
				{
					break;
				}
			}

			if (next != nullptr)
			{
				current->SetNext(next->GetNext());
				delete next;
				next = nullptr;
			}
			else
			{
				delete current;
				current = nullptr;
				m_pTail = nullptr;

				if (m_iSize == 1)
				{
					m_pHead = nullptr;
				}
			}

			m_iSize--;

			return true;
		}

		return false;
	}

	//Finds a node specified and returns it
	TNode<T>* Find(T iData) const
	{
		if (m_pHead != nullptr && m_pTail != nullptr)
		{
			for (TNode<T>* temp = m_pHead; temp != nullptr; temp = temp->GetNext())
			{
				if (temp->GetData() == iData)
				{
					return temp;
				}
			}
		}

		return nullptr;
	}

	//Prints contents of the list
	void Print()
	{
		if (m_pHead != nullptr && m_pTail != nullptr)
		{
			for (TNode<T>* temp = m_pHead; temp != nullptr; temp = temp->GetNext())
			{
				temp->Display();
			}
		}
	}

	TNode<T>* GetHead() const
	{
		if (m_pHead)
		{
			return m_pHead;
		}
		
		return nullptr;
	}

private:
	TNode<T>* m_pHead, *m_pTail;	//references to the start and end nodes of the list
	int m_iSize;	//size of the list
};

#endif