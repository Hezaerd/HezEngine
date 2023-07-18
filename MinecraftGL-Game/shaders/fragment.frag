#version 330 core

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
} fs_in;

out vec4 Frament_color

int main()
{
	fragment_color = vec4(fs_in.FragPos, 1.0);
}