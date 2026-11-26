#include "choosebutton.h"
#include<QDebug>
ChooseButton::ChooseButton(QString Path)
{
    ChooseButtonImgPath=Path;
    QPixmap pix;
    bool ret =pix.load(ChooseButtonImgPath);
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
