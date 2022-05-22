/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyGLWidget.h"
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    MyGLWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    MyLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QDial *dial;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QDial *dial_2;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QString::fromUtf8("MyForm"));
        MyForm->resize(957, 717);
        horizontalLayout_4 = new QHBoxLayout(MyForm);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new MyGLWidget(MyForm);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(50, 50));

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MyForm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(MyForm);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(90);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(MyForm);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(90);

        horizontalLayout->addWidget(spinBox);

        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox_2 = new QSpinBox(MyForm);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setSingleStep(1);
        spinBox_2->setStepType(QAbstractSpinBox::DefaultStepType);

        horizontalLayout->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(MyForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        spinBox_3 = new QSpinBox(MyForm);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMaximum(255);

        horizontalLayout_3->addWidget(spinBox_3);

        spinBox_4 = new QSpinBox(MyForm);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setMaximum(255);

        horizontalLayout_3->addWidget(spinBox_4);

        spinBox_5 = new QSpinBox(MyForm);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMaximum(255);

        horizontalLayout_3->addWidget(spinBox_5);


        verticalLayout_4->addLayout(horizontalLayout_3);

        label_6 = new MyLabel(MyForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0);"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_6);


        verticalLayout_6->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(MyForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        dial = new QDial(MyForm);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setMaximum(628);
        dial->setSingleStep(3);

        verticalLayout_2->addWidget(dial);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(MyForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        dial_2 = new QDial(MyForm);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setMaximum(628);
        dial_2->setSingleStep(3);

        verticalLayout_3->addWidget(dial_2);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_2);

        radioButton_3 = new QRadioButton(MyForm);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setCheckable(true);
        radioButton_3->setChecked(true);

        verticalLayout_6->addWidget(radioButton_3);

        groupBox = new QGroupBox(MyForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout_5->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_5->addWidget(radioButton_2);


        verticalLayout_6->addWidget(groupBox);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(pushButton);


        horizontalLayout_4->addLayout(verticalLayout_6);


        retranslateUi(MyForm);
        QObject::connect(pushButton, SIGNAL(clicked()), MyForm, SLOT(close()));
        QObject::connect(widget, SIGNAL(FOVchanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(FOVchanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), widget, SLOT(changeFOV(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), widget, SLOT(changeFOV(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(patricioRendered()), radioButton, SLOT(click()));
        QObject::connect(widget, SIGNAL(legoRendered()), radioButton_2, SLOT(click()));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), widget, SLOT(renderPatricio()));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), widget, SLOT(renderLego()));
        QObject::connect(radioButton_3, SIGNAL(clicked(bool)), widget, SLOT(changeProject(bool)));
        QObject::connect(widget, SIGNAL(projectChanged(bool)), radioButton_3, SLOT(click()));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), widget, SLOT(scaleModel(int)));
        QObject::connect(widget, SIGNAL(modelScaled(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(sliderMoved(int)), widget, SLOT(changePsi(int)));
        QObject::connect(dial_2, SIGNAL(sliderMoved(int)), widget, SLOT(changeTheta(int)));
        QObject::connect(widget, SIGNAL(psiChanged(int)), dial, SLOT(setValue(int)));
        QObject::connect(widget, SIGNAL(thetaChanged(int)), dial_2, SLOT(setValue(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), label_6, SLOT(changeRed(int)));
        QObject::connect(spinBox_4, SIGNAL(valueChanged(int)), label_6, SLOT(changeGreen(int)));
        QObject::connect(spinBox_5, SIGNAL(valueChanged(int)), label_6, SLOT(changeBlue(int)));
        QObject::connect(label_6, SIGNAL(changeColTerra(int,int,int,int)), widget, SLOT(changeTerra(int,int,int,int)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "IDI-Lab", nullptr));
        label->setText(QApplication::translate("MyForm", "FOV", nullptr));
        label_2->setText(QApplication::translate("MyForm", "Scale", nullptr));
        label_5->setText(QApplication::translate("MyForm", "RGB", nullptr));
        label_6->setText(QString());
        label_3->setText(QApplication::translate("MyForm", "Psi", nullptr));
        label_4->setText(QApplication::translate("MyForm", "Theta", nullptr));
        radioButton_3->setText(QApplication::translate("MyForm", "Project Type", nullptr));
        groupBox->setTitle(QApplication::translate("MyForm", "Model", nullptr));
        radioButton->setText(QApplication::translate("MyForm", "Patricio", nullptr));
        radioButton_2->setText(QApplication::translate("MyForm", "Lego", nullptr));
        pushButton->setText(QApplication::translate("MyForm", "&Sortir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H
