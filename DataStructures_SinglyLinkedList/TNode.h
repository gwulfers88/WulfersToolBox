/*	This program shows the basic use of a Node used by several Data Structures.

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

#ifndef TNODE_H
#define TNODE_H

#include <iostream>

using namespace std;

template <class T>
class TNode
{
public:
	//Constructor. Initializes variables
	TNode()
	{
		SetData(0);
		SetNext(nullptr);
	}

	//Overloaded Constructor. Initializes variables to specific data being passed
	TNode(T _newData, TNode<T>* _pNewNext)
	{
		SetData(_newData);
		SetNext(_pNewNext);
	}

	//Destructor
	~TNode()
	{

	}

	//returns current data
	T GetData()
	{
		return this->iData;
	}

	//returns node to next pointer
	TNode<T>* GetNext()
	{
		return this->pNext;
	}

	//sets new data
	void SetData(T _newData)
	{
		this->iData = _newData;
	}

	//sets new next node pointer
	void SetNext(TNode<T>* _newNext)
	{
		this->pNext = _newNext;
	}

	//prints out the data.
	void Display()
	{
		cout << "Data: " << GetData() << endl;
	}

private:
	T iData;		//Stores int type data 
	TNode<T>* pNext;	// this is a pointer to our next node in our list.
};

#endif