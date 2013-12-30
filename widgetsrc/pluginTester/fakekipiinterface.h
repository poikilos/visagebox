/*************************************************************************************
 *  Copyright (C) 2008-2010 by Aleix Pol <aleixpol@kde.org>                          *
 *  Copyright (C) 2008-2010 by Alex Fiestas <alex@eyeos.org>                         *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/

#ifndef FAKEKIPIINTERFACE_H
#define FAKEKIPIINTERFACE_H

#include <QList>

#include <kurl.h>
#include <libkipi/interface.h>
#include <libkipi/uploadwidget.h>
#include <libkipi/imagecollectionshared.h>

class FakeKIPIInterfacePrivate;
class FakeKIPIInterface :public KIPI::Interface {
    Q_OBJECT

public:
    FakeKIPIInterface(QUrl::List& kurlList);
    virtual ~FakeKIPIInterface();

    virtual bool addImage(const QUrl&, QString& err);
    virtual void delImage( const QUrl& );
    virtual void refreshImages( const QUrl::List& urls );

    virtual KIPI::ImageCollectionSelector* imageCollectionSelector(QWidget *parent);
    virtual KIPI::UploadWidget* uploadWidget(QWidget *parent);


    virtual QList< KIPI::ImageCollection > allAlbums();
    virtual KIPI::ImageCollection currentAlbum();
    virtual KIPI::ImageCollection currentSelection();
    virtual int features() const;
    virtual KIPI::ImageInfo info(const QUrl& );

private:
    private:
    FakeKIPIInterfacePrivate* const d;
};

#endif // FAKEKIPIINTERFACE_H
