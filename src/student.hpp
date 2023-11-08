#pragma once
#include <iostream>
#include <string>
#include "addresses.hpp"

enum class Gender{
    Male,
    Female,
    Unknown
};

class Student{
public:
    Student();
    Student(std::string student);

    Student(const std::string & name,
            const std::string & lastName, 
            const Address & address, 
            std::string indexNumber, 
            const std::string pesel, 
            Gender gender);

    std::string getFirstName() const;
    std::string getLastName() const;
    Address getAddress() const;
    std::string getIndexNumber() const;
    std::string getPesel() const;
    Gender getGender() const;

    std::string getGenderString() const;
    bool isPeselCorrect(const std::string pesel);
    bool isGenderCorrect(const std::string & gender);

    void setFirstName(const std::string & firstName);
    void setLastName(const std::string & lastName);
    void setAddress(const Address & address);
    void setIndexNumber(const std::string indexNumber);
    void setPesel(const std::string & pesel);
    void setGender(Gender & gender);

    std::string getDescripionOfStudent() const;
    std::string toString();
    void initializeDataFromUser();

private:
    std::string name_;
    std::string lastName_;
    Address address_;
    std::string indexNumber_;
    std::string pesel_;
    Gender gender_;

    std::string getFirstNameFromUser();
    std::string getLastNameFromUser();
    std::string getIdFromUser();
    std::string getPeselFromUser();
    std::string getIndexNumberFromUser();
    Gender getGenderFromUser();
};

