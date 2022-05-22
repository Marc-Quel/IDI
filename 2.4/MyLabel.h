#include <QLabel>
class MyLabel : public QLabel {
    Q_OBJECT

    public:
        MyLabel(QWidget *parent);
        ~MyLabel();
    
    public slots:
        void changeRed(int n);
        void changeGreen(int n);
        void changeBlue(int n);
    signals:
        void changeColTerra(int n, int r, int g, int b);
    private:
        int r = 0;
        int g = 0;
        int b = 0;
};