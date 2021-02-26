#include "../header/singleton.h"
#include "../header/contactdata.h"
#include<iostream> 
#include<map>


int main(void) 
{ 

    int option=0,id=0;
    bool found;
    /*ToDo Singleton Organizer*/
    /*Organizer org;*/
    Singleton_Organizer& org = Singleton_Organizer::get_organizer();
    std::string name, last_name,  email, phone_number;
 
    do { 

        std::cout << "Phone Directory\n"; 
        std::cout << "Select an option:\n\n";
        std::cout << "1. New contact\n\n"; 
        std::cout << "2. Display contacts\n\n"; 
        std::cout << "3. Delete Contact\n\n"; 
        std::cout << "4. Exit\n\n"; 
        std::cout << "Option:"; 
        std::cin >> option; 

  
        switch (option) 
        { 

        case 1:
            system("clear");
            std::cout << "Name:"; 
            std::cin >> name; 
            std::cout << "Last Name:"; 
            std::cin >> last_name; 
            std::cout << "Email:"; 
            std::cin >> email; 
            std::cout << "Phone Number:"; 
            std::cin >> phone_number; 
            org.create_contact(name,last_name,email,phone_number);
            std::cout << "New contact saved successfully";
            
            break;
            
        case 2:
            system("clear");
            org.display_contacts();
            
            break;
        
        case 3:
            system("clear");
            std::cout << "Id to detele?:"<< std::endl; 
            std::cin >> id; 
            found = org.delete_contact(id);
            if(found)
                std::cout << "Contact with ID:" << id << "has been deleted" << std::endl;
            else
            {
                std::cout << "Contact with ID:" << id << "wasn't found" << std::endl;
            }
            
        }

    } while (option != 4); 

} 