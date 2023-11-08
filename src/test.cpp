#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"
#include <string>
#include <memory>

struct DatabaseTest : ::testing::Test{
    void SetUp() override {
    database = std::make_unique<Database>("db-ut.txt");
    address1 = Address("Krakowska", "15", "37", "Cracow", "30-123", "malopolskie","Poland");
    address2 = Address("Warszawska", "25", "7", "Warsaw", "39-369", "mazowieckie","Poland");
    address3 = Address("Wadowicka", "5", "62", "Lublin", "31-369", "lubelskie","Poland");

    student1 = Student("Andrzej", "Nowak", address1, "123456", "84122557437", Gender::Male);
    student2 = Student("Aleksandra", "Kowalska", address2, "446688", "59041444173", Gender::Female);
    student3 = Student("Michal", "Wisniewski", address3, "24680", "55041613872", Gender::Male);

    }
    std::unique_ptr<Database> database;
    Address address1, address2, address3;
    Student student1, student2, student3;
    
};

TEST_F(DatabaseTest, CheckingNumberOfStudents){
    EXPECT_EQ(database->getAmountOfStudents(), 0);

    database->addStudent(student1);
    EXPECT_EQ(database->getAmountOfStudents(), 1);

    database->addStudent(student2);
    EXPECT_EQ(database->getAmountOfStudents(), 2);
}

TEST_F(DatabaseTest, SearchByPeselTest){
    database->addStudent(student1);
    database->addStudent(student2);

    EXPECT_EQ(database->searchByPesel("84122557437"), 1);
    EXPECT_EQ(database->searchByPesel("59041444173"), 1);
    EXPECT_EQ(database->searchByPesel("55041613872"), 0);

}

TEST_F(DatabaseTest, SortByPeselTest){
    database->addStudent(student1);
    database->addStudent(student2);
    database->addStudent(student3);
    database->sortByPesel();
    std::vector<Student> sortedStudents = database->getStudents();

    for (size_t i = 0; i < sortedStudents.size() - 1; ++i) {
        EXPECT_LE(std::stoll(sortedStudents[i].getPesel()), std::stoll(sortedStudents[i + 1].getPesel()));
    }
}

TEST_F(DatabaseTest, SortBySurnameTest){
    database->addStudent(student1);
    database->addStudent(student2);
    database->addStudent(student3);
    database->sortByLastName();
    std::vector<Student> sortedStudents = database->getStudents();

    for (size_t i = 0; i < sortedStudents.size() - 1; ++i) {
        EXPECT_LE(sortedStudents[i].getLastName(), sortedStudents[i + 1].getLastName());
    }
}

TEST_F(DatabaseTest, DeleteByIndexNumberTest){
    database->addStudent(student1);
    database->addStudent(student2);
    EXPECT_EQ(database->getAmountOfStudents(), 2);

    database->deleteByIndex("123456");
    EXPECT_EQ(database->getAmountOfStudents(), 1);
}

TEST_F(DatabaseTest, AddressInitializationTest){
    Address address1("Krakowska", "15", "37", "Cracow", "30-123", "malopolskie","Poland");
    Address address2("Warszawska", "25", "7", "Warsaw", "39-369", "mazowieckie","Poland");

    EXPECT_EQ(address1.getStreet(), "Krakowska");
    EXPECT_EQ(address1.getHouseNumber(), "15"); 
    EXPECT_EQ(address1.getFlatNumber(), "37"); 
    EXPECT_EQ(address1.getPostCode(), "30-123"); 
    EXPECT_EQ(address1.getCity(), "Cracow"); 
    EXPECT_EQ(address1.getProvince(), "malopolskie"); 
    EXPECT_EQ(address1.getCountry(), "Poland");

    EXPECT_EQ(address2.getStreet(), "Warszawska");
    EXPECT_EQ(address2.getHouseNumber(), "25"); 
    EXPECT_EQ(address2.getFlatNumber(), "7"); 
    EXPECT_EQ(address2.getPostCode(), "39-369"); 
    EXPECT_EQ(address2.getCity(), "Warsaw"); 
    EXPECT_EQ(address2.getProvince(), "mazowieckie"); 
    EXPECT_EQ(address2.getCountry(), "Poland");
}

