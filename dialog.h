#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QPushButton>
class Dialog: public QDialog
{
public:
    explicit Dialog(QString _messege = "", QWidget *parent = 0);
    QPlainTextEdit *messege = 0;
    QPushButton *exitButton = 0;
    QVBoxLayout *layout = 0;
    void setText(QString _messege);
    virtual ~Dialog();
};

#endif // DIALOG_H
