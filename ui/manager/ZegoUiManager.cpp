#include "ZegoUiManager.h"

//
// ����
//
ZegoUiManager::ZegoUiManager(QMainWindow* parent)
	: QObject(parent),
	m_pMainWindow(nullptr)
{
	setMainWindow(parent);
}

//
// ����
//
ZegoUiManager::~ZegoUiManager()
{
	if (m_ButtonMap.size())
	{
		for (auto iter = m_ButtonMap.begin(); iter != m_ButtonMap.end(); ++iter)
		{
			iter->second->release();
			iter->second = nullptr;
		}
	}
}

//
// ����������
//
void ZegoUiManager::setMainWindow(QMainWindow* pMainWindow)
{
	if (pMainWindow)
	{
		m_pMainWindow = pMainWindow;
	}
}

//
// ��Ӱ�ť
//
ZegoButton* ZegoUiManager::addButton(QString& key, vector<QString>& vec)
{
	if (m_pMainWindow)
	{
		ZegoButton* pButton = new ZegoButton(m_pMainWindow);
		
		pButton->setCycle(vec.size());
		pButton->setTexts(vec);

		m_ButtonMap.insert(map<QString, ZegoButton*>::value_type(key, pButton));

		return button(key);
	}
	return nullptr;
}

//
// ��ȡ��ť
//
ZegoButton* ZegoUiManager::button(QString& key) const
{
	return (m_ButtonMap.find(key))->second;
}
