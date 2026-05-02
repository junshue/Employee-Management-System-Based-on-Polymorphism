#pragma once
#include<iostream>

#include"worker.h"

using namespace std;

//老板类
class Boss : public Worker{
public:
Boss(int id, string name, int dId);
virtual void ShowInfo();
virtual string GetDeptName();
};
