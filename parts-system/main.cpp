#include "PartManager.h"
#include<iostream>
using namespace std;

int main()
{
    PartManager manager;
    int choice;

    
    while(true)
    {
         cout << "\n=== 零件管理系统 ===" << endl;
        cout << "1. 添加零件" << endl;
        cout << "2. 显示全部" << endl;
        cout << "3. 按编号查询" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择: ";
        cin >> choice;

       if (choice == 1) {
            int id;
            string name, category;
            double price;
            cout << "编号: "; cin >> id;
            cout << "名称: "; cin >> name;
            cout << "类别: "; cin >> category;
            cout << "价格: "; cin >> price;
            manager.addPart(id, name, category, price);
        }
        else if (choice == 2) {
            manager.showAll();
        }
        else if (choice == 3) {
            int id;
            cout << "输入编号: "; cin >> id;
            manager.findById(id);
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "无效选择" << endl;
        }
    }
    
    return 0;
}
