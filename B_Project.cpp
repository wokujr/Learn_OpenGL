#include <iostream>

#include <GLFW/glfw3.h>
#include <GL/glew.h>


const GLint WIDTH = 600, HEIGHT = 800;

int main()
{
    //initialise GLFW
	if (!glfwInit())
	{
		printf("GLFW initialisation failed!.");
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
		printf("GLFW window creation failed!");
		glfwTerminate();
		return 1;

	}

	//Get Buffer size information
	int BufferWIdth, BufferHeight;
	glfwGetFramebufferSize(mainWindow, &BufferWIdth, &BufferHeight);

	//Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);



	return 0;

}

