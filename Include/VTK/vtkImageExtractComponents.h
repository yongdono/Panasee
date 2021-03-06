/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkImageExtractComponents.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkImageExtractComponents - Outputs a single component
// .SECTION Description
// vtkImageExtractComponents takes an input with any number of components
// and outputs some of them.  It does involve a copy of the data.

// .SECTION See Also
// vtkImageAppendComponents

#ifndef __vtkImageExtractComponents_h
#define __vtkImageExtractComponents_h


#include "vtkThreadedImageAlgorithm.h"

class VTK_IMAGING_EXPORT vtkImageExtractComponents : public vtkThreadedImageAlgorithm
{
public:
  static vtkImageExtractComponents *New();
  vtkTypeRevisionMacro(vtkImageExtractComponents,vtkThreadedImageAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Set/Get the components to extract.
  void SetComponents(int c1);
  void SetComponents(int c1, int c2);
  void SetComponents(int c1, int c2, int c3);
  vtkGetVector3Macro(Components,int);
  
  // Description:
  // Get the number of components to extract. This is set implicitly by the 
  // SetComponents() method.
  vtkGetMacro(NumberOfComponents,int);

protected:
  vtkImageExtractComponents();
  ~vtkImageExtractComponents() {};

  int NumberOfComponents;
  int Components[3];

  virtual int RequestInformation (vtkInformation *, vtkInformationVector**,
                                  vtkInformationVector *);
  
  void ThreadedExecute (vtkImageData *inData, vtkImageData *outData, 
                       int ext[6], int id);
private:
  vtkImageExtractComponents(const vtkImageExtractComponents&);  // Not implemented.
  void operator=(const vtkImageExtractComponents&);  // Not implemented.
};

#endif










