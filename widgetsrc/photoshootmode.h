/*************************************************************************************
 *  Copyright (C) 2008-2011 by Aleix Pol <aleixpol@kde.org>                          *
 *  Copyright (C) 2008-2011 by Alex Fiestas <alex@eyeos.org>                         *
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

#ifndef PHOTOSHOOTMODE_H
#define PHOTOSHOOTMODE_H

#include "shootmode.h"
#include <QPointer>
#include <QPushButton>

class PhotoShootMode : public ShootMode
{
Q_OBJECT
    public:
        PhotoShootMode(Kamoso* camera);

        virtual QList<QAction*> actions() { return mActions; }
        virtual QWidget* mainAction();
        virtual QIcon icon() const;
        virtual QString name() const;
        virtual QStringList thumbnailsViewMimeTypes() const;
        virtual void deactivate();

    private Q_SLOTS:
        void shootClicked(bool pressed);
        void release();

    private:
        QList<QAction*> mActions;
        QPointer<QPushButton> mTrigger;
};

#endif // PHOTOSHOOTMODE_H