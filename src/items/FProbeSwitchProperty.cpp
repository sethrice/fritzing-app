/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2022 Fritzing GmbH

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************/

#include "FProbeSwitchProperty.h"
#include "debugdialog.h"
#include <QString>
#include <string>
#include <cctype>

FProbeSwitchProperty::FProbeSwitchProperty(FamilyPropertyComboBox *familyPropertyComboBox,
										   std::string property)
	: FProbe("Switch" + property)
	, m_familyPropertyComboBox(familyPropertyComboBox)
{
	assert(!property.empty() && std::isupper(property[0]));
}

void FProbeSwitchProperty::write(QVariant data) {
	int index = m_familyPropertyComboBox->findText(data.toString());
	DebugDialog::debug(QString("FProbeSwitchProperty index old: %1 index new: %2").arg(m_familyPropertyComboBox->currentIndex()).arg(index));
	DebugDialog::debug(QString("FProbeSwitchProperty text old: %1 text new: %2")
						   .arg(m_familyPropertyComboBox->itemText(m_familyPropertyComboBox->currentIndex())
						   , m_familyPropertyComboBox->itemText(index)));
	if (index != -1) {
		m_familyPropertyComboBox->setCurrentIndex(index);
	}
}

void FProbeSwitchProperty::insertIf(QString property,
									FamilyPropertyComboBox *comboBox,
									std::string propertyList)
{
	std::string propStd = property.toStdString();
	propStd[0] = std::toupper(propStd[0]);
	if (propertyList.find(propStd) != std::string::npos) {
		new FProbeSwitchProperty(comboBox, propStd);
	}
}
