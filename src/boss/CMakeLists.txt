# project(manager)

# add_library(${PROJECT_NAME}
# SHARED
# manager.cpp
# )

# target_include_directories(manager
# PRIVATE
# ${common_include_Dir})

add_library(boss STATIC
    boss.cpp
)

target_include_directories(boss
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(boss
    PUBLIC
    worker
)
