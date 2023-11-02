#include <gtest/gtest.h>
#include "student.hpp"
#include "database.hpp"

struct DatabaseTest : ::testing::Test{
    Database db;
};
TEST_F(DatabaseTest, SortByPesel){
    Student adam{"Adam", "Kowalski", 
    "ul. Dobra 23, 00-200 Warszawa", 
    123456, "12345678912", Gender::Male};
    db.add(adam);
    Student adrian{"Adrian", "Nowak", 
    "ul. Krakowska 13, 01-234 Krakow", 
    234567, "23456789123", Gender::Male};
    db.add(adrian);
    db.sortByPesel();
    
    // EXPECTED_EQ(students_[0] = Student.adam);

}


TEST_F(DatabaseTest, SearchByPesel){
    Student adam{"Adam", "Kowalski", 
    "ul. Dobra 23, 00-200 Warszawa", 
    123456, "12345678912", Gender::Male};
    db.add(adam);

    Student adrian{"Adrian", "Nowak", 
    "ul. Krakowska 13, 01-234 Krakow", 
    234567, "23456789123", Gender::Male};
    db.add(adrian);
    auto result = db.searchByPesel("12345678912");
    auto expected = "Adam Kowalski; ul. Dobra 23, 00-200 Warszawa; 123456; 12345678912; Male";
    EXPECT_EQ(result, expected);

    auto result1 = db.searchByPesel("12345678901");
    auto expected1 = "Person with that PESEL does not exist in database.";
    EXPECT_EQ(result1, expected1);
}



TEST_F(DatabaseTest, SearchByLastName){
    Student adam{"Adam", "Kowalski", 
    "ul. Dobra 23, 00-200 Warszawa", 
    123456, "12345678912", Gender::Male};
    db.add(adam);

    Student adrian{"Adrian", "Nowak", 
    "ul. Krakowska 13, 01-234 Krakow", 
    234567, "23456789123", Gender::Male};
    db.add(adrian);

    auto result = db.searchByLastName("Kowalski");
    auto expected = "Adam Kowalski; ul. Dobra 23, 00-200 Warszawa; 123456; 12345678912; Male";
    EXPECT_EQ(result, expected);

    auto result1 = db.searchByLastName("Nowakowski");
    auto expected1 = "Person with that last name does not exist in database.";
    EXPECT_EQ(result1, expected1); 
    }


// TEST_F(DatabaseTest, SearchByLastName){
//     Student adam{"Adam", "Kowalski", 
//     "ul. Dobra 23, 00-200 Warszawa", 
//     123456, "12345678912", Gender::Male};
//     db.add(adam);
//     auto result = db.searchByLastName("Kowalski");
//     EXPECT_TRUE(result);
// }

// TEST(CheckStructure, CanAddStudentToDb){
//     Student adam{"Adam", "Kowalski", 
//     "ul. Dobra 23, 00-200 Warszawa", 
//     123456, "12345678912", Gender::Male};

//     Database db;
//     EXPECT_TRUE(db.add(adam)); // Check adding the same person twice
// }

TEST_F(DatabaseTest, DisplayEmptyDb){
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);}




TEST_F(DatabaseTest, DisplayNonEmptyDb){
    Student adam{"Adam", "Kowalski", 
    "ul. Dobra 23, 00-200 Warszawa", 
    123456, "12345678912", Gender::Male};
    db.add(adam);

    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 23, 00-200 Warszawa; 123456; 12345678912; Male";
    EXPECT_EQ(content, expected);
}







