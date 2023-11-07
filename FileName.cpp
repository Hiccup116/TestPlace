#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>
using namespace std;
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	


	GLFWwindow* window = glfwCreateWindow(800, 600, "learnOpenGl", NULL, NULL);
	if (window==NULL)
	{
		cout << "FAILED to create Glfw windows" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		 cout << "Failed to initialize GLAD" <<endl;
		return -1;
		//We pass GLAD the function to load the address of the OpenGL function pointers which is 
		// OS-specific. GLFW gives us glfwGetProcAddress that 
		// defines the correct function based on which OS we're compiling for.
	}
	glViewport(0, 0, 800, 600);// third and fourth set the width and height
	 
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//Ready your engines
	
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}



 





/*
	1 //initialized the GLFW library befor we use any thing we have to add this

	2 //glfwWindowHint(int target,int hint)to configure GLFW,
	//The first argument tell us what option we want to cinfigure,The second argument is an integer that sets the value of our optionl



	3 we're required to create a window object.This window object holds all the windowing data and is required by most of GLFW'S other functions



	// glfwCreateWindows:// its requires the windows width and height as its first two argument,the third argument allows us to create a name for the window,we can discard the last two par.
	//Glfw Window: object that we'll later need for other GLFW operation

	4
	GLAD
	In the previous chapter we mentioned that GLAD manages function pointers for
	OpenGL so we want to initialize GLAD before we call any OpenGL function:

	5 	Behind the scenes OpenGL uses the data specified via glViewport to transform the 2D
	coordinates it processed to coordinates on your screen. For example, a processed point of location (-0.5,0.5)
	would (as its final transformation) be mapped to (200,450) in screen coordinates
	. Note that processed coordinates in OpenGL are between -1 and 1 so we effectively
	map from the range (-1 to 1) to (0, 800) and (0, 600).

	6  The glfwWindowShouldClose function checks at the start of each loop iteration if GLFW has been instructed to close.
	If so, the function returns true and the render loop stops running, after which we can close the application.
	The glfwPollEvents function checks if any events are triggered (like keyboard input or mouse movement events),
	updates the window state, and calls the corresponding functions (which we can register via callback methods).
	The glfwSwapBuffers will swap the color buffer (a large 2D buffer that contains color values for each pixel in GLFW's window)
	that is used to render to during this render iteration and show it as output to the screen.


*/
