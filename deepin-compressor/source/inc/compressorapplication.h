#pragma once

#include "DApplication"
#include "mainwindow.h"

class CompressorApplication: public DApplication
{
    Q_OBJECT
public:
    CompressorApplication(int &argc, char **argv)
        : DApplication(argc, argv)
    {

    }

    void setMainWindow(MainWindow *wd) { mainWindow_ = wd; }

private:
    void handleQuitAction() override
    {
        if (mainWindow_ == nullptr)
            return;

        if (mainWindow_->applicationQuit(this) == false) {
            return;
        }

        //DApplication::handleQuitAction();
    }

    MainWindow *mainWindow_ = nullptr;
};
