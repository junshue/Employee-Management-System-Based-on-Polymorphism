add_library(workermanager STATIC
    workmanager.cpp
)

target_include_directories(workermanager
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(workermanager
    PUBLIC
    boss
    employee
    manager
)
