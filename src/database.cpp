#include "database.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

Database::Database(){
    std::cout << "Welcome!\n";
    initializeDatabase("database.txt");
}

Database::Database(std::string DbFile){
    initializeDatabase(DbFile);
}

Database::~Database() {}

void Database::initializeDatabase(std::string DbFile){
    std::ifstream DatabaseFile(DbFile);
    if(!DatabaseFile.is_open())
    {
  //      std::cerr << "Error! Could not open the file: " << DbFile << "\n\n";
        return;
    }

    std::string line;
    while(std::getline(DatabaseFile, line))
    {
        this->students_.push_back(createNewStudent(line));
    }
    DatabaseFile.close();
}

void Database::updateDatabase(std::string DbFile){
    std::ofstream DatabaseFile(DbFile, std::ios::out | std::ios::trunc);

    if(!DatabaseFile.is_open()){
        std::cerr << "The file cannot be open: " << DbFile << std::endl;
        return;
    }

    std::for_each(this->students_.begin(), this->students_.end(), 
                        [&] (Student & student) { DatabaseFile << student.toString() << '\n';});

    DatabaseFile.close();
}

void Database::display() {
    if(this->students_.empty())
    {
        std::cout << "\nDatabase is empty.\n";
    }
    else
    {
        std::for_each(this->students_.begin(), students_.end(), [](Student & student){ std::cout << student.getDescripionOfStudent();});
    }
}

void Database::addStudent(){
    auto newStudent = Student();
    newStudent.initializeDataFromUser();
    addStudent(newStudent);
}

void Database::addStudent(const Student & s) {
    students_.push_back(s);
    }

std::vector<Student> Database::getStudents(){
    return students_;
}

void Database::searchByLastName(){
    std::string searchedLastName = "";
    std::cout << "Enter the surname you want to find: "; std::cin >> searchedLastName;
    int counter = searchByLastName(searchedLastName);
    if(counter == 0)
    {   
        std::cout << "Database has no record with surname " << searchedLastName << '\n';
    }
    else 
    {
        std::cout << "In database there is " << counter << " people with surname: " << searchedLastName << '\n';
    }
}

int Database::searchByLastName(std::string searchedLastName){
    int counter = 0;
    auto find = [] (const std::vector<Student> & students, int & counter, std::string searchedLastName) {
        std::vector<Student>::const_iterator it = students.cbegin();

        while(it != students.end()){
            it = std::find_if(it, students.cend(), [&] (const Student & s) { return s.getLastName() == searchedLastName;});
            if(it !=students.end())
            {
                std::cout << it->getDescripionOfStudent();
                ++counter;
                ++it;
            }
        }
        std::cout << std::endl;
    };
    find(students_, counter, searchedLastName);
    return counter;
}

void Database::searchByPesel(){
    std::string searchedPesel = "";
    std::cout << "Enter the PESEL you want to find: "; std::cin >> searchedPesel;
    int counter = searchByPesel(searchedPesel);
    if(counter == 0) 
    {
        std::cout << "Database has no record with PESEL: " << searchedPesel << '\n';
    }
    else
    {
        std::cout << "\nIn database there is " << counter << " people with PESEL: " << searchedPesel << '\n';
    }
}

int Database::searchByPesel(std::string pesel){
    int counter = 0;
    auto find = [] (const std::vector<Student> & students, int & counter, std::string pesel){
        std::vector<Student>::const_iterator it = students.cbegin();
        while(it != students.end()){
            it = std::find_if(it, students.cend(), 
                             [&](const Student & s){ return s.getPesel() == pesel; });
        
        if(it != students.end())
        {
            std::cout << it->getDescripionOfStudent();
            ++counter;
            ++it;
        }
        }
    std::cout << std::endl;
    };
    find(students_, counter, pesel);
    return counter;
}

Student Database::createNewStudent(std::string student){
    std::vector<std::string> properties;
    std::stringstream ss(student);
    std::string property;

    while(std::getline(ss, property, ';')){
        properties.push_back(property);
    }
    Gender gender = Gender::Unknown;

    if(properties[4] == "Female")    { gender = Gender::Female; }
    else if(properties[4] == "Male") {gender = Gender::Male; }

    Address address(properties[5],
                    properties[6],
                    properties[7],
                    properties[8],
                    properties[9],
                    properties[10],
                    properties[11]);

    return Student(properties[0],
                   properties[1],
                   address,
                   properties[2],
                   properties[3],
                   gender);
}

void Database::sortByPesel(){
    std::sort(students_.begin(), students_.end(), 
                [] (Student a, Student b) { 
                return std::stoll(a.getPesel()) < std::stoll(b.getPesel());});
    display();
}

void Database::sortByLastName(){
    std::sort(students_.begin(), students_.end(), 
             [](Student & a, Student & b){ return a.getLastName() < b.getLastName();});
    display();
}

void Database::deleteByIndex(){
    std::string index = "";
    std::cout << "\nEnter student's index number you want to delete from database: "; std::cin >> index;
    deleteByIndex(index);
}

void Database::deleteByIndex(std::string index){
    auto it = std::remove_if(students_.begin(), students_.end(), 
                             [&](const Student & student){ return student.getIndexNumber() == index;});
    students_.erase(it, students_.end());
}

int Database::getAmountOfStudents(){
    return students_.size();
}

void Database::showMenu(){
    int option;
    while(true){
        std::cout << "\n===============MENU===============\n";
        std::cout << "1. Add new student\n";
        std::cout << "2. Display the database.\n";
        std::cout << "3. Search by surname\n";
        std::cout << "4. Search by PESEL\n";
        std::cout << "5. Sort by surname\n";
        std::cout << "6. Sort by PESEL\n";
        std::cout << "7. Remove student by index number\n";
        std::cout << "0. Close database\n";
        std::cout << "Select an option: "; std::cin >> option;

        switch(option){
        case 1:
            addStudent();
            break;
        case 2:
            display();
            break;
        case 3:
            searchByLastName();
            break;
        case 4:
            searchByPesel();
            break;
        case 5:
            sortByLastName();
            break;
        case 6:
            sortByPesel();
            break;
        case 7:
            deleteByIndex();
            break;
        case 0:
            updateDatabase("Database.txt");
            std::cout << "\nGoodbye! Have a good day!\n";
            return;
        default:
            std::cout << "\nIncorrect option. Select from 0 to 7.\n";
        }
    }
}






