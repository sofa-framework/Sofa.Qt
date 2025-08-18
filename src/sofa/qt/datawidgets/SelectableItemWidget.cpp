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
#include <sofa/qt/datawidgets/SelectableItemWidget.h>

namespace sofa::qt
{

Creator<DataWidgetFactory, SelectableItemWidget> DWClass_SelectableItem("default",true);

SelectableItemWidget::SelectableItemWidget(QWidget* parent, const char* name,
    core::BaseData* m_data, const helper::BaseSelectableItem* item)
: TDataWidget(parent, name, m_data, item)
, m_selectableItem(item)
{}

bool SelectableItemWidget::createWidgets()
{
    if ((Tdata && Tdata->getValueTypeString() != "SelectableItem") ||
        (baseData && baseData->getValueTypeString() != "SelectableItem"))
    {
        return false;
    }

    QVBoxLayout* layout = new QVBoxLayout(this);

    assert(m_selectableItem);
    const std::size_t nbItems = m_selectableItem->getNumberOfItems();
    const auto* items = m_selectableItem->getItemsData();

    m_comboList=new QComboBox(this);
    m_comboList->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    for (std::size_t i = 0; i < nbItems; i++)
    {
        m_comboList->addItem(QString::fromUtf8(items[i].key));
        m_comboList->setItemData(i, QString::fromUtf8(items[i].description), Qt::ToolTipRole);
    }
    m_comboList->setCurrentIndex(m_selectableItem->getSelectedId());

    connect(m_comboList, SIGNAL(activated(int)), this, SLOT(setWidgetDirty()));
    layout->addWidget(m_comboList);

    return true;
}

void SelectableItemWidget::setDataReadOnly(const bool readOnly)
{
    m_comboList->setEnabled(!readOnly);
}

void SelectableItemWidget::readFromData()
{
    m_comboList->setCurrentIndex(m_selectableItem->getSelectedId());
}

void SelectableItemWidget::writeToData()
{
    const_cast<helper::BaseSelectableItem*>(m_selectableItem)->setSelectedId(static_cast<std::size_t>(m_comboList->currentIndex()));
}


} //namespace sofa::qt
