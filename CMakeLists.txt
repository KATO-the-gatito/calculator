cmake_minimum_required(VERSION 3.16)

project(calculator LANGUAGES C)

add_executable(calculator main.c
    calculate.h calculate.c
    common.h
    process.h process.c
    common.c)
target_link_libraries(calculator PRIVATE m)

include(GNUInstallDirs)
install(TARGETS calculator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
