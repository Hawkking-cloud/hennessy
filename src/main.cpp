#include "hennessy.h"
#include "imgui.h"
#include "rlImGui.h"
#include <raylib.h>
int main() {
  hen::initEngine(1920, 1080, "test");
  float pos = 0.0f;
  Model cubeModel = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));

  hen::overlay cube(cubeModel, BLUE);

  while (!WindowShouldClose()) {
    cube.setPosition(0.0f, 0.0f, pos);

    UpdateCamera(&hen::camera, CAMERA_ORBITAL);
    BeginDrawing();
    ClearBackground(BLACK);

    BeginMode3D(hen::camera);

    cube.render(true);

    EndMode3D();

    rlImGuiBegin();
    ImGui::Begin("example");

    ImGui::SliderFloat("test position", &pos, 0.0f, 10.0f);

    ImGui::End();

    rlImGuiEnd();
    ///

    EndDrawing();
  }

  hen::closeEngine();
}