TEST_F(DatabaseTest, getAddressTest){
    Address address1("Krakowska", "15", "37", "Cracow", "30-123", "malopolskie","Poland");
    Address address2("Warszawska", "25", "7", "Warsaw", "39-369", "mazowieckie","Poland");

    std::string address1test = address1.getAddress();
    std::string expectedAddress = "Krakowska 15/37\n30-123 Cracow\nmalopolskie Poland\n";

    EXPECT_EQ(address1test, expectedAddress);
}

TEST_F(DatabaseTest, isPostCodeCorrectTest){
    Address address1("Krakowska", "15", "37", "Cracow", "30-123", "malopolskie","Poland");

    EXPECT_TRUE(address1.isPostCodeCorrect("30-123"));
    EXPECT_TRUE(address1.isPostCodeCorrect("12-345"));
    EXPECT_TRUE(address1.isPostCodeCorrect("00-000"));
    EXPECT_TRUE(address1.isPostCodeCorrect("99-999"));

    EXPECT_FALSE(address1.isPostCodeCorrect("12-1234"));
    EXPECT_FALSE(address1.isPostCodeCorrect("125-152"));
    EXPECT_FALSE(address1.isPostCodeCorrect("123-12"));
    EXPECT_FALSE(address1.isPostCodeCorrect("1-1"));
    EXPECT_FALSE(address1.isPostCodeCorrect("12-1"));
    EXPECT_FALSE(address1.isPostCodeCorrect("12-15"));
    EXPECT_FALSE(address1.isPostCodeCorrect("aa-bcd"));
    EXPECT_FALSE(address1.isPostCodeCorrect("12-bcd"));
}

TEST_F(DatabaseTest, toStringTest){
    address1 = Address("Krakowska", "15", "37", "Cracow", "30-123", "malopolskie","Poland");
    student1 = Student("Andrzej", "Nowak", address1, "123456", "84122557437", Gender::Male);
    std::string student1String = student1.toString();
    Student testStudent(student1String);

    EXPECT_EQ(testStudent.getFirstName(), "Andrzej");
    EXPECT_EQ(testStudent.getLastName(), "Nowak");
    EXPECT_EQ(testStudent.getAddress().getStreet(), "Krakowska");
    EXPECT_EQ(testStudent.getIndexNumber(), "123456");
    EXPECT_EQ(testStudent.getPesel(), "84122557437");
    EXPECT_EQ(testStudent.getGender(), Gender::Male);
}

TEST_F(DatabaseTest, GetGenderStringTest) {
    Student maleStudent;
    Gender maleGender = Gender::Male;
    maleStudent.setGender(maleGender);
    EXPECT_EQ(maleStudent.getGenderString(), "Male");

    Student femaleStudent;
    Gender femaleGender = Gender::Female; 
    femaleStudent.setGender(femaleGender);
    EXPECT_EQ(femaleStudent.getGenderString(), "Female");

    Student unknownStudent;
    Gender unknownGender = Gender::Unknown;
    unknownStudent.setGender(unknownGender);
    EXPECT_EQ(unknownStudent.getGenderString(), "Unknown");
}

TEST_F(DatabaseTest, studentStringCreatorTest){
    std::string testStudent = "Andrzej;Nowak;12345;61122888279;Male;Szeroka;10;Konin;44-444;Poland;12;gdziestam";
    Student student(testStudent);

    EXPECT_EQ(student.getFirstName(), "Andrzej");
    EXPECT_EQ(student.getLastName(), "Nowak");
    EXPECT_EQ(student.getAddress().getStreet(), "Szeroka");
    EXPECT_EQ(student.getIndexNumber(), "12345");
    EXPECT_EQ(student.getPesel(), "61122888279");
    EXPECT_EQ(student.getGender(), Gender::Male);
}