#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象类
class Worker{
public:
    virtual ~Worker() = default;
    virtual void ShowInfo();
    virtual string GetDeptName();
    int m_Id;
    string m_Name;
    int m_DeptName; 
};