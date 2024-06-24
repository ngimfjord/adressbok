#include <iostream>

#include "Book.h"

int main()
{
	Book book;
	int input = 0;

	while (true)
	{
		// Menyn
		std::cout << std::endl;
		std::cout << "-----MAIN-MENU-----" << std::endl;
		std::cout << "Please make your choice below" << std::endl;
		std::cout << "[1] List contacts & indexes" << std::endl;
		std::cout << "[2] Sort contacts" << std::endl;
		std::cout << "[3] Display contact" << std::endl;
		std::cout << "[4] Add new contact" << std::endl;
		std::cout << "[5] Remove contact" << std::endl;

		/*
		Följand loop kontrollerar dels om cin har kunnat konverteras till int
		och dels att värdet på variabeln. Detta säkerställer att användaren
		skrivit in en siffra mellan och inklusive 1 och 5.
		*/

		while ((!(std::cin >> input)) || (input < 1) || (input > 5))
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			std::cout << "Invalid entry" << std::endl;
		}

		switch (input)
		{
		case 1:

			book.List();
			break;

		case 2:

			std::cout << "Sort by:" << std::endl;
			std::cout << "[1] Last name" << std::endl;
			std::cout << "[2] First name" << std::endl;

			while (!(std::cin >> input) || input < 1 || input > 2)
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "Invalid entry" << std::endl;
			}

			switch (input)
			{

			case 1:

				// Sorterar listan efter efternamn
				book.Sort(true);
				break;

			case 2:

				// Sorterar adressboken efter förnamn
				book.Sort(false);
			}

			break;

		case 3:

			// Vi frågar användaren vilket index som ska visas.

			std::cout << "Enter index" << std::endl;

			while (!(std::cin >> input) || input < 0 || input > 99)
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "Invalid entry" << std::endl;
			}

			book.Display(input);

			break;

		case 4:

			// Lägger till ett nytt "kontaktkort", se Book.cpp

			if (!book.AddEntry())
			{
				std::cout << "Something went wrong, the address book might be full" << std::endl;
			}

			break;

		case 5:

			// Vi frågar användaren vilket index som ska tas bort

			std::cout << "Enter index" << std::endl;

			while (!(std::cin >> input) || input < 0 || input > 99)
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');

				std::cout << "Invalid entry" << std::endl;
			}

			book.DeleteEntry(input);

			break;
		}
	}
}