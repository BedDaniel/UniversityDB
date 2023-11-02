#pragma once
#include <vector>
#include "student.hpp"

class Database{
public:
    void add(const Student & s);
    void display() const;
    std::string show() const;
    std::string searchByLastName(std::string lastName);
    std::string searchByPesel(std::string pesel);
    void sortByPesel();

private:
    std::vector<Student> students_;
};

