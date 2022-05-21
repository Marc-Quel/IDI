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
    glEnable(GL_DEPTH_TEST);
    iniCamera();
}
void MyGLWidget::iniCamera() {
    FOV = M_PI/2.0f;
    raw = 1.0f;
    Znear = 0.4f;
    Zfar = 3.0f;
    projectTransform();

    OBS = glm::vec3(0,0,1);
    VRP = glm::vec3(0,0,0);
    UP = glm::vec3(0,1,0);
    viewTransform();
}

void MyGLWidget::paintGL() {
    // Esborrem el frame-buffer
    glClear (GL_COLOR_BUFFER_BIT);

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
void MyGLWidget::modelTransform() {
    glm::mat4 trans;
    trans = glm::scale(trans, glm::vec3(escala));
    trans = glm::rotate(trans, rotate, glm::vec3(0,1,0));
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
    proj = glm::perspective(FOV, raw, Znear, Zfar);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &proj[0][0]);
}
void MyGLWidget::creaBuffers() {
    m.load("../assig/models/HomerProves.obj");
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
	glm::vec3(1.0, -1.0, 1.0),
	glm::vec3(1.0, -1.0, -1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	
	glm::vec3(1.0, -1.0, 1.0),
	glm::vec3(-1.0, -1.0, -1.0),
	glm::vec3(-1.0, -1.0, 1.0)
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
    case Qt::Key_R: { // escalar a més petit
      rotate += float(45*M_PI/180.0f);
      break;
    }
    default: event->ignore(); break;
  }
  update();
}
