#ifndef _LP_WIZARD_H
#define _LP_WIZARD_H

#include <QWizard>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>

#include "LPBackend.h"
#include "LPGUtils.h"

namespace Ui{
  class LPWizard;	
}

class LPWizard : public QWizard{
	Q_OBJECT
public:
	explicit LPWizard(QWidget *parent = 0);
	~LPWizard();

	//Input dataset
	void setDataset(QString);
	//Output variables
	bool cancelled, enableReplication, enableScrub;
	int localTime, totalSnapshots, remotePort, remoteTime, scrubTime, scrubDay;
	QString remoteHost, remoteUser, remoteDataset, scrubSchedule;

	virtual int nextId() const; //override the standard page order sometimes

private:
	Ui::LPWizard *ui;

private slots:
	void slotFinished();
	void slotCancelled();
	void scanNetwork();
	void on_combo_remote_freq_currentIndexChanged(int index);
	void UpdateScrubUI();
};

#endif
