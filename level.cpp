#include "level.h"
#include<QIcon>
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include"enemyfly.h"
#include<QTime>
#include<QCoreApplication>
#include"road.h"
#include<QBrush>
#include"tower2.h"
#include"soldier2.h"
#include"enemyfly2.h"
#include"enemy2.h"
#include"tower3.h"
#include<QPropertyAnimation>
int coins;
Level::Level()
{
    this->setFixedSize(1050,630);
    this->setWindowTitle("关卡一");
    this->setWindowIcon(QPixmap(":/Image/Icon.png"));
    map=new Map;
    map->paint(this);
    coins=goldcoins;
    s1=new Soldiers;
    s1->setParent(this);
    s1->move(950,20);
    s1->show();
    s1->get_SoldierButton()->setParent(this);
    s1->get_SoldierButton()->show();
    s1->get_SoldierButton()->move(930,20);
    s2=new Soldier2;
    s2->setParent(this);
    s2->move(950,170);
    s2->show();
    s2->get_SoldierButton()->setParent(this);
    s2->get_SoldierButton()->show();
    s2->get_SoldierButton()->move(930,170);
    connect(s1->get_SoldierButton(),&SoldierButton::click_soldier_button,s1,&Soldiers::Picturemove);
    connect(s1->get_SoldierButton(),&SoldierButton::release_soldier_button,s1,&Soldiers::mouseReleaseEvent);
    connect(s2->get_SoldierButton(),&SoldierButton::click_soldier_button,s2,&Soldier2::Picturemove);
    connect(s2->get_SoldierButton(),&SoldierButton::release_soldier_button,s2,&Soldier2::mouseReleaseEvent);
    timer2=new QTimer;
    timer2->start(100);
    connect(timer2,&QTimer::timeout,this,&Level::moveArmy);
    for(int i=0;i<map->get_remotennum();i++)
    {
        connect(map->AllRemoteButtons[i]->choose_btns[0],&ChooseButton::clicked,[=](){
            Tower* tower=new Tower;
            if(coins>=tower->get_cost())
            {
                tower->setParent(this);
                tower->set_btn(map->AllRemoteButtons[i]);
                tower->move(map->AllRemoteButtons[i]->x(),map->AllRemoteButtons[i]->y());
                towerVector.append(tower);
                tower->show();
                coins-=tower->get_cost();
                map->AllRemoteButtons[i]->MymousePressEvent(-1,-1);
                map->AllRemoteButtons[i]->set_state(0);
            }
            else
                map->AllRemoteButtons[i]->MymousePressEvent(-1,-1);

        });
        connect(map->AllRemoteButtons[i]->choose_btns[1],&ChooseButton::clicked,[=](){
            Tower* tower=new Tower2;
            if(coins>=tower->get_cost())
            {
                tower->set_btn(map->AllRemoteButtons[i]);
                tower->setParent(this);
                tower->move(map->AllRemoteButtons[i]->x(),map->AllRemoteButtons[i]->y());
                towerVector.append(tower);
                tower->show();
                coins-=tower->get_cost();
                map->AllRemoteButtons[i]->MymousePressEvent(-1,-1);
                map->AllRemoteButtons[i]->set_state(0);
            }
            else
                map->AllRemoteButtons[i]->MymousePressEvent(-1,-1);

        });
        connect(map->AllRemoteButtons[i]->choose_btns[2],&ChooseButton::clicked,[=](){
            Tower* tower=new Tower3;
            if(coins>=tower->get_cost())
            {
                tower->set_btn(map->AllRemoteButtons[i]);
                tower->setParent(this);
                tower->move(map->AllRemoteButtons[i]->x(),map->AllRemoteButtons[i]->y());
                towerVector.append(tower);
                tower->show();
                coins-=tower->get_cost();
                map->AllRemoteButtons[i]->MymousePressEvent(-1,-1);
                map->AllRemoteButtons[i]->set_state(0);
            }
            else
                map->AllRemoteButtons[i]->MymousePressEvent(-1,-1);

        });
    }
    QPixmap pix;
    pix.load(":/Image/money.png");
    moneylabel=new QLabel;
    moneynum=new QLabel;
    moneylabel->setParent(this);
    moneylabel->move(930,560);
    moneylabel->setFixedSize(pix.width(),pix.height());
    moneylabel->setStyleSheet("QPushButton{border:Opx;}");
    moneylabel->setPixmap(pix);
    moneylabel->setBaseSize(QSize(pix.width(),pix.height()));
    moneynum->setParent(this);
    moneynum->move(975,560);
    moneynum->setFixedSize(pix.width(),pix.height());
    moneynum->setBaseSize(QSize(pix.width(),pix.height()));
    moneynum->raise();
    pix.load(":/Image/life.png");
    lifelabel=new QLabel;
    lifenum=new QLabel;
    lifelabel->setParent(this);
    lifelabel->move(930,525);
    lifelabel->setFixedSize(pix.width(),pix.height());
    lifelabel->setStyleSheet("QPushButton{border:Opx;}");
    lifelabel->setPixmap(pix);
    lifelabel->setBaseSize(QSize(pix.width(),pix.height()));
    lifenum->setParent(this);
    lifenum->move(975,525);
    lifenum->setFixedSize(pix.width(),pix.height());
    lifenum->setBaseSize(QSize(pix.width(),pix.height()));
    lifenum->raise();
    winLabel=new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/Image/win.png");
    winLabel->setParent(this);
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->move((this->width()-tmpPix.width())*0.5,-tmpPix.height());
    failLabel=new QLabel;
    tmpPix.load(":/Image/fail.png");
    failLabel->setParent(this);
    failLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    failLabel->setPixmap(tmpPix);
    failLabel->move((this->width()-tmpPix.width())*0.5,-tmpPix.height());

}
void Level::moveArmy()
{
    moneynum->setText(QString::number(coins));
    lifenum->setText(QString::number(life));
    if(win)
    {
        timer2->stop();
        timer0->stop();
        timer1->stop();
        QPropertyAnimation *animation=new QPropertyAnimation(winLabel,"geometry");
        //设置时间间隔
        animation->setDuration(1000);

        //设置开始位置
        animation->setStartValue(QRect(QPoint(winLabel->x(),winLabel->y()),QPoint(winLabel->x()+winLabel->width(),winLabel->height())));
        //设置结束位置
        animation->setEndValue(QRect(QPoint(winLabel->x(),winLabel->y()+500),QPoint(winLabel->x()+winLabel->width(),winLabel->height()+120)));

        //设置缓和曲线
        animation->setEasingCurve(QEasingCurve::OutBounce);
        //执行动画
        animation->start();
        winLabel->raise();
    }
    if(life<=0&&!over)
    {
        for(auto tp:towerVector)
            tp->hide();
        for(auto sp:soldierVector)
            sp->hide();
        for(auto ep:enemyVector)
            ep->hide();
        over=1;
        timer2->stop();
        timer0->stop();
        timer1->stop();
        QPropertyAnimation *animation=new QPropertyAnimation(failLabel,"geometry");
        //设置时间间隔
        animation->setDuration(1000);

        //设置开始位置
        animation->setStartValue(QRect(QPoint(failLabel->x(),failLabel->y()),QPoint(failLabel->x()+failLabel->width(),failLabel->height())));
        //设置结束位置
        animation->setEndValue(QRect(QPoint(failLabel->x(),failLabel->y()+500),QPoint(failLabel->x()+failLabel->width(),failLabel->height()+120)));

        //设置缓和曲线
        animation->setEasingCurve(QEasingCurve::OutBounce);
        //执行动画
        animation->start();
        //
        failLabel->raise();
    }
    if(s1->get_putdownsuccess())
    {
        soldierVector.append(s1);
        s1=new Soldiers;
        s1->setParent(this);
        s1->move(950,20);
        s1->show();
        s1->get_SoldierButton()->setParent(this);
        s1->get_SoldierButton()->show();
        s1->get_SoldierButton()->move(930,20);
        connect(s1->get_SoldierButton(),&SoldierButton::click_soldier_button,s1,&Soldiers::Picturemove);
        connect(s1->get_SoldierButton(),&SoldierButton::release_soldier_button,s1,&Soldiers::mouseReleaseEvent);
    }
    if(s2->get_putdownsuccess())
    {
        soldierVector.append(s2);
        s2=new Soldiers;
        s2->setParent(this);
        s2->move(950,20);
        s2->show();
        s2->get_SoldierButton()->setParent(this);
        s2->get_SoldierButton()->show();
        s2->get_SoldierButton()->move(930,20);
        connect(s2->get_SoldierButton(),&SoldierButton::click_soldier_button,s2,&Soldier2::Picturemove);
        connect(s2->get_SoldierButton(),&SoldierButton::release_soldier_button,s2,&Soldier2::mouseReleaseEvent);
    }
    int die_num=0;
    for(auto ep : enemyVector)
    {
        if(ep->get_die())
            die_num++;
        if(die_num==enemy_num)
            win=1;
        if(ep->get_hp()<=0)
        {
            ep->hide();
            //qDebug()<<"?";

        }
        else
        {

            ep->move_animation();
            if(ep->isarrive())
            {
                qDebug()<<">";
                life--;
            }
        }
        if(ep->get_type()==fly_enemy2)
        {
            ((EnemyFly2*)ep)->EnemyFly2::chooseEnemy(soldierVector,towerVector);
            (Enemy*)ep;
        }
        else if(ep->get_type()==fly_enemy)
        {
            ((EnemyFly*)ep)->EnemyFly::chooseEnemy(soldierVector,towerVector);
            (Enemy*)ep;
        }
        else
            ep->choose_enemy(soldierVector);
    }
    for(auto tp:towerVector)
    {
        if(tp->isactive())
        {
            tp->choose_enemy(enemyVector);
        }
    }
    for(auto sp : soldierVector)
    {
        //        qDebug()<<sp->get_HP();
        if(sp->isactive())
        {
            for(auto ep : enemyVector)
            {
                if(ep->isactive())
                {

                    if(ep->get_type()==ground_enemy&&!ep->get_isblocked()&&sp->attackjudge(ep->x(),ep->y()))
                    {
                        sp->addto_enemyVector(ep);
                    }
                }

            }
            sp->attack_enemy();
        }
    }
    for(auto ep : enemyVector)
    {
        if(ep->get_type()==fly_enemy2&&ep->get_isattack())
        {
            ep->be_blocked();
        }
    }

}


