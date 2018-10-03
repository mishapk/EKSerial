#include "dialogdevice.h"
#include "ui_dialogdevice.h"

DialogDevice::DialogDevice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDevice)
{
    ui->setupUi(this);
}

DialogDevice::~DialogDevice()
{
    delete ui;
}
