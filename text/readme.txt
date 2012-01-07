Na p�ilo�en�m CD je k nalezen� spustiteln� *.exe soubor s p�ilo�en�mi dynamick�mi knihovnami, pro opera�n� syst�mu Windows. V p��pad� pot�eby spustit aplikaci pod opera�n�m syst�mem Linux, je t�eba projekt znovu zkompilovat.

Projekt je z�visl� na knihovn�ch libjpeg, Boost::gil (verze 1.47) s roz���en�mi, Qt (verze 4.7) a libexif.

P�i kompilaci pod OS Linux je t�eba postupovat n�sledovn�:
1) Nainstalovat knihovnu libjpeg, kter� je k nalezen� na http://www.ijg.org/.
2) St�hnout knihovnu Boost (je otestov�na na verzi 1.47, u verze 1.48 doch�zelo v dob� psan� bakal��sk� pr�ce ke koliz�m jmen s knihovnou Qt) a k nalezen� na http://sourceforge.net/projects/boost/files/boost/1.47.0/. Knihovna je tvo�ena hlavi�kov�mi soubory, nen� tak t�eba instalace. Pro GIL je t�eba i numerick� roz���en� z http://opensource.adobe.com/wiki/display/gil/Downloads.
3) Nainstalovat knihovnu libexif, kter� je k nalezen� na http://sourceforge.net/projects/libexif/files/libexif/0.6.20/.
4) Nainstalovat Qt SDK z http://qt.nokia.com/downloads.
5) Projekt spustit v prost�ed� Qt Creator.
6) Je t�eba upravit projektov� soubor MGalv2.pro (nap�. v prost�ed� Qt Creator), kde se do LIBS p�idaj� odkazy na knihovny libjpeg a libexif a do INCLUDEPATH cesty k hlavi�kov�m soubor�m Boost::GIL, libexif a libjpeg.
7) Spustit kompilaci.

Pro instalace knihoven libexif a libjpeg by m�lo sta�it zm�nit cestu v konzoli na slo�ku, do kter� byly knihovny nakop�rov�ny a n�sledn� jen spustit p��kazy:
./configure
make
make install
