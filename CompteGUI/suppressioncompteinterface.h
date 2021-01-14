#ifndef SUPPRESSIONCOMPTEINTERFACE_H
#define SUPPRESSIONCOMPTEINTERFACE_H

#include <QtGui/QDialog>
#include "ui_suppressioncompteinterface.h"

class SuppressionCompteInterface : public QDialog
{
    Q_OBJECT

public:
	SuppressionCompteInterface(QWidget *parent = 0);
    ~SuppressionCompteInterface();

    QString reqNoCompte() const;

public slots:
	void valideSuppression();

private:
    Ui::SuppressionCompteInterfaceClass ui;
};

#endif // SUPPRESSIONCOMPTEINTERFACE_H
