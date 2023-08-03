#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec3 vertex_normal;

uniform mat4 MVP;
uniform mat4 model;
// uniform mat3 normalMatrix;
out VS_OUT {
	vec3 FragPos;
	vec3 Normal;
	vec2 TexCoords;
} vs_out;

void main()
{
	gl_Position =  MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);

	vs_out.Normal = /*normalMatrix **/ vertex_normal;
	vs_out.TexCoords = uv;
	vs_out.FragPos = vec3(vec4(aPos.x, aPos.y, aPos.z, 1.0) * model);

}