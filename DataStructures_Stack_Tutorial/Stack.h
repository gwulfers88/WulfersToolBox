/*	This program shows the basic use of a stack Data Structure.

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

#pragma once

#include "TNode.h"

template <class T>
class Stack
{
public:
	//Constructor sets up default values for your variables
	Stack()
		: m_pHead(nullptr),
		m_iSize(0)
	{
	}

	//Destructor clear and return memory back to the OS
	~Stack()
	{
		//Call clear()
		Clear();
	}

	//Inserts data into the top of the stack
	void Push(T _data)
	{
		TNode<T>* temp = new TNode<T>(_data, nullptr);

		//Check to see if the stack is empty or not
		if (m_pHead)
		{
			//if it is not empty
			temp->SetNext(m_pHead);

			//Set head to temp
			m_pHead = temp;

			m_iSize++;
		}
		else
		{
			m_pHead = temp;
			m_iSize++;
		}
	}

	//Removes the top most data from the Stack
	void Pop()
	{
		if (m_pHead)
		{
			//Store top element in temp
			TNode<T>* temp = m_pHead;

			//go to the next node on the stack
			m_pHead = m_pHead->GetNext();

			//delete the node
			delete temp;

			//decrease size
			m_iSize--;
		}
	}

	//Returns the top most data of the stack
	T Peek()
	{
		return m_pHead->GetData();
	}

	//Returns true if empty, flase if not empty
	bool IsEmpty()
	{
		//if is empty
		if (m_iSize == 0 && !m_pHead)
		{
			return true;	//return true
		}

		//otherwise, false
		return false;
	}

	//Clears up the remaining data from the Stack 
	void Clear()
	{
		//check if we are empty
		if (m_pHead)
		{
			//store head on current node
			TNode<T>* current = m_pHead;

			//Loop while we havent reached the end of the stack
			while (current != nullptr)
			{
				//Store the next pointer in next
				TNode<T>* next = current->GetNext();
				delete current;	//deletes current node
				current = next;	//set current to next
				m_iSize--;	//decrease size of stack
			}

			m_pHead = nullptr;
		}
	}

	//returns size of stack
	int GetSize()
	{
		return m_iSize;
	}

private:
	TNode<T>* m_pHead;
	int m_iSize;
};