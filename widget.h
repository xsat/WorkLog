#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include "userview.h"

class Widget : public QWidget
{
    Q_OBJECT
private:
    //QVector<ParentView *> views;
    UserView *user;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
