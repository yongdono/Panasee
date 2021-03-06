/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkImageInPlaceFilter.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkImageInPlaceFilter - Filter that operates in place.
// .SECTION Description
// vtkImageInPlaceFilter is a filter super class that 
// operates directly on the input region.  The data is copied
// if the requested region has different extent than the input region
// or some other object is referencing the input region.  

// .SECTION See Also
// vtkImageToImageFilter vtkImageMultipleInputFilter vtkImageTwoInputFilter


#ifndef __vtkImageInPlaceFilter_h
#define __vtkImageInPlaceFilter_h

#include "vtkImageAlgorithm.h"

class VTK_FILTERING_EXPORT vtkImageInPlaceFilter : public vtkImageAlgorithm
{
public:
  vtkTypeRevisionMacro(vtkImageInPlaceFilter,vtkImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

protected:
  vtkImageInPlaceFilter();
  ~vtkImageInPlaceFilter();

  virtual int RequestData(vtkInformation *request,
                          vtkInformationVector** inputVector,
                          vtkInformationVector* outputVector);

  void CopyData(vtkImageData *in, vtkImageData *out);
  
private:
  vtkImageInPlaceFilter(const vtkImageInPlaceFilter&);  // Not implemented.
  void operator=(const vtkImageInPlaceFilter&);  // Not implemented.
};

#endif







