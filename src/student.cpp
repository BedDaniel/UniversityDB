#include "student.hpp"
#include <vector>
#include <sstream>

Student::Student(){}

Student::Student(std::string student) {
    std::vector<std::string> properties;
    std::stringstream ss(student);
    std::string property;

    while(std::getline(ss, property, ';'))
    {
        properties.push_back(property);
    }
    Gender gender = Gender::Unknown;

    if(properties[4] == "Male")
    {
        gender = Gender::Male;
    }
    else if(properties[4] == "Female")
    {
        gender = Gender::Female;
    }
 
    
    Address address(properties[5],
                    properties[6],
                    properties[7],
                    properties[8],
                    properties[9],
                    properties[10],
                    properties[11]);
    this->name_ = properties[0];
    this->lastName_ = properties[1];
    this->indexNumber_ = properties[2];
    this->pesel_ = properties[3];
    this->address_ = address;
    this->gender_ = gender; }

Student::Student(const std::string & name,
                 const std::string & lastName, 
                 const Address & address, 
                 int indexNumber, 
                 std::string pesel, 
                 Gender gender) 
        : name_(name), lastName_(lastName), address_(address), indexNumber_(indexNumber), pesel_(pesel), gender_(gender) {}
  
std::string Student::getFirstName() const   { return name_; }
std::string Student::getLastName() const    { return lastName_; }
Address     Student::getAddress() const     { return address_; }
std::string Student::getIndexNumber() const { return indexNumber_; }
std::string Student::getPesel() const       { return pesel_; }
Gender      Student::getGender() const      { return gender_; }

void Student::setFirstName(const std::string & name)        { name_ = name; }
void Student::setLastName(const std::string & lastName)     {lastName_ = lastName;}
void Student::setAddress(const Address & address)           { address_ = address;}
void Student::setIndexNumber(const std::string indexNumber) { indexNumber_ = indexNumber; }
void Student::setPesel(const std::string & pesel)           { pesel_ = pesel; }
void Student::setGender(Gender & gender)                    { gender_ = gender; }

std::string Student::getGenderString() const {
    if(gender_ == Gender::Male)        { return "Male"; }
    else if(gender_ == Gender::Female) { return "Female"; }
    else                               { return "Unknown"; }
}

std::string Student::getDescripionOfStudent() const {
    std::stringstream ss;
    ss << "==================================================\n";
    ss << "Name: " << name_ << " " << "Surname: " << lastName_ << '\n';
    ss << "Address: " << address_.getAddress() << '\n';
    ss << "Index number: " << indexNumber_ << '\n';
    ss << "PESEL: " << pesel_ << '\n';
    ss << "Gender: " << getGenderString() << '\n';
    ss << "==================================================\n";
    return ss.str();
}

std::string Student::getFirstNameFromUser(){
    std::string name;
    std::cout << "Enter student's name: "; std::cin >> name;
    return name;
}
std::string Student::getLastNameFromUser(){
    std::string lastName;
    std::cout << "Enter student's surname: "; std::cin >> lastName;
    return lastName;
}
std::string Student::getIdFromUser(){
    std::string indexNumber;
    std::cout << "Enter student's index number: "; std::cin >> indexNumber;
    return indexNumber;
}
std::string Student::getPeselFromUser(){
    std::string pesel;
    std::cout << "Enter student's PESEL: "; std::cin >> pesel;
    return pesel;
}

bool Student::isGenderCorrect(const std::string & gender){
    if(gender == "F" or gender == "M" or gender == "f" or gender == "m") { return true; }
    else { return false; }

}
Gender Student::getGenderFromUser(){
    std::string gender;
    std::cout << "Enter student's gender (F/M): "; std::cin >> gender;
    bool isGenderEnterCorrect = isGenderCorrect(gender);
    
    while(!isGenderEnterCorrect)
    {

    }
    
 //   bool isGenderC
}

