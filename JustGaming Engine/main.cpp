#include "src/graphics/window.h"

#include <iostream>

using namespace JustGamingEngine;
using namespace graphics;


int main(void) {
	
	Window window("Test", 600, 500);

	glClearColor(0.f, 1.f, 1.f, 1.f);

	std::cout << glGetString(GL_VERSION);

	while(!window.Closed()){
		
		window.Clear();

		glBegin(GL_TRIANGLES);

		glVertex2f(-.5f, -.5f);
		glVertex2f(0.f, .5f);
		glVertex2f(.5f, -.5f);

		glEnd();
		window.Update();
	}

	return 0;
}

