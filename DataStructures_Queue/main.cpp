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

#include "Queue.h"
#include <iostream>

using namespace std;

Queue q;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		q.Enqueue(i);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "Queue item: " << q.Peek() << endl;		//Get the item to print
		q.Dequeue();	// Removing the item from the queue
	}

	getchar();

	return 0;
}