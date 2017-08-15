#include <qdesktopwidget.h>

#include "ScreenCaptureDemoBeta.h"


ScreenCaptureDemoBeta::ScreenCaptureDemoBeta(QWidget *parent)
	: QMainWindow(parent)
{
	QDesktopWidget desk;
	QRect deskRect = desk.geometry();
	setGeometry(deskRect.x() + (deskRect.width() >> 2), deskRect.y() + (deskRect.height() >> 2), deskRect.width() >> 1, deskRect.height() >> 1);

	m_zUiManager = new ZegoUiManager(this);

	vector<QString> vec(1, QStringLiteral("开始捕获"));
	vec.push_back(QStringLiteral("停止捕获"));
	m_pButtonCapture = m_zUiManager->addButton(QString("Capture"), vec);
	m_pButtonCapture->setPosition(0, 0, 80, 30);

	vec.clear();
	vec.push_back(QStringLiteral("开始推流"));
	vec.push_back(QStringLiteral("停止推流"));
	m_pButtonPublish = m_zUiManager->addButton(QString("Publish"), vec);
	m_pButtonPublish->setPosition(90, 0, 80, 30);
	m_pButtonPublish->connectSonButton(m_pButtonCapture);

	ZegoGroupBox* gp = new ZegoGroupBox(this);
	gp->setTitle("Hello");
	gp->setGeometry(40, 40, 100, 100);

}
