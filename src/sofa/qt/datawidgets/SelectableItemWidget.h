/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU General Public License as published by the Free  *
* Software Foundation; either version 2 of the License, or (at your option)   *
* any later version.                                                          *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for    *
* more details.                                                               *
*                                                                             *
* You should have received a copy of the GNU General Public License along     *
* with this program. If not, see <http://www.gnu.org/licenses/>.              *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#pragma once

#include <sofa/qt/SimpleDataWidget.h>
#include <sofa/qt/DataWidget.h>

namespace sofa::qt
{

class SelectableItemWidget final : public TDataWidget<helper::BaseSelectableItem>
{
    Q_OBJECT

public :
    SelectableItemWidget(QWidget* parent, const char* name,
            core::BaseData* m_data, const helper::BaseSelectableItem* item);

    bool createWidgets() override;
    void setDataReadOnly(bool readOnly) override;

protected:
    void readFromData() override;
    void writeToData() override;

    QComboBox    *m_comboList { nullptr };
    const helper::BaseSelectableItem* m_selectableItem { nullptr };
};


} //namespace sofa::qt
