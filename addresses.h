#ifndef Addresses_H
#define Addresses_H
#include "data.h"
#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <vector>

enum class data_change_type
{
    name,
    surname,
    number,
    email
};

std::vector<std::string> split(const std::string &str);

class Addresses
{
public:
    void init_from_file(std::fstream &file);

    //
    void delete_data(std::list<Data>::iterator);
    void update_data(std::list<Data>::iterator el, data_change_type L);

    // getters
    std::list<Data>::iterator get_data_with_id(int id);
    std::vector<Data> search(std::string name, std::string surname) const;
    std::list<Data>::iterator get_list_end() { return book.end(); }

    // setters
    bool save_data_in_file(std::fstream &file) const;
    void set_data(Data &d);

    //
    void print_book() const;

private:
    std::list<Data> book;
    int id = 1;
};

void Addresses::init_from_file(std::fstream &file)
{
    int index = 0;
    std::string fileLine;
    while (getline(file, fileLine))
    {
        if (fileLine.empty())
        {
            continue;
        }
        index++;
        std::vector<std::string> lineData = split(fileLine);
        if (lineData.size() != 4)
        {
            std::cout << "in line:" << index << " The amount of data does not match\n";
            continue;
        }
        Data d;
        if (!d.set_name(lineData[0]))
        {
            std::cout << "in line:" << index << " name is invalid!\n";

            continue;
        }
        if (!d.set_surname(lineData[1]))
        {
            std::cout << "in line:" << index << " surname is invalid!\n";
            continue;
        }
        if (!d.set_number(lineData[2]))
        {
            std::cout << "in line:" << index << " ( " << lineData[2] << " ) number is invalid! | update or remove Addres |(U/R): ";
            char a;
            std::cin >> a;
            to_upper(a);
            if (a == 'U')
            {
                d.update_number();
            }
            else
            {
                continue;
            }
        }
        if (!d.set_email(lineData[3]))
        {
            std::cout << "in line:" << index << " ( " << lineData[3] << " ) email is invalid! | update or remove Addres |(U/R): ";
            char a;
            std::cin >> a;
            to_upper(a);
            if (a == 'U')
            {
                d.update_email();
            }
            else
            {
                continue;
            }
        }
        d.set_id(id++);
        book.push_back(d);
    }
}

std::vector<Data> Addresses::search(std::string name, std::string surname) const
{
    std::vector<Data> v;
    if (book.empty())
    {
        return v;
    }
    for (auto it = book.begin(); it != book.end(); ++it)
    {
        if (it->get_name() == name || it->get_surname() == surname)
        {
            v.push_back(*it);
        }
    }
    return v;
}

void Addresses::print_book() const
{
    if (book.empty())
    {
        std::cout << "no addresses :(\n";
        return;
    }
    for (auto it = book.begin(); it != book.end(); ++it)
    {
        it->print();
    }
}

std::list<Data>::iterator Addresses::get_data_with_id(int id)
{
    std::list<Data>::iterator it = book.begin();
    while (it != book.end())
    {
        if (it->get_id() == id)
        {
            return it;
        }
        ++it;
    }

    return it;
}

bool Addresses::save_data_in_file(std::fstream &file) const
{
    for (auto it = book.begin(); it != book.end(); ++it)
    {
        file << it->get_name() << ',' << it->get_surname() << ',' << it->get_number() << ',' << it->get_email() << '\n';
    }
    return true;
}
void Addresses::set_data(Data &d)
{
    d.set_id(id++);
    book.push_back(d);
}
void Addresses::delete_data(std::list<Data>::iterator el)
{
    book.erase(el);
}
void Addresses::update_data(std::list<Data>::iterator el, data_change_type L)
{
    switch (L)
    {
    case data_change_type::name:
        el->update_name();
        break;
    case data_change_type::surname:
        el->update_surname();
        break;
    case data_change_type::number:
        el->update_number();
        break;
    case data_change_type::email:
        el->update_email();
        break;
    default:
        break;
    }
}

std::vector<std::string> split(const std::string &str)
{
    std::vector<std::string> ans;
    std::string word;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == ',')
        {
            if (!word.empty())
            {
                ans.push_back(word);
                word.clear();
            }
            continue;
        }
        word.push_back(str[i]);
    }
    ans.push_back(word);
    return ans;
}
#endif