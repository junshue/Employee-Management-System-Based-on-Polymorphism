#pragma once
#include<iostream>

#include"worker.h"

using namespace std;

//老板类
class Manager : public Worker{
public:
Manager(int id, string name, int dId);
virtual void ShowInfo();
virtual string GetDeptName();
};
