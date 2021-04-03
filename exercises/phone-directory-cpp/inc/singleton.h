#pragma once
#include<iostream>
#include<map>
#include "contactdata.h"

class Singleton_Organizer {
private:
    Singleton_Organizer();    
    Singleton_Organizer(const Singleton_Organizer&) = delete;
    std::map<int, ContactData*> map;
    int _id = 0;

public:
    /*Getting singleton instance*/
    static Singleton_Organizer& get_organizer();

    void create_contact(const std::string& name, const std::string& last_name, const std::string& email, const std::string& phone_number);

    bool delete_contact(int id);

    void display_contacts(void);
};