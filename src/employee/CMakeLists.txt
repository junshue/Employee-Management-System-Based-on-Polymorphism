# project(employee)

# add_library(${PROJECT_NAME}
# SHARED
# employee.cpp
# )

# target_include_directories(employee
# PRIVATE
# ${worker_Dir})

add_library(employee STATIC
    employee.cpp
)

target_include_directories(employee
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(employee
    PUBLIC
    worker
)
