# project(contact_managemeEmployee-Management-System-Based-on-Polymorphismnt_system)

# add_subdirectory(boss)
# add_subdirectory(employee)
# add_subdirectory(manager)
# add_subdirectory(worker)
# add_subdirectory(workermanager)

# add_executable(${PROJECT_NAME} main.cpp)

# target_include_directories(${PROJECT_NAME}
# PUBLIC
# ${boss_Dir}
# ${employee_Dir}
# ${manager_Dir}
# ${worker_Dir}
# ${workermanager_Dir}
# )

# target_link_libraries(${PROJECT_NAME}
# PUBLIC
# boss
# employee
# manager
# worker
# workermanager
# )

# 定义各子目录路径（方便后续使用）
set(worker_Dir ${CMAKE_CURRENT_SOURCE_DIR}/worker)
set(boss_Dir ${CMAKE_CURRENT_SOURCE_DIR}/boss)
set(employee_Dir ${CMAKE_CURRENT_SOURCE_DIR}/employee)
set(manager_Dir ${CMAKE_CURRENT_SOURCE_DIR}/manager)
set(workermanager_Dir ${CMAKE_CURRENT_SOURCE_DIR}/workermanager)

# 添加子目录（先添加被依赖的）
add_subdirectory(worker)
add_subdirectory(boss)
add_subdirectory(employee)
add_subdirectory(manager)
add_subdirectory(workermanager)

# 可执行文件
add_executable(ems main.cpp)#ems: employee management system

target_include_directories(ems
    PRIVATE
    ${worker_Dir}
    ${boss_Dir}
    ${employee_Dir}
    ${manager_Dir}
    ${workermanager_Dir}
)

target_link_libraries(ems
    PRIVATE
    workermanager
)

