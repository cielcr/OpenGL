//
//  solarsystem.hpp
//  solarsystem
//
//  Created by Changkun Ou on 16/06/07.
//  Copyright © 2016 Shiyanlou.com. All rights reserved.


//太阳系类

#ifndef solarsystem_hpp
#define solarsystem_hpp


#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "stars.hpp"

#define STARS_NUM 10   //定义为10是因为太阳在内的一共有九颗行星（不包含冥王星），每个Star对象都具有parentStar的属性，因为我们还可以额外实现这些卫星，比如绕地球运行的太阳，所以为10颗行星

class SolarSystem {

public:

    SolarSystem();  //构造函数
    ~SolarSystem();  //析构函数

    void onDisplay();  //调用星球的draw()方法
    void onUpdate();  //调用星球的update()方法
    void onKeyboard(unsigned char key, int x, int y);  //键盘调用整个太阳系的显示

private:
    Star *stars[STARS_NUM];  //数组形式管理所用星球，不使用C++中的vector是因为传统形式的数组就足够

//定义观察视角参数
    GLdouble viewX, viewY, viewZ;  // 
    GLdouble centerX, centerY, centerZ; //
    GLdouble upX, upY, upZ;
};

#endif /* solarsystem_hpp */
