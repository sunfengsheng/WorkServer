
file(STRINGS "${CMAKE_CURRENT_LIST_DIR}/oatpp/core/base/Environment.hpp" OATPP_VERSION_MACRO REGEX "#define OATPP_VERSION \"[0-9]+.[0-9]+.[0-9]+\"$")
string(REGEX REPLACE "#define OATPP_VERSION \"([0-9]+.[0-9]+.[0-9]+)\"$" "\\1" oatpp_VERSION "${OATPP_VERSION_MACRO}")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

## collect all source files in folder 'oatpp' recursively (i.e. also including subfolders)
file(GLOB_RECURSE FILES_OATPP
    oatpp/*.cpp
    oatpp/*.hpp
)
## for the sace of a better overview/browsability in the IDE,
## organize source files in a hierarchy (reflecting the actual folder structure)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/oatpp" FILES ${FILES_OATPP})

add_library(oatpp ${FILES_OATPP})

set_target_properties(oatpp PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)

set(CMAKE_THREAD_PREFER_PTHREAD ON)

find_package(Threads REQUIRED)

SET(OATPP_ADD_LINK_LIBS atomic)

target_link_libraries(oatpp PUBLIC ${CMAKE_THREAD_LIBS_INIT}
        ${OATPP_ADD_LINK_LIBS}
)

target_include_directories(oatpp PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
