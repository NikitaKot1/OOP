#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "structure.h"
#include "constants.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fileButton_clicked();

    void on_transferButton_clicked();

private:
    void drawFrame(frame3d fr);
    void printMessage(err_type rc);


private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
};
#endif // MAINWINDOW_H
