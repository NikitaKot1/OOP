#include "constants.h"
#include "structure.h"
#include "frame_transform.h"
#include "mainwindow.h"
#include "frame_funcs.h"
#include "dot_funcs.h"
#include "output.h"
#include "cmath"
#include <QMessageBox>

void drawLine(scenet_t &sc, dot3d d1, dot3d d2)
{
    double z1 = sqrt(0.5) * get_dots_z(d1);
    double z2 = sqrt(0.5) * get_dots_z(d2);
    sc.addLine(get_dots_x(d1) - z1, get_dots_y(d1) - z1,
               get_dots_x(d2) - z2, get_dots_y(d2) - z2);
}

err_type drawFr(scenet_t &sc, frame3d fr)
{
    sc.clear();
    err_type rc = OK;
    for (size_t i = 0; i < frames_length_sects(fr); i++)
    {
        size_t ist = get_start_sect(get_sect(fr, i));
        size_t ien = get_end_sect(get_sect(fr, i));
        drawLine(sc, get_dot(fr, ist), get_dot(fr, ien));
    }
    return rc;
}

void printMessage(err_type rc)
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

    case UNKNOWN_COORD:
        mess.setText(QString("Попытка использования несуществующей координаты!"));
        break;

    case UNKNOWN_SECT:
        mess.setText(QString("Попытка использования несуществующего отрезка!"));
        break;

    case NON_SECT_ERR:
        mess.setText(QString("Попытка использования несуществующего отрезка!"));
        break;

    case UNKNOWN_TAG:
        mess.setText(QString("Неизвествный тэг!"));
        break;

    case INP_ACT_ERR:
        mess.setText(QString("Введенные значения должны быть представлены действительными десятичными числами!"));
        break;

    default:
        mess.setText(QString("Неизвестная ошибка!"));
        break;
    }
    mess.exec();
}
