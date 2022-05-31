// MyGLWidget.h
#include "BL3GLWidget.h"

class MyGLWidget : public BL3GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL3GLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void initializeGL ( );
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void iniMaterialTerra ();
    virtual void modelTransformPatricio ();

    void canviaPosFocus();
    void canviaColFocus();
    void canviaLlumAmbient();

  private:
    int printOglError(const char file[], int line, const char func[]);
    GLuint colFocusLoc, posFocusLocA, posFocusLocO, llumAmbientLoc, cameraFixeLoc, focusCameraLoc, focusAplicacioLoc;
    float XFocus;
    int focusCamera;
    int focusAplicacio;
};
