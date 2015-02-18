#include <GLFW/glfw3.h>

#include <iostream>

void err_cb(int error, const char* descr)
{
  std::cerr << descr << std::endl;
}

static void key_cb(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
      glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int main(int argc, char* argv[])
{
  std::cout << "Hello, World!" << std::endl;

  if(!glfwInit())
    exit(EXIT_FAILURE);

  GLFWwindow* window = glfwCreateWindow(640, 480, "My window!", NULL, NULL);

  glfwSetErrorCallback(err_cb);
  glfwSetKeyCallback(window, key_cb);
  
  if(!window)
    {
      glfwTerminate();
      exit(EXIT_FAILURE);
    }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  while(!glfwWindowShouldClose(window))
    {
      float ratio;
      int width, height;

      glfwGetFramebufferSize(window, &width, &height);
      ratio = width / (float) height;

      glViewport(0, 0, width, height);
      glClear(GL_COLOR_BUFFER_BIT);

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
      glMatrixMode(GL_MODELVIEW);

      glLoadIdentity();
      glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

      glBegin(GL_TRIANGLES);
      glColor3f(1.f, 0.f, 0.f);
      glVertex3f(-0.6f, -0.4f, 0.f);
      glColor3f(0.f, 1.f, 0.f);
      glVertex3f(0.6f, -0.4f, 0.f);
      glColor3f(0.f, 0.f, 1.f);
      glVertex3f(0.f, 0.6f, 0.f);
      glEnd();

      glfwSwapBuffers(window);
      glfwPollEvents();
    }
  
  glfwDestroyWindow(window);
  glfwTerminate();
  
  return 0;
}
