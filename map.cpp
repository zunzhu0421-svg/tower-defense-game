#include "map.h"
#include"road.h"
#include<QDebug>
#include<QLabel>
#include<QWidget>
#include<QFile>

int Map::get_width()const
{
    return width;
}
void Map::paint(QWidget* w)
{

    remote_num=0;
    for(int i=0;i<m_len/width-2;i++)
        for(int j=0;j<height/width;j++)
        {
            QLabel* label=new QLabel;
            switch(ground[i][j])
            {

            case stone_cell:
                label->setPixmap(StoneImg);
                break;
            case close_cell:
                label->setPixmap(CloseImg);
                break;
            case remote_cell:
                remote_num++;
                break;
            case end_cell:
                label->setPixmap(EndImg);
                break;
            case start_cell:
                label->setPixmap(StartImg);
                break;
            }
            label->setStyleSheet("QPushButton{border:Opx;}");
            label->setFixedSize(width,width);
            label->setParent(w);
            label->move(i*width,j*width);
            label->show();
        }

    AllRemoteButtons=new RemotePushButton*[remote_num];
    int k=0;
    for(int i=0;i<m_len/width-2;i++)
    {
        for(int j=0;j<height/width;j++)
        {
            if(ground[i][j]==remote_cell)
               {
                AllRemoteButtons[k]=new RemotePushButton(w);
                AllRemoteButtons[k]->move(i*width,j*width);
                AllRemoteButtons[k++]->setParent(w);
               }
        }
    }
}
Map::Map(/*QString Path*/)
{
    QFile in_file(":/Mapfile/mapfile.txt");
       if (!in_file.open(QIODevice :: ReadOnly))
           exit(-1);
       QString buffer;
       buffer=in_file.readLine();
       QTextStream s(&buffer);
       s>>r_num;
       allroad=new Road[r_num];
       int i=0;
       while(!in_file.atEnd())
       {
           buffer=in_file.readLine();
           QVector<QVector<int>> roadputin;
           QTextStream ss(&buffer);
           int t;
           int l;
            ss>>t>>l;
            allroad[i].set_type(t);
            buffer=in_file.readLine();
            QTextStream sss(&buffer);
           while (!sss.atEnd())
           {
               int x,y;
               sss>>x>>y;
               QVector<int> r;
               r.append(x);
               r.append(y);
               roadputin.append(r);
           }
           roadputin.pop_back();
           allroad[i].set_road(roadputin);
           allroad[i].map=this;
           i++;

       }
       int x,y;
       for(int k=0;k<r_num;k++)
       {
           for(int i=0;i<allroad[k].get_roadlen();i++)
           {
               x=allroad[k].get_road(i,0);
               y=allroad[k].get_road(i,1);
               if(allroad[k].get_type()!=stone_road)
               {
               if(i==0)
                   ground[x][y]=start_cell;
               else if(i==allroad[k].get_roadlen()-1)
                   ground[x][y]=end_cell;
               else
                   ground[x][y]=close_cell;
               }
               else
               ground[x][y]=stone_cell;
           }
       }
       //ground

       bool ret =StoneImg.load(":/Image/stone_cell.png");
       if(!ret)
       {
           qDebug()<<"picture fail";
           return;
       }
       ret =CloseImg.load(":/Image/close_cell.png");
       if(!ret)
       {
           qDebug()<<"picture fail";
           return;
       }
       ret =RemoteImg.load(":/Image/remote_cell.png");
       if(!ret)
       {
           qDebug()<<"picture fail";
           return;
       }
       ret =StartImg.load(":/Image/start.png");
       if(!ret)
       {
           qDebug()<<"picture fail";
           return;
       }
       ret =EndImg.load(":/Image/end.png");
       if(!ret)
       {
           qDebug()<<"picture fail";
           return;
       }
}
