# project(manager)

# add_library(${PROJECT_NAME}
# SHARED
# manager.cpp
# )

# target_include_directories(manager
# PRIVATE
# ${worker_Dir})

add_library(manager STATIC
    manager.cpp
)

target_include_directories(manager
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(manager
    PUBLIC
    worker
)
