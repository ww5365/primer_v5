/*
 * 13.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: wangwei69
 */

#include "all.hpp"
#include "13.h"

#include <string>


using namespace std;



/*
 * chapter 13 : copy control
 *
 * 主要讲：copy = move 析构
 *
 * copy 构造函数
 * 拷贝  赋值
 *
 * 移动 构造函数
 * move 赋值
 *
 * 析构
 *
 * 上面5个，都属于拷贝控制集合；
 *
 *  定义一个类，上面的操作都需要定义吗？
 *
 *  并不需要全部定义，但有些规则需要注意：
 *
 *  1、需要析构函数， 一般就得定义拷贝构造和拷贝赋值运算；泛指多次delete同一内存区域；
 *
 *  2、有拷贝构造，一般就得有拷贝赋值；
 *
 *
 *
 */



void test_13(){


    /*
     * copy constructor:
     *   1、编译器会自动合成一个默认的拷贝构造函数，但不一定适用；
     *   2、拷贝构造函数的参数：必须是自身类型的引用 ？ 不是引用是不行的。考虑为什么。
     *      foo(const foo&)
     *   3、什么情况下，会发生类对象的拷贝构造?
     *      =
     *      传参，非引用类型参数
     *      返回值， 非引用类型的函数返回值
     *      容器中存放类对象： push insert
     *
     *  copy assignment operator: 拷贝赋值运算符
     *
     *    1、一般如何定义：
     *
     *       foo& operator = (const foo& other){
     *         ....
     *
     *         [delete *self ]:一般要先释放自身
     *         return *this; //返回自身对象
     *
     *       }
     *
     *
     *   析构函数：
     *
     *     1、定义：
     *
     *        ~foo(){
     *        ...
     *        }
     *
     *        类析构函数唯一，无参数，无返回值
     *
     *     2、释放非static数据成员的顺序：
     *
     *        执行函数体 -》 释放类中数据成员： 按照定义出现的逆序
     *
     *        正好和构造函数初始化过程相反：
     *
     *        初始化，按照数据成员出现顺序 -》 执行函数体
     *
     *
     *    3、 类成员中，也有其它类定义的数据成员， 如何释放这些类数据成员的对象呢？
     *
     *        析构函数一般不直接销毁成员；成员是在析构函数体之后隐含的析构阶段中被销毁(调用自身的析构函数)；
     *        析构函数体内，主要释放自身动态分配的资源；
     *
     *
     *    =default :
     *
     *    显示的使用合成版本的构造函数或控制成员函数；
     *
     *
     *
     */


    /*
     *
     * 如何防止类对象被拷贝？
     *
     * 1、=delete : 删除的函数
     *
     *   虽然声明此函数，但不能以任何方式使用它；
     *
     * 2、声明为private，也不实现；
     *
     *
     */

    class noCopy{

    private:
        noCopy& operator= (const noCopy&); //不能赋值拷贝
    public:
        noCopy() = default; //使用合成版本的默认构造函数
        noCopy(const noCopy&) = delete; //定义为删除函数

    };


















}



