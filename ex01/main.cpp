#include "PhoneBook.hpp"

bool validPhoneNumber(std::string myPhoneNumber)
{
	std::string set = "0123456789";

	if (myPhoneNumber.length() < 8)
	{
		std::cout << RED << "Invalid phone number!" << WHITE << std::endl
				  << std::endl;
		return (false);
	}
	for (std::string::iterator it = myPhoneNumber.begin();
		 it != myPhoneNumber.end(); ++it)
	{
		if (set.find(*it) == std::string::npos)
		{
			std::cout << RED << "Invalid phone number!" << WHITE << std::endl
					  << std::endl;
			return (false);
		}
	}
	return (true);
}

bool validContactField(std::string field, std::string fieldName)
{
	for (std::string::iterator it = field.begin(); it != field.end(); ++it)
	{
		if (!std::isalnum(*it))
		{
			std::cout << fieldName << RED << " field accepts only alphanumeric ascii characters!"  << WHITE << std::endl
					  << std::endl;
			return (false);
		}
	}
	return (true);
}

void addContact(PhoneBook &myPhoneBook)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << YELLOW << "Please input the contact information:" << WHITE << std::endl
			  << std::endl;
	std::cin.ignore();
	std::cout << BLUE << "First Name: " << WHITE;
	std::getline(std::cin, firstName);
	if (!validContactField(firstName, "First Name"))
		return;
	std::cout << BLUE << "Last Name: " << WHITE;
	std::getline(std::cin, lastName);
	if (!validContactField(lastName, "Last Name"))
		return;
	std::cout << BLUE << "Nickname: " << WHITE;
	std::getline(std::cin, nickName);
	if (!validContactField(nickName, "Nickname"))
		return;
	std::cout << BLUE << "Phone Number: " << WHITE;
	std::getline(std::cin, phoneNumber);
	if (!validPhoneNumber(phoneNumber))
		return;
	std::cout << BLUE << "Darkest Secret: " << WHITE;
	std::getline(std::cin, darkestSecret);
	myPhoneBook.add(firstName, lastName, nickName, phoneNumber, darkestSecret);
	std::cout << std::endl;
	std::cout << "Contact " << BLUE << firstName << WHITE << " added to your phonebook." << std::endl
			  << std::endl;
}

void searchContact(PhoneBook myPhoneBook)
{
	std::string option;
	std::stringstream ss;
	int index;

	if (myPhoneBook.getContactsCount() == 0)
	{
		std::cout << YELLOW << "The phonebook is empty!" << WHITE << std::endl
				  << std::endl;
		return;
	}
	myPhoneBook.printAllContacts();
	std::cout << "Please enter the contact index: ", std::cin >> option;
	std::cout << std::endl;
	ss << option;
	ss >> index;
	myPhoneBook.search(index - 1);
}

int main(void)
{
	PhoneBook myPhoneBook;
	std::string option;

	while (1)
	{
		std::cout << WHITE <<"Please choose an option below:" << std::endl;
		std::cout << GREEN << "ADD" << WHITE << ", " YELLOW << "SEARCH" << WHITE " or " << RED << "EXIT" << WHITE << std::endl
				  << std::endl;

		std::cin >> option;
		if (option == "ADD"){
			std::cout << CLEAR;
			addContact(myPhoneBook);
		}
		else if (option == "SEARCH"){
			std::cout << CLEAR;
			searchContact(myPhoneBook);
		}
		else if (option == "EXIT")
		{
			std::cout << CLEAR << std::endl;
			std::cout << YELLOW << "Closing Phone Book..." << WHITE << std::endl;
			std::cout << GREEN << "Phone Book has been closed" << WHITE << std::endl;
			return 0;
		}
		else
			std::cout << CLEAR << RED << "Invalid Command!" << WHITE << std::endl;
	}
}