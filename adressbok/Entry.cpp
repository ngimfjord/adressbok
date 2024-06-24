#include "Entry.h"

Entry::Entry()
{
    /* 
    Det �r kutym men skitsamma att initiera f�ljande v�rden, eftersom vi inte
    kallar p� structen om den inte �r aktiv.
    */

    first_name = "";
    last_name = "";
    phone_number = "";
    email = "";

    // S�kerst�ller att alla kontaktkort �r oaktiverade fr�n b�rjan.
    is_active = false;
}

void Entry::Empty()
{
    // Ej n�dv�ndigt men kutym
    first_name = "";
    last_name = "";
    phone_number = "";
    email = "";

    // S�kerst�ller att kortet inte visas och kan redigeras p� nytt
    is_active = false;
}

bool Entry::Edit()
{
    /*
    F�ljande varning g�r vi d�rf�r att endast namn visas tillsammans med
    indexet som objektet kontrolleras med. Dessutom g�r det f�r n�rvarande
    endast att sortera med f�r eller efternamn.
    */
    std::cout << "Note: All fields are optional. Entry of either first or last name is highly advised." << std::endl;

    /* 
    Funktionen getline() g�r att f�lten f�r best� av flera ord, till skillnad
    fr�n cin. Dock m�ste vi f�rst t�mma funktionen som annars skulle skicka
    tillbaka skr�p och hoppas �ver.
    */
    std::string junk;
    std::getline(std::cin, junk);

    // Vi fr�gar anv�ndaren ett f�lt i taget. 
    std::cout << "Please enter the given name: " << std::endl;
    std::getline(std::cin, first_name);
    std::cout << "Please enter the family name: " << std::endl;
    std::getline(std::cin, last_name);
    std::cout << "Please enter the phone number: " << std::endl;
    std::getline(std::cin, phone_number);
    std::cout << "Please enter the email: " << std::endl;
    std::getline(std::cin, email);
    return false;
}
