#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Contact.hpp"
#include "Macro.hpp"


class PhoneBook {
	private:
		Contact _contacts[TABLE_SIZE];
		int		_count;
		int		_index;

		void _printSearchContact(Contact contact);
		void _printTable(std::string str);
		

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void add(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNumber,
			std::string darkestSecret
		);
		void search(int index);
		void printAllContacts(void);
		int getContactsCount(void);
};

#endif