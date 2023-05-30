#ifndef USERINFOHANDLER_H
#define USERINFOHANDLER_H

#include "oatpp/web/server/HttpRequestHandler.hpp"
#include "../json_struct/test.hpp"
#include "../function/user.h"
#include "../functionSql/sql_struct.hpp"
#include <iostream>

#define O_UNUSED(x) (void)x;

class UserInfoHandler : public oatpp::web::server::HttpRequestHandler 
{

public:
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest> &request) override {
        auto wxid = request.get()->getQueryParameter("WXId");
        User user;
        if(!user.IsUserRegister(wxid))
        {
            user.UserRegister(wxid, wxid);
        }
        user_info info;
        user.GetUserInfo(wxid, info);

        auto userInfoObj = RespUserInfo::createShared();
        userInfoObj.get()->WXId = info.WXId;
        userInfoObj.get()->Name = info.Name;
        userInfoObj.get()->AttentionCount = info.AttentionCount;
        userInfoObj.get()->LikeCount = info.LikeCount;

        auto mapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        auto data = mapper.get()->writeToString(userInfoObj);

        auto resp = ResponseFactory::createResponse(Status::CODE_200, data.get()->c_str());
        resp.get()->putHeader("Content-Type", "application/json");
        resp.get()->putHeader("Access-Control-Allow-Origin", "*");

        std::cout<<std::string(wxid)<<std::endl;
        return resp;
    }

private:

};

#endif