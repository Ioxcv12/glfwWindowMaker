#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <windows.h>

auto err = std::make_error_code(std::errc::file_exists);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	if (!glfwInit()) {
		MessageBoxA(NULL, "ERROR", "GLFW failed to initialize.", MB_ICONERROR | MB_OK);
		return -1;
	}
	gladLoadGL();

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	GLFWwindow* win;


	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	win = glfwCreateWindow(800, 600, "GLFW Test", NULL, NULL);

	glfwSetKeyCallback(win, key_callback);

	while (!glfwWindowShouldClose(win))
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(win);
	glfwTerminate();
	return 0;
}
