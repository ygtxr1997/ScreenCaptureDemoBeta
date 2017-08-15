#include <map>
#include <qmainwindow.h>

#pragma once

#include "../widgets/ZegoButton.h"
#include "../widgets/ZegoGroupBox.h"

using namespace::std;

class ZegoUiManager : public QObject
{
public:
	ZegoUiManager(QMainWindow* parent = 0);
	~ZegoUiManager();

	void setMainWindow(QMainWindow* mainWindow);

	ZegoButton* addButton(QString& key, vector<QString>& vec);
	ZegoButton* button(QString& key) const;

private:
	QMainWindow* m_pMainWindow;
	map<QString, ZegoButton*> m_ButtonMap;
};