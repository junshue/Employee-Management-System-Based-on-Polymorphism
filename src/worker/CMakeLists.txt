# project(woker)

# add_library(${PROJECT_NAME}
# SHARED
# boss.cpp
# )

# target_include_directories(boss
# PRIVATE
# ${worker_Dir})

add_library(worker INTERFACE)

target_include_directories(worker
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}#不懂
)

target_link_libraries(worker#不懂
    INTERFACE
)