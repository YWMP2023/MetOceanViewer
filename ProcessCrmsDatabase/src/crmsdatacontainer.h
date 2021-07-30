/*-------------------------------GPL-------------------------------------//
//
// MetOcean Viewer - A simple interface for viewing hydrodynamic model data
// Copyright (C) 2018  Zach Cobell
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
#ifndef CRMSDATACONTAINER_H
#define CRMSDATACONTAINER_H

#include <string>
#include <vector>

class CrmsDataContainer {
 public:
  CrmsDataContainer(size_t size);
  CrmsDataContainer(const CrmsDataContainer &c);

  std::string id() const;
  void setId(const std::string &id);

  bool valid() const;
  void setValid(bool valid);

  long long datetime() const;
  void setDatetime(long long datetime);

  float value(size_t index) const;
  void setValue(size_t index, float value);

  size_t size() const;

 private:
  std::string m_id;
  bool m_valid;
  size_t m_size;
  long long m_datetime;
  std::vector<float> m_values;
};

#endif  // CRMSDATACONTAINER_H
