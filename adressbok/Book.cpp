#include "Book.h"

void Book::List()
{
	std::cout << "---LIST OF CONTACTS---" << std::endl;

	for (int i = 0; i < 100; i++)
	{
		// �r kontaktkortet aktivt skriver vi ut det tillsammans med dess index
		if (entries[i].is_active)
		{
			std::cout << std::setw(2) << i << std::setw(20) << entries[i].last_name << ", " << entries[i].first_name << std::endl;
		}
	}
}

void Book::Sort(bool should_sort_by_last_name)
{
	// F�ljande �r en alfabetisk bubbelsortering

	Entry temporary{};
	Entry temporary_list[100];

	for (int i = 0; i < 99; i++)
	{
		for (int j = 0; j < 99; j++)
		{
			// Vi j�mf�r kontakternas namn.
			if (
				(entries[j].last_name.compare(entries[j + 1].last_name) > 0 && should_sort_by_last_name) ||
				(entries[j].first_name.compare(entries[j + 1].first_name) > 0 && !should_sort_by_last_name)
				)
			{
				// Vi byter plats p� kontakterna
				temporary = entries[j + 1];
				entries[j + 1] = entries[j];
				entries[j] = temporary;
			}
		}
	}

	/*
	Eftersom tomma kontakter har tomma namn hamnar de h�gst upp i listan. '' har ett l�gre "v�rde" �n 'a' 
	
	Vi kan g�ra en ny omg�ng av bubbelsortering. Om programmet inte hade
	till�tit tomma namn p� kontakterna hade vi l�tt kunnat kapa av listan, men
	p� grund av att man inte alltid vet s�g f�r eller efternamn f�r en person
	m�ste vi sortera.
	*/

	for (int i = 0; i < 99; i++)
	{
		for (int j = 0; j < 99; j++)
		{
			// Vi j�mf�r kontakternas namn.
			if (!entries[j].is_active && entries[j+1].is_active)
			{
				// Vi byter plats p� kontakterna
				temporary = entries[j + 1];
				entries[j + 1] = entries[j];
				entries[j] = temporary;
			}
		}
	}

}

void Book::Display(int index)
{
	// Kontrollerar om kontaktkortet anv�nds
	if (!entries[index].is_active)
	{
		std::cout << "The index is not currently in use" << std::endl;
		return;
	}

	// Vi visar kontaktkortets f�lt
	std::cout << "Name:  " << entries[index].first_name << ' ' << entries[index].last_name << std::endl;
	std::cout << "Phone: " << entries[index].phone_number << std::endl;
	std::cout << "Email: " << entries[index].email << std::endl;
}

bool Book::AddEntry()
{
	// Vi itererar genom varje plats i registret

	for (int i = 0; i < 100; i++)
	{

		/* 
		Om platsen inte �r upptagen utf�r vi Edit() som fr�gar anv�ndaren vilket
		namn telefonnummer och email som ska l�ggas till. D� anv�ndaren kanske
		inte har k�nnedom om detta finns �ven alternativet att l�mna alla eller
		n�gra f�lt blanka.
		*/
		if (!entries[i].is_active)
		{
			entries[i].Edit();
			entries[i].is_active = true;
			return true;
		}
	}
	return false;
}

void Book::DeleteEntry(int index)
{

	// OBS - �r indexet �ver 100 f�r vi problem, detta regleras i main().
	if (!entries[index].is_active)
	{
		std::cout << "The index is not currently in use" << std::endl;
		return;
	}

	// T�mmer kontaktkortet och s�tter is_active till falskt.
	entries[index].Empty();
	return;
}

