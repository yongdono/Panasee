
/* CO_Abstract and CCO_Abstract support classes */

#	include	"dicom.hpp"
#	include	"iod.hpp"
//��������
BOOL
CO_Abstract	::	Morph (
	DICOMObject	*)
	{
	return ( TRUE );	// we dont have any excess
	}
//��������

BOOL
CO_Abstract	::	SetIf (
	VR	*vr)
	{
	return ( FALSE );	// we never take any excess
	}
//��������

BOOL
CO_Abstract	::	Reset ()
	{
	return ( TRUE );	// and we never reset
	}
//��������
BOOL
CCO_Abstract	::	Reset ()
	{
	DICOMObject::Reset();
	return ( TRUE );
	}
//��DICOMObject���������ת�Ƶ���������
BOOL
CCO_Abstract	::	Set (
	DICOMObject	*DO)
	{
	VR	*vr;

	if ( ! DO )
		return ( FALSE );
	while(vr = DO->Pop())
		Push(vr);

	return ( TRUE );
	}

//���캯��
CCO_Abstract	::	CCO_Abstract ()
	{
	ReferentialIntegrityDatabase.LinkUp = this;
	}
//��������
CCO_Abstract	::	CCO_Abstract (
	DICOMObject	*DO)
	{
	ReferentialIntegrityDatabase.LinkUp = this;
	Set(DO);
	}
//������ѹ�뱾����
BOOL
CCO_Abstract	::	Push (
	VR	*vr)
	{
	ReferentialIntegrityDatabase.SetMaster ( vr );
	return ( DICOMObject :: Push ( vr ) );
	}
//����VR
VR	*
CCO_Abstract	::	Pop ()
	{
	VR	*vr = DICOMObject :: Pop ();

	if ( vr )
		ReferentialIntegrityDatabase.ClearMaster (vr->Group, vr->Element);

	return ( vr );
	}
//ͬ��
BOOL
CCO_Abstract	::	Sync ()
	{
	ReferentialIntegrityDatabase.Sync ();
	return ( TRUE );
	}
//ǿ��ת��
CCO_Abstract	::	operator	DICOMDataObject	* ()
	{
	return((DICOMDataObject*)this);
	}
//ǿ��ת��

CCO_Abstract	::	operator	DICOMCommandObject	* ()
	{
	return((DICOMCommandObject*)this);
	}
