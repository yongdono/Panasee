#ifndef	comp_hpp
#define	comp_hpp
#include "iodbase.hpp"
#pragma warning (disable:4355)
// ModalityWorklistInformationIOD
// Composite Module:ModalityWorklistInformationIODModule


// A.2.3 CR Image
// Composite Module:BasicDirectoryIODModule

//������������DICOMDIR
//�ڲ��ĳ�Ա�����˱��������
//ͨ�������������DICOMDIR�Ĳ���
//�����Ա����μ�iodbase.hpp

class	BasicDirectoryIODModule	:
	public	CCO_Abstract
	{
	public:
		CO_FileSetIdentificationModule		FileSetIdentificationModule;
		CO_DirectoryInformationModule		DirectoryInformationModule;
		BasicDirectoryIODModule()	:
			FileSetIdentificationModule(this),
			DirectoryInformationModule(this)
				{
				ReferentialIntegrityDatabase.Build();
				};
		BasicDirectoryIODModule(DICOMObject *DO)	:
			FileSetIdentificationModule(this),
			DirectoryInformationModule(this)
				{
				ReferentialIntegrityDatabase.Build();
				Set(DO);
				};
	}; // End of class defination for: BasicDirectoryIODModule


//���ඨ���˺˴Ź���ͼ�󸴺���Ϣ
//�ڲ��ĳ�Ա�����˱��������
//ͨ������������ɺ˴Ź���ͼ��
//�����Ա����μ�iodbase.hpp
// Composite Module:MRImageIODModule
class	MRImageIODModule	:
	public	CCO_Abstract
	{
	public:
		CO_PatientModule		PatientModule;
		CO_GeneralStudyModule		GeneralStudyModule;
		CO_PatientStudyModule		PatientStudyModule;
		CO_GeneralSeriesModule		GeneralSeriesModule;
		CO_FrameOfReferenceModule		FrameOfReferenceModule;
		CO_GeneralEquipmentModule		GeneralEquipmentModule;
		CO_GeneralImageModule		GeneralImageModule;
		CO_ImagePlaneModule		ImagePlaneModule;
		CO_ImagePixelModule		ImagePixelModule;
		CO_ContrastBolusModule		ContrastBolusModule;
		CO_MRImageModule		MRImageModule;
		CO_OverlayPlaneModule		OverlayPlaneModule;
		CO_VOILUTModule		VOILUTModule;
		CO_SOPCommonModule		SOPCommonModule;
		MRImageIODModule()	:
			PatientModule(this),
			GeneralStudyModule(this),
			PatientStudyModule(this),
			GeneralSeriesModule(this),
			FrameOfReferenceModule(this),
			GeneralEquipmentModule(this),
			GeneralImageModule(this),
			ImagePlaneModule(this),
			ImagePixelModule(this),
			ContrastBolusModule(this),
			MRImageModule(this),
			OverlayPlaneModule(this),
			VOILUTModule(this),
			SOPCommonModule(this)
				{
				ReferentialIntegrityDatabase.Build();
				};
		MRImageIODModule(DICOMObject *DO)	:
			PatientModule(this),
			GeneralStudyModule(this),
			PatientStudyModule(this),
			GeneralSeriesModule(this),
			FrameOfReferenceModule(this),
			GeneralEquipmentModule(this),
			GeneralImageModule(this),
			ImagePlaneModule(this),
			ImagePixelModule(this),
			ContrastBolusModule(this),
			MRImageModule(this),
			OverlayPlaneModule(this),
			VOILUTModule(this),
			SOPCommonModule(this)
				{
				ReferentialIntegrityDatabase.Build();
				Set(DO);
				};
	}; // End of class defination for: MRImageIODModule
#endif