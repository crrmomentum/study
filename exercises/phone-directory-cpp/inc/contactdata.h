
#include <iostream>
<<<<<<< HEAD:exercises/phone-directory-cpp/inc/contactdata.h
//#include <string>
=======
>>>>>>> 1e31bae3dd15ddaf8de2f36dad9a6d0b457db569:exercises/phone-directory-cpp/header/contactdata.h

class ContactData{

private:
    std::string _name;
    std::string _last_name;
    std::string _email;
    std::string _phone_number;

public:

    ContactData(const std::string& name, const std::string& last_name, const std::string& email, const std::string& phone_number);
    
    std::string get_name(void) {
        return _name;
    }
};
