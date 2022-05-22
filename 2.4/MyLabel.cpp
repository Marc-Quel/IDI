#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent) {
}

MyLabel::~MyLabel() {
}

void MyLabel::changeRed(int n) {
    r = n;
    std::string aux = "background-color: rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ");";
    setStyleSheet(QString::fromStdString(aux));
    emit changeColTerra(0,r,g,b);
    update();
}
        
void MyLabel::changeGreen(int n) {
    g = n;
    std::string aux = "background-color: rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ");";
    setStyleSheet(QString::fromStdString(aux));
    emit changeColTerra(0,r,g,b);
    update();
}

void MyLabel::changeBlue(int n){
    b = n;
    std::string aux = "background-color: rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ");";
    setStyleSheet(QString::fromStdString(aux));
    emit changeColTerra(0,r,g,b);
    update();
}