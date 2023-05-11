

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    "../3rd"
    "/usr/include/mysql"
)

file(GLOB_RECURSE FILES_OATPP
    ${CMAKE_CURRENT_SOURCE_DIR}/util/*.cpp
    *.cpp
)

link_directories(/usr/lib64/mysql)


add_executable(test ${FILES_OATPP})

target_link_libraries(test PRIVATE oatpp 
                        PUBLIC mysqlclient pthread dl ssl crypto resolv m rt)