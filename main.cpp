#include "ScreenCaptureDemoBeta.h"
#include <QtWidgets/QApplication>
#include <qtextcodec.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ScreenCaptureDemoBeta w;
	w.show();
	return a.exec();
}
