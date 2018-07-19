#include "widget.h"
#include "ui_widget.h"
#include "dij.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*int main()
    {
        cin>>n>>m;
        init();
        for(int i=0;i<m;i++)
        {
            cin>>from>>to>>len;
            addedge(from, to, len);
        }
        cout<<"Please input startg:"<<endl;
        cin>>startg;
        cout<<"Please input end:"<<endl;
        cin>>end;
        Dij(n, startg,previous);
        cout<<dist[end]<<endl;
        searchPath(previous, startg, end);
        return 0;
    }*/
    init();
    addedge(1,2,1);
    addedge(1,3,1);
    addedge(2,4,3);
    addedge(3,4,3);
    addedge(2,5,8);
    addedge(5,6,6);
    addedge(4,6,2);
    addedge(3,8,7);
    addedge(5,7,4);
    addedge(6,8,4);
    addedge(6,9,2);
    addedge(8,9,4);
    addedge(8,11,3);
    addedge(7,10,3);
    addedge(9,10,5);
    addedge(10,12,2);
    addedge(9,13,5);
    addedge(8,14,2);
    addedge(11,14,2);
    addedge(13,14,5);
    addedge(12,13,2);
    addedge(12,15,2);
    addedge(15,16,10);
    addedge(12,17,3);
    addedge(14,17,6);
    addedge(16,17,9);
    this->dialog = new Dialog("",this);
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this->dialog, SLOT(show()));
}

Widget::~Widget()
{
    delete ui;
    this->dialog->close();
    delete this->dialog;
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    if(ui->comboBox->currentIndex() != 0){
        start = index;
        qDebug()<<start;
    }
}

void Widget::on_comboBox_2_currentIndexChanged(int index)
{
    if(ui->comboBox_2->currentIndex() != 0){
        end = index;
        qDebug()<<end;
    }
}

void Widget::on_pushButton_3_clicked()
{
    qDebug()<<start;
    qDebug()<<end;
    Dij(17,start);
    QString str = QString("最短路径距离为:  " + to_string(dist[end]) + '\n' + searchPath(start,end));
    this->dialog->setText(str);
}
