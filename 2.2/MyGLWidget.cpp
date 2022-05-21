// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {
}
void MyGLWidget::initializeGL() {
    BL2GLWidget::initializeGL();
    rotate = 0;
    perspectiva = 1;
    glEnable(GL_DEPTH_TEST);
    
    calculCapsaModel();
    calculaCapsaEscena();
    calculCentreEscena();
    calculRadiEscena();

    iniCamera();
}
void MyGLWidget::iniCamera() {
    distancia = 2*escenaRadi;
    FOVini = 2*glm::asin(escenaRadi/distancia);
    FOV = FOVini;
    raw = 1.0f;
    Znear = distancia - escenaRadi;
    Zfar = distancia + escenaRadi;

    l = -escenaRadi;
    r = escenaRadi;
    b = -escenaRadi;
    t = escenaRadi;
    projectTransform();

    OBS = glm::vec3(escenaCentre.x,escenaCentre.y,distancia);
    VRP = glm::vec3(escenaCentre.x,escenaCentre.y,escenaCentre.z);
    UP = glm::vec3(0,1,0);
    viewTransform();
}

void MyGLWidget::paintGL() {
    // Esborrem el frame-buffer
    glClear (GL_COLOR_BUFFER_BIT);

    //actualitzem la projectTransform

    projectTransform();
    // Carreguem la transformació de model
    
    modelTransform ();

    // Activem el VAO per a pintar la caseta 
    glBindVertexArray (VAO);

    // pintem
    glDrawArrays(GL_TRIANGLES, 0, m.faces().size()*3);

    modelTransformTerra();

    glBindVertexArray (VAOT);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray (0);
}

void MyGLWidget::resizeGL(int w, int h) {
    BL2GLWidget::resizeGL(w,h);
    float rav = float(w) / float(h);
    if (perspectiva) {
        //Si rav > 1 nomes cal fer aixo
        raw = rav;
        //Si rav < 1 llavors hem de modificar el fov, perque no es queda espai als costats
        if (rav < 1.0) FOV = 2*glm::atan(glm::tan(FOVini/2)/rav);
    } else {
        if (rav > 1.0) {
            l = -escenaRadi*rav;
            r = escenaRadi*rav;
            b = -escenaRadi;
            t = escenaRadi;
        }
        if (rav < 1.0) {
            l = -escenaRadi;
            r = escenaRadi;
            b = -escenaRadi*rav;
            t = escenaRadi*rav;
        }
    }
    projectTransform();
    glViewport(0,0,w,h);
}

void MyGLWidget::modelTransform() {
    glm::mat4 trans;
    trans = glm::rotate(trans, rotate, glm::vec3(0,1,0));
    trans = glm::scale(trans, glm::vec3(escala));
    //movem el model al (0,0,0)
    trans = glm::translate(trans, -modelCentreBase);
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &trans[0][0]);
}

void MyGLWidget::modelTransformTerra() {
    glm::mat4 trans (1.0f);
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &trans[0][0]);
}
void MyGLWidget::viewTransform() {
    glm::mat4 view;
    view = glm::lookAt(OBS, VRP, UP);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
}

void MyGLWidget::projectTransform() {
    glm::mat4 proj;

    if (perspectiva) proj = glm::perspective(FOV, raw, Znear, Zfar);
    else proj = glm::ortho(l, r, b, t, Znear, Zfar);
    
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &proj[0][0]);
}
void MyGLWidget::creaBuffers() {
    m.load("../assig/models/Patricio.obj");
    // Creació del Vertex Array Object per pintar
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLuint VBO_HomerPos;
    glGenBuffers(1, &VBO_HomerPos);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerPos);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_vertices(), GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    GLuint VBO_HomerCol;
    glGenBuffers(1, &VBO_HomerCol);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerCol);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*m.faces().size()*3*3, m.VBO_matdiff(), GL_STATIC_DRAW);

    // Activem l'atribut colorLoc
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    glm::vec3 terra[6] = {
	glm::vec3(2.5, 0.0, 2.5),
	glm::vec3(2.5, 0.0, -2.5),
	glm::vec3(-2.5, 0.0, -2.5),
	
	glm::vec3(2.5, 0.0, 2.5),
	glm::vec3(-2.5, 0.0, -2.5),
	glm::vec3(-2.5, 0.0, 2.5)
  }; 
   glm::vec3 colorterra[6] = {
	glm::vec3(1,0,0),
	glm::vec3(0,0,1),
	glm::vec3(0,1,0),
	
	glm::vec3(1,0,0),
	glm::vec3(0,1,0),
	glm::vec3(0,0,1),
  };
    glGenVertexArrays(1, &VAOT);
    glBindVertexArray(VAOT);
    GLuint VBOTP;
    glGenBuffers(1, &VBOTP);
    glBindBuffer(GL_ARRAY_BUFFER, VBOTP);
    glBufferData(GL_ARRAY_BUFFER, sizeof(terra), terra, GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    GLuint VBOTC;
    glGenBuffers(1, &VBOTC);
    glBindBuffer(GL_ARRAY_BUFFER, VBOTC);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colorterra), colorterra, GL_STATIC_DRAW);

    // Activem l'atribut vertexLoc
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    glBindVertexArray(0);
}

void MyGLWidget::calculCapsaModel() {
    modelMin.x = modelMax.x = m.vertices()[0];
    modelMin.y = modelMax.y = m.vertices()[1];
    modelMin.z = modelMax.z = m.vertices()[2];
    for (unsigned int i = 3; i < m.vertices().size();i = i +3) {
        if (m.vertices()[i] > modelMax.x) modelMax.x = m.vertices()[i];
        if (m.vertices()[i] < modelMin.x) modelMin.x = m.vertices()[i];
        if (m.vertices()[i + 1] > modelMax.y) modelMax.y = m.vertices()[i + 1];
        if (m.vertices()[i + 1] < modelMin.y) modelMin.y = m.vertices()[i + 1];
        if (m.vertices()[i + 2] > modelMax.z) modelMax.z = m.vertices()[i + 2];
        if (m.vertices()[i + 2] < modelMin.z) modelMin.z = m.vertices()[i + 2];
    }
    //L'altura que volem posarli entre la resta del seu y max i min
    escala = 4.0f/(modelMax.y - modelMin.y);
    modelCentreBase = glm::vec3((modelMax.x + modelMin.x)/2, modelMin.y, (modelMax.z + modelMin.z)/2);
}

void MyGLWidget::calculaCapsaEscena() {
    escenaMax.x = 2.5f;
    escenaMax.y = 4.0f;
    escenaMax.z = 2.5f;
    escenaMin.x = -2.5f;
    escenaMin.y = 0.0f;
    escenaMin.z = -2.5f;
}

void MyGLWidget::calculCentreEscena() {
    escenaCentre = (escenaMax + escenaMin)/(glm::vec3(2.0f));
}

void MyGLWidget::calculRadiEscena() {
    escenaRadi = glm::distance(escenaMax,escenaMin)/2.0f;
}

void MyGLWidget::carregaShaders(){
    BL2GLWidget::carregaShaders();
    projLoc = glGetUniformLocation(program->programId(), "proj");
    viewLoc = glGetUniformLocation(program->programId(), "view");
}
void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      escala += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      escala -= 0.05;
      break;
    }
    case Qt::Key_R: { // rotar
      rotate += float(45*M_PI/180.0f);
      break;
    }
    case Qt::Key_O: { // canviar perspectiva
      if (perspectiva == 1) perspectiva = 0;
      else perspectiva = 1;
      break;
    }
    default: event->ignore(); break;
  }
  update();
}
