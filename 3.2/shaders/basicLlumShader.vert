#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

out vec4 vertexF;
out vec3 normalF;

out vec3 matambF;
out vec3 matdiffF;
out vec3 matspecF;
out float matshinF;
// Valors per als components que necessitem del focus de llum
//vec3 colorFocus = vec3(0.8, 0.8, 0.8);
//vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
//vec3 posFocus = vec3(1, 0, 1);  // en SCA

void main()
{	  //Calcul de la posicio del vertex en SCO
    vec4 vertexSCO = (view * TG * vec4(vertex,1.0));
    vertexF = vertexSCO;

    //Calcul del vector normal en SCO
    mat3 inverseMatrix = (inverse(transpose(mat3(view*TG))));
    vec3 normalSCO = inverseMatrix * normal;
    normalSCO = normalize(normalSCO);

    normalF = normalSCO;

    matambF = matamb;
    matdiffF = matdiff;
    matspecF = matspec;
    matshinF = matshin;

    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}
