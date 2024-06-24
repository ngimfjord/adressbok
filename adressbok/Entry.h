#pragma once

#include <iostream>

#include <string>

struct Entry
{
public:
	Entry();

	void Empty();

	bool is_active;

	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string email;

	bool Edit();
};