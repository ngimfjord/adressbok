#include "Entry.h"

Entry::Entry()
{
    /* 
    Det är kutym men skitsamma att initiera följande värden, eftersom vi inte
    kallar på structen om den inte är aktiv.
    */

    first_name = "";
    last_name = "";
    phone_number = "";
    email = "";

    // Säkerställer att alla kontaktkort är oaktiverade från början.
    is_active = false;
}

void Entry::Empty()
{
    // Ej nödvändigt men kutym
    first_name = "";
    last_name = "";
    phone_number = "";
    email = "";

    // Säkerställer att kortet inte visas och kan redigeras på nytt
    is_active = false;
}

bool Entry::Edit()
{
    /*
    Följande varning gör vi därför att endast namn visas tillsammans med
    indexet som objektet kontrolleras med. Dessutom går det för närvarande
    endast att sortera med för eller efternamn.
    */
    std::cout << "Note: All fields are optional. Entry of either first or last name is highly advised." << std::endl;

    /* 
    Funktionen getline() gör att fälten får bestå av flera ord, till skillnad
    från cin. Dock måste vi först tömma funktionen som annars skulle skicka
    tillbaka skräp och hoppas över.
    */
    std::string junk;
    std::getline(std::cin, junk);

    // Vi frågar användaren ett fält i taget. 
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
