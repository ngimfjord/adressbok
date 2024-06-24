#pragma once

#include <cstring>
#include <iomanip>

#include "Entry.h"

struct Book
{
public:
	void List();
	void Sort(bool should_sort_by_last_name);
	void Display(int index);
	bool AddEntry();
	void DeleteEntry(int index);
private:
	Entry entries[100];
};