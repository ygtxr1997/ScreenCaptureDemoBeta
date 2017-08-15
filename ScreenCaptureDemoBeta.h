#pragma once

#include <QtWidgets/QMainWindow>
#include <qlayout.h>

#include "./ui/manager/ZegoUiManager.h"

class ScreenCaptureDemoBeta : public QMainWindow
{
	Q_OBJECT

public:
	ScreenCaptureDemoBeta(QWidget *parent = Q_NULLPTR);

private:
	ZegoUiManager* m_zUiManager;
	ZegoButton* m_pButtonPublish = nullptr;
	ZegoButton* m_pButtonCapture = nullptr;
};
