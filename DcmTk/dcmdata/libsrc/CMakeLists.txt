# create library from source files
ADD_LIBRARY(dcmdata cmdlnarg dcbytstr dcchrstr dccodec dcdatset dcddirif dcdebug dcdicdir dcdicent dcdict dcdictzz dcdirrec dcelem dcerror dcfilefo dchashdi dcistrma dcistrmb dcistrmf dcistrmz dcitem dclist dcmetinf dcobject dcostrma dcostrmb dcostrmf dcostrmz dcpcache dcpixel dcpixseq dcpxitem dcrleccd dcrlecce dcrlecp dcrledrg dcrleerg dcrlerp dcsequen dcstack dcswap dctag dctagkey dctypes dcuid dcvm dcvr dcvrae dcvras dcvrat dcvrcs dcvrda dcvrds dcvrdt dcvrfd dcvrfl dcvris dcvrlo dcvrlt dcvrobow dcvrof dcvrpn dcvrpobw dcvrsh dcvrsl dcvrss dcvrst dcvrtm dcvrui dcvrul dcvrulup dcvrus dcvrut dcxfer)

# declare installation files
INSTALL_TARGETS(${INSTALL_LIBDIR} dcmdata)
INSTALL_FILES(${INSTALL_LIBDIR} FILES dicom.dic private.dic)
