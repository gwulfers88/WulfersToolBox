/*	This program shows the basic use of the Queue.

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

// FIFO Structure or First In First Out Structure.
// A queue can be considered to be a line at a grocery place or at the movie theatre or anywhere where there is a line.
// It is a first come first server idea.

#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode
{
	int value;
	QueueNode *next;
};

class Queue
{
public:
	//Initializer (Constructor)
	Queue()
	{
		tail = head = 0;
	}

	~Queue()
	{
		//check if we are empty
		if (head)
		{
			//store head on current node
			QueueNode* current = head;

			//Loop while we havent reached the end of the stack
			while (current != nullptr)
			{
				//Store the next pointer in next
				QueueNode* next = current->next;
				delete current;	//deletes current node
				current = next;	//set current to next
			}

			head = nullptr;
		}
	}

	//Pushes items into the Queue
	void Enqueue(int newVal)
	{
		QueueNode* newNode = new QueueNode();
		newNode->value = newVal;
		newNode->next = 0;

		if (!head)
		{
			head = newNode;
			tail = head;
		}
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
	}

	//Removes items from the Queue
	void Dequeue()
	{
		QueueNode* deletedNode = 0;
		
		if (head)
		{
			if (head->next)
			{
				deletedNode = head;
				head = head->next;

				delete deletedNode;

				return;
			}
		}
	}

	// returning the current value of the Queue
	int Peek()
	{
		if (head)
		{
			return head->value;
		}
	}

private:
	QueueNode* head;
	QueueNode* tail;
};

#endif