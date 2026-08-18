#include<iostream>
#include<memory>

using namespace std;

int main()
{
    //unique_ptr 独占
    unique_ptr<int> p1 = make_unique<int>(10);
    //unique_ptr<int> p2 = p1 //报错不能复制
    unique_ptr<int> p3 = move(p1);//可以移动

    //share_ptr  共享
    shared_ptr<int> p4 = make_shared<int>(20);
    shared_ptr<int> p5 = p4;
    cout << "use_cout = " << p4.use_count() << endl; //2

    //week_ptr 弱引用,用于打破循环,不增加计数
    weak_ptr<int> p6 = p4;
    cout << "weak use_cout = " << p6.use_count() << endl; //2
    return 0;

}