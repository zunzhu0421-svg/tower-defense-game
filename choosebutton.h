#ifndef CHOOSEBUTTON_H
#define CHOOSEBUTTON_H

#include <QPushButton>

class ChooseButton : public QPushButton
{
    Q_OBJECT
    QString ChooseButtonImgPath;
public:
    ChooseButton(QString Path);
signals:

};

#endif // CHOOSEBUTTON_H
