#ifndef UPLOADWORKHANDLER_H
#define UPLOADWORKHANDLER_H

#include "oatpp/web/server/HttpRequestHandler.hpp"
#include "../json_struct/test.hpp"
#include "../functionSql/sql_struct.hpp"
#include <iostream>

#define O_UNUSED(x) (void)x;

class UploadWorkHandler : public oatpp::web::server::HttpRequestHandler
{
public:
    std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest> &request) override {

        

        auto resp = ResponseFactory::createResponse(Status::CODE_200, data.get()->c_str());
        resp.get()->putHeader("Content-Type", "application/json");
        resp.get()->putHeader("Access-Control-Allow-Origin", "*");
        return resp;
    }
};

#endif