#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
    public:
        // Constructor
        Contact();
        // Destructor
        ~Contact();
        // Setters
        int set_first_name(std::string first_name);
        int set_last_name(std::string last_name);
        int set_nickname(std::string nickname);
        int set_phone_number(std::string phone_number);
        int set_darkest_secret(std::string darkest_secret);
        // Getters
        std::string get_first_name() const;
        std::string get_last_name() const;
        std::string get_nickname() const;
        std::string get_phone_number() const;
        std::string get_darkest_secret() const;
};

#endif