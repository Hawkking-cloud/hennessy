#include <raylib.h>
#include <string>

namespace hen {
extern Camera3D camera;
extern Model cube;
class staticObject {
public:
  Model model;
  Matrix transform;
  Color color;
};

class overlay {
public:
  Model model;
  Matrix transform;
  Color color;
  void render(bool wireframe);
  overlay(Model model, Color color);
  void setPosition(float x, float y, float z);
  void setPosition(Vector3 pos);
};

void initEngine(const int width, const int height, const char *title);
void closeEngine();

void defaultRender();

overlay createOverlay(Model model, Color color);

}; // namespace hen
