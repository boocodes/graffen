#version 330 core
out vec4 FragColor;
uniform vec3 color;
uniform float radius;
uniform float smoothness;
in vec2 fragCoord;

uniform vec2 boundsMin;
uniform vec2 boundsMax;

void main() {
    vec2 center = (boundsMin + boundsMax) * 0.5;
    vec2 size = boundsMax - boundsMin;
    vec2 halfSize = size * 0.5;
    
    float cornerRadius = min(halfSize.x, halfSize.y) * radius;
    
    vec2 position = abs(fragCoord - center);
    
    vec2 q = position - halfSize + cornerRadius;
    float dist = length(max(q, 0.0)) + min(max(q.x, q.y), 0.0) - cornerRadius;
    
    float alpha = 1.0 - smoothstep(0.0, smoothness, dist);
    
    if (alpha <= 0.0) discard;
    FragColor = vec4(color, alpha);
}