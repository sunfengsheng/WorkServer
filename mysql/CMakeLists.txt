set(APPNAME mysql-server)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    "../3rd/oatpp"
    "../3rd/oatpp-openssl"
    "/usr/include/mysql"
)

file(GLOB_RECURSE FILES_OATPP
    ${CMAKE_CURRENT_SOURCE_DIR}/util/*.cpp
    *.cpp
)

link_directories(/usr/lib64/mysql)

add_executable(${APPNAME} ${FILES_OATPP})

target_link_libraries(${APPNAME} PRIVATE oatpp 
                        PUBLIC mysqlclient pthread dl ssl crypto resolv m rt)

