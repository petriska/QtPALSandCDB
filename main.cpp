/**********************************************************
 *  QtPALSandCDB software for combined PALS + CDB setup
 *  using DRS4 EVM board for PALS and Adlink PCI9820 digitizer for CDB
 *
 *  Copyright (C) 2022 Martin Petriska
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 * @contact: martin.petriska@stuba.sk
 *
 *********************************************************/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("PASLAB");
    a.setOrganizationDomain("UJFI FEI STU");
    a.setApplicationName("QtPALSandCDB");
    a.setApplicationVersion("0.0.1");
    MainWindow w;
    w.show();
    return a.exec();
}
