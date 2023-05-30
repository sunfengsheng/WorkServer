#ifndef HANDLER_H
#define HANDLER_H

#include "oatpp/web/server/HttpRequestHandler.hpp"
#include "oatpp/network/tcp/client/ConnectionProvider.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp-openssl/client/ConnectionProvider.hpp"
#include "oatpp-openssl/Config.hpp"
#include <iostream>

#define O_UNUSED(x) (void)x;


// 自定义请求处理程序
class Handler : public oatpp::web::server::HttpRequestHandler {
public:
    // 处理传入的请求，并返回响应
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest> &request) override {
        std::cout<< "fffffff" << std::endl;

        // auto config = oatpp::openssl::Config::createShared();
        auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared(
            {"api.weixin.qq.com", 80});
        oatpp::web::client::HttpRequestExecutor executor(connectionProvider);

        auto response = executor.execute("GET", "sns/jscode2session?appid=wxf6a6ecbd6fe1ddd9&secret=SECRET&js_code=JSCODE&grant_type=authorization_code ", oatpp::web::protocol::http::Headers({}), nullptr, nullptr);



        std::cout<<*response.get()->readBodyToString()<<std::endl;

        auto img = oatpp::String::loadFromFile("./test.jpg");
        auto respo = ResponseFactory::createResponse(Status::CODE_200, img);
        respo.get()->putHeader(Header::CONTENT_TYPE, "image/jpeg");
        respo.get()->putHeader("Access-Control-Allow-Origin", "*");
        return respo;
    }
};

#endif // HANDLER_H