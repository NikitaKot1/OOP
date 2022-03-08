#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "structure.h"
#include "ioput.h"
#include "control.h"

#include <cstdio>
#include <cmath>
#include <QMessageBox>

frame3d fr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);/*
    frame3d fr;
    FILE* f = fopen("C:/msys64/home/PC/OOP/lab1/non-oop/frame.txt", "r");
    int rc = input_frame(f, fr);
    if (!rc)
    {
        drawFrame(fr);
    }
    else
        printMessage(rc);*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawFrame(frame3d fr)
{
    ui->graphicsView->scene()->clear();
    for (int i = 0; i < fr.leng; i++)
    {
        double x1 = fr.mass[i].start->x;
        double y1 = fr.mass[i].start->y;
        double x2 = fr.mass[i].end->x;
        double y2 = fr.mass[i].end->y;
        double z1 = fr.mass[i].start->z;
        double z2 = fr.mass[i].end->z;
        x1 = x1 - z1 * sqrt(0.5);
        y1 = y1 - z1 * sqrt(0.5);
        x2 = x2 - z2 * sqrt(0.5);
        y2 = y2 - z2 * sqrt(0.5);

        ui->graphicsView->scene()->addLine(x1, y1, x2, y2);
    }
}

void MainWindow::printMessage(err_type rc)
{
    QMessageBox mess;
    switch (rc) {
    case FILE_OPEN_ERR:
        mess.setText(QString("Ошибка открытия файла!"));
        break;

    case MEMORY_ERR:
        mess.setText(QString("Ошибка выделения памяти!"));
        break;

    case INPUT_ERR:
        mess.setText(QString("Ошибка чтения файла! Формат записи данных в файле неверен!"));
        break;

    case FRAME_I_ERR:
        mess.setText(QString("Попытка получения несуществующего отрезка!"));
        break;

    case NULLPTR_COORD:
        mess.setText(QString("Попытка использования несуществующей координаты!"));
        break;

    case NON_SECT_ERR:
        mess.setText(QString("Попытка использования несуществующего отрезка!"));
        break;

    case UNKNOWN_TAG:
        mess.setText(QString("Неизвествный тэг!"));
        break;

    default:
        mess.setText(QString("Неизвестная ошибка!"));
        break;
    }
}

//C:/msys64/home/PC/OOP/lab1/non-oop/frame.txt
void MainWindow::on_fileButton_clicked()
{
    std::string str = ui->fileEdit->text().toStdString();
    FILE* f = fopen(str.c_str(), "r");
    err_type rc = input_frame(f, fr);
    if (!rc)
        drawFrame(fr);
    else
        printMessage(rc);
}

void MainWindow::on_transferButton_clicked()
{
    action *act = new action;
    err_type rc = control(fr, TRANSFERE, *act);
    if (!rc)
        drawFrame(fr);
    else
        printMessage(rc);
}

