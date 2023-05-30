
set(APPNAME web)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    "../3rd/oatpp"
    "../3rd/oatpp-openssl"
    "/usr/include/mysql"
)

file(GLOB_RECURSE FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/util/*.cpp
    *.cpp
)

link_directories(/usr/local/openssl/lib)


add_executable(${APPNAME} ${FILES})


target_link_libraries(${APPNAME}
                     oatpp
                     ssl
                     crypto
                     oatpp-openssl 
                       )