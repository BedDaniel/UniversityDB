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
    void updateDatabase(std::string DbFile);
    void addStudent();
    void addStudent(const Student & s);
    std::vector<Student> getStudents();
    void display();
    Student createNewStudent(std::string student);

    void searchByLastName();
    int searchByLastName(std::string lastName);

    void searchByPesel();
    int searchByPesel(std::string pesel);

    void sortByPesel();
    void sortByLastName();

    void deleteByIndex();
    void deleteByIndex(std::string index);
    
    int getAmountOfStudents();
private:
    std::vector<Student> students_;
};

