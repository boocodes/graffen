#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 projection;
uniform mat4 rotation; // ������� ��������

out vec2 TexCoord;

void main()
{
    gl_Position = projection * vec4(aPos.x, -aPos.y, aPos.z, 1.0);
    
    // ������������ ���������� ���������� �� 90 �������� ������
    TexCoord = vec2(1.0 - aTexCoord.y, aTexCoord.x);
}