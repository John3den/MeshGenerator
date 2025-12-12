#version 420 core

uniform int useLighting;

// Outputs colors in RGBA
out vec4 FragColor;

// Imports the normal from the Vertex Shader
flat in vec3 Normal;

void main()
{ 
	float ambient = 0.20f;
	vec3 normal = Normal;
	vec3 lightDirection = vec3(1,0.7,0.5);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	// outputs final color
	FragColor = (vec4(0.5,0.5,0.5,1)  * (diffuse + ambient))*useLighting + vec4(0.2, 0.7, 0.2, 1) * (1-useLighting);
}