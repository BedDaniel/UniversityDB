#include "database.hpp"
#include <iostream>
#include <string>
#include <algorithm>

void Database::add(const Student & s) {
    students_.push_back(s);
    }

void Database::display() const { 
        std::cout << show();
}
std::string Database::show() const {
    std::string result = "";
    for (auto && student : students_){
        result += student.show();}
    
    return result;
}

std::string Database::searchByLastName(std::string lastName){
    std::string result {"Person with that last name does not exist in database."};

    for(auto student : students_)
    {
    student.getLastName();
    std::cout << student.getLastName() << '\n'; // to bedzie do usuniecia

    if(lastName == student.getLastName()) 
    { 
        result = student.show();
        std::cout << result << '\n';    
    }
    }
    return result;
}

std::string Database::searchByPesel(std::string pesel){
    std::string result {"Person with that PESEL does not exist in database."};

    for(auto student : students_)
    {
    student.getPesel();
    std::cout << student.getPesel() << '\n'; // to bedzie do usuniecia

    if(pesel == student.getPesel()) 
    { 
        result = student.show();
        std::cout << result << '\n';    
    }
    }
    return result;
}

void Database::sortByPesel(){
    std::sort(students_.begin(), students_.end(), 
                [] (Student a, Student b) { 
                return std::stoll(a.getPesel()) < std::stoll(b.getPesel());});
    display();
}
