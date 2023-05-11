#include <iostream>

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/network/Server.hpp"
#include "handler/handler.h"
#include "json_struct/test.hpp"
#include "router/router.hpp"

void dateInit()
{
    auto test1 = Test::createShared();
    test1->field_string = "fffff";
    auto mapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
    auto p = mapper.get()->writeToString(test1);
    std::cout << *p.get() << std::endl;

}


// void run() {
//     // 为 HTTP 请求创建路由器
//     auto router = oatpp::web::server::HttpRouter::createShared();

//     // 路由 GET - "/hello" 请求到处理程序
//     router->route("POST", "/hello", std::make_shared<Handler>());

//     // 创建 HTTP 连接处理程序
//     auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

//     // 创建 TCP 连接提供者
//     auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared(
//             {"localhost", 8000, oatpp::network::Address::IP_4});

//     // 创建服务器，它接受提供的 TCP 连接并将其传递给 HTTP 连接处理程序
//     oatpp::network::Server server(connectionProvider, connectionHandler);

//     // 打印服务器端口
//     OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

//     // 运行服务器
//     server.run();
// }


int main()
{



    Router router;
    router.Start();
    return 0;
}