cmake_minimum_required(VERSION 3.2)

set(PROJECT_VESRION 0.0.1)
set(MY_PROJECT_NAME thread_vk)
project(${MY_PROJECT_NAME} VERSION ${PROJECT_VESRION})

find_package( Threads )

add_executable(${MY_PROJECT_NAME} main.cpp
                               
)

set_target_properties(${MY_PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


if (MSVC)
    target_compile_options(${MY_PROJECT_NAME} PRIVATE
        /W4
    )
else ()
    target_compile_options(${MY_PROJECT_NAME} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

target_link_libraries( thread_vk ${CMAKE_THREAD_LIBS_INIT} )

install(TARGETS ${MY_PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT r.zhigalenko@mail.ru)
include(CPack)
