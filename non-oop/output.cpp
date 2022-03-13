#include "constants.h"
#include "structure.h"
#include "frame_transform.h"
#include "mainwindow.h"
#include "frame_funcs.h"

#include "cmath"
#include <QMessageBox>

void drawFr(frame3d fr, scenet_t *sc)
{
    sc->clear();
    for (int i = 0; i < fr.leng; i++)
    {
        bool ok = true;
        ok = frames_i_x(fr, i, true) != nullptr && frames_i_y(fr, i, true) != nullptr && frames_i_z(fr, i, true) != nullptr;
        ok = ok && frames_i_x(fr, i, false) != nullptr && frames_i_y(fr, i, false) != nullptr && frames_i_z(fr, i, false) != nullptr;
        double x1, x2, y2, y1, z1, z2;
        if (ok)
        {
            x1 = *frames_i_x(fr, i, true);
            x2 = *frames_i_x(fr, i, false);
            y1 = *frames_i_y(fr, i, true);
            y2 = *frames_i_y(fr, i, false);
            z1 = *frames_i_z(fr, i, true);
            z2 = *frames_i_z(fr, i, false);
            x1 = x1 - z1 * sqrt(0.5);
            y1 = y1 - z1 * sqrt(0.5);
            x2 = x2 - z2 * sqrt(0.5);
            y2 = y2 - z2 * sqrt(0.5);
            sc->addLine(x1, y1, x2, y2);
        }
    }
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

    case NULLPTR_COORD:
        mess.setText(QString("Попытка использования несуществующей координаты!"));
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
