#ifndef DATA_H
#define DATA_H
#include <string>
#include <iostream>

bool is_char(char c);
void to_upper(char &ch);

class Data
{
public:
    void update_name();
    void update_surname();
    void update_number();
    void update_email();

    // setters
    bool set_name(const std::string &str);
    bool set_surname(const std::string &str);
    bool set_email(const std::string &email);
    bool set_number(const std::string &phoneNumber);
    void set_id(int i) { _id = i; }

    // getters
    std::string get_name() const { return _name; }
    std::string get_surname() const { return _surname; }
    std::string get_email() const { return _email; }
    std::string get_number() const { return _number; }
    int get_id() const { return _id; }

    //
    void print() const
    {
        std::cout << "id:" << _id << "  ";
        std::cout << _name << " " << _surname << " " << _number << " " << _email << "\n";
    }

private:
    std::string _name;
    std::string _surname;
    std::string _email;
    std::string _number;
    int _id;
};

void Data::update_name()
{
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    to_upper(name[0]);
    while (!set_name(name))
    {
        std::cout << "invalid name Enter name again :)\n ";
        std::cin >> name;
    }
}
void Data::update_surname()
{
    std::string surname;
    std::cout << "Enter surname: ";
    std::cin >> surname;
    to_upper(surname[0]);
    while (!set_surname(surname))
    {
        std::cout << "invalid surname Enter surname again :)\n ";
        std::cin >> surname;
    }
}
void Data::update_number()
{
    std::string number;
    std::cout << "Enter number: ";
    std::cin >> number;
    while (!set_number(number))
    {
        std::cout << "invalid number: Enter number again (0XXXXXXXX) :)\n";
        std::cin >> number;
    }
}
void Data::update_email()
{
    std::string e;
    std::cout << "Enter email: ";
    std::cin >> e;
    while (!set_email(e))
    {
        std::cout << "invalid email: Enter email again :)\n";
        std::cin >> e;
    }
}

bool Data::set_name(const std::string &str)
{
    if (str.empty() || str.length() > 32)
    {
        return false;
    }
    for (int i = 0; i < str.length(); ++i)
    {
        if (!is_char(str[i]))
        {
            return false;
        }
    }
    _name = str;
    return true;
};
bool Data::set_surname(const std::string &str)
{
    if (str.empty() || str.length() > 32)
    {
        return false;
    }
    for (int i = 0; i < str.length(); ++i)
    {
        if (!is_char(str[i]))
        {
            return false;
        }
    }
    _surname = str;
    return true;
};
bool Data::set_email(const std::string &email)
{
    int valid1 = 0;
    int valid2 = 0;
    if (!is_char(email[0]))
    {
        return 0;
    }
    for (int i = 0; i < email.length(); ++i)
    {
        if (email[i] == ' ')
        {
            return false;
        }
        if (email[i] == '@')
        {
            valid1++;
        }
        if (valid1 > 0 && email[i] == '.')
        {
            if (!is_char(email[i + 1]) || !is_char(email[i + 2]))
            {
                return false;
            }
            valid2++;
        }
    }
    // std::cout << "valid1: " << valid1 << "  valid2: " << valid2 << "\n";
    if (valid1 != 1 || valid2 != 1)
    {
        return false;
    }
    _email = email;
    return true;
};
bool Data::set_number(const std::string &phoneNumber)
{
    if (phoneNumber.length() != 9 || phoneNumber[0] != '0')
    {
        return false;
    }
    for (int i = 1; i < 9; ++i)
    {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
        {
            return false;
        }
    }
    _number = phoneNumber;
    return true;
};

bool is_char(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
void to_upper(char &ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        ch -= 'a' - 'A';
    }
}

#endif