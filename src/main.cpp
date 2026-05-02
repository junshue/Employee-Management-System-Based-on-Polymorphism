#include<iostream>
#include"workermanager.h"
using namespace std;

int main(){
	//实例化管理者对象
	WorkerManager wm;
	//用户输入
	int choice = 0;
	while (true) {
		//调用成员函数展示菜单
		wm.Show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出程序
			wm.ExitSystem();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除离职职工
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.Mod_Emp();
			break;
		case 5://查找职工信息
			wm.Find_Emp();
			break;
		case 6://按照编号排序
			wm.Sort_Emp();
			break;
		case 7://清空所有文档
			wm.Clean_File();
			break;
		default:
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
			break;
		}
	}    
    system("pause");
    return 0;
}