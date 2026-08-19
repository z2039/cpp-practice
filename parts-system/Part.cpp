#include<iostream>
#include"Part.h"
#include<string>
using namespace std;

 

    Part::Part(int id, string name, string category, double price)
    {
        this->id = id;
        this->name = name;
        this->category = category;
        this->price = price;
    }

    int Part::getId() const{return id;}
    string Part::getName() const{return name;}
    string Part::getCategory() const{return category;}
    double Part::getPrice() const{return price;}
    
    void Part::display() const{

        cout<< "编号:" << id << " "
        << "名称:" << name << " "
        << "类别:" << category << " "
        << "价格:" << price << "元" << endl;

    }
