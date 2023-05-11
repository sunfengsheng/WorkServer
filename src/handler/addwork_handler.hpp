#ifndef ADDWORKHANDLER_H
#define ADDWORKHANDLER_H

#include "oatpp/web/server/HttpRequestHandler.hpp"
#include "../json_struct/test.hpp"
#include <iostream>

#define O_UNUSED(x) (void)x;

// 自定义请求处理程序
class AddWorkHandler : public oatpp::web::server::HttpRequestHandler {
public:
    // 处理传入的请求，并返回响应
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest> &request) override {
        O_UNUSED(request);
        auto test1 = Test::createShared();
        test1.get()->field_int32 = 12;
        test1.get()->field_string = "test";

        auto mapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        auto data = mapper.get()->writeToString(test1);

        auto p = ResponseFactory::createResponse(Status::CODE_200, data.get()->c_str());
        p.get()->putHeader("Content-Type", "application/json");
        p.get()->putHeader("Access-Control-Allow-Origin", "*");
        return p;
    }
};

#endif