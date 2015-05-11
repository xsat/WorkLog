#include "userview.h"

UserView::UserView(QWidget *parent)
    : QTableView(parent)
{
    createLoginWidgets();
    createRegistrationWidgets();
    setLoginWidgets();
    setFixedHeight(300);
    setFixedWidth(550);
    setStyleSheet(getStyles());
}

UserView::~UserView()
{
    for (auto *label: labels)
        delete label;
    for (auto *edit: edits)
        delete edit;
    for (auto *button: buttons)
        delete button;
}

void UserView::createLoginWidgets()
{
    labels.append(new QLabel("Login", this));
    labels[labels.size() - 1]->setGeometry(175, 20, 100, 30);
    labels[labels.size() - 1]->hide();
    labels[labels.size() - 1]->setAccessibleName("login");
    labels.append(new QLabel("Password", this));
    labels[labels.size() - 1]->setGeometry(175, 55, 100, 30);
    labels[labels.size() - 1]->hide();
    labels[labels.size() - 1]->setAccessibleName("login");
    labels.append(new QLabel("The email or password you \nentered is incorrect.", this));
    labels[labels.size() - 1]->setGeometry(20, 120, 250, 50);
    labels[labels.size() - 1]->setObjectName("error");
    labels[labels.size() - 1]->hide();
    labels[labels.size() - 1]->setAccessibleName("login");
    edits.append(new QLineEdit(this));
    edits[edits.size() - 1]->setGeometry(20, 20, 150, 30);
    edits[edits.size() - 1]->hide();
    edits[edits.size() - 1]->setAccessibleName("login");
    edits.append(new QLineEdit(this));
    edits[edits.size() - 1]->setGeometry(20, 55, 150, 30);
    edits[edits.size() - 1]->setEchoMode(QLineEdit::Password);
    edits[edits.size() - 1]->hide();
    edits[edits.size() - 1]->setAccessibleName("login");
    buttons.append(new QPushButton("&Sign in", this));
    buttons[buttons.size() - 1]->setGeometry(20, 90, 60, 30);
    buttons[buttons.size() - 1]->setCursor(QCursor(Qt::PointingHandCursor));
    buttons[buttons.size() - 1]->hide();
    buttons[buttons.size() - 1]->setAccessibleName("login");
    connect(buttons[buttons.size() - 1], SIGNAL(clicked()), this, SLOT(slotLogin()));
    buttons.append(new QPushButton("&Create an account", this));
    buttons[buttons.size() - 1]->setGeometry(85, 90, 120, 30);
    buttons[buttons.size() - 1]->setCursor(QCursor(Qt::PointingHandCursor));
    buttons[buttons.size() - 1]->hide();
    buttons[buttons.size() - 1]->setAccessibleName("login");
    connect(buttons[buttons.size() - 1], SIGNAL(clicked()), this, SLOT(slotToRegistration()));
}

void UserView::createRegistrationWidgets()
{
    labels.append(new QLabel("Email", this));
    labels[labels.size() - 1]->setGeometry(175, 20, 100, 30);
    labels[labels.size() - 1]->hide();
    labels[labels.size() - 1]->setAccessibleName("registration");
    labels.append(new QLabel("Login", this));
    labels[labels.size() - 1]->setGeometry(175, 55, 100, 30);
    labels[labels.size() - 1]->hide();
    labels[labels.size() - 1]->setAccessibleName("registration");
    labels.append(new QLabel("Password", this));
    labels[labels.size() - 1]->setGeometry(175, 90, 100, 30);
    labels[labels.size() - 1]->hide();
    labels[labels.size() - 1]->setAccessibleName("registration");
    labels.append(new QLabel("Re-password", this));
    labels[labels.size() - 1]->setGeometry(175, 125, 120, 30);
    labels[labels.size() - 1]->hide();
    labels[labels.size() - 1]->setAccessibleName("registration");
    edits.append(new QLineEdit(this));
    edits[edits.size() - 1]->setGeometry(20, 20, 150, 30);
    edits[edits.size() - 1]->hide();
    edits[edits.size() - 1]->setAccessibleName("registration");
    edits.append(new QLineEdit(this));
    edits[edits.size() - 1]->setGeometry(20, 55, 150, 30);
    edits[edits.size() - 1]->hide();
    edits[edits.size() - 1]->setAccessibleName("registration");
    edits.append(new QLineEdit(this));
    edits[edits.size() - 1]->setGeometry(20, 90, 150, 30);
    edits[edits.size() - 1]->setEchoMode(QLineEdit::Password);
    edits[edits.size() - 1]->hide();
    edits[edits.size() - 1]->setAccessibleName("registration");
    edits.append(new QLineEdit(this));
    edits[edits.size() - 1]->setGeometry(20, 125, 150, 30);
    edits[edits.size() - 1]->setEchoMode(QLineEdit::Password);
    edits[edits.size() - 1]->hide();
    edits[edits.size() - 1]->setAccessibleName("registration");
    buttons.append(new QPushButton("&Create", this));
    buttons[buttons.size() - 1]->setGeometry(20, 160, 60, 30);
    buttons[buttons.size() - 1]->setCursor(QCursor(Qt::PointingHandCursor));
    buttons[buttons.size() - 1]->hide();
    buttons[buttons.size() - 1]->setAccessibleName("registration");
    connect(buttons[buttons.size() - 1], SIGNAL(clicked()), this, SLOT(slotRegistration()));
    buttons.append(new QPushButton("&Sign in", this));
    buttons[buttons.size() - 1]->setGeometry(85, 160, 120, 30);
    buttons[buttons.size() - 1]->setCursor(QCursor(Qt::PointingHandCursor));
    buttons[buttons.size() - 1]->hide();
    buttons[buttons.size() - 1]->setAccessibleName("registration");
    connect(buttons[buttons.size() - 1], SIGNAL(clicked()), this, SLOT(slotToLogin()));
}

void UserView::slotLogin()
{

}

void UserView::slotToLogin()
{
    setLoginWidgets();
}

void UserView::slotRegistration()
{

}

void UserView::slotToRegistration()
{
    setRegistrationWidgets();
}

void UserView::setLoginWidgets()
{
    setWidgetsByName("login");
}

void UserView::setRegistrationWidgets()
{
    setWidgetsByName("registration");
}

void UserView::setWidgetsByName(const QString &name)
{
    for (auto *label: labels)
        setVisibleByName(label, name);
    for (auto *edit: edits)
        setVisibleByName(edit, name);
    for (auto *button: buttons)
        setVisibleByName(button, name);
}

void UserView::setVisibleByName(QWidget *widget, const QString &name)
{
    if (widget->accessibleName() == name)
        widget->show();
    else
        widget->hide();
}

const QString UserView::getStyles() const
{
    return QString(
        "QLabel { color: #404040; font-size: 16px; font-weight: bold; }"
        "QPushButton { background: #4d90fe; color: #fff; border: 1px solid #3079ed; font-weight: bold; }"
        "QLineEdit { background: #FAFFBD; border: 1px solid #d9d9d9; color: #000; font-size: 16px; font-weight: bold; qproperty-alignment: AlignCenter; }"
        "#user { background-color: #f7f7f7; }"
        "#error { color: red; }"
    );
}
