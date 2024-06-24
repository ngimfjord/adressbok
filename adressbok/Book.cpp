#include "Book.h"

void Book::List()
{
	std::cout << "---LIST OF CONTACTS---" << std::endl;

	for (int i = 0; i < 100; i++)
	{
		// Är kontaktkortet aktivt skriver vi ut det tillsammans med dess index
		if (entries[i].is_active)
		{
			std::cout << std::setw(2) << i << std::setw(20) << entries[i].last_name << ", " << entries[i].first_name << std::endl;
		}
	}
}

void Book::Sort(bool should_sort_by_last_name)
{
	// Följande är en alfabetisk bubbelsortering

	Entry temporary{};
	Entry temporary_list[100];

	for (int i = 0; i < 99; i++)
	{
		for (int j = 0; j < 99; j++)
		{
			// Vi jämför kontakternas namn.
			if (
				(entries[j].last_name.compare(entries[j + 1].last_name) > 0 && should_sort_by_last_name) ||
				(entries[j].first_name.compare(entries[j + 1].first_name) > 0 && !should_sort_by_last_name)
				)
			{
				// Vi byter plats på kontakterna
				temporary = entries[j + 1];
				entries[j + 1] = entries[j];
				entries[j] = temporary;
			}
		}
	}

	/*
	Eftersom tomma kontakter har tomma namn hamnar de högst upp i listan. '' har ett lägre "värde" än 'a' 
	
	Vi kan göra en ny omgång av bubbelsortering. Om programmet inte hade
	tillåtit tomma namn på kontakterna hade vi lätt kunnat kapa av listan, men
	på grund av att man inte alltid vet säg för eller efternamn för en person
	måste vi sortera.
	*/

	for (int i = 0; i < 99; i++)
	{
		for (int j = 0; j < 99; j++)
		{
			// Vi jämför kontakternas namn.
			if (!entries[j].is_active && entries[j+1].is_active)
			{
				// Vi byter plats på kontakterna
				temporary = entries[j + 1];
				entries[j + 1] = entries[j];
				entries[j] = temporary;
			}
		}
	}

}

void Book::Display(int index)
{
	// Kontrollerar om kontaktkortet används
	if (!entries[index].is_active)
	{
		std::cout << "The index is not currently in use" << std::endl;
		return;
	}

	// Vi visar kontaktkortets fält
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
		Om platsen inte är upptagen utför vi Edit() som frågar användaren vilket
		namn telefonnummer och email som ska läggas till. Då användaren kanske
		inte har kännedom om detta finns även alternativet att lämna alla eller
		några fält blanka.
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

	// OBS - är indexet över 100 får vi problem, detta regleras i main().
	if (!entries[index].is_active)
	{
		std::cout << "The index is not currently in use" << std::endl;
		return;
	}

	// Tömmer kontaktkortet och sätter is_active till falskt.
	entries[index].Empty();
	return;
}

