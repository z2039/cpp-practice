#include<iosream>
#include<memory>

using namespace std;

int main()
{
    //unique_ptr 独占
    unique_ptr<int> p1 = make_unique<int>(10);
    //unique_ptr<int> p2 = p1 //报错不能复制
    unique_ptr<int> p3 = move(p1);//可以移动

    //share_ptr  共享
    share_ptr<int> p4 = make_share<int>(20);
    share_ptr<int> p5 = p4;
    cout << "use_cout = " << p4.use_cout() << endl; //2
    return 0;

}