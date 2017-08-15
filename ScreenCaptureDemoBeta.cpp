#include <qdesktopwidget.h>

#include "ScreenCaptureDemoBeta.h"


ScreenCaptureDemoBeta::ScreenCaptureDemoBeta(QWidget *parent)
	: QMainWindow(parent)
{
	QDesktopWidget desk;
	QRect deskRect = desk.geometry();
	setGeometry(deskRect.x() + (deskRect.width() >> 2), deskRect.y() + (deskRect.height() >> 2), deskRect.width() >> 1, deskRect.height() >> 1);

	m_zUiManager = new ZegoUiManager(this);

	vector<QString> vec(1, QStringLiteral("��ʼ����"));
	vec.push_back(QStringLiteral("ֹͣ����"));
	m_pButtonCapture = m_zUiManager->addButton(QString("Capture"), vec);
	m_pButtonCapture->setPosition(0, 0, 80, 30);

	vec.clear();
	vec.push_back(QStringLiteral("��ʼ����"));
	vec.push_back(QStringLiteral("ֹͣ����"));
	m_pButtonPublish = m_zUiManager->addButton(QString("Publish"), vec);
	m_pButtonPublish->setPosition(90, 0, 80, 30);
	m_pButtonPublish->connectSonButton(m_pButtonCapture);

	ZegoGroupBox* gp = new ZegoGroupBox(this);
	gp->setTitle("Hello");
	gp->setGeometry(40, 40, 100, 100);

}
