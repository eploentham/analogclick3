#include <QtWidgets>
#include "analogclock.h"

analogclock::analogclock(QWidget *parent): QWidget(parent)

    {
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);

        setWindowTitle(tr("Analog Clock"));
        resize(1600, 800);

    }
void analogclock::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        close();
        break;
    default:
        QWidget::keyReleaseEvent(event);
    }
}
    void analogclock::paintEvent(QPaintEvent *)
    {
        static const QPoint hourHand[3] = {
            QPoint(7, 8),
            QPoint(-7, 8),
            QPoint(0, -40)
        };
        static const QPoint minuteHand[3] = {
            QPoint(7, 8),
            QPoint(-7, 8),
            QPoint(0, -70)
        };

        QColor hourColor(127, 0, 127);
        QColor minuteColor(0, 127, 127, 191);

        int side = qMin(width(), height());
        QTime time = QTime::currentTime();

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.translate(width() / 2, height() / 2);
        painter.scale(side / 200.0, side / 200.0);

        painter.setPen(Qt::NoPen);
        painter.setBrush(hourColor);

        painter.save();
        painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
        painter.drawConvexPolygon(hourHand, 3);
        painter.restore();
        painter.setPen(hourColor);

        for (int i = 0; i < 12; ++i) {
            //painter.setPen(hourColor);
            painter.drawLine(88, 0, 96, 0);
            painter.rotate(30.0);
            //painter.setPen(Qt::red);
            //painter.drawText(80,-20,QVariant(12-i).toString());
        }

        painter.setPen(Qt::red);
        painter.drawText(-10,-75,"12");
        painter.drawText(-5,85,"6");
        painter.drawText(60,40,"4");
        painter.drawText(-70,40,"8");
        painter.drawText(65,-35,"2");
        painter.drawText(-75,-35,"10");
        painter.drawText(35,-60,"1");
        painter.drawText(-45,-60,"11");
        painter.drawText(-45,73,"7");

        painter.setPen(Qt::NoPen);
        painter.setBrush(minuteColor);


        painter.save();
        painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
        painter.drawConvexPolygon(minuteHand, 3);
        painter.restore();

        painter.setPen(minuteColor);

        for (int j = 0; j < 60; ++j) {
            if ((j % 5) != 0)
                painter.drawLine(92, 0, 96, 0);
                //painter.drawLine(120, 0, 96, 0);
            painter.rotate(6.0);
        }
    }

