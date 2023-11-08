#pragma once
#include <iostream>
#include <string>

class Address {
public:
    Address();
    Address(const std::string street,
            const std::string houseNumber,
            const std::string city,
            const std::string postCode,
            const std::string country,
            const std::string flatNumber = "",
            const std::string province = "");

    std::string getStreet() const;
    std::string getHouseNumber() const;
    std::string getFlatNumber() const;
    std::string getCity() const;
    std::string getPostCode() const;
    std::string getProvince() const;
    std::string getCountry() const;

    std::string getAddress() const;
    std::string toString();

    bool isPostCodeCorrect(const std::string & postCode);
    void initializeDataFromUser();

private:
    std::string street_;
    std::string houseNumber_;
    std::string flatNumber_;
    std::string city_;
    std::string postCode_;
    std::string province_;
    std::string country_;

    std::string getStreetFromUser();
    std::string getHouseNumberFromUser();
    std::string getFlatNumberFromUser();
    std::string getCityFromUser();
    std::string getpostCodeFromUser();
    std::string getProvinceFromUser();
    std::string getCountryFromUser();

};