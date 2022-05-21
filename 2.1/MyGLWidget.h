// MyGLWidget.h
#include "BL2GLWidget.h"
#include "../assig/Model/model.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();
  protected:
    virtual void initializeGL ( );
    virtual void carregaShaders();
    virtual void creaBuffers ();
    virtual void paintGL ( );
    virtual void keyPressEvent (QKeyEvent *event);
    virtual void modelTransform ();
    void modelTransformTerra();
    void projectTransform();
    void viewTransform();
    void iniCamera();
    GLuint VAO;
    GLuint VAOT;
    GLuint projLoc;
    GLuint viewLoc;
    float FOV, raw, Znear, Zfar;
    glm::vec3 OBS, VRP, UP;
    Model m;
    float rotate;
  private:
    int printOglError(const char file[], int line, const char func[]);
};
