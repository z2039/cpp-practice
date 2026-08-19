#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace std;


int main()
{

    //拷贝vsmove
    vector<string> s1 = {"这是一段很长的内容"};

    vector<string> s2 = s1;//拷贝复制,不影响原来的容器内容
    cout << "move前s1.size()" << s1.size() << endl;

    vector<string> s3 = move(s1);
    cout << "move后s1.size()" << s1.size() << endl;//应该是0
    cout << "s3[0]: " << s3[0] << endl;

    //unique_ptr的move
    unique_ptr<int> p1 = make_unique<int>(19);
     cout << "p1: " << *p1 << endl;

    unique_ptr<int> p2 = move(p1);
     //cout << "p1: " << *p1 << endl;//此时p1为空指针

      cout << "p2: " << *p2 << endl;

    return 0;
}