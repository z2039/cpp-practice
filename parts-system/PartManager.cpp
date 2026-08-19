#include"PartManager.h"
#include<iostream>
#include<string>

using namespace std;

    void PartManager::addPart(int id, string name, string category, double price)
    {
        parts.emplace_back(id,name,category,price);
        cout << "添加成功: " << name << endl;
    }

    void PartManager::showAll() const
    {
        if(parts.empty())
        {
            cout << "零件仓库为空" << endl;
            return;
        }
        cout << "=== 零件列表 ===" << endl;
        for(auto & p : parts)
        {
            p.display();
        }
    }

    void PartManager::findById(int id) const
    {
        for(auto & p : parts)
        {
            if(p.getId() == id)
            {
                cout << "找到零件:" << endl;
                p.display();
                return;
            }
        }
    }