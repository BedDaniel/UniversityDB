#pragma once
#include <string>
#include "address.hpp"

enum class Gender{
    Male,
    Female,
    Unknown
};

class Student{
public:
    Student();
    Student(std::string student);

    Student(std::string name,
            std::string lastName, 
            Address address, 
            std::string indexNumber, 
            std::string pesel, 
            Gender gender);

    std::string getFirstName() const;
    std::string getLastName() const;
    Address getAddress() const;
    std::string getIndexNumber() const;
    std::string getPesel() const;
    Gender getGender() const;

    std::string getGenderString() const;
    bool isPeselCorrect(const std::string & pesel);
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
    Gender getGenderFromUser();
};

