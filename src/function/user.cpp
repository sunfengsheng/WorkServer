#include "user.h"
#include "../functionSql/sql_control.hpp"

User::User()
{

}
ExeStatus User::UserRegister(std::string WXId, std::string UserName)
{
    user_info userInfo = {0, WXId, UserName, 0, 0, 0, ""};
    auto ret = SqlControl::GetInstance()->GetMysqlHandler()->insert(userInfo);
    if(ret == 0)
        return ExeStatus::User_RegisterFailed;
    return ExeStatus::Exe_Success;
}
ExeStatus User::GetUserInfo(std::string WXId, user_info& info)
{
    auto userInfoResult = SqlControl::GetInstance()->GetMysqlHandler()->query(FID(user_info::WXId), "=", WXId);
    if(userInfoResult.size() == 0)
        return ExeStatus::User_GetUserInfoFailrd;
    for(auto it_userInfoResult : userInfoResult)
    {
        info.WXId = it_userInfoResult.WXId;
        info.Name = it_userInfoResult.Name;
        info.AttentionCount = it_userInfoResult.AttentionCount;
        info.LikeCount = it_userInfoResult.LikeCount;
    }
    return ExeStatus::Exe_Success;

}
bool User::IsUserRegister(std::string WXId)
{
    auto userInfoResult = SqlControl::GetInstance()->GetMysqlHandler()->query(FID(user_info::WXId), "=", WXId);
    if(userInfoResult.size() == 0)
        return false;
    return true;
}