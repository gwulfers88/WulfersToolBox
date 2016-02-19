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

#include "SLList.h"

#include <iostream>
#include <string>

enum MenuState
{
	MAIN = 0,
	INSERT,
	DELETE,
	SEARCH,
	PRINT,
	EXIT
};

MenuState currentState = MenuState::MAIN;
bool isRunning = true;

void Menu();
void Insert();
void Delete();
void Search();
void Print();
void Exit();

void Pause();

SLList<string>* list = new SLList<string>();

int main()
{
	while (isRunning)
	{
		switch (currentState)
		{
		case MenuState::MAIN:
		{
			Menu();
		}break;

		case MenuState::INSERT:
		{
			Insert();

		}break;

		case MenuState::DELETE:
		{
			Delete();
		}break;

		case MenuState::SEARCH:
		{
			Search();
		}break;

		case MenuState::PRINT:
		{
			Print();
		}break;

		case MenuState::EXIT:
		{
			Exit();
		}break;

		default:
			break;
		}
	}

	if (list)
	{
		delete list;
	}

	return 0;
}

void Menu()
{
	std::cout << "\t*** Name List Program ***\n"
		"\n\tWhat would like to do?\n"
		"\t1. Insert Name.\n"
		"\t2. Delete Name.\n"
		"\t3. Search Name.\n"
		"\t4. Print List.\n"
		"\t5. Exit Program.\n";
	
	int iChoice;
	std::cin >> iChoice;

	switch (iChoice)
	{
		case MenuState::INSERT:
		{
			currentState = MenuState::INSERT;
		}break;

		case MenuState::DELETE:
		{
			currentState = MenuState::DELETE;
		}break;

		case MenuState::SEARCH:
		{
			currentState = MenuState::SEARCH;
		}break;

		case MenuState::PRINT:
		{
			currentState = MenuState::PRINT;
		}break;

		case MenuState::EXIT:
		{
			currentState = MenuState::EXIT;
		}break;
	}

}

void Insert()
{
	cout << "\t*** INSERT ***\n\n"
		"\tPlease enter a name to add to the list: ";
	string tempName;

	cin >> tempName;

	if (tempName != " ")
	{
		list->Insert(tempName);
	}
	else
	{
		cout << "Sorry, name is not valid. Please make sure it is two or mote characters long.\n";
		Pause();

		return;
	}

	currentState = MenuState::MAIN;
}

void Delete()
{
	cout << "\t*** Delete ***\n\n"
		"\tPlease enter a name to delete from the list: ";
	string tempName;

	cin >> tempName;

	if (tempName != " ")
	{
		TNode<string>* temp = list->Find(tempName);

		if (temp)
		{
			list->RemoveAt(temp->GetData());
			
			cout << tempName << " succesfully removed from list.\n";
			Pause();

		}
		else
		{
			cout << "Sorry, Name specified was not found in list.\n";
			Pause();
		}
	}
	else
	{
		cout << "Sorry, name is not valid. Please make sure it is two or mote characters long.\n";
		Pause();

		return;
	}

	currentState = MenuState::MAIN;
}

void Search()
{
	cout << "\t*** Search ***\n\n"
		"\tPlease enter a name to search for in the list: ";
	string tempName;

	cin >> tempName;

	if (tempName != " ")
	{
		TNode<string>* temp = list->Find(tempName);

		if (temp)
		{
			cout << tempName << " is in this list.\n";
			Pause();

		}
		else
		{
			cout << "Sorry, Name specified was not found in list.\n";
			Pause();
		}
	}
	else
	{
		cout << "Sorry, name is not valid. Please make sure it is two or mote characters long.\n";
		Pause();

		return;
	}

	currentState = MenuState::MAIN;
}

void Print()
{
	cout << "\nPrinting Name List:\n";
	
	list->Print();

	Pause();

	currentState = MenuState::MAIN;
}

void Exit()
{
	isRunning = false;

	std::cout << "Thank you for using this program!\n";

	Pause();
		
}

void Pause()
{
	cout << "Press any key to continue. ";

	char tmp = 0;

	std::cin >> tmp;
}