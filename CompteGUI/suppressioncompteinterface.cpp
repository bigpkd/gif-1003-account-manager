#include <qmessagebox.h>
#include <suppressioncompteinterface.h>
#include <sstream>

using namespace std;

SuppressionCompteInterface::SuppressionCompteInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(valideSuppression()));
}

SuppressionCompteInterface::~SuppressionCompteInterface()
{

}

QString SuppressionCompteInterface::reqNoCompte() const{
	return ui.lineEditNoCompte->text();
}

void SuppressionCompteInterface::valideSuppression()
{
	if (ui.lineEditNoCompte->text().isEmpty()){
		QString message("Veuillez entrez un numero de compte non vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}else{
		accept();
	}
}
