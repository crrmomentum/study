#include "../header/singleton.h"
#include <iostream>


Singleton_Organizer::Singleton_Organizer()
{
    std::cout << "Creating organizer" << std::endl;
}
    Singleton_Organizer& Singleton_Organizer::get_organizer() {
    std::cout << "Getting organizer from singleton" << std::endl;
    static Singleton_Organizer org;
    return org;
}

void Singleton_Organizer::create_contact(std::string name, std::string last_name, std::string email, std::string phone_number) {
    ContactData* contact = new ContactData(name, last_name, email, phone_number);
    map[_id] = contact;
    ++_id;
}

bool Singleton_Organizer::delete_contact(int id) {
    std::map<int, ContactData*>::iterator it;
    it = map.find(id);
    if (it != map.end()) {
        map.erase(it);
        std::cout << "ID: " << id << "was deleted" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Error: Element not found" << std::endl;
        return false;
    }
}

void Singleton_Organizer::display_contacts(void) {
    std::cout << "Displaying contacts ...";
    for (auto& it : map) {
        std::cout << "The name of the contact for id: " << it.first << " is: " << it.second->get_name() << std::endl;
    }
}