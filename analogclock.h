#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
class analogclock: public QWidget
{
    Q_OBJECT
public:
    analogclock(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event);
};

#endif // ANALOGCLOCK_H
