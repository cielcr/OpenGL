//
//  main.cpp
//  solarsystem
//
//  Created by Changkun Ou on 16/06/07.
//  Copyright © 2016 Shiyanlou.com. All rights reserved.
//



#ifdef __APPLE__
#include <GLUT/glut.h>  //GLUT的图形库
#else
#include <GL/glut.h>   //GL库
#endif
#include "solarsystem.hpp"   //太阳西系类头文件class 

#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700

SolarSystem solarsystem;

//用与于注册GLUT的回调
void onDisplay(void) {
    solarsystem.onDisplay();   //
}
void onUpdate(void) {
    solarsystem.onUpdate();
}
void onKeyboard(unsigned char key, int x, int y) {
    solarsystem.onKeyboard(key, x, y);
}

int main(int argc, char*  argv[]) {
    //对GLUT進行初始化，并处理所有的命令行参数
    glutInit(&argc, argv);
    
    //此函数制定指定指定了指定了了使用GLUT_RGBA模式韩式颜色索引模式。
    //此外还可以指定是使用单缓冲窗口还是双缓冲窗口
    glutInitDisplayMode( GLUT_DOUBLE);//GLUT_RGBA |
    
    //设置窗口被创建时时时左上角位于屏幕上的位置
    glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
    
    
    //设置窗口被创建创建时的宽高，为了简便起见
    glutInitWindowSize(400,400);
    
    
    // 创建一个窗口，输入的字符串为窗口的标题
    glutCreateWindow("SolarSystem at Shiyanlou");

    //回调函数，每当GLUT确定一个窗口的内容需要更新显示的时候，gglutDisplayFunc注册的回调函数就会被执行
    glutDisplayFunc(onDisplay);
    
    //该函数原型：glutIdleFunc(void (*func)(void)) 将指定一个函数，用于处理当事件循环
    //处于空闲时执行此函数，此回调函数接受一个函数指针作为它它唯一参数
    glutIdleFunc(onUpdate);
    
    //该函数使得键盘上的键与一个函数关联，当这个键被按下或者释放时，函数会把调用
    glutKeyboardFunc(onKeyboard);
    
    //glutMainLoop（）：使程序进入事件处理循环。该函数必须是main主函数的最后一条语句。
    
    glutMainLoop();
    
    return 0;
}


