#ifndef USERVIEW_H
#define USERVIEW_H

#include <QTableView>
#include <QVector>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "usermodel.h"

class UserView : public QTableView
{
    Q_OBJECT
private:
    QVector<QLabel *> labels;
    QVector<QLineEdit *> edits;
    QVector<QPushButton *> buttons;
    UserModel *userModel;
    void createLoginWidgets();
    void createRegistrationWidgets();
    void setLoginWidgets();
    void setRegistrationWidgets();
    void setWidgetsByName(const QString &name);
    void setVisibleByName(QWidget * widget,  const QString &name);
    const QString getStyles() const;
private slots:
    void slotLogin();
    void slotToLogin();
    void slotRegistration();
    void slotToRegistration();
public:
    UserView(QWidget *parent = 0);
    ~UserView();
};

#endif // USERVIEW_H
