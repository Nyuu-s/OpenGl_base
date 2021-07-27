#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"shaderClass.h"

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);

	//prevent the camera from jumping around when left click
	bool firstClick;

	//width and height of the window
	int width;
	int height;

	//camera speed and mouse sensitivity
	float speed = 0.01f;
	float sens = 100.0f;

	//camera constructor
	Camera(int width, int height, glm::vec3 position);

	//update and export de camera matric to the vertex shader
	void updateMatrix(float FOCdeg, float nearPlane, float farPlane);
	void Matrix(Shader& shader, const char* uniform);
	//handles camera inputs
	void Inputs(GLFWwindow* window);
};


#endif