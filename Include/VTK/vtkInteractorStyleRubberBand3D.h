/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkInteractorStyleRubberBand3D.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/*-------------------------------------------------------------------------
  Copyright 2008 Sandia Corporation.
  Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
  the U.S. Government retains certain rights in this software.
-------------------------------------------------------------------------*/
// .NAME vtkInteractorStyleRubberBand3D - A rubber band interactor for a 3D view
//
// .SECTION Description
// vtkInteractorStyleRubberBand3D manages interaction in a 3D view.
// The style also allows draws a rubber band using the left button.
// All camera changes invoke InteractionBeginEvent when the button
// is pressed, InteractionEvent when the mouse (or wheel) is moved,
// and InteractionEndEvent when the button is released.  The bindings
// are as follows:
// Left mouse - Select (invokes a SelectionChangedEvent).
// Right mouse - Rotate.
// Shift + right mouse - Zoom.
// Middle mouse - Pan.
// Scroll wheel - Zoom.

#ifndef __vtkInteractorStyleRubberBand3D_h
#define __vtkInteractorStyleRubberBand3D_h

#include "vtkInteractorStyleTrackballCamera.h"

class vtkUnsignedCharArray;

class VTK_RENDERING_EXPORT vtkInteractorStyleRubberBand3D : public vtkInteractorStyleTrackballCamera
{
public:
  static vtkInteractorStyleRubberBand3D *New();
  vtkTypeRevisionMacro(vtkInteractorStyleRubberBand3D, vtkInteractorStyleTrackballCamera);
  void PrintSelf(ostream& os, vtkIndent indent);

  virtual void OnLeftButtonDown();
  virtual void OnLeftButtonUp();
  virtual void OnMiddleButtonDown();
  virtual void OnMiddleButtonUp();
  virtual void OnRightButtonDown();
  virtual void OnRightButtonUp();
  virtual void OnMouseMove();
  virtual void OnMouseWheelForward();
  virtual void OnMouseWheelBackward();

  // Description:
  // Whether to invoke a render when the mouse moves.
  vtkSetMacro(RenderOnMouseMove, bool);
  vtkGetMacro(RenderOnMouseMove, bool);
  vtkBooleanMacro(RenderOnMouseMove, bool);

  //BTX
  // Description:
  // Selection types
  enum
    {
    SELECT_NORMAL = 0,
    SELECT_UNION = 1
    };
  //ETX

  // Description:
  // Current interaction state
  vtkGetMacro(Interaction, int);
  
  //BTX
  enum
    {
    NONE,
    PANNING,
    ZOOMING,
    ROTATING,
    SELECTING
    };
  //ETX
    
protected:
  vtkInteractorStyleRubberBand3D();
  ~vtkInteractorStyleRubberBand3D();
  
  // The interaction mode
  int Interaction;
  
  // Draws the selection rubber band
  void RedrawRubberBand();
  
  // The end position of the selection
  int StartPosition[2];
  
  // The start position of the selection
  int EndPosition[2];
  
  // The pixel array for the rubber band
  vtkUnsignedCharArray* PixelArray;

  // Whether to trigger a render when the mouse moves
  bool RenderOnMouseMove;
  
private:
  vtkInteractorStyleRubberBand3D(const vtkInteractorStyleRubberBand3D&); //Not implemented
  void operator=(const vtkInteractorStyleRubberBand3D&); // Not implemented
};

#endif
