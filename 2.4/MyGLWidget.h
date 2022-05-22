// MyGLWidget.h
#include "BL2GLWidget.h"
#include "../assig/Model/model.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  public slots:
    void changeFOV(int n);
    void renderPatricio();
    void renderLego();
    void changeProject(bool n);
    void scaleModel(int n);
    void changePsi(int n);
    void changeTheta(int n);
  signals:
    void FOVchanged(int n);
    void patricioRendered();
    void legoRendered();
    void projectChanged(bool n);
    void modelScaled(int n);
    void psiChanged(int n);
    void thetaChanged(int n);

  protected:
    virtual void initializeGL ( );
    virtual void carregaShaders();
    virtual void creaBuffers ();
    virtual void paintGL ( );
    virtual void keyPressEvent (QKeyEvent *event);
    virtual void resizeGL (int width, int height);
    virtual void mouseMoveEvent(QMouseEvent *e);

    virtual void modelTransform ();
    void modelTransform1 ();
    void modelTransform2 ();
    void modelTransform3 ();
    void modelTransformTerra();
    void projectTransform();
    void viewTransform();
    void iniCamera();

    void calculCapsaModel();
    void calculaCapsaEscena();
    void calculCentreEscena();
    void calculRadiEscena();

    GLuint VAO;
    GLuint VAO1;
    GLuint VAOT;
    GLuint projLoc;
    GLuint viewLoc;

    float distancia, FOVini, FOV, raw, Znear, Zfar;
    float l,r,t,b;
    glm::vec3 OBS, VRP, UP;

    glm::vec3 modelMax, modelMin, modelCentreBase;
    glm::vec3 escenaMax, escenaMin;
    glm::vec3 escenaCentre;
    float escenaRadi;
    Model m;
    Model m1;

    float rotate;
    float girPsi, girTheta;
    float x_ant, y_ant;
    int perspectiva;
    int patricio;
  private:
    int printOglError(const char file[], int line, const char func[]);
};
