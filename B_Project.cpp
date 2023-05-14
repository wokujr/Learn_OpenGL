#include <iostream>
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


const GLint WIDTH = 800, HEIGHT = 800;

int main()
{
    //initialise GLFW
	if (!glfwInit())
	{
		printf("GLFW initialisation failed! GLFW.");
		glfwTerminate();
		return 1;
	}

	//setup GLFW window
	//OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//core profile = no backward compability
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "testing window", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation failed! mainWindow");
		glfwTerminate();
		return 1;

	}

	//Get Buffer size information
	int BufferWidth, BufferHeight;
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//Set context for GLEW to use, so everything that should be drawn will be drawn in this window
	glfwMakeContextCurrent(mainWindow);

	//Allow modern extension features
	glewExperimental = GL_TRUE;

	//initialise GLEW
	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation is failed");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//Setup viewport size
	glViewport(0, 0, BufferWidth, BufferHeight);
	
	//Loop until window close
	while (!glfwWindowShouldClose(mainWindow))
	{
		//Get + Handle user input events
		glfwPollEvents();

		//Clear Window
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f); //the color is in RGB give value (1.0f, 0.f, 0.f, 1.f) will make it red, and change another value will make it green the last value is oppacity give in 1 will make transparent
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);

	}

	return 0;

}

