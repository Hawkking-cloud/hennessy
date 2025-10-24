#include "hennessy.h"
#include "imgui.h"
#include "rlImGui.h"
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <vector>

std::vector<hen::staticObject> staticObjects;

Camera3D hen::camera = {{0.0f, 10.0f, 10.0f},
                        {0.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f},
                        45.0f,
                        CAMERA_PERSPECTIVE};

void hen::initEngine(const int width, const int height, const char *title) {
  InitWindow(width, height, title);
  rlImGuiSetup(1);

  hen::camera = {0};
  hen::camera.position = {0.0f, 10.0f, 10.0f};
  hen::camera.target = {0.0f, 0.0f, 0.0f};
  hen::camera.up = {0.0f, 1.0f, 0.0f};
  hen::camera.fovy = 45.0f;
  hen::camera.projection = CAMERA_PERSPECTIVE;
}
void hen::closeEngine() {
  rlImGuiShutdown();
  CloseWindow();
}

void hen::defaultRender() {}

hen::overlay::overlay(Model aModel, Color aColor) {
  model = aModel;
  transform = MatrixIdentity();
  color = aColor;
}

void hen::overlay::render(bool wireframe) {
  if (wireframe) {
    rlPushMatrix();
    rlMultMatrixf(MatrixToFloatV(transform).v);
    DrawModelWires(model, (Vector3){0, 0, 0}, 1.0f, color);
    rlPopMatrix();
  } else {
    rlPushMatrix();
    rlMultMatrixf(MatrixToFloatV(transform).v);
    DrawModel(model, (Vector3){0, 0, 0}, 1.0f, color);
    rlPopMatrix();
  }
}
void hen::overlay::setPosition(float x, float y, float z) {
  transform.m12 = x;
  transform.m13 = y;
  transform.m14 = z;
}
void hen::overlay::setPosition(Vector3 pos) {
  transform.m12 = pos.x;
  transform.m13 = pos.y;
  transform.m14 = pos.z;
}
