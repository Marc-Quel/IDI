#version 330 core

out vec4 FragColor;

in vec4 vertexF;
in vec3 normalF;

in vec3 matambF;
in vec3 matdiffF;
in vec3 matspecF;
in float matshinF;

uniform vec3 colorFocus;
uniform vec3 llumAmbient;

uniform vec3 posFocusA;
uniform vec3 posFocusO;
uniform mat4 view;

uniform int focusAplicacio;
uniform int focusCamera;

vec3 Ambient() {
    return llumAmbient * matambF;
}

vec3 Difus (vec3 NormSCO, vec3 L, vec3 colFocus) 
{
    // Fixeu-vos que SOLS es retorna el terme difús
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats
    vec3 colRes = vec3(0);
    // Càlcul component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colFocus * matdiffF * dot (L, NormSCO);
    return (colRes);
}

vec3 Especular (vec3 NormSCO, vec3 L, vec4 vertSCO, vec3 colFocus) 
{
    // Fixeu-vos que SOLS es retorna el terme especular!
    // Assumim que els vectors estan normalitzats
    vec3 colRes = vec3 (0);
    // Si la llum ve de darrera o el material és mate no fem res
    if ((dot(NormSCO,L) < 0) || (matshinF == 0))
      return colRes;  // no hi ha component especular

    // Calculem R i V
    vec3 R = reflect(-L, NormSCO); // equival a: 2.0*dot(NormSCO,L)*NormSCO - L;
    vec3 V = normalize(-vertSCO.xyz); // perquè la càmera està a (0,0,0) en SCO

    if (dot(R, V) < 0)
      return colRes;  // no hi ha component especular
    
    float shine = pow(max(0.0, dot(R, V)), matshinF);
    return (matspecF * colFocus * shine); 
}

void main()
{	
	vec3 posFocusASCO = (view * vec4(posFocusA,1.0)).xyz;

  vec3 colorFocusCamera = vec3(0.0, 0.0, 0.0);
  vec3 colorFocusAplicacio = vec3(0.0, 0.0, 0.0);

  if (focusAplicacio == 1) colorFocusAplicacio = vec3(0.8, 0.8, 0);

  if (focusCamera == 1) colorFocusCamera = vec3(0.8, 0.8, 0.8);
  //Calcul de L en SCO (es el vector direccional que surt de la resta de posFocusSCO - vertexSCO)
  vec3 LSCOA = posFocusASCO - vertexF.xyz;
  LSCOA = normalize(LSCOA);

  vec3 LSCOO = posFocusO - vertexF.xyz;
  LSCOO = normalize(LSCOO);

  //Calcul del vector normal en SCO
	vec3 fcolor = Ambient() + Difus(normalF, LSCOA, colorFocusAplicacio) + Difus(normalF, LSCOO, colorFocusCamera) + Especular(normalF, LSCOA, vertexF, colorFocusAplicacio) + Especular(normalF, LSCOO, vertexF, colorFocusCamera);
	FragColor = vec4(fcolor,1);	
}
 