void Level::paintEvent(QPaintEvent *)
{
    //    QPainter painter(this);
    //    painter.drawPixmap(0,0,QPixmap(":/Image/map1.png"));

}



void Level::game_start()
{
    timer0 = new QTimer(this);
    timer0->start(1000);
    connect(timer0,&QTimer::timeout,[=](){
        coins+=5;
        //qDebug()<<coins;
    });
    enemy_action(10,5,5,5);
}
void Level::enemy_action(int type1num,int type2num,int type3num,int type4num)
{
    int groundroad_num=0;
    for(int i=0;i<map->get_roadnum();i++)
    {
        if(map->allroad[i].get_type()==ground_road)
            groundroad_num++;
    }
    timer1=new QTimer;
    timer1->start(100);
    int sleep;
//    for(int i=0;i<type1num;i++)
//    {
//        Enemy* enemy_1=new Enemy;
//        enemyVector.append(enemy_1);
//        sleep=enemy_1->get_moveinterval()/groundroad_num;
//        int road_index=i%groundroad_num;
//        enemy_1->setParent(this);
//        enemy_1->set_roadindex(road_index);
//        connect(timer1,&QTimer::timeout,[=](){
//            enemy_1->add_distance(enemy_1->get_speed());
//            enemy_1->moveEnemy(road_index,enemy_1->get_distance());
//            if(!enemy_1->get_die())
//                enemy_1->show();
//        });
//        Sleep(sleep);
//    }
    for(int i=0;i<type2num;i++)
    {
        Enemy* enemy_2=new EnemyFly;
        enemyVector.append(enemy_2);
        sleep=enemy_2->get_moveinterval();
        int road_index=groundroad_num;
        enemy_2->setParent(this);
        enemy_2->set_roadindex(road_index);
        connect(timer1,&QTimer::timeout,[=](){
            enemy_2->add_distance(enemy_2->get_speed());
            enemy_2->moveEnemy(road_index,enemy_2->get_distance());
            if(!enemy_2->get_die())
                enemy_2->show();
        });
        Sleep(sleep);
    }
    for(int i=0;i<type3num;i++)
    {
        Enemy* enemy_3=new EnemyFly2;
        enemyVector.append(enemy_3);
        sleep=enemy_3->get_moveinterval();
        int road_index=groundroad_num;
        enemy_3->setParent(this);
        enemy_3->set_roadindex(road_index);
        connect(timer1,&QTimer::timeout,[=](){
            enemy_3->add_distance(enemy_3->get_speed());
            enemy_3->moveEnemy(road_index,enemy_3->get_distance());
            if(!enemy_3->get_die())
                enemy_3->show();
        });
        Sleep(sleep);
    }
//    for(int i=0;i<type4num;i++)
//    {
//        Enemy* enemy_4=new Enemy2;
//        enemyVector.append(enemy_4);
//        sleep=enemy_4->get_moveinterval();
//        int road_index=i%groundroad_num;
//        enemy_4->setParent(this);
//        enemy_4->set_roadindex(road_index);
//        connect(timer1,&QTimer::timeout,[=](){
//            enemy_4->add_distance(enemy_4->get_speed());
//            enemy_4->moveEnemy(road_index,enemy_4->get_distance());
//            if(!enemy_4->get_die())
//                enemy_4->show();
//        });
//        Sleep(sleep);
//    }
    enemy_num=type1num+type2num+type3num+type4num;
}
void Level::Sleep(int msec)
{
    QTime dieTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
void Level::mousePressEvent(QMouseEvent* event)
{
    for(int i=0;i<map->get_remotennum();i++)
    {
        map->AllRemoteButtons[i]->MymousePressEvent(event->x(),event->y());
    }
}

