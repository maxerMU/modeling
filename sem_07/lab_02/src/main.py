import sys
from PyQt5.QtCore import QObject, pyqtSlot, Qt
from PyQt5 import uic, QtWidgets, QtGui
from PyQt5.QtWidgets import QApplication, QWidget, QListWidgetItem,  QTableWidgetItem
import markov

class MainWindow(QWidget):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.ui = uic.loadUi("window.ui", self)
        self.ui.tableWidgetMatrix.horizontalHeader().setDefaultSectionSize(30)
        self.tableWidgetMatrix.itemChanged.connect(lambda x: self._item_changed(x))
        self.spinBoxStatesCount.setValue(3)
            
    def _item_changed(self, value):
        try:
            if value.text() != "":
                float(value.text())
        except ValueError:
            QtWidgets.QMessageBox.critical(None, "Invalid input", "Please, enter a float number!")
            value.setText("")

    @pyqtSlot()
    def on_pushButtonSolve_clicked(self):
        table = self._get_matrix_from_table()
        self.ui.listWidgetSolution.clear()
        i = 1
        result = markov.get_system_times(table)
        if len(result) == 0:
            QtWidgets.QMessageBox.critical(None, "Invalid input", "Please, enter correct intensities!")
        else:
            for i in range(len(result[0])):
                QListWidgetItem("{n}: {time:0.5f} {p:0.5f}".format(n = i + 1, time = round(result[0][i], 5), p = round(result[1][i], 5)), self.ui.listWidgetSolution)

    @pyqtSlot('int')
    def on_spinBoxStatesCount_valueChanged(self, value):
        self.ui.tableWidgetMatrix.setRowCount(value)
        self.ui.tableWidgetMatrix.setColumnCount(value)
        self.ui.tableWidgetMatrix.clearContents()
            

    def _get_matrix_from_table(self):
        res = []
        try:
            for i in range(self.ui.tableWidgetMatrix.rowCount()):
                row = []
                for j in range(self.ui.tableWidgetMatrix.columnCount()):
                    item  = self.ui.tableWidgetMatrix.item(i, j)
                    val =  item.text() if item and item.text() != "" else "0"
                    row.append(float(val))
                res.append(row)
        except KeyError:
            print(res)
            QtWidgets.QMessageBox.critical(None, "Invalid input", "Please, enter a float number!")
        return res

def main():
    app = QApplication(sys.argv)

    window = MainWindow()
    window.show()

    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
