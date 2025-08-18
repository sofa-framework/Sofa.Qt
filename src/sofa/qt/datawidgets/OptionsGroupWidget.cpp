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

#include <sofa/helper/Factory.inl>
#include <sofa/qt/datawidgets/OptionsGroupWidget.h>

namespace sofa::qt
{
//these functions must be written here for effect of writeToData
Creator<DataWidgetFactory,OptionsGroupWidget> DWClass_OptionsGroup("default",true);

bool OptionsGroupWidget::createWidgets()
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    comboList=new QComboBox(this);
    comboList->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    auto optiongroup = getData()->getValue();
    QStringList list;
    for(unsigned int i=0; i<optiongroup.size(); i++) list << optiongroup[i].c_str();

    comboList->insertItems(0, list);
    comboList->setCurrentIndex(optiongroup.getSelectedId());

    connect(comboList, SIGNAL(activated(int)), this, SLOT(setWidgetDirty()));
    layout->addWidget(comboList);

    return true;
}
void OptionsGroupWidget::setDataReadOnly(bool readOnly)
{
    comboList->setEnabled(!readOnly);
}

void OptionsGroupWidget::readFromData()
{
    auto optiongroup = getData()->getValue();
    comboList->setCurrentIndex(optiongroup.getSelectedId());
}

void OptionsGroupWidget::writeToData()
{
    auto optiongroup = getData()->getValue();
    optiongroup.setSelectedItem(static_cast<std::size_t>(comboList->currentIndex()));
    getData()->setValue(optiongroup);
}

} //namespace sofa::qt
