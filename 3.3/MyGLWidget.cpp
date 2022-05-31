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

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
  makeCurrent();
  // Aqui cal que es calculi i s'apliqui la rotacio o el zoom com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotació
    angleY += (e->x() - xClick) * M_PI / ample;
    viewTransform ();
  }

  xClick = e->x();
  yClick = e->y();

  update ();
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
      case Qt::Key_K: 
        XFocus -= 0.1;
        canviaPosFocus();
        break;
    case Qt::Key_L: 
        XFocus += 0.1;
        canviaPosFocus();
        break;
    case Qt::Key_1:
        if (focusCamera) focusCamera = 0;
        else focusCamera = 1;
        glUniform1i(focusCameraLoc, focusCamera);
        break;
    case Qt::Key_2:
        if (focusAplicacio) focusAplicacio = 0;
        else focusAplicacio = 1;
        glUniform1i(focusAplicacioLoc, focusAplicacio);
        break;
    case Qt::Key_B: 
        glEnable(GL_CULL_FACE);
        break;
    default: BL3GLWidget::keyPressEvent(event); break;
  }
  update();
}
void MyGLWidget::initializeGL() {
    BL3GLWidget::initializeGL();
    calculaCapsaModel();

    colFocusLoc = glGetUniformLocation(program->programId(), "colorFocus");
    posFocusLocA = glGetUniformLocation(program->programId(), "posFocusA");
    posFocusLocO = glGetUniformLocation(program->programId(), "posFocusO");
    focusCameraLoc = glGetUniformLocation(program->programId(), "focusCamera");
    focusAplicacioLoc = glGetUniformLocation(program->programId(), "focusAplicacio");
    llumAmbientLoc = glGetUniformLocation(program->programId(), "llumAmbient");
    cameraFixeLoc = glGetUniformLocation(program->programId(), "cameraFixe");
    
    XFocus = 0.0f;
    focusCamera = 1;
    glUniform1i(focusCameraLoc, focusCamera);
    focusAplicacio = 1;
    glUniform1i(focusAplicacioLoc, focusAplicacio);
    canviaPosFocus();
    canviaColFocus();
    canviaLlumAmbient();
}

void MyGLWidget::canviaPosFocus() {
    glm::vec3 posFocusA = glm::vec3(XFocus, 0.5, 0.0);
    glm::vec3 posFocusO = glm::vec3(0.0, 0.0, 0.0);
    
    glUniform3fv(posFocusLocA, 1, &posFocusA[0]);
    glUniform3fv(posFocusLocO, 1, &posFocusO[0]);
}
void MyGLWidget::canviaColFocus() {
    glm::vec3 colFocus = glm::vec3(0.8, 0.8, 0.8);
    glUniform3fv(colFocusLoc, 1, &colFocus[0]);
}
void MyGLWidget::canviaLlumAmbient() {
    glm::vec3 llumAmbient = glm::vec3(0.2, 0.2, 0.2);
    glUniform3fv(llumAmbientLoc, 1, &llumAmbient[0]);
}
void MyGLWidget::iniMaterialTerra () {
  // Donem valors al material del terra
  amb = glm::vec3(0.2,0,0.2);
  //Es el colorete
  diff = glm::vec3(0,0,1);

  //Lo que influya la posicion de la luz respecto la posicion del observador
  spec = glm::vec3(1,1,1);

  //Augmenta o disminueix la llum relfexada
  //Com mes petit mes llum es veu
  shin = 10;
}

void MyGLWidget::modelTransformPatricio () {
  TG = glm::translate(glm::mat4(1.f), glm::vec3(0,-0.85,0));
  TG = glm::scale(TG, glm::vec3(0.15*escala,0.15*escala,0.15*escala));
  TG = glm::translate(TG, -centrePatr);
  
  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}