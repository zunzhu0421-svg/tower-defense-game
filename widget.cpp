#include "widget.h"
#include "ui_widget.h"
#include<QTimer>
#include<QPainter>
#include<QDebug>
#include"map.h"
#include"mypushbutton.h"
#include"level.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("王国保卫战");
    this->setWindowIcon(QPixmap(":/Image/Icon.png"));
    Map map;
    this->setFixedSize(map.get_maplen(),map.get_height());
    MyPushButton* startBtn=new MyPushButton(":/Image/start1.png",":/Image/start2.png");
    startBtn->move(370,330);
    startBtn->setParent(this);
    connect(startBtn,&QPushButton::clicked,[=]()
    {
        qDebug()<<"clicked the startBtn";
        startBtn->zoomdown();
        startBtn->zoomup();
        QTimer::singleShot(200,[=](){
            Level* level1=new Level;
            connect(this,&Widget::get_into_level,level1,&Level::game_start);
            this->hide();
            level1->show();
            emit get_into_level();
        });
    });

}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/Image/map1.png"));
    painter.drawPixmap(0,0,QPixmap(":/Image/menu.jpg"));
    // painter.drawPixmap(370,330,QPixmap(":/Image/start1.png"));

}

