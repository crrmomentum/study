#include<iostream> 
#include<map>

class ContactData { 

private: 

    std::string _name;
    std::string _last_name;
    std::string _email;
    std::string _phone_number;
   
public: 

    ContactData(std::string name, std::string last_name, std::string email, std::string phone_number){
        _name = name;
        _phone_number = phone_number;
        _email = email;
        _last_name = last_name;
    }
    
    std::string get_name(void){
        return _name;
    }
}; 

class Singleton_Organizer {
    private:
        Singleton_Organizer()
        {
            std::cout<<"Creating organizer" << std::endl;
        }
        std::map<int, ContactData*> map;
        std::map<int, ContactData*>::iterator it;
        int _id=0;

    public: 
        /*Getting singleton instance*/
        static Singleton_Organizer& get_organizer(){
            std::cout<<"Getting organizer from singleton"<<std::endl;
            static Singleton_Organizer org;
            return org;
        }

       void create_contact(std::string name, std::string last_name, std::string email, std::string phone_number) {
            ContactData* contact = new ContactData(name,last_name,email,phone_number);  
            map[_id] = contact;
            ++_id;
       }

       bool delete_contact(int id) {
            it = map.find(id);
            if (it != map.end()){
                map.erase (it);   
                std::cout<< "ID: " << id << "was deleted" <<std::endl;
            }
            else
            {
                std::cout<<"Error: Element not found"<<std::endl;
            }
                    
        
       }

       void display_contacts(void) {
            std::cout << "Displaying contacts ...";
           for (auto& it : map) {
               std::cout << "The name of the contact for id: " << it.first << " is: " << it.second->get_name() << std::endl;
            }
       }
    };


int main(void) 
{ 

    int option=0,id=0;
    bool found;
    /*ToDo Singleton Organizer*/
    /*Organizer org;*/
    Singleton_Organizer& org = Singleton_Organizer::get_organizer();
    std::string name, last_name, email, phone_number;
 
    do { 

        std::cout << "Directorio Telefonico\n"; 
        std::cout << "Seleccione una opcion:\n\n";
        std::cout << "1. Agregar Nuevo\n\n"; 
        std::cout << "2. Imprimir contactos\n\n"; 
        std::cout << "3. Eliminar Contacto\n\n"; 
        std::cout << "4. Salir\n\n"; 
        std::cout << "Seleccione:"; 
        std::cin >> option; 

  
        switch (option) 
        { 

        case 1:
            system("clear");
            std::cout << "Nombre:"; 
            std::cin >> name; 
            std::cout << "Apellido:"; 
            std::cin >> last_name; 
            std::cout << "Email:"; 
            std::cin >> email; 
            std::cout << "Telefono:"; 
            std::cin >> phone_number; 
            org.create_contact(name,last_name,email,phone_number);
            std::cout << "Contacto nuevo guardado con exito";
            
            break;
            
        case 2:
            system("clear");
            org.display_contacts();
            
            break;
        
        case 3:
            system("clear");
            std::cout << "Introduce ID a eliminar:"<< std::endl; 
            std::cin >> id; 
            org.delete_contact(id);
            
        }

    } while (option != 4); 

} 