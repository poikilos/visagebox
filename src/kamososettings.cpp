#include "kamososettings.h"
#include <kamosoSettings.h>

QUrl KamosoSettings::saveUrl() const
{
    return Settings::self()->saveUrl();
}

void KamosoSettings::setSaveUrl(const QUrl& url)
{
    Settings::self()->setSaveUrl(url);
    Q_EMIT saveUrlChanged();
}


