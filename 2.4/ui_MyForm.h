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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    MyGLWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
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


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        groupBox = new QGroupBox(MyForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout_4->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_4->addWidget(radioButton_2);


        verticalLayout_3->addWidget(groupBox);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(pushButton);


        horizontalLayout_4->addLayout(verticalLayout_3);


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

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "IDI-Lab", nullptr));
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
