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

class OptionsGroupWidget : public TDataWidget<sofa::helper::OptionsGroup >
{
    Q_OBJECT
public :

    OptionsGroupWidget(QWidget* parent, const char* name,
            core::objectmodel::Data<sofa::helper::OptionsGroup >* m_data)
        : TDataWidget<sofa::helper::OptionsGroup >(parent,name,m_data) {}

    ///In this method we  create the widgets and perform the signal / slots connections.
    virtual bool createWidgets();
    virtual void setDataReadOnly(bool readOnly);

protected:
    ///Implements how update the widgets knowing the data value.
    virtual void readFromData();

    ///Implements how to update the data, knowing the widget value.
    virtual void writeToData();

    QComboBox    *comboList;
};

} //namespace sofa::qt
