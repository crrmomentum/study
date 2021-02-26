
//#include <iostream>
#include <string>
class ContactData {

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
