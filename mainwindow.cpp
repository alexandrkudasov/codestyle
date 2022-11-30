#include "mainwindow.h"
#include <QtWidgets>
#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    int map_size = 2000;
        QGraphicsScene* scene = new QGraphicsScene();
        QPixmap map(map_size, map_size);
        QPainter p(&map);

        QColor array[200];
        for (int i = 0; i < 200; i++)
        {
            if (i < 44) array[i] = QColor(230, 46, 46);
            else if (i < 54) array[i] = QColor(230, 83, 46);
            else if (i < 64) array[i] = QColor(230, 114, 46);
            else if (i < 74) array[i] = QColor(230, 151, 46);
            else if (i < 84) array[i] = QColor(230, 200, 46);
            else if (i < 94) array[i] = QColor(194, 230, 46);
            else if (i < 104) array[i] = QColor(138, 230, 46);
            else if (i < 114) array[i] = QColor(58, 230, 46);
            else if (i < 124) array[i] = QColor(46, 230, 138);
            else if (i < 134) array[i] = QColor(46, 175, 230);
            else if (i < 144) array[i] = QColor(46, 80, 230);
           //else if (i < 95) array[i] = QColor(46, 80, 230);
           // else if (i < 100) array[i] = QColor(65, 46, 230);
           // else if (i < 105) array[i] = QColor(31, 18, 148);
            //else if (i < 110) array[i] = QColor(19, 10, 97);
            else array[i] = QColor(0, 0, 0);
        }

        for(int i = 0; i < map_size; i++){
            for(int j = 0; j < map_size; j++){
                int dBm;
                dBm = (int)getDBm(i + 1, j + 1, 1000, 1000);
               // dBm_array[1] = (int)getDBm(i + 1, j + 1, 850, 100);
               // dBm_array[2] = (int)getDBm(i + 1, j + 1, 278, 300);
               // dBm_array[3] = (int)getDBm(i + 1, j + 1, 756, 765);
               // dBm_array[4] = (int)getDBm(i + 1, j + 1, 58, 700);
               // for (int k = 0; k < 5; k++) {
                  //  for (int l = 0; l < 5; l++) {
                      //  if (dBm_array[l] > dBm_array[l + 1]) {
                       //     int b = dBm_array[l];
                        //    dBm_array[l] = dBm_array[l + 1];
                       //     dBm_array[l + 1] = b;
                      //  }
                 //   }
              //  }
                p.setPen(array[dBm]);
                p.drawPoint(i, j);
            }
        }

        p.end();
        scene->addPixmap(map);
        QGraphicsView* view = new QGraphicsView(scene);
        setCentralWidget(view);
    }

    double MainWindow::calcDBm (double dist, double h)
    {
        return (20 * (log10((40 * 3.14 * dist * 5) / 3)) + qMin(0.03 * pow(h, 1.72), 10.0) * log10(dist) - qMin(0.044 * pow(h, 1.72), 14.77) + (0.002 * log10(h) * dist));
    }

   double MainWindow::getDBm (int i, int j, int x, int y)
    {
        int a = qAbs(x - i);
        int b = qAbs(y - j);
        double dist = (qSqrt(a * a + b * b));
        double break_point = (2 * 3.14 * 50) / 3 * qPow(10, 8);
        double h = 5;

        if (dist < 10)
        {
            return 1;
        }
        else if (dist >= 10 && dist <= break_point)
        {
            return calcDBm(dist, h);
        }
        else if (dist > break_point && dist < 10000.0)
        {
            return (calcDBm(break_point, h) + (40 * log10(dist / break_point)));
        }
        else
        {
            return 199;
        }

    }



MainWindow::~MainWindow()
{

}

