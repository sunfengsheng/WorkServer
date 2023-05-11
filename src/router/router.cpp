#include "router.hpp"

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/network/Server.hpp"
#include "handler/handler.h"
#include "handler/addwork_handler.hpp"
#include "handler/userinfo_handler.hpp"
#include "../util/globalPara.h"

#include <iostream>
#include <string>

Router::Router()
{

}

bool Router::Start()
{
    oatpp::base::Environment::init();
        // 为 HTTP 请求创建路由器
    auto router = oatpp::web::server::HttpRouter::createShared();

    // 路由 GET - "/hello" 请求到处理程序
    router->route("GET", "/hello", std::make_shared<Handler>());
    router->route("POST", "/addwork", std::make_shared<AddWorkHandler>());
    router->route("GET", "/userinfo", std::make_shared<UserInfoHandler>());

    // 创建 HTTP 连接处理程序
    auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

    // 创建 TCP 连接提供者
    auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared(
            {GlobalPara::GetInstance()->GetServerAddr().c_str(), GlobalPara::GetInstance()->GetServerPort(), oatpp::network::Address::IP_4});

    // 创建服务器，它接受提供的 TCP 连接并将其传递给 HTTP 连接处理程序
    oatpp::network::Server server(connectionProvider, connectionHandler);

    // 打印服务器端口
    OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

    // 运行服务器
    server.run();
    oatpp::base::Environment::destroy();
}