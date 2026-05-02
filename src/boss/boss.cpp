#include"boss.h"

Boss::Boss(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptName = dId;
}
void Boss::ShowInfo(){
    cout << "职工编号：" << this->m_Id
	<< "\t职工姓名：" << this->m_Name
	<< "\t岗位：" << this->GetDeptName()
	<< "\t岗位职责：管理公司所有事物" << endl;
}
string Boss::GetDeptName(){
    return string("总裁");
}