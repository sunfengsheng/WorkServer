#ifndef HANDLER_H
#define HANDLER_H

#include "oatpp/web/server/HttpRequestHandler.hpp"
#include <iostream>

#define O_UNUSED(x) (void)x;

// 自定义请求处理程序
class Handler : public oatpp::web::server::HttpRequestHandler {
public:
    // 处理传入的请求，并返回响应
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest> &request) override {
        std::cout<< "fffffff" << std::endl;

        auto img = oatpp::String::loadFromFile("./test.jpg");
        auto respo = ResponseFactory::createResponse(Status::CODE_200, img);
        respo.get()->putHeader(Header::CONTENT_TYPE, "image/jpeg");
        respo.get()->putHeader("Access-Control-Allow-Origin", "*");
        return respo;
    }
};

#endif // HANDLER_H