#include <iostream>
#include <fstream>
#include "addresses.h"

std::string FILENAME = "addressData.csv";

void commands_table(Addresses &b);
bool init_from_file(Addresses &b);
bool save_in_file(const Addresses &b);
void search(Addresses &b);
void add_data(Addresses &b);
void select(Addresses &b);
void to_upper(char &ch);

int main()
{

    Addresses myBook;
    init_from_file(myBook);

    commands_table(myBook);

    if (save_in_file(myBook))
    {
        std::cout << "data saved successfully :)\n";
    };
}

void commands_table(Addresses &b)
{
    while (1)
    {
        std::cout << "\n:0: exit \n";
        std::cout << ":1: see all contact information \n";
        std::cout << ":2: search in contact information  \n";
        std::cout << ":3: add new contact information \n";
        std::cout << ":4: select contact with id \n";
        std::cout << ":5: save data in file \n";

        std::cout << "enter comand ";
        int n;
        std::cin >> n;
        std::cout << "\n";
        if (n == 0)
            break;
        switch (n)
        {
        case 1:
            b.print_book();
            break;
        case 2:
            search(b);
            break;
        case 3:
            add_data(b);
            break;
        case 4:
            select(b);
            break;
        case 5:
            if (save_in_file(b))
            {
                std::cout << "data saved successfully :)\n";
            }
            break;
        default:
            std::cout << "command not found :(\n";
            break;
        }
    }
}

bool save_in_file(const Addresses &b)
{
    std::fstream f;

    f.open(FILENAME, std::ios::out);
    if (!f.is_open())
    {
        std::cout << "ERROR: can not open output file\n";
        return false;
    }
    if (!b.save_data_in_file(f))
    {
        f.close();
        return false;
    }
    f.close();
    return true;
}
bool init_from_file(Addresses &b)
{
    std::fstream inputfile;
    inputfile.open(FILENAME, std::ios::in);
    if (!inputfile.is_open())
    {
        std::cerr << "Warning: can not open input file\n";
        return 0;
    }
    b.init_from_file(inputfile);
    inputfile.close();
    return 1;
}
void add_data(Addresses &b)
{
    Data m;
    m.update_name();
    m.update_surname();
    m.update_number();
    m.update_email();
    b.set_data(m);
}

void search(Addresses &b)
{

    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    to_upper(name[0]);

    std::string surname;
    std::cout << "Enter surname: ";
    std::cin.ignore(44, '\n');
    std::cin >> surname;
    to_upper(surname[0]);

    const std::vector<Data> v = b.search(name, surname);
    if (v.empty())
    {
        std::cout << "\nnothing found :(\n";
        return;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        v[i].print();
    }
}
void select(Addresses &b)
{
    int id;
    std::cout << "Enter id ";
    std::cin >> id;
    std::list<Data>::iterator it = b.get_data_with_id(id);
    if (it == b.get_list_end())
    {
        std::cout << "Contact not found with id :(\n";
        return;
    }

    while (1)
    {
        std::cout << std::endl;
        it->print();
        std::cout << "\n:0: go back \n";
        std::cout << ":1: change name \n";
        std::cout << ":2: change surname \n";
        std::cout << ":3: change number \n";
        std::cout << ":4: change email \n";
        std::cout << ":5: delete\n";

        std::cout << "enter comand ";
        int n;
        std::cin >> n;
        std::cout << "\n";

        switch (n)
        {
        case 0:
            return;
        case 1:
            b.update_data(it, data_change_type::name);
            break;
        case 2:
            b.update_data(it, data_change_type::surname);
            break;
        case 3:
            b.update_data(it, data_change_type::number);
            break;
        case 4:
            b.update_data(it, data_change_type::email);
            break;
        case 5:
            b.delete_data(it);
            return;
        default:
            std::cout << "command not found :(\n";
            break;
        }
    }
}
