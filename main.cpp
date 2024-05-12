#include "libs.hpp"

int main(void)
{
    GLFWwindow* window;

    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 480;
    int frameBufferWidth = 0;
    int frameBufferHeight = 0;

    if(!glfwInit()){  
        printf("ERROR::MAIN.CPP::GLFW FAILED TO INITIATE");
        return -1;
    }

    //it specifies openGL version 4.6
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_RESIZABLE,GLFW_TRUE);

    window = glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"Window", NULL, NULL);
    
    //glfwGetFramebufferSize(window, &frameBufferWidth,&frameBufferHeight);
    //glViewport(0,0, 40, 50);
    glfwMakeContextCurrent(window);

    //INITIATE GLEW
    GLenum err = glewInit();
    if(err != GLEW_OK){
    /* Problem: glewInit failed, something is seriously wrong. */
    fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }

    //MAIN LOOP
    while(!glfwWindowShouldClose(window)){
        //UPDATE INPUT 
        glfwPollEvents();
        //UPDATE
        
        //CLEAR
        glClearColor(1.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        //DRAW
        glfwSwapBuffers(window);
        glFlush();
    }

    glfwTerminate();
    
    return 0;
} 

