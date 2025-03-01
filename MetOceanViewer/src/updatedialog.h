/*-------------------------------GPL-------------------------------------//
//
// MetOcean Viewer - A simple interface for viewing hydrodynamic model data
// Copyright (C) 2019  Zach Cobell
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//-----------------------------------------------------------------------*/
#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDateTime>
#include <QDialog>
#include "boost/format.hpp"

namespace Ui {
class UpdateDialog;
}

class UpdateDialog : public QDialog {
  Q_OBJECT

 public:
  explicit UpdateDialog(QWidget *parent = nullptr);
  ~UpdateDialog();

  void runUpdater();
  bool checkForUpdate();

  struct gitVersion {
    int versionMajor;
    int versionMinor;
    int versionRev;
    int versionDev;
    int versionGit;
    std::string toString() {
      return boost::str(boost::format("%i - %i - %i - %i - %i") % versionMajor %
                        versionMinor % versionRev % versionDev % versionGit);
    }
  };

 private slots:
  void on_button_ok_clicked();

 private:
  Ui::UpdateDialog *ui;

  int getLatestVersionData();
  int parseGitVersion(QString versionString, gitVersion &version);
  void parseUpdateData();
  void setDialogText();

  QString currentVersion;
  QString latestVersion;
  QDateTime latestVersionDate;
  QString latestVersionURL;
  bool networkError;
  bool hasNewVersion;
};

#endif  // UPDATEDIALOG_H
