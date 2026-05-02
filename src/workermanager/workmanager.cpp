#include"wokermanager.h"
// #include<fstream>
// #include"employee.h"
// #include"common.h"


WorkerManager::WorkerManager(){
    ifstream ifs(FILENAME, ios::in);
    //1、文件不存在
    if(!ifs.is_open()){
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //2、文件存在但记录为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //文件存在 且存在数据
    int num = this->Get_EmpNum();
    this->m_EmpNum = num;
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    this->Init_Emp();
}

//展示菜单
 void WorkerManager::Show_Menu(){
    cout << "******************************************" << endl;
    cout << "**********欢迎使用职工管理系统！**********" << endl;
    cout << "**************0.退出管理程序**************" << endl;
    cout << "**************1.增加职工信息**************" << endl;
    cout << "**************2.显示职工信息**************" << endl;
    cout << "**************3.删除离职职工**************" << endl;
    cout << "**************4.修改职工信息**************" << endl;
    cout << "**************5.查找职工信息**************" << endl;
    cout << "**************6.按照编号排序**************" << endl;
    cout << "**************7.清空所有文档**************" << endl;
    cout << "******************************************" << endl;
    cout << endl;
}

//退出功能
void WorkerManager::ExitSystem(){
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

//判断id是否重复
bool WorkerManager::IsExistId(int id){
    for(int i = 0; i < this->m_EmpNum; i++)
        if(this->m_EmpArray[i]->m_Id == id)
            return true;
    return false;
}

//添加员工
void WorkerManager::Add_Emp(){
    cout << "请输入要添加的员工数量：" << endl;
    int addNum;
    cin >> addNum;
    if (addNum > 0) {
        int newSize = this->m_EmpNum + addNum;//计算新空间大小
        Worker** newSpace = new Worker * [newSize];//开辟新空间
        //将原来空间里的内容存到新空间下
        if (this->m_EmpArray == NULL){
            for (int i = 0; i < this->m_EmpNum; i++)
                newSpace[i] = this->m_EmpArray[i];
        }
        //输入新数据
        for (int i = 0; i < addNum; i++){
            int id;
            string name;
            int dId;
            cout << "请输入第" << i + 1 << "个职工编号：" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个职工姓名：" << endl;
            cin >> name;
            Worker* worker = NULL;
            while (worker == NULL) {
                cout << "请选择该职工的岗位" << endl;
                cout << "1.普通职工" << endl;
                cout << "2.经理" << endl;
                cout << "3.老板" << endl;
                cin >> dId;
                switch (dId)
                {
                case 1:
                    worker = new Employee(id, name, dId);
                    break;
                case 2:
                    worker = new Manager(id, name, dId);
                    break;
                case 3:
                    worker = new Boss(id, name, dId);
                    break;
                default:
                    cout << "输入有误，请重新输入：" << endl;
                    break;
                }
            }
            newSpace[this->m_EmpNum + i] = worker;
        }
        //释放原本空间
        delete[] this->m_EmpArray;
        //更新新空间指向
        this->m_EmpArray =  newSpace;
        //更新职工个数
        this->m_EmpNum = newSize;
        //更新职工不为零标志
        this->m_FileIsEmpty = false;
        cout << "添加成功！" << endl;
        // ifs.close();
    }
    else {
        cout << "输入有误！" << endl;
    }
    system("pause");
    system("cls");
}

//保存文件
void WorkerManager::Save(){
    ofstream ofs(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_Id << " "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptName << endl;
    }
    ofs.close();
}

//统计人数 
int WorkerManager::Get_EmpNum(){
    ifstream ifs(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while(ifs >> id && ifs >> name && ifs >> dId)
        num++;
    ifs.close();
    return num;
}

//初始化员工 加载数据
void WorkerManager::Init_Emp(){
    ifstream ifs(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index = 0;//数组指针
    while(ifs >> id && ifs >> name && ifs >> dId){
        Worker* worker = NULL;
        if(id == 1)
            worker = new Employee(id, name, dId);
        else if (id == 2)
            worker = new Manager(id, name, dId);
        else
            worker = new Boss(id, name, dId);
        this->m_EmpArray[index++] = worker;
    }
    ifs.close();
}

//显示职工
void WorkerManager::Show_Emp(){
    if(this->m_FileIsEmpty)
        cout << "文件不存在或文件为空！" << endl;
    else{
        for(int i = 0; i = this->m_EmpNum; i++)
            this->m_EmpArray[i]->ShowInfo();
    }
    system("pause");
    system("cls");
}

//按照职工编号判断职工是否存在，若存在返回职工在数组中的位置，若不存在返回-1
int WorkerManager::IsExist(int id){
    int index = -1;
    for(int i =0; i < this->m_EmpNum; i++){
        if(this->m_EmpArray[i]->m_Id == id){
            index = i;
            break;
        }
    }
    return index;
}

//删除员工
void WorkerManager::Del_Emp(){
    if(this->m_FileIsEmpty)
        cout << "文件不存在或文件为空！" << endl;
    else{
        cout << "请输入你想删除的员工编号：" << endl;
        int id = -1;
        cin >> id;
        int index = this->IsExistId(id);
        if(index != -1){
            delete this->m_EmpArray[index];
            for(int i = 0; i < this->m_EmpNum; i++)
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            // this->m_EmpNum--;
            if(!--this->m_EmpNum) 
                this->m_FileIsEmpty = true;
            this->Save();
            cout << "删除成功!" << endl;
        }
        else{
            cout << "删除失败，未找到该员工！" << endl;
        }
    }
    system("pause");
    system("cls");
}

//修改职工
void WorkerManager::Mod_Emp(){
    if(this->m_FileIsEmpty)
        cout << "文件不存在或文件为空！" << endl;
    else{
        cout << "请输入你想修改的员工编号：" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if(ret != -1){
            delete this->m_EmpArray[ret];
            int newId = -1;
            string newName = "";
            int newDId = -1;
            cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
            cin >> newId;
            cout << "请输入新职工姓名：" << endl;
            cin >> newName;
            cout << "请输入岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> newDId;
            Worker* worker = NULL;
            while (newId)
            {
                
                switch (newDId)
                {
                case 1:
                    worker = new Employee(newId, newName, newDId);
                    break;
                case 2:
                    worker = new Manager(newId, newName, newDId);
                    break;
                case 3:
                    worker = new Boss(newId, newName, newDId);
                    break;
                default:
                    cout << "输入有误请重新输入：" << endl;
                    cout << "1.普通职工" << endl;
                    cout << "2.经理" << endl;
                    cout << "3.老板" << endl;
                    cin >> newDId;
                    break;
                }
            }
            this->m_EmpArray[ret] = worker;
            cout << "修改成功！" << endl;
            this->Save();
        }
        else{
            cout << "修改失败，未找到该员工！" << endl;
        }
    }
    system("pause");
    system("cls");
}

//查找职工
void WorkerManager::Find_Emp(){
    if(this->m_FileIsEmpty)
        cout << "文件不存在或文件为空！" << endl;
    else{
        cout << "请输入查找方式" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按职工姓名查找" << endl;
        int select = 0;
        cin >> select;
        switch (select)
        {
        case 1:{
            int id = 0;
            cout << "请输入想要查找的职工编号：" << endl;
            cin >> id;
            int ret = this->IsExist(id);
            if(ret != -1){
                cout << "查找成功！该职工信息为：" << endl;
                this->m_EmpArray[ret]->ShowInfo();
            }
            break;
        }
        case 2:{
            cout << "请输入想要查找的职工姓名" << endl;
            string name;
            cin >> name;
            bool flag = false;
            for(int i = 0; i < this->m_EmpNum; i++){
                if(this->m_EmpArray[i]->m_Name == name){
                    cout << "查找成功！该职工职工号为："
                    << this->m_EmpArray[i]->m_Id <<"  信息为：" << endl;
                    this->m_EmpArray[i]->ShowInfo();
                    flag = true;
                }
            }
            if(!flag) cout << "查找失败，未找到该员工！" << endl;
            break;
        }
            
        default:
            cout << "输入有误！" << endl;
            break;
        }
    }
    system("pause");
	system("cls");
}

//排序职工
void WorkerManager::Sort_Emp(){
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空" << endl;
        system("pause");
        system("cls");
    }
    else {
        cout << "请选择排序方式：" << endl;
        cout << "1、按职工号就行升序" << endl;
        cout << "2、按职工号就行降序" << endl;
        int select = 0;
        cin >> select;
        for (int i = 0; i < this->m_EmpNum; i++) {
            int MinOrMax = i;
            for (int j = i + 1; j < this->m_EmpNum; j++) {
                if (select == 1) {//升序
                    if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
                        MinOrMax = j;
                    }
                }
                else {//降序
                    if (this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
                        MinOrMax = j;
                    }
                }

            }
            if (i != MinOrMax) {
                Worker* temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
                this->m_EmpArray[MinOrMax] = temp;
            }
        }
        cout << "排序成功，排序后结果为：" << endl;
        this->Save();
        this->Show_Emp(); 
    }
}

//清空文件
void WorkerManager::Clean_File(){
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录已为空！" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "确定清空？" << endl;
    cout << "1、确定" << endl;
    cout << "2、返回" << endl;
    int select = 0;
    cin >> select;
    if(select == 1){
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();
        if(this->m_EmpArray != NULL){
            for(int i = 0; i < this->m_EmpNum; i++){
                delete this->m_EmpArray[i];
            }
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }
    system("pause");
    system("cls");
}

//析构函数
WorkerManager::~WorkerManager(){
    if(this->m_EmpArray != NULL){
        for(int i = 0; i < this->m_EmpNum; i++){
            delete this->m_EmpArray[i];
        }
    }
    delete[] this->m_EmpArray;
    this->m_EmpArray = NULL;
}



