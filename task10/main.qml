import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

//
// Создать программу-органайзер, в которую можно будет вводить задачи.
// Каждая задача состоит из следующих пунктов:
// — название задачи
// — дата окончания выполнения задачи (дедлайн - в формате dd.mm.yyyy)
// — текущий прогресс (число от 0 до 10)
// С помощью QML создать графический интерфейс программы для ввода данных и кнопку для записи задачи.
// Предусмотреть возможность при закрытии программы сохранения всех введенных пользователем задач в файл,


// а при открытии подгрузить данные из файла.
// Последующие задачи дозаписывать в уже существующий файл.
// Отображать задачи в программе не надо.
//

import SavingData 1.0

Window {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Organizer")
    property int number: 0
    Saving {
        id:_saving
    }

    IntValidator {
        id: _intValid
    }
    Column {
        id: _column0
        spacing: 10

        Rectangle {
        id: _rectangel
        width: _column.width
        height: _column.height
        color: "green"

        Column {
            id: _column
            padding: 20
            spacing: 10

            TextField {
                id: _name
                placeholderText: qsTr("Name")
            }

            TextField {
                id: _date
                validator: RegExpValidator { regExp: /(0[1-9]|[12][0-9]|3[01])[ \.-](0[1-9]|1[012])[ \.-](20|)\d\d/ }
                placeholderText: qsTr("dd.mm.yyyy")
                focus: true
            }

            SpinBox {
                id: _spinBox
                width: _date.width
                from: 0
                to: 10
            }

            Button {
                id: _button
                text: qsTr("Save")
                width: _date.width
                onClicked: {

                    _saving.saveData(_name.text, _date.text, _spinBox.value)
                    _name.clear()
                    _date.clear()
                    _spinBox.value = 0
                    root.number +=1
                }
                Label {
                    text: root.number
                }
            }
        }
    }

        Rectangle {
            id: _rectangel2
            width: _column.width
            height: _column.height

            TextEdit {

                width: 240
                font.family: "Helvetica"
                font.pointSize: 14
                color: "black"
                focus: true
                id:textEdit
            }
        }
    }
}

