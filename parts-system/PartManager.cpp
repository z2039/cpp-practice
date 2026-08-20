#include"PartManager.h"
#include<iostream>
#include<string>
#include <fstream>



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

    void PartManager::saveToFile(const string& filename) const
    {
            ofstream out(filename);
    for (const auto& p : parts) {
        out << p.getId() << " " << p.getName() << " " 
            << p.getCategory() << " " << p.getPrice() << endl;
    }
    cout << "保存成功: " << parts.size() << " 个零件" << endl;
   }
    
    void PartManager::loadFromFile(const string& filename)
    {
        ifstream in(filename);
    int id;
    string name, category;
    double price;
    while (in >> id >> name >> category >> price) {
        parts.emplace_back(id, name, category, price);
    }
    cout << "加载成功: " << parts.size() << " 个零件" << endl;

    }
