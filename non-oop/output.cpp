#include "constants.h"
#include "structure.h"
#include "frame_transform.h"
#include "mainwindow.h"
#include "frame_funcs.h"

#include "cmath"
#include <QMessageBox>

err_type drawFr(scenet_t &sc, frame3d fr)
{
    sc.clear();
    err_type rc = OK;
    for (int i = 0; i < frames_length_sects(fr); i++)
    {
        double x1, x2, y2, y1, z1, z2;
        int i1, i2;
        rc = get_i_sect(i1, i2, i, fr);
        if (rc == OK)
            rc = get_dot_i_x(x1, i1, fr);
        if (rc == OK)
            rc = get_dot_i_x(x2, i2, fr);

        if (rc == OK)
            rc = get_dot_i_y(y1, i1, fr);
        if (rc == OK)
            rc = get_dot_i_y(y2, i2, fr);

        if (rc == OK)
            rc = get_dot_i_z(z1, i1, fr);
        if (rc == OK)
            rc = get_dot_i_z(z2, i2, fr);

        if (rc == OK)
        {
            x1 = x1 - z1 * sqrt(0.5);
            y1 = y1 - z1 * sqrt(0.5);
            x2 = x2 - z2 * sqrt(0.5);
            y2 = y2 - z2 * sqrt(0.5);

            sc.addLine(x1, y1, x2, y2);
        }
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
