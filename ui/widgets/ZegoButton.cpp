#include "ZegoButton.h"

using namespace::std;

//
// 构造
//
ZegoButton::ZegoButton(QMainWindow *parent)
	: QObject(parent)
{
	m_pButton = new QPushButton(parent);
	m_pButton->setCursor(QCursor(Qt::PointingHandCursor));

	connect(this, SIGNAL(indexChanged()), this, SLOT(onIndexChanged()));
	connect(m_pButton, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
}

//
// 析构
// 
ZegoButton::~ZegoButton()
{
	release();
}

//
// 槽, 序号改变
//
void ZegoButton::onIndexChanged()
{
	m_pButton->setText(m_vTexts[m_uIndex]);
}

//
// 槽，按钮点击
//
void ZegoButton::onButtonClicked()
{
	m_uIndex = (m_uIndex + 1) % m_uCycle;
	emit indexChanged();
}

//
// 设置当前序号
//
void ZegoButton::setIndex(const unsigned int index)
{
	if (index < m_uCycle)
	{
		m_uIndex = index;
		emit indexChanged();
	}
}

//
// 设置循环周期
//
void ZegoButton::setCycle(const unsigned int cycle)
{
	m_uCycle = cycle;
}


//
// 设置循环显示文字+1
//
void ZegoButton::setTexts(vector<QString>& texts)
{
	m_vTexts.clear();
	for (unsigned int i = 0; i < m_uCycle && i < texts.size(); ++i)
	{
		m_vTexts.push_back(texts[i]);
	}
	emit indexChanged();
}

//
// 设置循环显示文字+2
//
void ZegoButton::setTexts(QString text, unsigned int index)
{
	if (index < m_vTexts.size())
	{
		m_vTexts[index] = text;
		m_pButton->setText(m_vTexts[m_uIndex]);
	}
	else
	{
		for (unsigned int i = 0; i < index - m_vTexts.size(); ++i)
		{
			m_vTexts.push_back(QString(""));
		}
		m_vTexts.push_back(text);
		m_pButton->setText(tr(m_vTexts[m_uIndex].toStdString().data()));
	}
}

//
// 设置位置
//
void ZegoButton::setPosition(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	m_rRect = QRect(x, y, w, h);
	m_pButton->setGeometry(m_rRect);
}

//
// 获取当前序号
//
unsigned int ZegoButton::index() const
{
	return m_uIndex;
}

//
// 连接按钮
//
void ZegoButton::connectSonButton(ZegoButton* sonButton)
{
	if (sonButton)
	{
		sonButton->m_pParentButton = this;
		connect(this, SIGNAL(indexChanged()), sonButton, SLOT(onParentButtonClicked()));
	}
}

//
// 取消连接按钮
//
void ZegoButton::disconncetSonButton(ZegoButton* sonButton)
{
	if (sonButton && sonButton->m_pParentButton)
	{
		disconnect(m_pParentButton, SIGNAL(indexChanged()), this, SLOT(onParentButtonClicked()));
		sonButton->m_pParentButton = nullptr;
	}
}

//
// 父按钮被点击
//
void ZegoButton::onParentButtonClicked()
{
	if ((m_pParentButton->index() == 1) && (this->index() == 0))
	{
		setIndex(1);
	}
}

//
// 释放资源
//
void ZegoButton::release()
{
	if (m_pButton)
	{
		delete m_pButton;
		m_pButton = nullptr;
	}
}