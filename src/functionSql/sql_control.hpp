#ifndef SQLCONTROL_H
#define SQLCONTROL_H

#include "../util/ini/SimpleIni.h"
#include "../util/errorCode.h"

#include "MysqlOrm/dbng.hpp"
#include "MysqlOrm/mysql.hpp"
#include "MysqlOrm/entity.hpp"
#include "MysqlOrm/iguana/reflection.hpp"
#include "MysqlOrm/type_mapping.hpp"

using namespace ormpp;

class SqlControl
{

public:
    static SqlControl* GetInstance();
    dbng<mysql>* GetMysqlHandler();

private:
    SqlControl();
    ExeStatus Init();
    ~SqlControl();
    dbng<mysql> m_Mysql;
};

#endif