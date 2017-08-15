#include "ZegoButton.h"

using namespace::std;

//
// ����
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
// ����
// 
ZegoButton::~ZegoButton()
{
	release();
}

//
// ��, ��Ÿı�
//
void ZegoButton::onIndexChanged()
{
	m_pButton->setText(m_vTexts[m_uIndex]);
}

//
// �ۣ���ť���
//
void ZegoButton::onButtonClicked()
{
	m_uIndex = (m_uIndex + 1) % m_uCycle;
	emit indexChanged();
}

//
// ���õ�ǰ���
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
// ����ѭ������
//
void ZegoButton::setCycle(const unsigned int cycle)
{
	m_uCycle = cycle;
}


//
// ����ѭ����ʾ����+1
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
// ����ѭ����ʾ����+2
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
// ����λ��
//
void ZegoButton::setPosition(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	m_rRect = QRect(x, y, w, h);
	m_pButton->setGeometry(m_rRect);
}

//
// ��ȡ��ǰ���
//
unsigned int ZegoButton::index() const
{
	return m_uIndex;
}

//
// ���Ӱ�ť
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
// ȡ�����Ӱ�ť
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
// ����ť�����
//
void ZegoButton::onParentButtonClicked()
{
	if ((m_pParentButton->index() == 1) && (this->index() == 0))
	{
		setIndex(1);
	}
}

//
// �ͷ���Դ
//
void ZegoButton::release()
{
	if (m_pButton)
	{
		delete m_pButton;
		m_pButton = nullptr;
	}
}