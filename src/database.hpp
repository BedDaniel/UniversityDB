#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "student.hpp"

class Database{
public:
    Database();
    Database(std::string DbFile);
    ~Database();

    void showMenu();
    void initializeDatabase(std::string DbFile);

    
    void add(const Student & s);
    void display() const;
    int getAmountOfStudents();
    std::string show() const;
    void displayDb();
    Student addNewStudent();
    std::string searchByLastName(std::string lastName);
    std::string searchByPesel(std::string pesel);
    void sortByPesel();
    void sortByLastName();
    void deleteByIndex(int index);

private:
    std::vector<Student> students_;
};

