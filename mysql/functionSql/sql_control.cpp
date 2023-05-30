#include "sql_control.hpp"
#include "../util/globalPara.h"
#include "sql_struct.hpp"

static SqlControl* Mysql_instance;
SqlControl* SqlControl::GetInstance() 
{
    if(Mysql_instance == nullptr) 
        Mysql_instance = new SqlControl();
    return Mysql_instance;
}

SqlControl::SqlControl()
{
    Init();
}

ExeStatus SqlControl::Init()
{

    ormpp_key key{"Id"};
    ormpp_not_null not_null{{"Id"}};
    ormpp_auto_key auto_key{"Id"};

    bool ret = m_Mysql.connect(GlobalPara::GetInstance()->GetMysqlAddr().c_str(), GlobalPara::GetInstance()->GetMysqlUserName().c_str(),
                                GlobalPara::GetInstance()->GetMysqlUserPassword().c_str(), DATABASE_NAME.c_str());
    m_Mysql.create_datatable<user_info>(auto_key, not_null);
    if(!ret)
        return Mysql_ConnectFailed;

    return ExeStatus::Exe_Success;
}

dbng<mysql>* SqlControl::GetMysqlHandler()
{
    return &m_Mysql;
}