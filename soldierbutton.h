#ifndef SOLDIERBUTTON_H
#define SOLDIERBUTTON_H
#include<QPushButton>
#include<QLabel>
class SoldierButton : public QPushButton
{
    Q_OBJECT
    QString soldierBtnImgImgPath;
    bool moveavailable;
public:
    //explicit SoldierButton(QWidget *parent = nullptr);
    SoldierButton(QString soldierBtnImg);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent *event);
signals:
    void click_soldier_button(QMouseEvent *event);
    void release_soldier_button(QMouseEvent *event);
};

#endif // SOLDIERBUTTON_H
