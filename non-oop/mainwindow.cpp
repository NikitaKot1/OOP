#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "structure.h"
#include "input.h"
#include "control.h"
#include "frame_funcs.h"
#include "output.h"

frame3d fr;
action act;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fileButton_clicked()
{
    std::string str = ui->fileEdit->text().toStdString();
    FILE* f = fopen(str.c_str(), "r");
    err_type rc = input_frame(f, fr);
    control(fr, PRINT, act, ui->graphicsView->scene(), rc);
}

void MainWindow::on_transferButton_clicked()
{
    bool ok = true;
    act.tr.dx = ui->editDX->text().toFloat(&ok);
    if (ok)
        act.tr.dy = ui->editDY->text().toFloat(&ok);
    if (ok)
        act.tr.dz = ui->editDZ->text().toFloat(&ok);
    err_type rc = ok ? OK : INP_ACT_ERR;
    control(fr, TRANSFERE, act, ui->graphicsView->scene(), rc);
}


void MainWindow::on_scaleButton_clicked()
{
    bool ok = true;
    act.sc.kx = ui->editKX->text().toFloat(&ok);
    if (ok)
        act.sc.ky = ui->editKY->text().toFloat(&ok);
    if (ok)
        act.sc.kz = ui->editKZ->text().toFloat(&ok);
    err_type rc = ok ? OK : INP_ACT_ERR;
    control(fr, SCALE, act, ui->graphicsView->scene(), rc);
}


void MainWindow::on_rotateButton_clicked()
{
    bool ok = true;
    act.rt.ang_xy = ui->editAngXY->text().toFloat(&ok);
    if (ok)
        act.rt.nag_xz = ui->editAngXZ->text().toFloat(&ok);
    if (ok)
        act.rt.ang_yz = ui->editAngYZ->text().toFloat(&ok);
    err_type rc = ok ? OK : INP_ACT_ERR;
    control(fr, ROTATE, act, ui->graphicsView->scene(), rc);
}

