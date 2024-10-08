#include "phonebook.hpp"

Phonebook::Phonebook()
{
	_nb_contacts = 0;
	std::cout << "\033[1:37;42mPhonebook created.\033[0m" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << std::endl;
	std::cout << "\033[1:37;41mPhonebook destroyed.\033[0m" << std::endl;
}

void Phonebook::add_contact()
{
	int			valid_flag = 0;
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone_number = "";
	std::string darkest_secret = "";

	while (std::cin.good() && (valid_flag == 1 || first_name.empty()))
	{
		valid_flag = 0;
		std::cout << "\033[0;92m -> Enter first name: \033[0m";
		std::getline(std::cin, first_name);
		if (first_name.empty())
			std::cout << "Invalid first name. Please try again." << std::endl;
		else if (_contacts[_nb_contacts % 8].set_first_name(first_name) == 1)
		{
			std::cout << "Invalid first name. Please try again." << std::endl;
			valid_flag = 1;
		}
	}

	while (std::cin.good() && (valid_flag == 1 || last_name.empty()))
	{
		valid_flag = 0;
		std::cout << "\033[0;92m -> Enter last name: \033[0m";
		std::getline(std::cin, last_name);
		if (last_name.empty())
			std::cout << "Invalid last name. Please try again." << std::endl;
		else if (_contacts[_nb_contacts % 8].set_last_name(last_name) == 1)
		{
			std::cout << "Invalid last name. Please try again." << std::endl;
			valid_flag = 1;
		}
	}

	while (std::cin.good() && (valid_flag == 1 || nickname.empty()))
	{
		valid_flag = 0;
		std::cout << "\033[0;92m -> Enter nickname: \033[0m";
		std::getline(std::cin, nickname);
		if (nickname.empty())
			std::cout << "Invalid nickname. Please try again." << std::endl;
		else if (_contacts[_nb_contacts % 8].set_nickname(nickname) == 1)
		{
			std::cout << "Invalid nickname. Please try again." << std::endl;
			valid_flag = 1;
		}
	}

	while (std::cin.good() && (valid_flag == 1 || phone_number.empty()))
	{
		valid_flag = 0;
		std::cout << "\033[0;92m -> Enter phone number: \033[0m";
		std::getline(std::cin, phone_number);
		if (phone_number.empty())
			std::cout << "Invalid phone number. Please try again." << std::endl;
		else if (_contacts[_nb_contacts % 8].set_phone_number(phone_number) == 1)
		{
			std::cout << "Invalid phone number. Please try again." << std::endl;
			valid_flag = 1;
		}
	}

	while (std::cin.good() && (valid_flag == 1 || darkest_secret.empty()))
	{
		valid_flag = 0;
		std::cout << "\033[0;92m -> Enter darkest secret: \033[0m";
		std::getline(std::cin, darkest_secret);
		if (darkest_secret.empty())
			std::cout << "Invalid darkest secret. Empty input." << std::endl;
		_contacts[_nb_contacts % 8].set_darkest_secret(darkest_secret);
	}

	this->_nb_contacts++;
	std::cout << " [Contact added]" << std::endl;
	std::cin.clear();
}

void Phonebook::search_contact()
{
	int			index;
	std::string	input;
	display_contact();
	std::cout << "\033[0;94m -> Enter an index: \033[0m";
	std::cin >> input;
	std::cin.ignore(10000, '\n');
	if (input.length() > 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid index. Exiting to main menu." << std::endl;
		return;
	}
	index = input[0] - '0';
	if (index < 0 || index > 7)
	{
		std::cout << "Invalid index. Exiting to main menu." << std::endl;
		return;
	}
	std::cout << "First Name____: " << _contacts[index].get_first_name() << std::endl;
	std::cout << "Last Name_____: " << _contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname______: " << _contacts[index].get_nickname() << std::endl;
	std::cout << "Phone Number__: " << _contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].get_darkest_secret() << std::endl;
	std::cin.clear();
}

void Phonebook::display_contact()
{
	std::cout << std::endl;
	std::cout << " | | First Name|  Last Name|   Nickname|"
			<< "                                             " << std::endl;
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << " |" << i;
		std::cout << "|" << std::setw(11) << _contacts[i].get_first_name();
		std::cout << "|" << std::setw(11) << _contacts[i].get_last_name();
		std::cout << "|" << std::setw(11) << _contacts[i].get_nickname();
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;
}

void Phonebook::menu_guide(void)
{
	std::cout << std::endl;
	std::cout << "\033[0;93m Phonebook command guide \033[0m" << std::endl;
	std::cout << "  [ADD] [SEARCH] [EXIT]" << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	Phonebook	phonebook;
	std::string	command;

	phonebook.menu_guide();
	std::cout << "\033[0;94m -> Enter a command: \033[0m";
	while (getline(std::cin,command))
	{
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
			break;
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
		std::cout << "\033[0;94m -> Enter a command: \033[0m";
	}
	return (0);
}