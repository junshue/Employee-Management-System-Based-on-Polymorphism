#include"employee.h"

Employee::Employee(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptName = dId;
}
void Employee::ShowInfo(){
    cout << "职工编号：" << this->m_Id
	<< "\t职工姓名：" << this->m_Name
	<< "\t岗位：" << this->GetDeptName()
	<< "\t岗位职责：完成经理下达的任务" << endl;
}
string Employee::GetDeptName(){
    return string("员工");
}