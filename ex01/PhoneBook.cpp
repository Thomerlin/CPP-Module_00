#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_count = 0;
	this->_index = 0;
	std::cout << YELLOW << "Opening Phone Book..." << WHITE << std::endl;
	std::cout << GREEN << "Phone Book has been opened" << WHITE << std::endl
			  << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::add(std::string firstName, std::string lastName,
					std::string nickName, std::string phoneNumber,
					std::string darkestSecret)
{
	this->_contacts[this->_index].setFirstName(firstName);
	this->_contacts[this->_index].setLastName(lastName);
	this->_contacts[this->_index].setNickName(nickName);
	this->_contacts[this->_index].setPhoneNumber(phoneNumber);
	this->_contacts[this->_index].setDarkestSecret(darkestSecret);
	if (this->_count < TABLE_SIZE)
		this->_count++;
	this->_index++;
	if (this->_index >= TABLE_SIZE)
		this->_index %= TABLE_SIZE;
}

void PhoneBook::search(int index)
{
	if (index >= 0 && index < this->_count && index < TABLE_SIZE)
	{
		_printSearchContact(this->_contacts[index]);
	}
	else
	{
		std::cout << RED << "Invalid contact index!"  << WHITE << std::endl
				  << std::endl;
	}
}

void PhoneBook::_printTable(std::string str)
{
	if (str.length() > 9)
	{
		std::cout << std::right << std::setw(10) << str.substr(0, 9) + '.';
	}
	else
	{
		std::cout << std::right << std::setw(10) << str;
	}
}

void PhoneBook::printAllContacts(void)
{
	std::cout << "| ";
	std::cout << YELLOW << " INDEX " << WHITE;
	std::cout << " | ";
	std::cout << YELLOW << " FIRST NAME " << WHITE;
	std::cout << " | ";
	std::cout << YELLOW << " LAST NAME " << WHITE;
	std::cout << " | ";
	std::cout << YELLOW << " NICKNAME " << WHITE;
	std::cout << " |";
	std::cout << std::endl;
	std::cout << "-----------------------------------------------------";
	std::cout << std::endl;
	for (int i = 0; i < this->_count; i++)
	{
		std::cout << "| ";
		std::cout << std::right << std::setw(10) << i + 1;
		std::cout << " | ";
		_printTable(this->_contacts[i].getFirstName());
		std::cout << " | ";
		_printTable(this->_contacts[i].getLastName());
		std::cout << " | ";
		_printTable(this->_contacts[i].getNickName());
		std::cout << " |";
		std::cout << std::endl;
		std::cout << "-----------------------------------------------------";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::_printSearchContact(Contact contact)
{
	std::cout << YELLOW << "First Name: " << WHITE << contact.getFirstName() << std::endl;
	std::cout << YELLOW << "Last Name: " << WHITE << contact.getLastName() << std::endl;
	std::cout << YELLOW << "Nickname: " << WHITE << contact.getNickName() << std::endl;
	std::cout << YELLOW << "Phone Number: " << WHITE << contact.getPhoneNumber() << std::endl;
	std::cout << YELLOW << "Darkest Secret: " << WHITE << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

int PhoneBook::getContactsCount(void)
{
	return (this->_count);
}
 