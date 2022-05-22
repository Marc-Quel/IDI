#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent) {
}

MyLabel::~MyLabel() {
}

void MyLabel::changeRed(int n) {
    
    if (n == 1) {
        if (g == 0 and b == 0) setStyleSheet("background-color: rgb(255,0,0);");
        else if (g == 0 and b == 1) setStyleSheet("background-color: rgb(255,0,255);");
        else if (g == 1 and b == 0) setStyleSheet("background-color: rgb(255,255,0);");
        else setStyleSheet("background-color: rgb(255,255,255);");
    }
    else {
        if (g == 0 and b == 0) setStyleSheet("background-color: rgb(0,0,0);");
        else if (g == 0 and b == 1) setStyleSheet("background-color: rgb(0,0,255);");
        else if (g == 1 and b == 0) setStyleSheet("background-color: rgb(0,255,0);");
        else setStyleSheet("background-color: rgb(0,255,255);");
    }
    
    r = n;
    emit changeColTerra(0,r,g,b);
    update();
}
        
void MyLabel::changeGreen(int n) {
    
    if (n == 1) {
        if (r == 0 and b == 0) setStyleSheet("background-color: rgb(0,255,0);");
        else if (r == 0 and b == 1) setStyleSheet("background-color: rgb(0,255,255);");
        else if (r == 1 and b == 0) setStyleSheet("background-color: rgb(255,255,0);");
        else setStyleSheet("background-color: rgb(255,255,255);");
    }
    else {
        if (r == 0 and b == 0) setStyleSheet("background-color: rgb(0,0,0);");
        else if (r == 0 and b == 1) setStyleSheet("background-color: rgb(0,0,255);");
        else if (r == 1 and b == 0) setStyleSheet("background-color: rgb(255,0,0);");
        else setStyleSheet("background-color: rgb(255,0,255);");
    }
    
    g = n;
    emit changeColTerra(1,r,g,b);
    update();
}

void MyLabel::changeBlue(int n){
    
    if (n == 1) {
        if (g == 0 and r == 0) setStyleSheet("background-color: rgb(0,0,255);");
        else if (g == 0 and r == 1) setStyleSheet("background-color: rgb(255,0,255);");
        else if (g == 1 and r == 0) setStyleSheet("background-color: rgb(0,255,255);");
        else setStyleSheet("background-color: rgb(255,255,255);");
    }
    else {
        if (g == 0 and r == 0) setStyleSheet("background-color: rgb(0,0,0);");
        else if (g == 0 and r == 1) setStyleSheet("background-color: rgb(255,0,0);");
        else if (g == 1 and r == 0) setStyleSheet("background-color: rgb(0,255,0);");
        else setStyleSheet("background-color: rgb(255,255,0);");
    }
    
    b = n;
    emit changeColTerra(2,r,g,b);
    update();
}