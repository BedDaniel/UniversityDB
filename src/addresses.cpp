#include "addresses.hpp"
#include <regex>

Address::Address() {}

Address::Address(const std::string street,
                 const std::string houseNumber,
                 const std::string flatNumber,
                 const std::string city,
                 const std::string postCode,
                 const std::string province,
                 const std::string country) 
        :   street_(street), houseNumber_(houseNumber), flatNumber_(flatNumber), city_(city),
            postCode_(postCode), province_(province), country_(country) 
        {}
std::string Address::getStreet() const { return street_; }
std::string Address::getHouseNumber() const { return houseNumber_; }
std::string Address::getFlatNumber() const { return flatNumber_; }
std::string Address::getCity() const { return city_; }
std::string Address::getPostCode() const { return postCode_; }
std::string Address::getProvince() const { return province_; }
std::string Address::getCountry() const { return country_; }

std::string Address::getAddress() const {
    std::string completeAddress;

    if(flatNumber_.empty())
    {
        completeAddress += street_ + " " + houseNumber_ + '\n';
    }
    else
    {
        completeAddress += street_ + " " + houseNumber_ + "/" + flatNumber_ + '\n';
    }
    completeAddress += postCode_ + " " + city_ + '\n' + province_ + " " + country_ + '\n';

    return completeAddress;
}

std::string Address::toString(){
    return this -> street_ + ";" +
           this -> houseNumber_ + ";" +
           this -> flatNumber_ + ";" +
           this -> postCode_ + ";" +
           this -> city_ + ";" +
           this -> province_ + ";" +
           this -> country_ + ";";
}

std::string Address::getStreetFromUser(){
    std::string street;
    std::cout << "Enter the street name: "; std::cin >> street;
    return street;
}
std::string Address::getHouseNumberFromUser(){
    std::string house;
    std::cout << "Enter the house number: "; std::cin >> house;
    return house;
}
std::string Address::getFlatNumberFromUser(){
    std::string flat;
    std::cout << "Enter the flat number: "; std::cin >> flat;
    return flat;
}
std::string Address::getpostCodeFromUser(){
    std::string post;
    std::cout << "Enter the postcode number: "; std::cin >> post;
    bool isCorrect = isPostCodeCorrect(post);
    while(!isCorrect)
    {
        std::cout << "Provided postcode is incorrect.\nTry XX-XXX format.";
        std::cin >> post;
        isCorrect = isPostCodeCorrect(post);
    }
    return post;
}

std::string Address::getCityFromUser(){
    std::string city;
    std::cout << "Enter the city: "; std::cin >> city;
    return city;
}
std::string Address::getProvinceFromUser(){
    std::string province;
    std::cout << "Enter the province: "; std::cin >> province;
    return province;
}
std::string Address::getCountryFromUser(){
    std::string country;
    std::cout << "Enter the flat number: "; std::cin >> country;
    return country;
}

bool Address::isPostCodeCorrect(const std::string & postCode){
    std::regex postCodeRegex(R"(\d{2}-\d{3})");
    return std::regex_match(postCode, postCodeRegex);
}

void Address::initializeDataFromUser(){
    this->street_ = getStreetFromUser();
    this->houseNumber_ = getHouseNumberFromUser();
    this->flatNumber_ = getFlatNumberFromUser();
    this->postCode_ = getpostCodeFromUser();
    this->city_ = getCityFromUser();
    this->province_ = getProvinceFromUser();
    this->country_ = getCountryFromUser();
}