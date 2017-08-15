#include <qpushbutton.h>
#include <qmainwindow.h>
#include <vector>

#pragma once

using namespace::std;

class ZegoButton : public QObject
{
	Q_OBJECT

signals:
	void indexChanged();

private slots:
	void onIndexChanged();
	void onButtonClicked();

public:
	ZegoButton(QMainWindow *parent = 0);
	~ZegoButton();
	void release();

	void setIndex(const unsigned int index);
	void setCycle(const unsigned int cycle);
	void setTexts(vector<QString>& texts);
	void setTexts(QString text, unsigned int index);
	void setPosition(unsigned int x, unsigned int y, unsigned int w, unsigned int h);

	unsigned int index() const;

	void connectSonButton(ZegoButton* sonButton);
	void disconncetSonButton(ZegoButton* sonButton);

private slots:
	void onParentButtonClicked();

private:
	unsigned int m_uCycle = 1;
	unsigned int m_uIndex = 0;
	vector<QString> m_vTexts;
	QPushButton* m_pButton = nullptr;
	QRect m_rRect;
	ZegoButton* m_pParentButton = nullptr;
};