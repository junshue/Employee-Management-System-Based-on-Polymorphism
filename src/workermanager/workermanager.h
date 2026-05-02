#pragma once
#include<iostream>
#include<fstream>

#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"

#define FILENAME "EmpFile.txt"

using namespace std;

class WorkerManager{
    public:
    //构造函数
    WorkerManager();
    //展示菜单
    void Show_Menu();
    //退出功能
    void ExitSystem();
    //判断id是否重复
    bool IsExistId(int id); 
    //添加员工
    void Add_Emp();
    //保存文件
    void Save();
    //统计人数
    int Get_EmpNum();
    //初始化员工
    void Init_Emp();
    //显示职工
    void Show_Emp();
    //按照职工编号判断职工是否存在，若存在返回职工在数组中的位置，若不存在返回-1
    int IsExist(int id);
    //删除员工
    void Del_Emp();
    //修改职工
    void Mod_Emp();
    //查找职工
    void Find_Emp();
    //排序职工
    void Sort_Emp();
    //清空文件
    void Clean_File();


    //析构函数
    ~WorkerManager();

    int m_EmpNum;//记录员工数量
    Worker** m_EmpArray;//员工数组指针
    bool m_FileIsEmpty;//标志文件是否为空
};