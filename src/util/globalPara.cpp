#include "globalPara.h"

static GlobalPara* m_Instance = nullptr;

GlobalPara* GlobalPara::GetInstance() 
{
	if(m_Instance == nullptr) 
		m_Instance = new GlobalPara();
	return m_Instance;
}

GlobalPara::GlobalPara()
{
    Init();
}

ExeStatus GlobalPara::Init()
{
	SI_Error rc = m_Ini.LoadFile(PARA_FILE_PATH.c_str());
	if (rc < 0) { return ExeStatus::Para_FileNotExist;}

    m_ServerAddr = m_Ini.GetValue("server", "addr");
    if(m_ServerAddr.empty())
        return Para_ServerAddrNotExist;
    m_ServerPort = atoi(std::string(m_Ini.GetValue("server", "port")).c_str());
    if(std::string(m_Ini.GetValue("server", "port")).empty())
        return Para_SercerPortNotExist;
    m_MysqlAddr = m_Ini.GetValue("mysql", "addr");
    if(m_MysqlAddr.empty())
        return Para_MysqlAddrNotExist;
    m_MysqlUserName = m_Ini.GetValue("mysql", "username");
    if(m_MysqlUserName.empty())
        return Para_MysqlUserNameNotExist;
    m_MysqlUserPassword = m_Ini.GetValue("mysql", "password");
    if(m_MysqlUserPassword.empty())
        return Para_MysqlUserPassWordNotExist;

    return ExeStatus::Exe_Success;
}

std::string GlobalPara::GetServerAddr()
{
    return m_ServerAddr;
}
int GlobalPara::GetServerPort()
{
    return m_ServerPort;
}
std::string GlobalPara::GetMysqlAddr()
{
    return m_MysqlAddr;
}
std::string GlobalPara::GetMysqlUserName()
{
    return m_MysqlUserName;
}
std::string GlobalPara::GetMysqlUserPassword()
{
    return m_MysqlUserPassword;
}