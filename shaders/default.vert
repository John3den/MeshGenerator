#version 420 core


layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;


// Outputs the normal for the Fragment Shader
flat out vec3 Normal;
// Outputs the current position for the Fragment Shader
out vec3 crntPos;

// Imports the camera matrix from the main function
uniform mat4 camMatrix;
// Imports the model matrix from the main function
uniform mat4 model;

void main()
{
	// calculates current position
	crntPos = vec3(model * vec4(aPos, 1.0f));
	// Outputs the positions/coordinates of all vertices
	gl_Position = camMatrix * vec4(crntPos, 1.0);
	
	Normal = vec3(model*vec4(aNormal,0.0f));

}