#include "contactdata.h"
#include <string>

ContactData::ContactData(const std::string& name, const std::string& last_name, const std::string& email, const std::string& phone_number) {
	_name = name; 
	_phone_number.assign(phone_number);
	_email.assign(email);
	_last_name.assign(last_name);

}