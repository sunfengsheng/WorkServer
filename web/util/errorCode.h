#ifndef ERRORCODE_H
#define ERRORCODE_H

enum ErrorCode {
    Web_Success = 0,

};

enum ExeStatus{
    Exe_Success = 0,
    Para_FileNotExist = 1,
    Para_ServerAddrNotExist = 2,
    Para_SercerPortNotExist = 3,
    Para_MysqlAddrNotExist = 4,
    Para_MysqlUserNameNotExist = 5,
    Para_MysqlUserPassWordNotExist = 6,

    Mysql_ConnectFailed = 50,


    User_RegisterFailed = 70,
    User_GetUserInfoFailrd = 71,
    User_AlreadyRegister = 72

};

#endif