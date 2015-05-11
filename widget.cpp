#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    user = new UserView(this);
}

Widget::~Widget()
{
    delete user;
}
