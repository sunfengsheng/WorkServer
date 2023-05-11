#ifndef USER_H
#define USER_H

#include "../util/errorCode.h"
#include "../functionSql/sql_struct.hpp"
#include <string>

class User
{
public:
    User();
    ExeStatus UserRegister(std::string WXId, std::string UserName);
    ExeStatus GetUserInfo(std::string WXId, user_info& info);
    bool IsUserRegister(std::string WXId);
    
private:
    
};
#endif