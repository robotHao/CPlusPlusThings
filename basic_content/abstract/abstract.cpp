/**
 * @file abstract.cpp
 * @brief
 * 抽象类中：在成员函数内可以调用纯虚函数，在构造函数/析构函数内部不能使用纯虚函数
 * 如果一个类从抽象类派生而来，它必须实现了基类中的所有纯虚函数，才能成为非抽象类
 * @author 光城
 * @version v1
 * @date 2019-07-20
 */

#include <iostream>
using namespace std;

// 只要类里存在至少一个纯虚函数 → 这个类就是抽象类 (abstract class) 即类A是抽象类
class A
{
public:
    virtual void f() = 0; // 纯虚函数 :没有函数体的虚函数，声明时赋值0 表明这个类中不提供函数实现，只规定接口规范
    void g() //类A中普通的成员函数
    {
        /// 在普通成员函数g内部调用纯虚函数this->f(),运行时调用子类重写的f，模板方法模式
        this->f();
    }

    int m_classAVar{0};

    /*
        `this->f()`走虚函数表多态机制：
        1. 类 A 本身是抽象类，不会创建类A的对象；真正运行的一定是类A的子类对象
        2. 子类重写了`f()`，子类对象的虚表里存放的是子类`f`的地址
        3. 调用`g()`（继承自 A）时，`this`指向子类对象，通过虚表，调用到**子类实现的 f ()**
     */
    // 在构造函数 / 析构函数里面调用纯虚函数是未定义行为，不能调用纯虚函数
    /// 抽象类可以有构造函且抽象类只是不能实例化，父类中的构造函数用于子类继承时初始化父类部分,
    /// 抽象类不能直接 new / 创建自己的对象，但是抽象类完全可以写构造函数；子类继承抽象类，创建子类对象的时候，会自动调用抽象父类的构造函数，用来初始化父类里面的成员变量
    A(int num)
    {
        cout << "Abstract class A construct function execute" << endl;
        m_classAVar = num;
    } //构造函数
    ~A()
    {
    } //析构函数
};

///  派生类，必须实现纯虚函数f
class B : public A
{
public:
    int m_classBVar{0};
    /// 子类构造函数，必须调用父类A的构造
    B(int num1, int num2) : A(num1)
    {
        cout << "subAbstract class B construct function execute" << endl;
        m_classBVar = num2;
    }

    void f()
    {
        cout << "B:f()" << endl;
    }
};

class C : public A
{
    // 没有override 父类中函数 void f()
public:
    int m_classCVar{0};

    C(int num1) : A(num1)
    {
        cout << "subAbstract class C construct function execute" << endl;
        m_classCVar = num1;
        cout << "m_classCVar, " << m_classCVar << endl;
    }

    void f()
    {
        cout <<
            "C:f(): because class C is an abstract class  pure virtual function void A::f()  pure virtual A::f not overridden"
            << endl;
    }
};

int main()
{
    B b(10, 20);
    b.g();
    C c(30);
    c.g();

    return 0;
}

