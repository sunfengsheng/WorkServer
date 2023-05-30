#ifndef SQLSTRUCT_H
#define SQLSTRUCT_H

#include <string>

#include "MysqlOrm/dbng.hpp"
#include "MysqlOrm/entity.hpp"
#include "MysqlOrm/iguana/reflection.hpp"
#include "MysqlOrm/type_mapping.hpp"

struct user_info
{
    int Id;
    std::string WXId;
    std::string Name;
    int PhoneNum;
    int AttentionCount;
    int LikeCount;
    std::string CollectWorkIds; 
};
REFLECTION(user_info, Id, WXId, Name, PhoneNum, AttentionCount, LikeCount, CollectWorkIds)


#endif