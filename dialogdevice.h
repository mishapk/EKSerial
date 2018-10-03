#ifndef DIALOGDEVICE_H
#define DIALOGDEVICE_H

#include <QDialog>

namespace Ui {
class DialogDevice;
}

class DialogDevice : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDevice(QWidget *parent = nullptr);
    ~DialogDevice();

private:
    Ui::DialogDevice *ui;
};

#endif // DIALOGDEVICE_H
