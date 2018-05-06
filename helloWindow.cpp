//学习地址：
//https://learnopengl-cn.readthedocs.io/zh/latest/01%20Getting%20started/03%20Hello%20Window/
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
void key_callback(GLFWwindow *window, int key, int scanode, int action, int mode){
    if(key == GLFW_KEY_ESCAPE && action==GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
int main(int argc, char * argv[]) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//glfwWindowHint函数的第一个参数代表选项的名称，我们可以从很多以GLFW_开头的枚举值中选择；第二个参数接受一个整形，用来设置这个选项的值
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow *window = glfwCreateWindow(800, 600, "myWindow", nullptr, nullptr);
    if(window == nullptr){
        std::cout<<"creat window failed\n";
        glfwTerminate();
        return -1;
    }else{
        std::cout<<"creat success\n";
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        std::cout<<"glew init fialed\n";
        return -1;
    }else{
        std::cout<<"glew init success\n";
    }
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0.2, 0.2, width, height);
    glfwSetKeyCallback(window, key_callback);
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();//检查有没有触发什么事件
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);//交换颜色缓冲（它是一个储存着GLFW窗口每一个像素颜色的大缓冲），它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上。
    }
    
    glfwTerminate();//释放GLFW分配的内存
    return 0;
}
