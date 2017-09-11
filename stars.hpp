//
//  star.hpp
//  solarsystem
//
//  Created by Changkun Ou on 16/06/07.
//  Copyright © 2016 Shiyanlou.com. All rights reserved.
//实际模型假设：
//星球的运行轨道是圆形
//2、自转速度保持相同
//3、每次刷新绘制的时候假设时间经过了一天
#ifndef star_hpp
#define star_hpp

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif//防止重复包含库文件
/*
星球分为：
	普通能够自转并绕某个点公转的星球(Star)
	具有特殊材质的星球（Planet）
	能够发光的星球（LightPlanet）


*/
class Star {
public:
//在OpenGL中，建议使用GLfloat来表示浮点数
    GLfloat radius;//公转半径
    GLfloat speed, selfSpeed;//自转速度
    GLfloat distance;//距离太阳中心的距离
    GLfloat rgbaColor[4];//星球颜色

    Star* parentStar;//父节点星球  Star指针类型变量


//构造函数，构造一颗星球时必须提供  旋转半径、 自转速度、绕行（父节点）星球
    Star(GLfloat radius, GLfloat distance,
         GLfloat speed,  GLfloat selfSpeed,
         Star* parent);

//对一般的星球的移动、旋转等活动进行绘制
    void drawStar();

//提供默认实现，负责调用drawStar()
    virtual void draw() { drawStar(); }

//virtual 通过指向派生类的基类指针或引用，访问派生类中同名覆盖成员函数
//基类的成员函数设为virtual，其派生类的相应类的相应函数也会自动变为虚函数
//

//参数为每次刷新画面时的时间跨度
    virtual void update(long timeSpan);
protected:
    GLfloat alphaSelf, alpha;//alphaSelf当前的自转的角度、alpha当前的公转角度alpha
};

class Planet : public Star {//具有特殊材质的星球
public:
//构造函数
    Planet(GLfloat radius, GLfloat distance,
           GLfloat speed,  GLfloat selfSpeed,
           Star* parent, GLfloat rgbColor[3]);
    
//增加对具备自身材质的行星绘制材质
    void drawPlanet();

//继续向其子类开放重写功能
    virtual void draw() { drawPlanet(); drawStar(); }
};

class LightPlanet : public Planet {//发光的行星
public:

//构造函数
    LightPlanet(GLfloat Radius, GLfloat Distance,
                GLfloat Speed,  GLfloat SelfSpeed,
                Star* Parent, GLfloat rgbColor[]);

//增加对提供光源的恒星绘制光照
    void drawLight();
//子类开放重写功能
    virtual void draw() { drawLight(); drawPlanet(); drawStar(); }
};

#endif /* star_hpp */
