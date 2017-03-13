#include <iostream>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->QuitButton, SIGNAL(clicked()), this, SLOT(quit_button()));
    QObject::connect(ui->comboBox_Algorithm, SIGNAL(activated(int)), this, SLOT(on_comboBox_Algorithm_activated(int)));
    QObject::connect(ui->comboBox_color, SIGNAL(activated(int)), this, SLOT(on_comboBox_LineColor_activated(int)));
    QObject::connect(ui->lineSizeBox, SIGNAL(valueChanged(double)), this, SLOT(on_LineSizeBox_valueChanged(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quit_button()
{
    exit(0);
}


void MainWindow::on_comboBox_Algorithm_activated(int index)
{
    ui->openGLWidget->algorithm = bool{index};
    ui->openGLWidget->repaint();
}

void MainWindow::on_comboBox_LineColor_activated(int index)
{
    ui->openGLWidget->colorChosed = index;
    ui->openGLWidget->repaint();
}

void MainWindow::on_LineSizeBox_valueChanged(double arg1)
{
    ui->openGLWidget->lineSize = arg1;
    ui->openGLWidget->repaint();
}
