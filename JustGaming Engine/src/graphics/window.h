#pragma once

#include <GL/glew.h>
#include  <GLFW/glfw3.h>

namespace JustGamingEngine {
	namespace graphics {
		class Window {
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			//bool m_Closed;


		public:
			Window(const char *name, int width, int height);
			~Window();
			void Update();
			bool Closed() const;
			void Clear() const;

			inline int getWidth() const {
				return m_Width;
			}
			inline int getHeight() const {
				return m_Height;
			}

		private:
			bool Init();

		};
	}
}