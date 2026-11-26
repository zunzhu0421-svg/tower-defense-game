#include "soldierbutton.h"
#include<QDebug>
SoldierButton::SoldierButton(QString soldierBtnImg)
{
    soldierBtnImgImgPath=soldierBtnImg;
    QPixmap pix;
    bool ret =pix.load(soldierBtnImg);
    if(!ret)
    {
        qDebug()<<"picture fail";
        return;
    }
    setFixedSize(pix.width(),pix.height());
    setStyleSheet("QPushButton{border:Opx;}");
    setIcon(pix);
    setIconSize(QSize(pix.width(),pix.height()));
}
void SoldierButton::mousePressEvent(QMouseEvent* event)
{
        //窗体中相对鼠标位置与图片位置的判断，检测是否选中图片
            moveavailable=true;
}
void SoldierButton::mouseMoveEvent(QMouseEvent *event)
{
        if(moveavailable)
        {
           emit click_soldier_button(event);
        }
}
void SoldierButton::mouseReleaseEvent(QMouseEvent* event)
{
    if(moveavailable)
        emit release_soldier_button(event);
    moveavailable=false;
}
