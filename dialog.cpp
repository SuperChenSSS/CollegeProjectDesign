#include "dialog.h"

Dialog::Dialog(QString _messege, QWidget *parent) : QDialog(parent)
{
    this->messege = new QPlainTextEdit(_messege);
    this->exitButton = new QPushButton("EXIT");
    this->layout = new QVBoxLayout(this);
    this->layout->addWidget(this->messege);
    this->layout->addWidget(this->exitButton);
    this->setLayout(this->layout);

    connect(this->exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void Dialog::setText(QString _messege)
{
    if(!_messege.isEmpty())
        this->messege->setPlainText(_messege);
}

Dialog::~Dialog()
{

    delete this->messege;
    delete this->exitButton;
    delete this->layout;
}
