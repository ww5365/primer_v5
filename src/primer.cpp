/*
 *  头文件中函数，以primer开头的,紧跟章节号
 *  比如：primer_2_1_2 标识第2章，第1节第2个问题的discussion；
 *
 *  Created on: 2016年2月26日
 */

#include <iostream>
#include <vector>
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.hpp"



using namespace std;

int main(){

    cout << "hello word!" <<endl;
    primer_2_2_1();

    int res= 0;
    std::string str = "-4c";
    hex_2_dec(str,res);
    cout <<"hex: " << str << " to: " <<res <<endl;
    test_6();

}
