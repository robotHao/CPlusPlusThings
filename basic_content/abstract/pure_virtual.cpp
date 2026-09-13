/**
 * @file pure_virtual.cpp
 * @brief 纯虚函数：没有函数体的虚函数
 * 抽象类：包含纯虚函数的类
 *
 * @author 光城
 * @version v1
 * @date 2019-07-20
 */

#include <iostream>

using namespace std;

class A
{
private:
    int m_a;

public:
    virtual void show() = 0; // 纯虚函数  `=0` 不是赋值，只是语法标记，表示这个函数没有实现，留给子类实现

     static void InClassARealize()
    {
        cout << "new function realize in sub class A " << endl;
    }
};

class B : public A
{
public:
    void show() override
    {
        cout << "function show realize in sub class B " << endl;
    }
};

int main()
{
    /*
     * 1. 抽象类只能作为基类来派生新类使用
     * 2. 抽象类的指针和引用->由抽象类派生出来的类的对象！
     */
    // A a; //todo error 抽象类，不能创建对象

    /*
    * 指针本身只是一个变量，保存内存地址。**定义指针 ≠ 创建类对象**。抽象类禁止的是【创建 A 本身的对象】，并没有禁止定义 A 类型的指针 / 引用。
    此时 `a1` 只是一个野指针，没有指向任何有效对象，不能直接使用
     */
    A* a1; // ok 可以定义抽象类的指针,其用途：指向它的派生类（子类）对象，实现多态

    // A* a2 = new A(); // todo error, A是抽象类，不能创建对象

    B b;
    a1 = &b; //抽象类指针a1，指向子类B的对象
    a1->show(); //// 多态：调用B的show()

    A::InClassARealize();
    b.InClassARealize();//等价于 A::InClassARealize();
    A *p = &b;
    p->show();
    p->InClassARealize();

}
