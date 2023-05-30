#ifndef GLOBALPARA_H
#define GLOBALPARA_H

#include <string>
#include "errorCode.h"
#include "ini/SimpleIni.h"

const std::string PARA_FILE_PATH = "./server_setting.ini";
const std::string DATABASE_NAME = "AppData_db";

class GlobalPara
{
public:
    static GlobalPara* GetInstance();

    std::string GetServerAddr();
    int GetServerPort();
    std::string GetMysqlAddr();
    std::string GetMysqlUserName();
    std::string GetMysqlUserPassword();

private:
    ExeStatus Init();
    GlobalPara();
    CSimpleIniA m_Ini;
    std::string m_ServerAddr;
    int m_ServerPort;
    std::string m_MysqlAddr;
    std::string m_MysqlUserName;
    std::string m_MysqlUserPassword;

};


#endif