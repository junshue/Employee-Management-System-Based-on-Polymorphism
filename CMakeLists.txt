cmake_minimum_required(VERSION 4.3.1)
project(EmployeeManagementSystem
    VERSION 0.0.1
    DESCRIPTION "a demo of cmake planning"
    HOMEPAGE_URL https://github.com/junshue/Employee-Management-System-Based-on-Polymorphism.git
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
#可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# set(common_include_Dir ${CMAKE_CURRENT_SOURCE_DIR}/include)
# set(boss_Dir ${CMAKE_SOURCE_DIR}/src/boss)
# set(employee_Dir ${CMAKE_SOURCE_DIR}/src/employee)
# set(manager_Dir ${CMAKE_SOURCE_DIR}/src/manager)
# set(worker_Dir ${CMAKE_SOURCE_DIR}/src/worker)
# set(workermanager_Dir ${CMAKE_SOURCE_DIR}/src/workermanager)
# include_directories(${CMAKE_SOURCE_DIR}/include)


#添加子目录
add_subdirectory(src)