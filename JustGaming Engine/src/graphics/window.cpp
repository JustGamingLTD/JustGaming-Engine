#include "window.h"
#include <iostream>


namespace JustGamingEngine { namespace graphics {

	void windowResize(GLFWwindow *window, int width, int height);

	Window::Window(const char *title, int width, int height) {
		this->m_Title = title;

		this->m_Width = width;
		this->m_Height = height;
		if (!Init()) {
			glfwTerminate;
		}
	}

	Window::~Window() {
		glfwTerminate();
	}

	void Window::Update(){


		glfwPollEvents();



		glfwSwapBuffers(m_Window);

	}

	void Window::Clear() const{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	}

	bool Window::Closed() const {
		return glfwWindowShouldClose(m_Window) == 1;
	}

	bool Window::Init() {

		if (!glfwInit()) {
			std::cout << "Failed to initialize GLFW" << std::endl;
			return false;
		}



		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window) {
			std::cout << "Failed to create window" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);
		return true;
	}

	void windowResize(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);

	}


} }