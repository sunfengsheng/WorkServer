
set(OATPP_THIS_MODULE_NAME oatpp-openssl)
add_library(${OATPP_THIS_MODULE_NAME}
        oatpp-openssl/Config.cpp
        oatpp-openssl/Config.hpp
        oatpp-openssl/Connection.cpp
        oatpp-openssl/Connection.hpp
        oatpp-openssl/client/ConnectionProvider.cpp
        oatpp-openssl/client/ConnectionProvider.hpp
        oatpp-openssl/server/ConnectionProvider.cpp
        oatpp-openssl/server/ConnectionProvider.hpp
        oatpp-openssl/configurer/CaCertificateBundleBuffer.cpp
        oatpp-openssl/configurer/CaCertificateBundleBuffer.hpp
        oatpp-openssl/configurer/CertificateChainBuffer.cpp
        oatpp-openssl/configurer/CertificateChainBuffer.hpp
        oatpp-openssl/configurer/CertificateChainFile.cpp
        oatpp-openssl/configurer/CertificateChainFile.hpp
        oatpp-openssl/configurer/CertificateBuffer.cpp
        oatpp-openssl/configurer/CertificateBuffer.hpp
        oatpp-openssl/configurer/CertificateFile.cpp
        oatpp-openssl/configurer/CertificateFile.hpp
        oatpp-openssl/configurer/ContextConfigurer.hpp
        oatpp-openssl/configurer/PeerCertificateVerification.cpp
        oatpp-openssl/configurer/PeerCertificateVerification.hpp
        oatpp-openssl/configurer/PrivateKeyBuffer.cpp
        oatpp-openssl/configurer/PrivateKeyBuffer.hpp
        oatpp-openssl/configurer/PrivateKeyFile.cpp
        oatpp-openssl/configurer/PrivateKeyFile.hpp
        oatpp-openssl/configurer/TemporaryDhParamsFile.cpp
        oatpp-openssl/configurer/TemporaryDhParamsFile.hpp
)

set_target_properties(${OATPP_THIS_MODULE_NAME} PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/oatpp-openssl
        ../oatpp
        /usr/local/openssl/include
)

link_directories(/usr/local/openssl/lib)

target_link_libraries(${OATPP_THIS_MODULE_NAME}
        oatpp
        ssl
        crypto
)
