#version 330 core

layout (location = 0) in vec2 aPos;

uniform vec2 entityPos;

void main()
{
    gl_Position = vec4(aPos + entityPos, 0.0, 1.0);
}