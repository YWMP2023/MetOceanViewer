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
#ifndef TIMEZONE_H
#define TIMEZONE_H

#include <QMap>
#include <QObject>
#include "metocean_global.h"
#include "timezonestruct.h"

class Timezone : public QObject {
  Q_OBJECT

 public:
  explicit Timezone(QObject *parent = nullptr);

  static int localMachineOffsetFromUtc();

  static int offsetFromUtc(QString value,
                           TZData::Location location = TZData::NorthAmerica);

  bool fromAbbreviation(QString value,
                        TZData::Location location = TZData::NorthAmerica);

  bool initialized();

  int utcOffset();

  int offsetTo(Timezone &zone);

  QString abbreviation();

  QStringList getAllTimezoneAbbreviations();
  QStringList getAllTimezoneNames();
  QStringList getTimezoneAbbreviations(TZData::Location location);
  QStringList getTimezoneNames(TZData::Location location);

 private:
  void build();

  bool m_initialized;

  TimezoneStruct m_zone;

  QMap<std::pair<TZData::Location, TZData::Abbreviation>, TimezoneStruct>
      m_timezones;
};

#endif  // TIMEZONE_H
