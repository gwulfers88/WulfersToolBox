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

#include "Stack.h"

#include <iostream>
#include <Windows.h>

using namespace std;

bool openDelimFound(char symbol)
{
	return (symbol == '(' ||
			symbol == '{' ||
			symbol == '[');
}

bool closeDelimFound(char symbol)
{
	return (symbol == ')' ||
			symbol == '}' ||
			symbol == ']');
}

bool openCloseDelimMatch(char openDelim, char closeDelim)
{
	return ((openDelim == '(' && closeDelim == ')') ||
			(openDelim == '{' && closeDelim == '}') ||
			(openDelim == '[' && closeDelim == ']'));
}

int main()
{
	Stack<char> openDelimStack;

	HANDLE fileHandle = CreateFile("TNode.h", GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0 );
	void *buffer = 0;

	if (fileHandle != INVALID_HANDLE_VALUE)
	{
		LARGE_INTEGER fileSize;
		
		//Get File size of the entire
		GetFileSizeEx(fileHandle, &fileSize);

		buffer = VirtualAlloc(0, fileSize.QuadPart, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		if (buffer)
		{
			DWORD bytesRead;
			//Read entire file into buffer
			if (ReadFile(fileHandle, buffer, fileSize.QuadPart, &bytesRead, 0))
			{
				if (bytesRead == fileSize.QuadPart)
				{

				}
			}
		}

		//close the file
		CloseHandle(fileHandle);
	}

	char* readBuffer = (char*)buffer;

	printf("\n\n%s\n\n", readBuffer);

	bool delimMatched = true;

	while (delimMatched && *readBuffer++)
	{
		//Check if there are any open delimeters (, {, [
		//if there are any, then we are going to add them to the stack.
		if (openDelimFound(*readBuffer))
		{
			openDelimStack.Push(*readBuffer);
		}
		else if (closeDelimFound(*readBuffer))
		{
			//check if there are any closing delimeters ), }, ]
			//make sure that the stack is not empty.
			if (openDelimStack.IsEmpty())
				delimMatched = false;
			else
			{
				//if the stack is not empty then we want to extract the open delimeter and compare it to the closed delimeter to see if they are the same.
				//if they are the same then we continue other wise we get out of the loop.
				char delim = openDelimStack.Peek();
				openDelimStack.Pop();
				delimMatched = openCloseDelimMatch(delim, *readBuffer);
			}
		}
		else
		{
			//if there are any other character that are not delimeters then, we want to ignore them and keep looping.
			delimMatched = true;
		}
	}

	if (delimMatched && openDelimStack.IsEmpty())
	{
		printf("All delimeters matched!\n");
	}
	else
	{
		printf("%d delimeters did not match!\n", openDelimStack.GetSize());
	}

	int i = 0;

	if (buffer)
	{
		//Free the memory at the end
		VirtualFree(buffer, 0, MEM_RELEASE);
	}

	return 0;
}